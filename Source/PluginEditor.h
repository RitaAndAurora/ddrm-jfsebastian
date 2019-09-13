/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "defines.h"
#include "PluginProcessor.h"
#include "DDRMControlPanelComponent.h"
#include "DDRMToneSelectorComponent.h"
#include "DDRMControlPanelExtraComponent.h"
#include "TimbreSpaceComponent.h"
#include "PresetControlComponent.h"
#include "MIDISettingsComponent.h"
#include "HeaderComponent.h"
#include "FooterComponent.h"
#include "LogoComponent.h"
#include "CustomLookAndFeel.h"

//==============================================================================
/**
*/
class DdrmtimbreSpaceAudioProcessorEditor  : public AudioProcessorEditor,
                                             public ActionListener
{
public:
    DdrmtimbreSpaceAudioProcessorEditor (DdrmtimbreSpaceAudioProcessor&);
    ~DdrmtimbreSpaceAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DdrmtimbreSpaceAudioProcessor& processor;
    
    // Look and feel
    CustomLookAndFeel customLookAndFeel;
    Image bgImage;
    
    // Header & footer components
    HeaderComponent header;
    LogoComponent logo;
    FooterComponent footer;
    
    // MIDI Settings component
    MIDISettingsComponent midiSettingsPanel;
    
    // Preset control component
    PresetControlComponent presetControlPanel;
    
    // DDRM Control panel component
    DDRMControlPanelComponent ddrmControlPanel;
    DDRMControlPanelExtraComponent ddrmControlPanelExtra;
    
    // Timbre Space component
    TimbreSpaceComponent timbreSpace;
    
    // Tone selector component
    DDRMToneSelectorComponent ddrmToneSelector;
    
    // Logging code
    void actionListenerCallback (const String &message) override;
    void logMessageInUI (const String& message);
    TextEditor logArea;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DdrmtimbreSpaceAudioProcessorEditor)
};
