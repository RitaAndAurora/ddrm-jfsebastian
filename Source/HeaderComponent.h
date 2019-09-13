/*
  ==============================================================================

    HeaderComponent.h
    Created: 2 Jul 2019 8:51:56am
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "defines.h"

class HeaderComponent: public Component,
                       public ActionListener
{
public:
    
    HeaderComponent ()
    {
        titleImage.setImage(ImageCache::getFromMemory (BinaryData::TitleLogo_png, BinaryData::TitleLogo_pngSize));
        addAndMakeVisible (titleImage);
    }
    
    ~HeaderComponent ()
    {
        processor->removeActionListener(this);  // Stop receivng messages from processor
    }
    
    void initialize (DdrmtimbreSpaceAudioProcessor* p)
    {
        // Set processor object
        processor = p;
        
        // Set up listeners
        processor->addActionListener(this);  // Receive messages from processor
    }
    
    void resized () override
    {
        titleImage.setBounds (0, 0, getHeight() * 20, getHeight());
    }
    
    void actionListenerCallback (const String &message) override
    {
        // TODO: implement action listenr handlers
    }
    
private:
    DdrmtimbreSpaceAudioProcessor* processor;
    ImageComponent titleImage;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HeaderComponent);
};

