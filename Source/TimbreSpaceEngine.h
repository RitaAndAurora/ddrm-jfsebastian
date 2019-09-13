//
//  TimbreSpaceEnginge.h
//  DDRMTimbreSpace
//
//  Created by Frederic Font Corbera on 17/04/2019.
//  Copyright © 2019 Rita&AuroraAudio. All rights reserved.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "defines.h"
#include <delaunator/delaunator.h>
#include <tapkee/tapkee.hpp>


class TimbreSpaceEngine: public ActionBroadcaster

{
public:
    TimbreSpaceEngine ()
    {
        selectedPointX = -1.0;
        selectedPointY = -1.0;
        selectedTriangleIdx = 0;
        selectedPresetPointIdx = -1;
        synthSlidersOutOfSync = true;
        
        // Set last timbre space was updated from position parameter automation to now
        lastTimeInterpolatedPresetLoaded = Time::currentTimeMillis();
        
        solution = ValueTree(TIMBRE_SPACE_SOLUTION_IDENTIFIER);
    }
    
    ~TimbreSpaceEngine ()
    {
        // De-register action listeners
        removeAllActionListeners();
    }
    
    void computeMapPoints(timbreSpaceInputDataMatrix data)
    {
        // Filter out rows of the matrix which correspond to empty presets
        // That will be rows in which the sum of all of its values is not above some threshold (hence all being 0s or noise).
        // We also need to keep a record of the original matrix row number and the corresponding rows in the resulting filtered
        // matrix as row numbers of the original matrix correspond to preset IDXs.
        
        // Filter input data
        timbreSpaceInputDataMatrix filteredData;
        std::vector<int> presetIDXmap;
        for (int i=0; i < data.size(); i++){
            float rowSum = 0.0;
            for (int j=0; j < data[i].size(); j++){
                rowSum += data[i][j];
            }
            if (rowSum > EMPTY_PRESET_SUM_THRESHOLD){
                filteredData.push_back(data[i]);
                presetIDXmap.push_back(i);
            }
        }
        
        // Do map computation
        /*
         The function doing map computation is expected to outputs a ValueTree
         object representing the "solution" of the map computation. The ValueTree must
         have as many children as points in the input data. Each children must in its
         turn be a nested ValueTree with the following properties:
         - presetIdx: the preset index (of the bank) to which the point corresponds
         - x: x position in a normalized [0-1] coordinate space
         - y: y position in a normalized [0-1] coordinate space
         - r: r component of an RGB colouring for the point (range [0-1])
         - g: g component of an RGB colouring for the point (range [0-1])
         - b: b component of an RGB colouring for the point (range [0-1])
         
         Input "data" is of type timbreSpaceInputDataMatrix, which is a matrix of floats
         (implemented as a vector of vectors) in which each row corresponds to one preset
         of the loaded bank. The number of rows in "data" could be different than the number
         of presets in the bank as some presets might not be used for map computation (e.g.
         empty pesets). To know which preset corresponds to which row of "data", the
         "presetIDXmap" argument is passed which is a vector of integers that map "data" rows
         to the corresponding preset indexes in the loaded bank.
         */
        ValueTree solutionPoints = computeMapUsingMethod(filteredData, presetIDXmap, DIMENSIONALITY_REDUCTION_METHOD_DEFAULT);
        
        // Store results in class member
        if (hasMapPointsComputed()){
            // If already existing child with name, remove it
            solution.removeChild(solution.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER), nullptr);
        }
        solution.appendChild(solutionPoints, nullptr);
    }
    
    void computeTriangulation()
    {
        if (!solution.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).isValid()){
            #if JUCE_DEBUG
                logMessage("Can't compute triangulation as no map points have not yet been computed");
            #endif
            return;
        }
        
        // Compute delanuay triangles and convert to coordinates
        ValueTree solutionPoints = solution.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER);
        std::vector<double> coords;
        for (int i=0; i<solutionPoints.getNumChildren(); i++){
            coords.push_back((double)solutionPoints.getChild(i)["x"]);
            coords.push_back((double)solutionPoints.getChild(i)["y"]);
        }
                             
        ValueTree solutionTriangles = ValueTree(TIMBRE_SPACE_SOLUTION_TRIANGLES_IDENTIFIER);
        delaunator::Delaunator d(coords);
        for(std::size_t i = 0; i < d.triangles.size(); i+=3) {
            ValueTree solutionTriangle = ValueTree(TIMBRE_SPACE_SOLUTION_TRIANGLE_IDENTIFIER);
            solutionTriangle.setProperty("x1", d.coords[2 * d.triangles[i]], nullptr);
            solutionTriangle.setProperty("y1", d.coords[2 * d.triangles[i] + 1], nullptr);
            solutionTriangle.setProperty("x2", d.coords[2 * d.triangles[i + 1]], nullptr);
            solutionTriangle.setProperty("y2", d.coords[2 * d.triangles[i + 1] + 1], nullptr);
            solutionTriangle.setProperty("x3", d.coords[2 * d.triangles[i + 2]], nullptr);
            solutionTriangle.setProperty("y3", d.coords[2 * d.triangles[i + 2] + 1], nullptr);
            solutionTriangle.setProperty("preset1Idx", (int)d.triangles[i], nullptr);
            solutionTriangle.setProperty("preset2Idx", (int)d.triangles[i + 1], nullptr);
            solutionTriangle.setProperty("preset3Idx", (int)d.triangles[i + 2], nullptr);
            solutionTriangles.appendChild(solutionTriangle, nullptr);
        }
        if (hasTrianglesComputed()){
         // If already existing child with name, remove it
            solution.removeChild(solution.getChildWithName(TIMBRE_SPACE_SOLUTION_TRIANGLES_IDENTIFIER), nullptr);
        }
        solution.appendChild(solutionTriangles, nullptr);
    }
    
    void selectPointInSpace(float x, float y)
    {
        if (!solutionComputed()){
            #if JUCE_DEBUG
                logMessage("No solution computed, can't select point in space");
            #endif
            return;
        }
        
        // Store selected point in class member
        // coordinates can be updated individually if either x or y are set to -1.0f
        if (x != -1.0f){
            selectedPointX = x;
        }
        if (y != -1.0f){
            selectedPointY = y;
        }
        selectedPresetPointIdx = -1; // Points do not correspond to any specific preset
        selectedTriangleIdx = -1; // Reset selected triangle idx
        
        // Get interpolation data
        selectedPointInterpolationData = getInterpolationDataForPointUsingTriangulation();
        //selectedPointInterpolationData = getInterpolationDataForPointUsingNN(10);
        
        #if JUCE_DEBUG
            logMessage(String::formatted("Interpolating %i presets", selectedPointInterpolationData.size()));
        #endif
        
        // Load interpolated preset
        loadInterpolatedPresetInProcessor();
    
        // Repaint timbre space UI
        loadSelectedPointDataInTimbreSpaceComponentAndRepaint ();
        
        // Set selected point in sync
        setSelectedPointInSync();
    }
    
    float getSelectedPointX()
    {
        return selectedPointX;
    }
    
    float getSelectedPointY()
    {
        return selectedPointY;
    }
    
    int getSelectedTriangleIdx()
    {
        return selectedTriangleIdx;
    }
    
    int getSelectedPresetPointIdx()
    {
        return selectedPresetPointIdx;
    }
    
    ValueTree getSolution()
    {
        return solution;
    }
    
    PresetDistancePairsToInterpolate getSelectedPointInterpolationData()
    {
        return selectedPointInterpolationData;
    }
                             
    bool hasMapPointsComputed() {
        return solution.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).isValid();
    }

    bool hasTrianglesComputed() {
        return solution.getChildWithName(TIMBRE_SPACE_SOLUTION_TRIANGLES_IDENTIFIER).isValid();
    }

    bool solutionComputed() {
        return hasMapPointsComputed() && hasTrianglesComputed();
    }
    
    void setSelectedPointOutOfSync() {
        setTimbreSpaceComponentOutOfSyncWithSliders();
        synthSlidersOutOfSync = true;
    }
    
    void setSelectedPointInSync() {
        setTimbreSpaceComponentInSyncWithSliders();
        synthSlidersOutOfSync = false;
    }
    
    // State load/save
    
    ValueTree getState()
    {
        // Returns the internal state of TimbreSpaceEngine as a value tree object
        ValueTree state = ValueTree(STATE_TIMBRE_SPACE_IDENTIFIER);
        state.setProperty(STATE_TIMBRE_SPACE_SELECTED_POINT_X_IDENTIFIER, selectedPointX, nullptr);
        state.setProperty(STATE_TIMBRE_SPACE_SELECTED_POINT_Y_IDENTIFIER, selectedPointY, nullptr);
        state.setProperty(STATE_TIMBRE_SPACE_SELECTED_TRIANGLE_IDX_IDENTIFIER, selectedTriangleIdx, nullptr);
        state.setProperty(STATE_TIMBRE_SPACE_SELECTED_PRESET_IDX_IDENTIFIER, selectedPresetPointIdx, nullptr);
        state.setProperty(STATE_TIMBRE_SPACE_OUT_OF_SYNC, synthSlidersOutOfSync, nullptr);
        state.appendChild(solution, nullptr);
        return state;
    }
    
    void loadState(ValueTree state)
    {
        if (state.getChildWithName(TIMBRE_SPACE_SOLUTION_IDENTIFIER).isValid()){
            solution = state.getChildWithName(TIMBRE_SPACE_SOLUTION_IDENTIFIER);
            
            // Only load rest of state if solution is present
            if (state.hasProperty(STATE_TIMBRE_SPACE_SELECTED_POINT_X_IDENTIFIER)){
                selectedPointX = (float)state.getProperty(STATE_TIMBRE_SPACE_SELECTED_POINT_X_IDENTIFIER);
            }
            if (state.hasProperty(STATE_TIMBRE_SPACE_SELECTED_POINT_Y_IDENTIFIER)){
                selectedPointY = (float)state.getProperty(STATE_TIMBRE_SPACE_SELECTED_POINT_Y_IDENTIFIER);
            }
            if (state.hasProperty(STATE_TIMBRE_SPACE_SELECTED_TRIANGLE_IDX_IDENTIFIER)){
                selectedTriangleIdx = (int)state.getProperty(STATE_TIMBRE_SPACE_SELECTED_TRIANGLE_IDX_IDENTIFIER);
            }
            if (state.hasProperty(STATE_TIMBRE_SPACE_SELECTED_PRESET_IDX_IDENTIFIER)){
                selectedPresetPointIdx = (int)state.getProperty(STATE_TIMBRE_SPACE_SELECTED_PRESET_IDX_IDENTIFIER);
            }
            if (state.hasProperty(STATE_TIMBRE_SPACE_OUT_OF_SYNC)){
                synthSlidersOutOfSync = (bool)state.getProperty(STATE_TIMBRE_SPACE_OUT_OF_SYNC);
            }
            
            logMessage("Loaded Timbre Space solution form state");
        }
    }
    
    // Functions to communicate with Timbre Space Component
    
    void loadSelectedPointDataInTimbreSpaceComponentAndRepaint ()
    {
        sendActionMessage(ACTION_LOAD_SELECTED_POINT_DATA);
        sendActionMessage(ACTION_REPAINT);
    }
    
    void loadSolutionDataInTimbreSpaceComponent()
    {
        sendActionMessage(ACTION_LOAD_TS_SOLUTION);
    }
    
    void setIsLoadingSolutionInTimbreSpaceComponent()
    {
        sendActionMessage(ACTION_SET_IS_COMPUTING_TS_SOLUTION);
    }
    
    void setTimbreSpaceComponentSlidersSyncStatus()
    {
        if (synthSlidersOutOfSync == true){
            setTimbreSpaceComponentOutOfSyncWithSliders();
        } else {
            setTimbreSpaceComponentInSyncWithSliders();
        }
    }
    
    void setTimbreSpaceComponentOutOfSyncWithSliders()
    {
        sendActionMessage(ACTION_SET_TS_SLIDERS_OUT_OF_SYNC);
    }
    
    void setTimbreSpaceComponentInSyncWithSliders()
    {
        sendActionMessage(ACTION_SET_TS_SLIDERS_IN_SYNC);
    }
    
    void setTimbreSpaceComponentXYToPresetNumber(int presetIdx)
    {
        // Update selectedPresetPointIdx and set it to the solution preset index which corresponds to the selected
        // preset bank index. These two indices might be different if when creating the timbre space some presets
        // get filtered out
        selectedPresetPointIdx = -1;
        for (int i=0; i<solution.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getNumChildren(); i++){
            ValueTree point = solution.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getChild(i);
            if ((int)point["presetIdx"] ==  presetIdx){
                selectedPresetPointIdx = i;
                break;
            }
        }
        sendActionMessage(ACTION_SET_TS_XY_TO_PRESET_NUMBER);
    }
    
    bool isSynthSlidersOutOfSync(){
        return synthSlidersOutOfSync;
    }
    
