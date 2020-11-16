/*
  ==============================================================================

    DDRMControlPanelExtraComponent.h
    Created: 4 Jul 2019 9:14:13am
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "CustomLookAndFeel.h"
#include "defines.h"

class DDRMControlPanelExtraComponent: public Component,
                       public ActionListener,
                       public Button::Listener
{
public:
    
    DDRMControlPanelExtraComponent ()
    {
        importButton.addListener (this);
        importButton.setButtonText("Import...");
        addAndMakeVisible (importButton);
        
        saveButton.addListener (this);
        saveButton.setButtonText("Save...");
        addAndMakeVisible (saveButton);
        
        copyButton.addListener (this);
        copyButton.setButtonText("Copy...");
        addAndMakeVisible (copyButton);
        
        randomizeButton.addListener (this);
        randomizeButton.setButtonText("Randomize!");
        addAndMakeVisible (randomizeButton);
        
        sendButton.addListener (this);
        sendButton.setButtonText("Send to synth...");
        addAndMakeVisible (sendButton);    
    }
    
    ~DDRMControlPanelExtraComponent ()
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
        float buttonWidthShort = getWidth() * 80/800;
        float buttonWidthLong = getWidth() * 120/800;
        float buttonHeight = getHeight();
        float margin = getWidth() * 10/800;
        importButton.setBounds (0, 0, buttonWidthShort, buttonHeight);
        saveButton.setBounds (1 * (buttonWidthShort + margin), 0, buttonWidthShort, buttonHeight);
        copyButton.setBounds (2 * (buttonWidthShort + margin), 0, buttonWidthShort, buttonHeight);
        randomizeButton.setBounds (3 * (buttonWidthShort + margin), 0, buttonWidthLong, buttonHeight);
        sendButton.setBounds (3 * (buttonWidthShort + margin) + 1 * (buttonWidthLong + margin), 0, buttonWidthLong, buttonHeight);
    }
    
    void actionListenerCallback (const String &message) override
    {
        // TODO: implement action listenr handlers
    }
    
    void buttonClicked (Button* button) override
    {
        int  selectedActionID = -1;
        
        if (button == &importButton)
        {
            PopupMenu m;
            m.addItem (MENU_OPTION_ID_IMPORT_FROM_PATCH_FILE, "From patch file");
            m.addItem (MENU_OPTION_ID_IMPORT_FROM_VOICE_FILE_TO_VOICE_1, "From voice file to channel I");
            m.addItem (MENU_OPTION_ID_IMPORT_FROM_VOICE_FILE_TO_VOICE_2, "From voice file to channel II");
            selectedActionID = m.showAt(button);
        }
        else if (button == &saveButton)
        {
            PopupMenu m;
            m.addItem (MENU_OPTION_ID_SAVE_PATCH_TO_PATCH_FILE, "To patch file");
            m.addItem (MENU_OPTION_ID_SAVE_VOICE_1_TO_VOICE_FILE, "Channel I to voice file");
            m.addItem (MENU_OPTION_ID_SAVE_VOICE_2_TO_VOICE_FILE, "Channel II to voice file");
            selectedActionID = m.showAt(button);
        }
        else if (button == &copyButton)
        {
            PopupMenu m;
            m.addItem (MENU_OPTION_ID_COPY_VOICE_1_TO_VOICE_2, "From channel I to channel II");
            m.addItem (MENU_OPTION_ID_COPY_VOICE_2_TO_VOICE_1, "From channel II to channel I");
            m.addItem (MENU_OPTION_ID_SWAP_VOICES, "Swap channels");
            selectedActionID = m.showAt(button);
        }
        else if (button == &randomizeButton)
        {
            selectedActionID = MENU_OPTION_ID_RANDOMIZE;
        }
        else if (button == &sendButton)
        {
            PopupMenu m;
            m.addItem (MENU_OPTION_ID_SEND_PATCH_TO_SYNTH, "Patch");
            m.addItem (MENU_OPTION_ID_SEND_VOICE_1_TO_SYNTH, "Channel I");
            m.addItem (MENU_OPTION_ID_SEND_VOICE_2_TO_SYNTH, "Channel II");
            selectedActionID = m.showAt(button);
        }
        
        if (selectedActionID > 0){
            processMenuAction(selectedActionID);
        }
    }
    
    void processMenuAction(int actionID)
    {
        if (actionID == MENU_OPTION_ID_COPY_VOICE_1_TO_VOICE_2){
            processor->copyDDRMChannel1ToChannel2();
        } else if (actionID == MENU_OPTION_ID_COPY_VOICE_2_TO_VOICE_1){
            processor->copyDDRMChannel2ToChannel1();
        } else if (actionID == MENU_OPTION_ID_SWAP_VOICES){
            processor->swapDDRMChannels();
        } else if (actionID == MENU_OPTION_ID_SEND_PATCH_TO_SYNTH){
            processor->sendControlsToSynth(-1);  // -1 menans no channel filter (all controls)
        } else if (actionID == MENU_OPTION_ID_SEND_VOICE_1_TO_SYNTH){
            processor->sendControlsToSynth(1);
        } else if (actionID == MENU_OPTION_ID_SEND_VOICE_2_TO_SYNTH){
            processor->sendControlsToSynth(2);
        } else if (actionID == MENU_OPTION_ID_RANDOMIZE){
            processor->randomizeControlValues();
        } else if (actionID == MENU_OPTION_ID_IMPORT_FROM_PATCH_FILE){
            processor->importFromPatchFile();
        } else if (actionID == MENU_OPTION_ID_IMPORT_FROM_VOICE_FILE_TO_VOICE_1){
            processor->importFromVoiceFile(1);
        } else if (actionID == MENU_OPTION_ID_IMPORT_FROM_VOICE_FILE_TO_VOICE_2){
            processor->importFromVoiceFile(2);
        } else if (actionID == MENU_OPTION_ID_SAVE_PATCH_TO_PATCH_FILE){
            processor->saveToPatchFile();
        } else if (actionID == MENU_OPTION_ID_SAVE_VOICE_1_TO_VOICE_FILE){
            processor->saveToVoiceFile(1);
        } else if (actionID == MENU_OPTION_ID_SAVE_VOICE_2_TO_VOICE_FILE){
            processor->saveToVoiceFile(2);
        } else {
            std::cout << "Non implemented action selected " << actionID << std::endl;
        }
    }
    
private:
    DdrmtimbreSpaceAudioProcessor* processor;
    
    CustomLookAndFeel customLookAndFeel;
    
    TextButton importButton;
    TextButton saveButton;
    TextButton copyButton;
    TextButton randomizeButton;
    TextButton sendButton;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DDRMControlPanelExtraComponent);
};

