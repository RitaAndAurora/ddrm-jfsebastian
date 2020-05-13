/*
  ==============================================================================

    MIDISettingsComponent.h
    Created: 13 Jun 2019 8:36:00am
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "defines.h"

class MIDISettingsComponent: public Component,
                             public ActionListener,
                             public Timer
{
public:
    
    MIDISettingsComponent ()
    {
        addAndMakeVisible (midiInputList);
        addAndMakeVisible (midiOutputList);
        addAndMakeVisible (midiInputChannelList);
        addAndMakeVisible (midiOutputChannelList);
    }
    
    ~MIDISettingsComponent ()
    {
        processor->removeActionListener(this);  // Stop receivng messages from processor
        if (isTimerRunning()){
            stopTimer();
        }
    }
    
    void initialize (DdrmtimbreSpaceAudioProcessor* p)
    {
        // Set processor object
        processor = p;
        
        // Set up listeners
        processor->addActionListener(this);  // Receive messages from processor
        
        // Build UI objects
        buildMidiChannelLists();
        refreshMidiInputOutputLists();
        
        // Start auto-scan timer
        if (processor->midiDevicesAutoScanEnabled){
            if (REFRESH_MIDI_DEVICES_TIMER_INTERVAL_MS > 0){
                startTimer(REFRESH_MIDI_DEVICES_TIMER_INTERVAL_MS); // Start timer to check for new MIDI devices
            }
        }
    }
    
    void resized () override
    {
        float deviceSelectorWidth = getWidth() * 150/800;
        float channelSelectorWidth = getWidth() * 60/800;
        if (processor->uiScaleFactor < 0.85){
             channelSelectorWidth = getWidth() * 80/800;  // For small ui scale, make selector wider in proportion
        }
        float unitMargin = getWidth() * 10/800;
        float inOutSeparator = getWidth() * 30/800;
        midiInputList.setBounds (0, 0, deviceSelectorWidth, getHeight());
        midiInputChannelList.setBounds (deviceSelectorWidth + unitMargin, 0, channelSelectorWidth, getHeight());
        midiOutputList.setBounds (deviceSelectorWidth + channelSelectorWidth + 2 * unitMargin + inOutSeparator, 0, deviceSelectorWidth, getHeight());
        midiOutputChannelList.setBounds (2 * deviceSelectorWidth + channelSelectorWidth + 3 * unitMargin + inOutSeparator, 0, channelSelectorWidth, getHeight());
    }
    
    void actionListenerCallback (const String &message) override
    {
        if (message.startsWith(String(ACTION_UPDATED_MIDI_DEVICE_SETTINGS)))
        {
            updateSelectedMidiDevices();
        }
        else if (message.startsWith(String(ACTION_REFRESH_MIDI_DEVICE_LISTS)))
        {
            refreshMidiInputOutputLists();
        }
        else if (message.startsWith(String(ACTION_MIDI_ENABLE_AUTO_SCAN)))
        {
            if (REFRESH_MIDI_DEVICES_TIMER_INTERVAL_MS > 0){
                startTimer(REFRESH_MIDI_DEVICES_TIMER_INTERVAL_MS);
            }
        }
        else if (message.startsWith(String(ACTION_MIDI_DISABLE_AUTO_SCAN)))
        {
            stopTimer();
        }
        else if (message.startsWith(String(ACTION_MIDI_TRIGGER_DEVICE_SCAN)))
        {
            refreshMidiInputOutputLists();
        }
    }
    
    void buildMidiChannelLists ()
    {
        midiInputChannelList.clear(dontSendNotification);
        midiOutputChannelList.clear(dontSendNotification);
        for (int i=1; i<=16; i++){
            midiInputChannelList.addItem((String)i, i);
            midiOutputChannelList.addItem((String)i, i);
        }
        midiInputChannelList.onChange = [this] {  processor->setMidiInputChannel(midiInputChannelList.getSelectedItemIndex() + 1); };
        midiOutputChannelList.onChange = [this] {  processor->setMidiOutputChannel(midiOutputChannelList.getSelectedItemIndex() + 1); };
    }
    
    void setMidiOutputDeviceHelper(int midiOutputListSelectedIndex)
    {
        if (midiOutputListSelectedIndex <= 0){
            processor->setMidiOutputDevice ("-");
        } else{
            String deviceID = currentMidiOutDevices[midiOutputList.getSelectedItemIndex() - 1].identifier;
            processor->setMidiOutputDevice (deviceID);
        }
    }
    
    void setMidiInputDeviceHelper(int midiInputListSelectedIndex)
    {
        if (midiInputListSelectedIndex <= 0){
            processor->setMidiInputDevice ("-");
        } else{
            String deviceID = currentMidiInDevices[midiInputList.getSelectedItemIndex() - 1].identifier;
            processor->setMidiInputDevice (deviceID);
        }
    }
    
    void refreshMidiInputOutputLists ()
    {
        // Update MIDI in list (if devices changed)
        Array<MidiDeviceInfo> midiInDevices = MidiInput::getAvailableDevices();
        bool midiInHasChanged = midiInDevices != currentMidiInDevices;
        if (midiInHasChanged){
            currentMidiInDevices = midiInDevices;
            midiInputList.clear(dontSendNotification);
            midiInputList.addItem ("No MIDI input", 1);
            midiInputList.addSeparator();
            
            StringArray midiInDevicesNames = {};
            for (int i=0; i<midiInDevices.size(); i++) {
                midiInDevicesNames.add(midiInDevices[i].name);
            }
            if (midiInDevices.size() > 0) {
                midiInputList.addItemList (midiInDevicesNames, 2);
                midiInputList.onChange = [this] {setMidiInputDeviceHelper(midiInputList.getSelectedItemIndex()); };
            }
        }
        
        // Update MIDI output list (if devices changed)
        Array<MidiDeviceInfo> midiOutDevices = MidiOutput::getAvailableDevices();
        bool midiOutHasChanged = midiOutDevices != currentMidiOutDevices;
        if (midiOutHasChanged){
            currentMidiOutDevices = midiOutDevices;
            midiOutputList.clear(dontSendNotification);
            midiOutputList.addItem ("No MIDI output", 1);
            midiOutputList.addSeparator();
            
            StringArray midiOutDevicesNames = {};
            for (int i=0; i<midiOutDevices.size(); i++) {
                midiOutDevicesNames.add(midiOutDevices[i].name);
            }
            if (midiOutDevices.size() > 0){
                midiOutputList.addItemList (midiOutDevicesNames, 2);
                midiOutputList.onChange = [this] {setMidiOutputDeviceHelper(midiOutputList.getSelectedItemIndex()); };
            }
        }
        
        if (midiInHasChanged || midiOutHasChanged){
            // Update the selected items in the lists (in case the list has changed and devics idxs do not match
            updateSelectedMidiDevices();
        }
    }
    
    void updateSelectedMidiDevices ()
    {
        if (processor->midiInput != nullptr){
            // Find and select the item in the combo box corresponding to the selected device (by name)
            int itemIdx = 0;
            for (int i=0; i<midiInputList.getNumItems(); i++){
                if (processor->midiInput->getName() == midiInputList.getItemText(i)){
                    itemIdx = i;
                }
            }
            if (midiInputList.getSelectedItemIndex() != itemIdx){
                midiInputList.setSelectedItemIndex(itemIdx, dontSendNotification);
            }
        } else {
            if (midiInputList.getSelectedItemIndex() != 0){
                midiInputList.setSelectedItemIndex(0, dontSendNotification); // Update to no device selected
            }
        }
        
        if (processor->midiOutput != nullptr){
            // Find and select the item in the combo box corresponding to the selected device (by name)
            int itemIdx = 0;
            for (int i=0; i<midiOutputList.getNumItems(); i++){
                if (processor->midiOutput->getName() == midiOutputList.getItemText(i)){
                    itemIdx = i;
                }
            }
            if (midiOutputList.getSelectedItemIndex() != itemIdx){
                midiOutputList.setSelectedItemIndex(itemIdx, dontSendNotification);
            }
        } else {
            if (midiOutputList.getSelectedItemIndex() != 0){
                midiOutputList.setSelectedItemIndex(0, dontSendNotification); // Update to no device selected
            }
        }
        
        if (processor->midiInputChannel > -1){
            if (midiInputChannelList.getSelectedId() != processor->midiInputChannel){
                midiInputChannelList.setSelectedId(processor->midiInputChannel, dontSendNotification);
            }
        }
        
        if (processor->midiOutputChannel > -1){
            if (midiOutputChannelList.getSelectedId() != processor->midiOutputChannel){
                midiOutputChannelList.setSelectedId(processor->midiOutputChannel, dontSendNotification);
            }
        }
    }
    
    void timerCallback() override
    {
        refreshMidiInputOutputLists();
    }
    
private:
    DdrmtimbreSpaceAudioProcessor* processor;
    ComboBox midiInputList;
    ComboBox midiOutputList;
    ComboBox midiInputChannelList;
    ComboBox midiOutputChannelList;
    Array<MidiDeviceInfo> currentMidiInDevices;
    Array<MidiDeviceInfo> currentMidiOutDevices;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MIDISettingsComponent);
};
