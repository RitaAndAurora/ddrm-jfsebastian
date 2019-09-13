/*
  ==============================================================================

    LogoComponent.h
    Created: 25 Jul 2019 8:41:36am
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class LogoComponent: public Component
{
public:
    
    LogoComponent ()
    {
        logoImage.setImage(ImageCache::getFromMemory (BinaryData::RitaAuroraLogo1_png, BinaryData::RitaAuroraLogo1_pngSize));
        addAndMakeVisible (logoImage);
    }
    
    ~LogoComponent ()
    {
    }
    
    void resized () override
    {
        logoImage.setBounds(0, 0, getWidth(), getHeight());
    }
    
private:
    ImageComponent logoImage;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LogoComponent);
};
