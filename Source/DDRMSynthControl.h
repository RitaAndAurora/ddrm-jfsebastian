//
//  DDRMSynthControl.h
//  DDRMTimbreSpace
//
//  Created by Frederic Font Corbera on 12/04/2019.
//  Copyright © 2019 Rita&AuroraAudio. All rights reserved.
//

#pragma once

#include <array>
#include "defines.h"

class DDRMSynthControl

{
public:
    DDRMSynthControl (const String& _ID, const String& _name, int _ccNumber, int _byteNumber, int _byteNumberVoiceFile, int _channelNumber, bool _includeOnTimbreSpace)
    {
        ID = _ID;
        name = _name;
        ccNumber = _ccNumber;
        byteNumber = _byteNumber;
        byteNumberVoiceFile = _byteNumberVoiceFile;
        channelNumber = _channelNumber;
        includeOnTimbreSpace = _includeOnTimbreSpace;
    }
    
    ~DDRMSynthControl ()
    {
    }
    
    const String getID ()
    {
        return ID;
    }
    
    const String getDisplayName ()
    {
        return name;
    }
    
    const String getDipslayValue (double normValue)
    {
        return String::formatted("%d", normValue);
    }
    
    int getCCNumber ()
    {
        return ccNumber;
    }
    
    int getChannelNumber ()
    {
        return channelNumber;
    }
    
    int getPresetByteNumber ()
    {
        return byteNumber;
    }
    
    int getVoiceByteNumber ()
    {
        return byteNumberVoiceFile;
    }
    
    bool shouldBeIncludedInTimbreSpace()
    {
        return includeOnTimbreSpace;
    }
    
    double getNormValueFromPresetByteArray(DDRMPresetBytes& bytes)
    {
        // Return parameter value normalized [0.0-1.0] taking it from corresponding spot in DDRMPresetBytes array
        // If parameter is not represented in DDRMPresetBytes, this will return -1
        
        if ((byteNumber > -1) && (byteNumber < DDRM_PRESET_NUM_BYTES)){
            return jlimit(0.0, 1.0, (double)bytes[byteNumber] / 255.0);
        }
        
        if (ID == "DDRM_GLIDE_MODE_GLIDE"){
            // Custom behaviour for DDRM_GLIDE_MODE_GLIDE
            // Note that some parameter info is hardcoded here and should be manually changed if needed
            // b72=255 & b80=0 -> portamento, b72=0 & b80=255 -> glissando, b72=0 & b80 = 0 -> none
            
            bool portamentoOn = bytes[72] > 127;  // Note range is 0-255 here
            bool glissandoOn = bytes[80] > 127; // Note range is 0-255 here
            
            if (portamentoOn && !glissandoOn) {
                return 0.0; // Portamento on
            } else if (!portamentoOn && glissandoOn) {
                return 1.0; // Glissando on
            } else {
                // If both off or both on, we consider none is active
                return 0.5; // Both off
            }
        }
        
        return -1.0;
    }
    
    double getNormValueFromVoiceByteArray(DDRMVoiceBytes& bytes)
    {
        // Return parameter value normalized [0.0-1.0] taking it from corresponding spot in DDRMPresetBytes array
        // If parameter is not represented in DDRMVoiceBytes, this will return -1
        if ((byteNumberVoiceFile > -1) && (byteNumberVoiceFile < DDRM_VOICE_NUM_BYTES)){
            return jlimit(0.0, 1.0, (double)bytes[byteNumberVoiceFile] / 255.0);
        }
        return -1.0;
    }
    
    void updatePresetByteArrayFromNormValue (float normValue, DDRMPresetBytes& bytes)
    {
        // Updates DDRMPresetBytes with the given normalized value of the synth control parameter
        // Normalized value ranges from [0.0-1.0], bytes range from [0-255]
        
        int byteValue = jlimit(0, 255, (int) round(normValue * 255));
        if ((byteNumber > -1) && (byteNumber < DDRM_PRESET_NUM_BYTES)){
            bytes[byteNumber] = byteValue;
        }
        
        if (ID == "DDRM_GLIDE_MODE_GLIDE"){
            // Custom behaviour for DDRM_GLIDE_MODE_GLIDE
            // Note that some parameter info is hardcoded here and should be manually changed if needed
            // b72=255 & b80=0 -> portamento, b72=0 & b80=255 -> glissando, b72=0 & b80 = 0 -> none
            
            // Currently all parameters are in range 0-127 therefore to return the "midi" value (the real parameter value) we just need to multiply by 127.
            // In the future there might be parameters outside the range 0-127 requiring special treatment
            int midiValue = jlimit(0, 127, (int) round((double)normValue * 127));
            
            if (midiValue < 32) { // Follow DDRM MIDI spec
                // Set to Portamento
                bytes[72] = 255;
                bytes[80] = 0;
            } else if (midiValue >= 32 && midiValue < 85) {
                // Set to None
                bytes[72] = 255;
                bytes[80] = 255;
            } else if (midiValue >= 85) {
                // Set to glissando
                bytes[72] = 0;
                bytes[80] = 255;
            }
        }
    }
    
    void updateVoiceByteArrayFromNormValue (float normValue, DDRMVoiceBytes& bytes)
    {
        // Updates DDRMVoiceBytes with the given normalized value of the synth control parameter
        // Normalized value ranges from [0.0-1.0], bytes range from [0-255]
        
        int byteValue = jlimit(0, 255, (int) round(normValue * 255));
        if ((byteNumberVoiceFile > -1) && (byteNumberVoiceFile < DDRM_VOICE_NUM_BYTES)){
            bytes[byteNumberVoiceFile] = byteValue;
        }
    }
    
private:
    
    String ID;
    String name;
    int ccNumber;
    int byteNumber;
    int byteNumberVoiceFile;
    int channelNumber;
    bool includeOnTimbreSpace;
};
