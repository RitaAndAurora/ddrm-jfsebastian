/*
  ==============================================================================

    PresetControlComponent.h
    Created: 24 May 2019 7:02:31pm
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "DDRMInterface.h"
#include "CustomLookAndFeel.h"
#include "defines.h"


class NumericEditorLabel: public Label
{
public:
    virtual TextEditor* createEditorComponent() override
    {
        // Sublass Label method to create an editor that only allows numeric characters and sets a max length
        TextEditor* const ed = Label::createEditorComponent();
        ed->setInputRestrictions(3, "0123456789");
        ed->setJustification(Justification::centred);
        ed->setColour(TextEditor::focusedOutlineColourId, Colours::transparentBlack);
        return ed;
    }
};


class PresetControlComponent: public Component,
                              public Button::Listener,
                              public ActionListener
{
public:
    
    PresetControlComponent ()
    {
        currentPresetSlidersOutOfSync = false;
        
        loadFileButton.addListener (this);
        loadFileButton.setButtonText("Load bank file...");
        addAndMakeVisible (loadFileButton);
        
        loadedFileLabel.setJustificationType (Justification::left);
        loadedFileLabel.setText("-", dontSendNotification);
        addAndMakeVisible (loadedFileLabel);
                
        customLookAndFeelSmallerFont.defaultFontSize = 11.0;

        nextPresetButton.addListener (this);
        nextPresetButton.setButtonText(">");
        nextPresetButton.setEnabled(false);
        nextPresetButton.setLookAndFeel(&customLookAndFeelSmallerFont);
        addAndMakeVisible (nextPresetButton);
        
        previousPresetButton.addListener (this);
        previousPresetButton.setButtonText("<");
        previousPresetButton.setEnabled(false);
        previousPresetButton.setLookAndFeel(&customLookAndFeelSmallerFont);
        addAndMakeVisible (previousPresetButton);
        
        presetNameLabel.setJustificationType (Justification::centred);
        presetNameLabel.setText(String(PRESET_NAME_DEFAULT_TEXT), dontSendNotification);
        presetNameLabel.setEnabled(false);
        presetNameLabel.setEditable (true);
        presetNameLabel.onTextChange = [this] { setPresetFromName(); };
        addAndMakeVisible (presetNameLabel);
        
        saveToCurrentBankLocationButton.addListener (this);
        saveToCurrentBankLocationButton.setEnabled(false);
        saveToCurrentBankLocationButton.setButtonText("Save to bank location...");
        addAndMakeVisible (saveToCurrentBankLocationButton);
        
        saveBankFileButton.addListener (this);
        saveBankFileButton.setEnabled(false);
        saveBankFileButton.setButtonText("Save bank file...");
        addAndMakeVisible (saveBankFileButton);
    }
    
    ~PresetControlComponent ()
    {
        processor->removeActionListener(this);  // Stop receivng messages from processor
    }
    
    void initialize (DdrmtimbreSpaceAudioProcessor* p)
    {
        // Set processor object
        processor = p;
        
        // Set up listeners
        processor->addActionListener(this);  // Receive messages from processor
        
        // Set initial state of mmebers by getting data from processor
        setStateFromProcessor();
    }
    
    void setStateFromProcessor () {
        // Load preset (plus out of sync indicator) name and bank filename (if data loaded)
        loadedFileLabel.setText(processor->ddrmInterface->getPresetBankLoadedFilename(), dontSendNotification);
        setPresetNameLabel ();
        if ((processor->currentPresetOutOfSyncWithSliders) && (presetNameLabel.getText() != String(PRESET_NAME_DEFAULT_TEXT))){
            presetNameLabel.setText(presetNameLabel.getText() + String(PRESET_NAME_MODIFIED_TEXT), dontSendNotification);
            //saveToCurrentBankLocationButton.setEnabled(true);  // Enable save preset button as it is out of sync
        }
        
        if (processor->ddrmInterface->hasPresetsDataLoaded()){
            enableBankTransportButtons();
        }
    }
    
    void resized () override
    {
        float unitMargin = getWidth() * 10/800;
        float fileNameLabelWidth = getWidth() * 120/800;
        float presetNameLabelWidth = getWidth() * 45/800;
        float defaultButtonWidth = getWidth() * 110/800;
        float nextPrevButtonWidth = getWidth() * 22/800;
        float saveBankLocationButtonWidth = getWidth() * 150/800;
        
        loadFileButton.setBounds (0, 0, defaultButtonWidth, getHeight());
        loadedFileLabel.setBounds (defaultButtonWidth + unitMargin, 0, fileNameLabelWidth, getHeight());
        previousPresetButton.setBounds (defaultButtonWidth + fileNameLabelWidth + 2 * unitMargin, 0, nextPrevButtonWidth, getHeight());
        presetNameLabel.setBounds (defaultButtonWidth + fileNameLabelWidth + nextPrevButtonWidth + 3 * unitMargin, 0, presetNameLabelWidth, getHeight());
        nextPresetButton.setBounds (defaultButtonWidth + fileNameLabelWidth + nextPrevButtonWidth + presetNameLabelWidth + 4 * unitMargin, 0, nextPrevButtonWidth, getHeight());
        saveToCurrentBankLocationButton.setBounds (defaultButtonWidth + fileNameLabelWidth + 2 * nextPrevButtonWidth + presetNameLabelWidth + 5 * unitMargin, 0, saveBankLocationButtonWidth, getHeight());
        saveBankFileButton.setBounds (defaultButtonWidth + fileNameLabelWidth + 2 * nextPrevButtonWidth + presetNameLabelWidth + saveBankLocationButtonWidth + 6 * unitMargin, 0, defaultButtonWidth, getHeight());
    }
    
    void loadBankFile()
    {
        juce::String patternFilter = "*.p";
    #if JUCE_IOS
        patternFilter = "";
    #endif
        FileChooser fileChooser ("Please select a DDRM bank file to load...",
                                 processor->getDirectoryForFileSaveLoad(),
                                 patternFilter);
        if (fileChooser.browseForFileToOpen())
        {
            File bankFile (fileChooser.getResult());
            processor->setLastUserDirectoryForFileSaveLoad(bankFile);
            processor->loadBankFile(&bankFile);
            processor->computeTimbreSpace();
        }
    }
    
    void enableBankTransportButtons() {
        previousPresetButton.setEnabled(true);
        nextPresetButton.setEnabled(true);
        presetNameLabel.setEnabled(true);
        saveBankFileButton.setEnabled(true);
        saveToCurrentBankLocationButton.setEnabled(true);
    }
    
    void buttonClicked (Button* button) override
    {
        if (button == &nextPresetButton)
        {
            int64 currentTime = Time::getCurrentTime().toMilliseconds();
            if ((currentTime - lastTimeNextButtonPressed) > MIN_TIME_BETWEEN_NEXT_PREV_RAND_PATCH_BUTTON_PRESSED){
                processor->nextPreset();
                lastTimeNextButtonPressed = currentTime;
            }
        }
        else if (button == &previousPresetButton)
        {
            int64 currentTime = Time::getCurrentTime().toMilliseconds();
            if ((currentTime - lastTimePreviousButtonPressed) > MIN_TIME_BETWEEN_NEXT_PREV_RAND_PATCH_BUTTON_PRESSED){
                processor->previousPreset();
                lastTimePreviousButtonPressed = currentTime;
            }
        }
        else if (button == &loadFileButton)
        {
            loadBankFile();
        } else if (button == &saveToCurrentBankLocationButton)
        {
            AlertWindow w ("Please choose the location where to save the patch", "", AlertWindow::NoIcon);
            w.addTextBlock ("NOTE: this will save the patch in the selected location of the bank loaded in J.F. Sebastian, but won't save the preset in DDRM itself nor send any information to it.");
            w.addTextEditor ("bankLocation", "", "");
            w.getTextEditor ("bankLocation")->setInputRestrictions(3, "0123456789");  // Make it numbers only
            w.addButton ("Cancel", 0, KeyPress (KeyPress::escapeKey, 0, 0));
            w.addButton ("Save", 1, KeyPress (KeyPress::returnKey, 0, 0));
            
            if (w.runModalLoop() == 1) // use clicked "ok"
            {
                // this is the text they entered..
                int location = w.getTextEditorContents ("bankLocation").getIntValue() - 1;
                processor->savePresetToBankLocation(location);
            }
            
        } else if (button == &saveBankFileButton)
        {
            processor->saveBankFile();
        }
    }
    
    void setPresetFromName ()
    {
        // Subtract 1 as loadPresetAtIndex is 0-indexed but user inputs 1-indexed
        int presetIdx = presetNameLabel.getText().getIntValue() - 1;
        if (presetIdx > -1){
            // Valid number entered
            processor->loadPresetAtIndex(presetIdx);
        } else {
            // Re-set it to the preset already had
            processor->loadPresetAtIndex(processor->currentPreset);
        }
    }
    
    void setPresetNameLabel () {
        if (processor->currentPreset > -1){
            // Add 1 as label should show preset numbers 1-indexed but currentPreset stores them 0-indexed
            presetNameLabel.setText(String(PRESET_NAME_PREFIX) + (String)(processor->currentPreset + 1), dontSendNotification);
        } else {
            presetNameLabel.setText(String(PRESET_NAME_DEFAULT_TEXT), dontSendNotification);
        }
    }
    
    void actionListenerCallback (const String &message) override
    {
        if (message.startsWith(String(ACTION_SET_CURRENT_PRESET_NAME))){
            setPresetNameLabel ();
            
        } else if (message.startsWith(String(ACTION_SET_CURRENT_PRESET_NAME_OUT_OF_SYNC))){
            if (!currentPresetSlidersOutOfSync) {
                currentPresetSlidersOutOfSync = true;
                if ((presetNameLabel.getText() != String(PRESET_NAME_DEFAULT_TEXT)) && (!presetNameLabel.getText().endsWith(String(PRESET_NAME_MODIFIED_TEXT)))){
                    presetNameLabel.setText(presetNameLabel.getText() + String(PRESET_NAME_MODIFIED_TEXT), dontSendNotification);
                    //saveToCurrentBankLocationButton.setEnabled(true);  // Enable save preset button as it is out of sync
                }
            }
        } else if (message.startsWith(String(ACTION_SET_CURRENT_PRESET_NAME_IN_SYNC))){
            setPresetNameLabel ();
            if (currentPresetSlidersOutOfSync) {
                currentPresetSlidersOutOfSync = false;
                //saveToCurrentBankLocationButton.setEnabled(false);  // Disable save preset button as it is out of sync
                if ((presetNameLabel.getText() != String(PRESET_NAME_DEFAULT_TEXT)) && (presetNameLabel.getText().endsWith(String(PRESET_NAME_MODIFIED_TEXT)))){
                    String presetNameLabelText = presetNameLabel.getText();
                    presetNameLabel.setText(presetNameLabelText.substring(presetNameLabelText.length() - 1), dontSendNotification);   
                }
            }
        }
        else if (message.startsWith(String(ACTION_BANK_FILE_LOADED))){
            loadedFileLabel.setText(processor->ddrmInterface->getPresetBankLoadedFilename() , dontSendNotification);
            presetNameLabel.setText(String(PRESET_NAME_DEFAULT_TEXT), dontSendNotification);
            enableBankTransportButtons();
        } else if (message.startsWith(String(ACTION_CURRENT_PRESENT_SAVED_TO_BANK))){
            //saveToCurrentBankLocationButton.setEnabled(false);
        }
    }
    
private:
    DdrmtimbreSpaceAudioProcessor* processor;
    
    CustomLookAndFeel customLookAndFeel;
    CustomLookAndFeel customLookAndFeelSmallerFont;  // Needed for the next/previous preset buttons to show properly on smaller scales
    
    TextButton loadFileButton;
    Label loadedFileLabel;
    TextButton nextPresetButton;
    int64 lastTimeNextButtonPressed = 0;
    TextButton previousPresetButton;
    int64 lastTimePreviousButtonPressed = 0;
    NumericEditorLabel presetNameLabel;
    TextButton saveToCurrentBankLocationButton;
    TextButton saveBankFileButton;
    
    bool currentPresetSlidersOutOfSync;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetControlComponent);
};
