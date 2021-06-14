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

class DdrmtimbreSpaceAudioProcessorEditor;


class UIWrapperComponent: public Component,
                          public ActionListener,
                          public Button::Listener
{
public:
    UIWrapperComponent();
    ~UIWrapperComponent();
    
    void initialize (DdrmtimbreSpaceAudioProcessor* p, DdrmtimbreSpaceAudioProcessorEditor* e);
    void paint (Graphics&) override;
    void resized() override;
    void buttonClicked (Button* button) override;
    void processMenuAction(int actionID);
    
    int sizeWidth = 0;
    int sizeHeight = 0;
    
private:
    DdrmtimbreSpaceAudioProcessor* processor;
    DdrmtimbreSpaceAudioProcessorEditor* editor;
    bool wasInitialized = false;
    
    // Bg image
    Image bgImage;
    
    // Header & footer components
    HeaderComponent header;
    LogoComponent logo;
    FooterComponent footer;
    TextButton viewButton;
    
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

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UIWrapperComponent)
};


class DdrmtimbreSpaceAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    DdrmtimbreSpaceAudioProcessorEditor (DdrmtimbreSpaceAudioProcessor&);
    ~DdrmtimbreSpaceAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    CustomLookAndFeel customLookAndFeel;  // Make it public so UIWrapperComponent can access it

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DdrmtimbreSpaceAudioProcessor& processor;
    UIWrapperComponent uiWrapper;
    Viewport uiViewport;
    
    int screenHeight = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DdrmtimbreSpaceAudioProcessorEditor)
};