private:
    
    ValueTree solution;
    float selectedPointX;
    float selectedPointY;
    int selectedTriangleIdx;
    int selectedPresetPointIdx;
    bool synthSlidersOutOfSync; // This is used to indicate wether synth controls correpsond to a position in the timbre space or are out of sync
    PresetDistancePairsToInterpolate selectedPointInterpolationData;
    int64 lastTimeInterpolatedPresetLoaded;
    
    void logMessage (const String& message)
    {
        // Broadcasts a "LOG:" action with a message that will be received in the editor and printed to the logArea component
        sendActionMessage(ACTION_LOG_PREFIX + message);
    }
    
    void loadInterpolatedPresetInProcessor ()
    {
        // Load interpolated preset
        int64 currentTime = Time::currentTimeMillis();
        if (currentTime - lastTimeInterpolatedPresetLoaded > MIN_MILLISECONDS_FOR_AUTOMATION_TIMBRE_SPACE_UPDATE){
            // Because loading the preset to the synth involves sending many MIDI messages, make sure we don't trigger that action
            // More than X times per second
            sendActionMessage(ACTION_LOAD_INTERPOLATED_PRESET);
            lastTimeInterpolatedPresetLoaded = currentTime;
        }
    }
    
    std::vector<float> normalizeFloatVector(std::vector<float> v)
    {
        // Normalize vector in range [0-1]
        float max = *std::max_element(v.begin(), v.end());
        float min = *std::min_element(v.begin(), v.end());
        std::vector<float> v_out;
        for (int i=0; i<v.size(); i++){
            v_out.push_back((v[i] - min) / (max - min));
        }
        return v_out;
    }
    
    int getTriangleForPoint(float x, float y)
    {
        // Return the triangle index where the sleected point is found
        int triangleIdx = -1;
        if (!solutionComputed()){
            #if JUCE_DEBUG
                logMessage("No solution computed, can't get triangle for point");
            #endif
        } else {
            for(int i=0; i < solution.getChildWithName(TIMBRE_SPACE_SOLUTION_TRIANGLES_IDENTIFIER).getNumChildren(); i++){
                ValueTree triangle = solution.getChildWithName(TIMBRE_SPACE_SOLUTION_TRIANGLES_IDENTIFIER).getChild(i);
                if (isInTriangle(x, y,
                                 (float)triangle["x1"], (float)triangle["y1"],
                                 (float)triangle["x2"], (float)triangle["y2"],
                                 (float)triangle["x3"], (float)triangle["y3"])){
                    triangleIdx = i;
                }
            }
        }
        return triangleIdx;
    }
    
    float euclideanDistance(float x1, float y1, float x2, float y2)
    {
        // Adapted from http://www.cplusplus.com/forum/beginner/178293/
        float x = x1 - x2;
        float y = y1 - y2;
        float dist;
        dist = pow(x, 2) + pow(y, 2);
        dist = sqrt(dist);
        return dist;
    }
    
    PresetDistancePairsToInterpolate getPresetInterpolationDataForTriangle(float x, float y, int triangleIdx)
    {
        if (!solutionComputed()){
            #if JUCE_DEBUG
                logMessage("No solution computed, can't get triangle for point");
            #endif
        }
        
        // Return the presets correspodning to the vertices of the triangle and their distances
        // to the given point
        int preset1Idx, preset2Idx, preset3Idx;
        float preset1Dist, preset2Dist, preset3Dist;
        
        if (!solutionComputed()){
            #if JUCE_DEBUG
                logMessage("No solution computed, can't get preset interpolation data");
            #endif
            preset1Idx = preset2Idx = preset3Idx = -1;
            preset1Dist = preset2Dist = preset3Dist = -1.0;
            
        } else {
            ValueTree triangle = solution.getChildWithName(TIMBRE_SPACE_SOLUTION_TRIANGLES_IDENTIFIER).getChild(triangleIdx);
            preset1Idx = (int)triangle["preset1Idx"];
            preset2Idx = (int)triangle["preset2Idx"];
            preset3Idx = (int)triangle["preset3Idx"];
            preset1Dist = euclideanDistance(x, y, (float)solution.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getChild(preset1Idx)["x"], (float)solution.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getChild(preset1Idx)["y"]);
            preset2Dist = euclideanDistance(x, y, (float)solution.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getChild(preset2Idx)["x"], (float)solution.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getChild(preset2Idx)["y"]);
            preset3Dist = euclideanDistance(x, y, (float)solution.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getChild(preset3Idx)["x"], (float)solution.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getChild(preset3Idx)["y"]);
        }
        
        PresetDistancePairsToInterpolate output;
        PresetDistanceStruct pd;
        pd.presetIdx = preset1Idx;
        pd.presetDist = preset1Dist;
        output.push_back(pd);
        pd.presetIdx = preset2Idx;
        pd.presetDist = preset2Dist;
        output.push_back(pd);
        pd.presetIdx = preset3Idx;
        pd.presetDist = preset3Dist;
        output.push_back(pd);
        
        return output;
    }
    
    bool isInTriangle(float px, float py, float ax, float ay, float bx, float by, float cx, float cy)
    {
        // Target point (px, py)
        // Triangle coodinates (ax, ay), (bx, by), (cx, cy)
        //credit: http://www.blackpawn.com/texts/pointinpoly/default.html
        
        float v0_0 = cx - ax;
        float v0_1 = cy - ay;
        float v1_0 = bx - ax;
        float v1_1 = by - ay;
        float v2_0 = px - ax;
        float v2_1 = py - ay;
        
        float dot00 = (v0_0 * v0_0) + (v0_1 * v0_1);
        float dot01 = (v0_0 * v1_0) + (v0_1 * v1_1);
        float dot02 = (v0_0 * v2_0) + (v0_1 * v2_1);
        float dot11 = (v1_0 * v1_0) + (v1_1 * v1_1);
        float dot12 = (v1_0 * v2_0) + (v1_1 * v2_1);
        
        float invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
        
        float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
        float v = (dot00 * dot12 - dot01 * dot02) * invDenom;
        
        return ((u >= 0) && (v >= 0) && (u + v < 1));
    }
    
    tapkee::TapkeeOutput doDimensionalityReduction(tapkee::DenseMatrix inputData, int outDimensions, const String& methodName)
    {
        #if JUCE_DEBUG
            logMessage(String::formatted("Computing dimensionality reduction of %i dimensions with method ", outDimensions) + methodName);
        #endif
        tapkee::TapkeeOutput output;
        if (methodName == DIMENSIONALITY_REDUCTION_METHOD_TSNE){
            output = tapkee::initialize()
            .withParameters((tapkee::method=tapkee::tDistributedStochasticNeighborEmbedding,
                             tapkee::target_dimension=outDimensions))
            .embedUsing(inputData);
        } else if (methodName == DIMENSIONALITY_REDUCTION_METHOD_MDS){
           output = tapkee::initialize()
            .withParameters((tapkee::method=tapkee::MultidimensionalScaling,
                             tapkee::target_dimension=outDimensions))
            .embedUsing(inputData);
        } else if (methodName == DIMENSIONALITY_REDUCTION_METHOD_PCA){
            output = tapkee::initialize()
            .withParameters((tapkee::method=tapkee::PCA,
                             tapkee::target_dimension=outDimensions))
            .embedUsing(inputData);
        } else {
            // Use PCA by default
            output = tapkee::initialize()
            .withParameters((tapkee::method=tapkee::PCA,
                             tapkee::target_dimension=outDimensions))
            .embedUsing(inputData);
        }
        return output;
    }
    
    ValueTree computeMapUsingMethod(timbreSpaceInputDataMatrix data, std::vector<int> presetIDXmap, const String& methodName)
    {
        // NOTE: See computeMap documentation for details about input and output signatures of this function
        
        // Adapt input data and put it into matrix needed by tapkee
        int N, D;
        N = (int)data.size();
        D = (int)data[0].size();
        tapkee::DenseMatrix inputData(N, D);
        for (int i=0; i<inputData.rows(); i++){
            for (int j=0; j<inputData.cols(); j++){
                inputData(i,j) = data[i][j];
            }
        }
        inputData = inputData.transpose();
       
        // Compute dimensionality reduction in 2D and normalize output
        tapkee::TapkeeOutput output2D = doDimensionalityReduction(inputData, 2, methodName);
        std::vector<float> xx2D, yy2D;
        for (int i=0; i<output2D.embedding.rows(); i++)
        {
            xx2D.push_back((float)output2D.embedding(i,0));
            yy2D.push_back((float)output2D.embedding(i,1));
        }
        xx2D = normalizeFloatVector(xx2D);
        yy2D = normalizeFloatVector(yy2D);
        
        // Compute dimensionality reduction in 3D and normalize output
        tapkee::TapkeeOutput output3D = doDimensionalityReduction(inputData, 3, methodName);
        std::vector<float> xx3D, yy3D, zz3D;
        for (int i=0; i<output3D.embedding.rows(); i++)
        {
            xx3D.push_back((float)output3D.embedding(i,0));
            yy3D.push_back((float)output3D.embedding(i,1));
            zz3D.push_back((float)output3D.embedding(i,2));
        }
        xx3D = normalizeFloatVector(xx3D);
        yy3D = normalizeFloatVector(yy3D);
        zz3D = normalizeFloatVector(zz3D);
        
        // Store results of in solution ValueTree (remove children if alreadye xisting)
        ValueTree solutionPoints = ValueTree(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER);
        for (int i=0; i<N; i++){
            ValueTree solutionPoint = ValueTree(TIMBRE_SPACE_SOLUTION_POINT_IDENTIFIER);
            solutionPoint.setProperty("presetIdx", presetIDXmap[i], nullptr);
            solutionPoint.setProperty("x", xx2D[i], nullptr);
            solutionPoint.setProperty("y", yy2D[i], nullptr);
            solutionPoint.setProperty("r", xx3D[i], nullptr);
            solutionPoint.setProperty("g", yy3D[i], nullptr);
            solutionPoint.setProperty("b", zz3D[i], nullptr);
            solutionPoints.appendChild(solutionPoint, nullptr);
        }
        
        return solutionPoints;
    }
    
    PresetDistancePairsToInterpolate getInterpolationDataForPointUsingTriangulation()
    {
        /*
         Returns PresetDistancePairsToInterpolate for the presets to interpolate using the triangulation method
         if possible or 3-NN search for points outside triangles. Does not take input parameters as uses class
         members to get information about selected point and other necessary data.
         */
        
        PresetDistancePairsToInterpolate interpolationData;
        
        // Find which triangle contains the point
        selectedTriangleIdx = getTriangleForPoint(selectedPointX, selectedPointY);
        
        if (selectedTriangleIdx > -1){
            // Prepare interpolation data for the 3 points of the triangle enclosing the selected point
            interpolationData = getPresetInterpolationDataForTriangle(selectedPointX, selectedPointY, selectedTriangleIdx);
        } else {
            // If selected point outside triangle, fall back to the nearest neighbours method
            interpolationData = getInterpolationDataForPointUsingNN(3);
        }
        
        return interpolationData;
    }
    
    PresetDistancePairsToInterpolate getInterpolationDataForPointUsingNN(int N)
    {
        /*
         Returns PresetDistancePairsToInterpolate for the presets to interpolate using the nearest neigbours method
         Does not take input parameters as uses class members to get information about selected point and other necessary data.
         */

        // Calculate distances with all points
        std::vector<std::pair<float, int>> distances;
        for (int i=0; i<solution.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getNumChildren(); i++){
            ValueTree point = solution.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getChild(i);
            float distance =  euclideanDistance(selectedPointX, selectedPointY, (float)point["x"], (float)point["y"]);
            distances.emplace_back(distance, (int)point["presetIdx"]);
        }
        
        // Sort points by distance
        std::sort(distances.begin(), distances.end());
        
        // Take the N first points (the N nearest neighbours) and add to PresetDistancePairsToInterpolate
        PresetDistancePairsToInterpolate interpolationData;
        for (int i=0; i<N; i++){
            PresetDistanceStruct pd;
            pd.presetIdx = distances[i].second;
            pd.presetDist = distances[i].first;
            interpolationData.push_back(pd);
        }
    
        return interpolationData;
    }
};
