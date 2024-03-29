/*
  ==============================================================================

    FooterComponent.h
    Created: 2 Jul 2019 8:51:40am
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "CustomLookAndFeel.h"
#include "AboutComponent.h"
#include "defines.h"

class FooterComponent: public Component,
                       public ActionListener,
                       public Button::Listener
{
public:
    
    FooterComponent ()
    {
        aboutButton.addListener (this);
        aboutButton.setButtonText("About");
        addAndMakeVisible (aboutButton);
        
        settingsButton.addListener (this);
        settingsButton.setButtonText("Settings...");
        addAndMakeVisible (settingsButton);
    }
    
    ~FooterComponent ()
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
        float buttonWidth = getWidth() * 80/170;
        float buttonHeight = getHeight();
        aboutButton.setBounds (getWidth() - buttonWidth, 0, buttonWidth, buttonHeight);
        about.setBounds (0, 0, 400, 300);
        
        settingsButton.setBounds (getWidth() - 2.05 * buttonWidth, 0, buttonWidth, buttonHeight);
    }
    
    void actionListenerCallback (const String &message) override
    {
        // TODO: implement action listenr handlers
    }
    
    void buttonClicked (Button* button) override
    {
        int selectedActionID = -1;
        
        if (button == &aboutButton)
        {
            AlertWindow w ("J.F. Sebastian",
                           "a Dekcard's Dream companion tool made by Rita & Aurora, v" + String(JucePlugin_VersionString),
                           AlertWindow::NoIcon);
            w.addCustomComponent(&about);
            w.addButton ("Ok", 0, KeyPress (KeyPress::returnKey, 0, 0));
            w.addButton ("More info", 1, KeyPress (KeyPress::returnKey, 0, 0));
            w.addButton ("Donate :)", 2, KeyPress (KeyPress::returnKey, 0, 0));
            int modalReturn = w.runModalLoop();
            if (modalReturn == 1) // use clicked "more info"
            {
                URL(MORE_INFO_URL).launchInDefaultBrowser();
            }
            else if (modalReturn == 2) // use clicked "donate"
            {
                URL(DONATE_URL).launchInDefaultBrowser();
            }
        }
        else if (button == &settingsButton)
        {
            PopupMenu m;
            
            PopupMenu randomAmountOptionsSubmenu;
            randomAmountOptionsSubmenu.addItem (MENU_OPTION_ID_RANDOMIZE_PATCH_5_ID, "5%", true, processor->randomizationSettings.amount == 5);
            randomAmountOptionsSubmenu.addItem (MENU_OPTION_ID_RANDOMIZE_PATCH_10_ID, "10%", true, processor->randomizationSettings.amount == 10);
            randomAmountOptionsSubmenu.addItem (MENU_OPTION_ID_RANDOMIZE_PATCH_25_ID, "25%", true, processor->randomizationSettings.amount == 25);
            randomAmountOptionsSubmenu.addItem (MENU_OPTION_ID_RANDOMIZE_PATCH_50_ID, "50%", true, processor->randomizationSettings.amount == 50);
            randomAmountOptionsSubmenu.addItem (MENU_OPTION_ID_RANDOMIZE_PATCH_100_ID, "100%", true, processor->randomizationSettings.amount == 100);
            
            PopupMenu randomPanelOptionsSubmenu;
            randomPanelOptionsSubmenu.addItem (MENU_OPTION_ID_RANDOMIZE_CH1, "Channel I", true, processor->randomizationSettings.channel1Controls == true);
            randomPanelOptionsSubmenu.addItem (MENU_OPTION_ID_RANDOMIZE_CH2, "Channel II", true, processor->randomizationSettings.channel2Controls == true);
            randomPanelOptionsSubmenu.addItem (MENU_OPTION_ID_RANDOMIZE_PERF, "Performance controls", true, processor->randomizationSettings.performanceControls == true);
            
            PopupMenu randomOptionsSubmenu;
            randomOptionsSubmenu.addSubMenu ("Affected controls", randomPanelOptionsSubmenu);
            randomOptionsSubmenu.addSubMenu ("Amount", randomAmountOptionsSubmenu);
            m.addSubMenu ("Randomizer", randomOptionsSubmenu);
            
            PopupMenu timbreSpaceInterpolationControlsSubMenu;
            timbreSpaceInterpolationControlsSubMenu.addItem (MENU_OPTION_ID_TIMBRE_SPACE_CH1, "Channel I", true, processor->timbreSpaceSettings.channel1Controls == true);
            timbreSpaceInterpolationControlsSubMenu.addItem (MENU_OPTION_ID_TIMBRE_SPACE_CH2, "Channel II", true, processor->timbreSpaceSettings.channel2Controls == true);
            timbreSpaceInterpolationControlsSubMenu.addItem (MENU_OPTION_ID_TIMBRE_SPACE_PERF, "Performance controls", true, processor->timbreSpaceSettings.performanceControls == true);
            PopupMenu timbreSpaceSubMenu;
            timbreSpaceSubMenu.addSubMenu ("Affected controls", timbreSpaceInterpolationControlsSubMenu);
            m.addSubMenu ("Timbre Space", timbreSpaceSubMenu);
            
            PopupMenu midiDevicesSubMenu;
            bool autoScanTicked = processor->midiDevicesAutoScanEnabled;
            int autoScanMenuOptionID = processor->midiDevicesAutoScanEnabled ? MENU_OPTION_MIDI_SET_AUTOSCAN_OFF : MENU_OPTION_MIDI_SET_AUTOSCAN_ON;
            bool scanNowEnabled = !processor->midiDevicesAutoScanEnabled;
            midiDevicesSubMenu.addItem (autoScanMenuOptionID, "Auto-scan MIDI devices", true, autoScanTicked);
            midiDevicesSubMenu.addItem (MENU_OPTION_MIDI_SCAN_NOW, "Scan devices now", scanNowEnabled, false);
            m.addSubMenu ("MIDI device scan", midiDevicesSubMenu);
            
            selectedActionID = m.showAt(button);
            
        }
        
        if (selectedActionID > 0){
            processMenuAction(selectedActionID);
        }
    }
    
    void processMenuAction(int actionID)
    {
        if (actionID == MENU_OPTION_MIDI_SET_AUTOSCAN_OFF){
            processor->setMidiDevicesAutoScan(false);
        } else if (actionID == MENU_OPTION_MIDI_SET_AUTOSCAN_ON){
            processor->setMidiDevicesAutoScan(true);
        } else if (actionID == MENU_OPTION_MIDI_SCAN_NOW){
            processor->triggerMidiDevicesScan();
        } else if (actionID == MENU_OPTION_ID_RANDOMIZE_PATCH_5_ID){
            processor->randomizationSettings.amount = 5;
        } else if (actionID == MENU_OPTION_ID_RANDOMIZE_PATCH_10_ID){
            processor->randomizationSettings.amount = 10;
        } else if (actionID == MENU_OPTION_ID_RANDOMIZE_PATCH_25_ID){
            processor->randomizationSettings.amount = 25;
        } else if (actionID == MENU_OPTION_ID_RANDOMIZE_PATCH_50_ID){
            processor->randomizationSettings.amount = 50;
        } else if (actionID == MENU_OPTION_ID_RANDOMIZE_PATCH_100_ID){
            processor->randomizationSettings.amount = 100;
        } else if (actionID == MENU_OPTION_ID_RANDOMIZE_CH1){
            processor->randomizationSettings.channel1Controls = !processor->randomizationSettings.channel1Controls;
        } else if (actionID == MENU_OPTION_ID_RANDOMIZE_CH2){
            processor->randomizationSettings.channel2Controls = !processor->randomizationSettings.channel2Controls;
        } else if (actionID == MENU_OPTION_ID_RANDOMIZE_PERF){
            processor->randomizationSettings.performanceControls = !processor->randomizationSettings.performanceControls;
        } else if (actionID == MENU_OPTION_ID_TIMBRE_SPACE_CH1){
            processor->timbreSpaceSettings.channel1Controls = !processor->timbreSpaceSettings.channel1Controls;
        } else if (actionID == MENU_OPTION_ID_TIMBRE_SPACE_CH2){
            processor->timbreSpaceSettings.channel2Controls = !processor->timbreSpaceSettings.channel2Controls;
        } else if (actionID == MENU_OPTION_ID_TIMBRE_SPACE_PERF){
            processor->timbreSpaceSettings.performanceControls = !processor->timbreSpaceSettings.performanceControls;
        }
    }
    
private:
    DdrmtimbreSpaceAudioProcessor* processor;
    
    CustomLookAndFeel customLookAndFeel;
    
    AboutComponent about;
    TextButton aboutButton;
    TextButton settingsButton;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FooterComponent);
};


