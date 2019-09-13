/*
  ==============================================================================

    TimbreSpaceComponent.h
    Created: 25 Apr 2019 8:32:52am
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "defines.h"


class TimbreSpaceComponent: public Component,
                            public ActionListener

{
public:
    TimbreSpaceComponent ()
    {
        isLoadingData = false;
        dataLoaded = false;
        
        overlayImage = ImageCache::getFromMemory (BinaryData::TS_OVERLAY_corners_fixed_png, BinaryData::TS_OVERLAY_corners_fixed_pngSize);
    }
    
    ~TimbreSpaceComponent ()
    {
        processor->timbreSpaceEngine->removeActionListener(this);  // Stop receivng messages from timbre space engine
    }
    
    void initialize (DdrmtimbreSpaceAudioProcessor* p)
    {
        processor = p;
        
        // Set up listeners
        processor->timbreSpaceEngine->addActionListener(this);  // Receive messages from timbre space engine
        
        // Init variables and try to load solution (if any already present)
        setWantsKeyboardFocus(true);
        drawExtraInfo = true;
        lastTimeMouseDragged = Time::currentTimeMillis();
        initMainVariables();
        setStateFromProcessor ();
    }
    
    void initMainVariables() {
        // Init variables that will need to be re-set when re-loading ts data
        backgroundNeedsUpdate = true;
        selectedPointX = 0.5;
        selectedPointY = 0.5;
        selectedTriangleIdx = -1;
        selectedPointInterpolationData = {};
        synthControlsOutOfSync = true;
    }
    
    void setStateFromProcessor () {
        // Try to load data from timbre space engine (if existing) and repaint
        setTimbreSpaceData(processor->timbreSpaceEngine->getSolution());
        if (dataLoaded){
            // If data has been loaded do also other init steps
            selectedPointX = processor->timbreSpaceEngine->getSelectedPointX();
            selectedPointY = processor->timbreSpaceEngine->getSelectedPointY();
            selectedTriangleIdx = processor->timbreSpaceEngine->getSelectedTriangleIdx();
            if (processor->timbreSpaceEngine->isSynthSlidersOutOfSync()){
                synthControlsOutOfSync = true;
            } else {
                synthControlsOutOfSync = false;
            }
            repaint();
        }
    }
    
    void setTimbreSpaceData (ValueTree solution)
    {
        if (solution.isValid()){
            initMainVariables();
            data = solution;
            dataLoaded = true;
            isLoadingData = false;
        }
    }
    
    void paint (Graphics& g) override
    {
        // Configure font
        g.setFont(((CustomLookAndFeel&)getLookAndFeel()).tsHudFont);  // Sent font face
        
        if (isLoadingData) {
            // Is loading data
            g.fillAll (Colours::black);
            float fontSize = 12.0f;
            g.setColour (Colours::white);
            g.setFont(fontSize);
            g.drawFittedText("Loading Timbre Space...", 0, 0, getWidth(), getHeight(), Justification::centred, 1);
            
            // Draw tv-like overlay
            g.drawImage (overlayImage, getLocalBounds().toFloat());
            return;
        }
        
        if (!dataLoaded) {
            // No data loaded (and no loading any data)
            g.fillAll (Colours::black);
            
            // Draw tv-like overlay
            g.drawImage (overlayImage, getLocalBounds().toFloat());
            return;
        }
        
        // Background circles
        float bigCircleRadius = 1.5 * getWidth();
        float bigCricleOpacity = 0.1f;
        float smallCircleRadius = 0.5 * getWidth();
        float smallCircleOpacity = 0.5f;
        
        // Triangles, preset circles and interpolation data
        float trianglesLineIWdth = 1.0f;
        float presetCircleRadius = 0.0f;
        float presetCircleLineWidth = 2.0f;
        float presetLabelFontSize = 12.0f;
        float interpolatedPresetCircleRadius = 6.0f;
        float interpolatedPresetCircleLineWidth = 1.0f;
        Colour interpolatedPresetCircleColour = Colour(0xFFFFFFFF);
        Colour trianglesColour = Colour(0x33FFFFFF);
        Colour selectedTriangleColour = Colour(0x33FFFFFF);
        Colour selectedTriangleFillColour = Colour(0x33FFFFFF);
        PathStrokeType stroke(trianglesLineIWdth);
        
        // Selected point
        float selectedPointRadius = 0.0f;  // 6.0 Set it to 0 to draw no circle
        float selectedPointLineWidth = 1.0f;
        float selectedPointLineGap = 15.0f;  // Set it no negative to draw no line
        Colour selectedPointColour = Colours::white;
        Colour selectedPointOutOfSyncColour = Colour(0x99FFFFFF);  // Semi transparent
        
        if (backgroundNeedsUpdate){
            // Compute new background
            
            backgroundImage = Image(Image::RGB, getWidth(), getHeight(), true);
            Graphics gBg(backgroundImage);
            
            float saturation = 1.0;
            float brightnessMultiplier = 1.8;
            
            // Fill bg colour
            gBg.fillAll (Colours::black);
            
            // Draw big circles
            for (int i=0; i<data.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getNumChildren(); i++){
                ValueTree point = data.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getChild(i);
                float x = (float)point["x"] * getWidth();
                float y = (float)point["y"] * getHeight();
                float red = (float)point["r"];
                float green = (float)point["g"];
                float blue = (float)point["b"];
                
                Colour color1 = Colour::fromFloatRGBA(red, green, blue, bigCricleOpacity).withSaturation(saturation).withMultipliedBrightness(brightnessMultiplier);
                Colour color2 = Colour::fromFloatRGBA(red, green, blue, 0.0f).withSaturation(saturation).withMultipliedBrightness(brightnessMultiplier);
                ColourGradient cg = ColourGradient(color1, x, y, color2, x + 0.5 * bigCircleRadius, y + 0.5 * bigCircleRadius, true);
                gBg.setGradientFill (cg);
                gBg.fillEllipse (x - bigCircleRadius, y - bigCircleRadius, bigCircleRadius * 2, bigCircleRadius * 2);
            }
            
            // Draw small circles
            for (int i=0; i<data.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getNumChildren(); i++){
                ValueTree point = data.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getChild(i);
                float x = (float)point["x"] * getWidth();
                float y = (float)point["y"] * getHeight();
                float red = (float)point["r"]; 
                float green = (float)point["g"];
                float blue = (float)point["b"];
                
                Colour color1 = Colour::fromFloatRGBA(red, green, blue, bigCricleOpacity).withSaturation(saturation).withMultipliedBrightness(brightnessMultiplier);
                Colour color2 = Colour::fromFloatRGBA(red, green, blue, 0.0f).withSaturation(saturation).withMultipliedBrightness(brightnessMultiplier);
                ColourGradient cg = ColourGradient(color1, x, y, color2, x + 0.5 * smallCircleRadius, y + 0.5 * smallCircleRadius, true);
                gBg.setGradientFill (cg);
                gBg.fillEllipse (x - smallCircleRadius, y - smallCircleRadius, smallCircleRadius * 2, smallCircleRadius * 2);
            }
            
            // Draw background image to component and set backgroundNeedsUpdate to false so next time we run this
            // function we don't recompute the background image and draw the saved one
            g.drawImage(backgroundImage, getLocalBounds().toFloat());
            backgroundNeedsUpdate= false;
            
        } else {
            // Load stored background
            g.drawImage(backgroundImage, getLocalBounds().toFloat());
        }
        
        // Draw preset circles, triangles and interpolation data
        if (drawExtraInfo) {
            g.setColour(trianglesColour);
            
            // Draw preset circles
            if (presetCircleRadius){
                for (int i=0; i<data.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getNumChildren(); i++){
                    ValueTree point = data.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getChild(i);
                    float x = (float)point["x"] * getWidth();
                    float y = (float)point["y"] * getHeight();
                    g.drawEllipse (x - presetCircleRadius, y - presetCircleRadius, presetCircleRadius * 2, presetCircleRadius * 2, presetCircleLineWidth);
                }
            }
            
            // Draw triangles (if any)
            for(int i=0; i < data.getChildWithName(TIMBRE_SPACE_SOLUTION_TRIANGLES_IDENTIFIER).getNumChildren(); i++){
                ValueTree triangle = data.getChildWithName(TIMBRE_SPACE_SOLUTION_TRIANGLES_IDENTIFIER).getChild(i);
                float x1 = (float)triangle["x1"] * getWidth();
                float y1 = (float)triangle["y1"] * getHeight();
                float x2 = (float)triangle["x2"] * getWidth();
                float y2 = (float)triangle["y2"] * getHeight();
                float x3 = (float)triangle["x3"] * getWidth();
                float y3 = (float)triangle["y3"] * getHeight();
                Path path;
                path.addTriangle (x1, y1, x2, y2, x3, y3);
                g.strokePath (path, stroke);
            }
            
            // Draw selected triangle (if any)
            if (selectedTriangleIdx > -1) {
                g.setColour(selectedTriangleColour);
                ValueTree triangle = data.getChildWithName(TIMBRE_SPACE_SOLUTION_TRIANGLES_IDENTIFIER).getChild(selectedTriangleIdx);
                float x1 = (float)triangle["x1"] * getWidth();
                float y1 = (float)triangle["y1"] * getHeight();
                float x2 = (float)triangle["x2"] * getWidth();
                float y2 = (float)triangle["y2"] * getHeight();
                float x3 = (float)triangle["x3"] * getWidth();
                float y3 = (float)triangle["y3"] * getHeight();
                Path path;
                path.addTriangle (x1, y1, x2, y2, x3, y3);
                g.strokePath (path, stroke);
                g.setColour(selectedTriangleFillColour);
                g.fillPath (path);
            }
            
            // Mark points selected for interpolation (if any)
            if ((interpolatedPresetCircleRadius) && (selectedPointInterpolationData.size() > 0)){
                g.setColour(interpolatedPresetCircleColour);
                
                float totalDistance = 0.0;
                float minDist = 1000.0;
                float maxDist = 0.0;
                for (int i=0;i<selectedPointInterpolationData.size(); i++){
                    float dist = selectedPointInterpolationData[i].presetDist;
                    totalDistance += dist;
                    if (dist < minDist){
                        minDist = dist;
                    }
                    if (dist > maxDist){
                        maxDist = dist;
                    }
                }
                
                for (int i=0; i<selectedPointInterpolationData.size(); i++){
                    int presetIdx = selectedPointInterpolationData[i].presetIdx;
                    ValueTree point = data.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getChild(presetIdx);
                    float x = (float)point["x"] * getWidth();
                    float y = (float)point["y"] * getHeight();
                    
                    float dist = selectedPointInterpolationData[i].presetDist;
                    float normDist = 1 - (dist - minDist)/(maxDist - minDist);  // Invert distance so closer ones are 1.0
                    float minOpacity = 0.3;
                    normDist = normDist * (1.0 - minOpacity) + minOpacity; // Add minimum value so minimum opacity is not total transparent
                    g.setOpacity(normDist);
                    
                    // Draw circle
                    g.drawEllipse (x - interpolatedPresetCircleRadius, y - interpolatedPresetCircleRadius, interpolatedPresetCircleRadius * 2, interpolatedPresetCircleRadius * 2, interpolatedPresetCircleLineWidth);
                    
                    // Draw preset idx label
                    if (presetLabelFontSize) {
                        g.setFont(presetLabelFontSize);
                        g.drawSingleLineText(String::formatted("#%i", (int)point["presetIdx"] + 1), x + 15.0f, y + 0.0f);
                    }
                }
            }
        }
        
        // Draw current selected point
        if ((selectedPointX != -1.0) && (selectedPointY != -1.0)){
            float x = selectedPointX * getWidth();
            float y = selectedPointY * getHeight();
            if (!synthControlsOutOfSync){
                g.setColour (selectedPointColour);
            } else {
                g.setColour (selectedPointOutOfSyncColour);
            }
            
            if (selectedPointRadius > 0.0f){
                g.drawEllipse (x - selectedPointRadius, y - selectedPointRadius, selectedPointRadius * 2, selectedPointRadius * 2, selectedPointLineWidth);
            }

            if (selectedPointLineGap >= 0.0f){
                g.drawLine (0, y, x - (selectedPointLineGap / 2), y, selectedPointLineWidth);
                g.drawLine (x + (selectedPointLineGap / 2), y, getWidth(), y, selectedPointLineWidth);
                
                g.drawLine (x, 0, x, y - (selectedPointLineGap / 2), selectedPointLineWidth);
                g.drawLine (x, y + (selectedPointLineGap / 2), x, getHeight(), selectedPointLineWidth);
            }
        }
        
        // Draw tv-like overlay
        g.setOpacity(1.0);
        g.drawImage (overlayImage, getLocalBounds().toFloat());
    }
    
    void resized() override
    {
    }
    
    void mouseUp(const MouseEvent& event) override
    {
        if (event.mouseWasClicked() && dataLoaded){
            float x = (float)event.getMouseDownX() / getWidth();
            float y = (float)event.getMouseDownY() / getHeight();
            processor->updateSpacePointAudioParametersFromMouseEvent(x, y);  // This will in its time trigger the loading of new preset
        }
    }
    
    void mouseDrag(const MouseEvent& event) override
    {
        if (event.mouseWasDraggedSinceMouseDown() && dataLoaded){
            int64 currentTime = Time::currentTimeMillis();
            if (currentTime - lastTimeMouseDragged > MIN_MILLISECONDS_FOR_MOUSE_DRAG_UPDATE) {
                float x = (float)event.getPosition().x / getWidth();
                float y = (float)event.getPosition().y / getHeight();
                processor->updateSpacePointAudioParametersFromMouseEvent(x, y);  // This will in its time trigger the loading of new preset
                lastTimeMouseDragged = currentTime;
            }
        }
    }
    
    bool keyPressed(const KeyPress &k) override
    {
        if( k.getTextCharacter() == 't' ) {
            drawExtraInfo = !drawExtraInfo;
            repaint();
        }
        
        // Return true so key event is not passed to other consumers
        return true;
    }
    
    void actionListenerCallback (const String &message) override
    {
        if (message.startsWith(String(ACTION_LOAD_TS_SOLUTION))){
            setTimbreSpaceData(processor->timbreSpaceEngine->getSolution());
            repaint();
        }
        else if (message.startsWith(String(ACTION_SET_IS_COMPUTING_TS_SOLUTION))){
            isLoadingData = true;
            repaint();
        }
        else if (message.startsWith(String(ACTION_LOAD_SELECTED_POINT_DATA))){
            selectedPointX = processor->timbreSpaceEngine->getSelectedPointX();
            selectedPointY = processor->timbreSpaceEngine->getSelectedPointY();
            selectedTriangleIdx = processor->timbreSpaceEngine->getSelectedTriangleIdx();
            selectedPointInterpolationData = processor->timbreSpaceEngine->getSelectedPointInterpolationData();
        }
        else if (message.startsWith(String(ACTION_REPAINT))){
            repaint();
        }
        else if (message.startsWith(String(ACTION_SET_TS_SLIDERS_OUT_OF_SYNC))){
            if (!synthControlsOutOfSync){
                selectedTriangleIdx = -1;
                synthControlsOutOfSync = true;
                selectedPointInterpolationData = {};
                repaint();
            }
        }
        else if (message.startsWith(String(ACTION_SET_TS_SLIDERS_IN_SYNC))){
            if (synthControlsOutOfSync){
                synthControlsOutOfSync = false;
                repaint();
            }
        }
        else if (message.startsWith(String(ACTION_SET_TS_XY_TO_PRESET_NUMBER))){
            if (dataLoaded){
                int selectedPointIdx = processor->timbreSpaceEngine->getSelectedPresetPointIdx();
                if (selectedPointIdx > -1){
                    ValueTree point = data.getChildWithName(TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER).getChild(selectedPointIdx);
                    selectedPointX = (float)point["x"];
                    selectedPointY = (float)point["y"];
                } else {
                    selectedPointX = -1.0;
                    selectedPointY = -1.0;
                }
                selectedTriangleIdx = -1;
                synthControlsOutOfSync = true;
                selectedPointInterpolationData = {};
                repaint();
            }
        }
    }
    
private:
    DdrmtimbreSpaceAudioProcessor* processor;
    ValueTree data;
    bool isLoadingData;
    bool dataLoaded;
    
    Image backgroundImage;
    bool backgroundNeedsUpdate;
    bool drawExtraInfo;
    float selectedPointX;
    float selectedPointY;
    int selectedTriangleIdx;
    PresetDistancePairsToInterpolate selectedPointInterpolationData;
    bool synthControlsOutOfSync; // This is used to indicate wether synth controls correpsond to a position in the timbre space or are out of sync
    
    int64 lastTimeMouseDragged;
    
    Image overlayImage;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TimbreSpaceComponent);
};
