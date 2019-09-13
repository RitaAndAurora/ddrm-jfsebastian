//
//  DDRMPresetBank.h
//  DDRMTimbreSpace
//
//  Created by Frederic Font Corbera on 17/04/2019.
//  Copyright © 2019 Rita&AuroraAudio. All rights reserved.
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "defines.h"

class DDRMPresetBank: public ActionBroadcaster

{
public:
    DDRMPresetBank ()
    {
        bankFilename = "-";
    }
    
    ~DDRMPresetBank ()
    {
        // De-register action listeners
        removeAllActionListeners();
    }
    
    DDRMPresetBytes& getPresetBytesAtIndex(int index){
        // Return reference to preset byes at index position
        return presetsBytes.at(index);
    }
    
    void setPresetBytesAtIndex(int index, DDRMPresetBytes bytes)
    {
        presetsBytes[index] = bytes;
    }
    
    int getNumPresetsInBank(){
        // Returns number of loaded presets
        return (int)presetsBytes.size();
    }
    
    String getLoadedFilename()
    {
        return bankFilename;
    }
    
    bool hasDataLoaded() {
        return presetsBytes.size() > 0;
    }
    
    void loadFromFile(const String& filepath)
    {
        // Reads from DDRM bank file and fills presetsBytes
        // This function might throw errors if file has not correct format or other problems happen
        // Calls to this function should be prepared for that
        
        File path (filepath);
        MemoryBlock fileContents;
        path.loadFileAsData(fileContents);
        presetsBytes.clear();
        for (int i=0; i<fileContents.getSize(); i=i+DDRM_PRESET_NUM_BYTES){  // Move in blocks of 98 bytes (DDRM preset size)
            DDRMPresetBytes currentPresetBytes = {0};
            for (int j=0; j<DDRM_PRESET_NUM_BYTES; j++){  // Go byte by byte
                unsigned char byte = fileContents[i + j];
                uint8 byte_int = uint8(byte);
                currentPresetBytes[j] = byte_int;
            }
            presetsBytes.push_back(currentPresetBytes);
        }
        bankFilename = path.getFileName();
    }
    
    void loadState(ValueTree state)
    {
        // Load filename
        if (state.hasProperty(STATE_BANK_FILENAME_IDENTIFIER)){
            bankFilename = state.getProperty(STATE_BANK_FILENAME_IDENTIFIER).toString();
        }
     
        // Load preset data
        presetsBytes.clear();
        for (int i=0; i<state.getNumChildren(); i++){
            String serlializedPresetBytes = state.getChild(i)["bytes"].toString();
            StringArray serlializedPresetBytesTokens = StringArray::fromTokens(serlializedPresetBytes, ",", "\"");
            DDRMPresetBytes currentPresetBytes = {0};
            for (int j=0; j<serlializedPresetBytesTokens.size(); j++){
                currentPresetBytes[j] = uint8(serlializedPresetBytesTokens[j].getIntValue());
            }
            presetsBytes.push_back(currentPresetBytes);
        }
    }
    
    ValueTree getState()
    {
        // Returns the internal state of DDRMPResetBank as a value tree object, including:
        // - preset bytes for all presets in loaded bank
        ValueTree state = ValueTree(STATE_PRESET_BANK_IDENTIFIER);
        state.setProperty(STATE_BANK_FILENAME_IDENTIFIER, bankFilename, nullptr);
        for (int i=0; i<presetsBytes.size(); i++){
            ValueTree presetState = ValueTree(STATE_PRESET_IDENTIFIER);
            
            DDRMPresetBytes presetBytes = presetsBytes[i];
            StringArray currentPresetBytes;
            for (int j=0; j<presetBytes.size(); j++){
                currentPresetBytes.add((String)presetBytes[j]);
            }
            
            presetState.setProperty(STATE_PRESET_BYTES_IDENTIFIER, currentPresetBytes.joinIntoString(","), nullptr);
            presetState.setProperty(STATE_PRESET_IDX_IDENTIFIER, i, nullptr);
            // TODO: Add extra info about the current preset (if any)
            
            state.appendChild(presetState, nullptr);
        }
        return state;
    }
    
    void writeToFile()
    {
        // Writes the contents of presetsBytes to a file
    }
    
private:
    
    std::vector<DDRMPresetBytes> presetsBytes;
    String bankFilename;

};
