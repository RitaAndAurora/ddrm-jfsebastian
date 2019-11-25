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
        
        zoomButton.addListener (this);
        zoomButton.setButtonText("Zoom...");
        addAndMakeVisible (zoomButton);
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
        
        zoomButton.setBounds (getWidth() - 2.05 * buttonWidth, 0, buttonWidth, buttonHeight);
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
                           "a Dekcard's Dream companion tool made by Rita & Aurora, v" + String(VERSION),
                           AlertWindow::NoIcon);
            
            w.setLookAndFeel(&customLookAndFeel);
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
        else if (button == &zoomButton)
        {
            PopupMenu m;
            m.setLookAndFeel(&customLookAndFeel);
            m.addItem (MENU_OPTION_ID_ZOOM_70, "70%");
            m.addItem (MENU_OPTION_ID_ZOOM_80, "80%");
            m.addItem (MENU_OPTION_ID_ZOOM_90, "90%");
            m.addItem (MENU_OPTION_ID_ZOOM_100, "100%");
            selectedActionID = m.showAt(button);
        }
        
        if (selectedActionID > 0){
            processMenuAction(selectedActionID);
        }
    }
    
    void processMenuAction(int actionID)
    {
        if (actionID == MENU_OPTION_ID_ZOOM_60){
            processor->setUIScaleFactor(0.6);
        } else if (actionID == MENU_OPTION_ID_ZOOM_70){
            processor->setUIScaleFactor(0.7);
        } else if (actionID == MENU_OPTION_ID_ZOOM_80){
            processor->setUIScaleFactor(0.8);
        } else if (actionID == MENU_OPTION_ID_ZOOM_90){
            processor->setUIScaleFactor(0.9);
        } else if (actionID == MENU_OPTION_ID_ZOOM_100){
            processor->setUIScaleFactor(1.0);
        } else if (actionID == MENU_OPTION_ID_ZOOM_75){
            processor->setUIScaleFactor(0.75);
        }
    }
    
private:
    DdrmtimbreSpaceAudioProcessor* processor;
    
    CustomLookAndFeel customLookAndFeel;
    
    AboutComponent about;
    TextButton aboutButton;
    TextButton zoomButton;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FooterComponent);
};


