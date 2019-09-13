/*
 ==============================================================================
 
 DDRMToneSelectorComponent.h
 Created: 20 May 2019 6:32:35pm
 Author:  Frederic Font Corbera
 
 ==============================================================================
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "DDRMInterface.h"
#include "CustomLookAndFeel.h"
#include "defines.h"


class DDRMToneSelectorButtonComponent: public ToggleButton
{
public:
    DDRMToneSelectorButtonComponent()
    {
        name = "button1";
        displayName = "Button\n1";
        buttonColor = Colours::yellow;
        textColor = Colours::black;
        appliesToChannel = 1;
    }
    
    ~DDRMToneSelectorButtonComponent ()
    {
    }
    
    const String getName()
    {
        return name;
    }
    
    int getAppliesToChannel()
    {
        return appliesToChannel;
    }
    
    void configButton(const String& _name, const String& _displayName, const Colour& _buttonColor, const Colour& _textColor, int _appliesToChannel)
    {
        name = _name;
        displayName = _displayName;
        buttonColor = _buttonColor;
        textColor = _textColor;
        appliesToChannel = _appliesToChannel;
    }
    
    void paintButton (Graphics& g, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override
    {
        float darkenWhenOff = 0.5f;
        float brighenWhenDown = 0.0f;
        float darkerWhenDisabled = 0.9f;
        float roundedCornerSize = 4.0f;
        float fontSize = getHeight() * 0.22;
        
        Colour color = buttonColor;
        if (!getToggleState()) {
            color = buttonColor.darker(darkenWhenOff); // When it is OFF
        }
        if (shouldDrawButtonAsDown) {
            color = buttonColor.brighter(brighenWhenDown);  // While it is being pressed
        }
        if (!isEnabled()){
            color = buttonColor.darker(darkerWhenDisabled); // When it is diabled
        }
        g.setColour (color);
        g.fillRoundedRectangle (0, 0, getWidth(), getHeight(), roundedCornerSize);
        g.setColour (textColor);  // Set text colour
        g.setFont(((CustomLookAndFeel&)getLookAndFeel()).cs80Font);  // Sent font face
        g.setFont(fontSize);  // Set font size
        g.drawFittedText(displayName, 0, 0, getWidth(), getHeight(), Justification::centred, 3);
    }
    
private:
    Colour buttonColor;
    Colour textColor;
    String name;
    String displayName;
    int appliesToChannel;
};


class DDRMToneSelectorComponent: public Component,
                                 public ActionListener,
                                 public Button::Listener

{
public:
    DDRMToneSelectorComponent ()
    {
        // Configure all buttons
        bassButton.configButton("bass", "BASS", Colour(CS80COLOR_YELLOW), Colours::black, 2);
        bassButton.addListener (this);
        addAndMakeVisible(bassButton);
        
        brass1Button.configButton("brass1", "BRASS\n1", Colour(CS80COLOR_RED), Colours::white, 1);
        brass1Button.addListener (this);
        addAndMakeVisible(brass1Button);
        
        brass2Button.configButton("brass2", "BRASS\n2", Colour(CS80COLOR_RED), Colours::white, 2);
        brass2Button.addListener (this);
        addAndMakeVisible(brass2Button);
        
        brass3Button.configButton("brass3", "BRASS\n3", Colour(CS80COLOR_RED), Colours::white, 2);
        brass3Button.addListener (this);
        addAndMakeVisible(brass3Button);
        
        clav1Button.configButton("clav1", "CLAVI-\nCHORD\n1", Colour(CS80COLOR_YELLOW), Colours::black, 1);
        clav1Button.addListener (this);
        addAndMakeVisible(clav1Button);
        
        clav2Button.configButton("clav2", "CLAVI-\nCHORD\n2", Colour(CS80COLOR_YELLOW), Colours::black, 2);
        clav2Button.addListener (this);
        addAndMakeVisible(clav2Button);
        
        epianoButton.configButton("epiano", "ELECTRIC\nPIANO", Colour(CS80COLOR_YELLOW), Colours::black, 1);
        epianoButton.addListener (this);
        addAndMakeVisible(epianoButton);
        
        fluteButton.configButton("flute", "FLUTE", Colour(CS80COLOR_WHITE), Colours::black, 1);
        fluteButton.addListener (this);
        addAndMakeVisible(fluteButton);
        
        funky1Button.configButton("funky1", "FUNKY\n1", Colour(CS80COLOR_GREEN), Colours::white, 1);
        funky1Button.addListener (this);
        addAndMakeVisible(funky1Button);
        
        funky2Button.configButton("funky2", "FUNKY\n2", Colour(CS80COLOR_GREEN), Colours::white, 2);
        funky2Button.addListener (this);
        addAndMakeVisible(funky2Button);
        
        funky3Button.configButton("funky3", "FUNKY\n3", Colour(CS80COLOR_GREEN), Colours::white, 1);
        funky3Button.addListener (this);
        addAndMakeVisible(funky3Button);
        
        funky4Button.configButton("funky4", "FUNKY\n4", Colour(CS80COLOR_GREEN), Colours::white, 2);
        funky4Button.addListener (this);
        funky4Button.setEnabled(false);
        addAndMakeVisible(funky4Button);
        
        guitar1Button.configButton("guitar1", "GUITAR\n1", Colour(CS80COLOR_YELLOW), Colours::black, 1);
        guitar1Button.addListener (this);
        addAndMakeVisible(guitar1Button);
        
        guitar2Button.configButton("guitar2", "GUITAR\n2", Colour(CS80COLOR_YELLOW), Colours::black, 2);
        guitar2Button.addListener (this);
        addAndMakeVisible(guitar2Button);
        
        harpsi1Button.configButton("harpsi1", "HARPSI-\nCHORD\n1", Colour(CS80COLOR_YELLOW), Colours::black, 1);
        harpsi1Button.addListener (this);
        addAndMakeVisible(harpsi1Button);
        
        harpsi2Button.configButton("harpsi2", "HARPSI-\nCHORD\n2", Colour(CS80COLOR_YELLOW), Colours::black, 2);
        harpsi2Button.addListener (this);
        addAndMakeVisible(harpsi2Button);
        
        organ1Button.configButton("organ1", "ORGAN\n1", Colour(CS80COLOR_WHITE), Colours::black, 1);
        organ1Button.addListener (this);
        addAndMakeVisible(organ1Button);
        
        organ2Button.configButton("organ2", "ORGAN\n2", Colour(CS80COLOR_WHITE), Colours::black, 2);
        organ2Button.addListener (this);
        addAndMakeVisible(organ2Button);
        
        string1Button.configButton("string1", "STRING\n1", Colour(CS80COLOR_YELLOW), Colours::black, 1);
        string1Button.addListener (this);
        addAndMakeVisible(string1Button);
        
        string2Button.configButton("string2", "STRING\n2", Colour(CS80COLOR_YELLOW), Colours::black, 2);
        string2Button.addListener (this);
        addAndMakeVisible(string2Button);
        
        string3Button.configButton("string3", "STRING\n3", Colour(CS80COLOR_YELLOW), Colours::black, 1);
        string3Button.addListener (this);
        addAndMakeVisible(string3Button);
        
        string4Button.configButton("string4", "STRING\n4", Colour(CS80COLOR_YELLOW), Colours::black, 2);
        string4Button.addListener (this);
        addAndMakeVisible(string4Button);
        
        // Fill in button row vectors
        buttonsRow1.push_back(&string1Button);
        buttonsRow1.push_back(&string3Button);
        buttonsRow1.push_back(&brass1Button);
        buttonsRow1.push_back(&fluteButton);
        buttonsRow1.push_back(&epianoButton);
        buttonsRow1.push_back(&clav1Button);
        buttonsRow1.push_back(&harpsi1Button);
        buttonsRow1.push_back(&organ1Button);
        buttonsRow1.push_back(&guitar1Button);
        buttonsRow1.push_back(&funky1Button);
        buttonsRow1.push_back(&funky3Button);
        
        buttonsRow2.push_back(&string2Button);
        buttonsRow2.push_back(&string4Button);
        buttonsRow2.push_back(&brass2Button);
        buttonsRow2.push_back(&brass3Button);
        buttonsRow2.push_back(&bassButton);
        buttonsRow2.push_back(&clav2Button);
        buttonsRow2.push_back(&harpsi2Button);
        buttonsRow2.push_back(&organ2Button);
        buttonsRow2.push_back(&guitar2Button);
        buttonsRow2.push_back(&funky2Button);
        buttonsRow2.push_back(&funky4Button);
    }
    
    ~DDRMToneSelectorComponent ()
    {
        processor->ddrmInterface->removeActionListener(this);  // Stop receivng messages from DDRMInterface
    }
    
    void initialize (DdrmtimbreSpaceAudioProcessor* p)
    {
        // Set processor object
        processor = p;
        
        allRow1ButtonsAreOff = true;
        allRow2ButtonsAreOff = true;
        
        // Set up listeners
        processor->ddrmInterface->addActionListener(this);  // Receive messages from DDRMInterface
        
        // Set initial state from processor (if any)
        setStateFromProcessor();
    }
    
    void setStateFromProcessor () {
        // Set buttons toggle state from processor
        for (int channel=1; channel <=2; channel++){
            String toneName = processor->ddrmInterface->getSelectedToneSelector(channel);
            if (toneName != String(EMPTY_TONE_SELECTOR_NAME)){
                DDRMToneSelectorButtonComponent* button = getButtonWithName(toneName, channel);
                button->setToggleState(true, NotificationType::dontSendNotification);
            }
        }
    }
    
    void setRow1ButtonsToOff ()
    {
        // Shows row1 buttons as OFF. This is used when a parameter is changed outside the tone selector
        // to reflect that current state of sliders is no longer the one of the preset
        for (int i=0; i<buttonsRow1.size(); i++){
            buttonsRow1[i]->setToggleState(false, NotificationType::dontSendNotification);
        }
        allRow1ButtonsAreOff = true;
    }
    
    void setRow2ButtonsToOff ()
    {
        // Shows row2 buttons as OFF. This is used when a parameter is changed outside the tone selector
        // to reflect that current state of sliders is no longer the one of the preset
        for (int i=0; i<buttonsRow2.size(); i++){
            buttonsRow2[i]->setToggleState(false, NotificationType::dontSendNotification);
        }
        allRow2ButtonsAreOff = true;
    }
    
    void setAllButtonsToOff ()
    {
        setRow1ButtonsToOff();
        setRow2ButtonsToOff();
    }
    
    void paint (Graphics& g) override
    {
    }
    
    void resized() override
    {
        float buttonSize = getHeight() * 1.0f / 2.5f;
        float buttonMargin = 1.0f;  // Applies to both sides and top/down
        float buttonSizeWithMargins = buttonSize + 2 * buttonMargin;
        float marginTopFisrtRow = (getHeight() - 2 * buttonSizeWithMargins) / 2.0f;
        float marginTopSecondRow = marginTopFisrtRow + buttonSizeWithMargins;
        float marginLeft = (getWidth() - buttonSizeWithMargins * 11.0f) / 2.0f;  // Assumes width will be enough
        
        // Top row
        for (int i=0; i<buttonsRow1.size(); i++){
            buttonsRow1[i]->setBounds(marginLeft  + i * buttonSizeWithMargins, marginTopFisrtRow, buttonSize, buttonSize);
        }
        
        // Bottom row
        for (int i=0; i<buttonsRow2.size(); i++){
            buttonsRow2[i]->setBounds(marginLeft  + i * buttonSizeWithMargins, marginTopSecondRow, buttonSize, buttonSize);
        }
    }
    
    void buttonClicked (Button* button) override
    {
        DDRMToneSelectorButtonComponent* ddrmButton = static_cast<DDRMToneSelectorButtonComponent*>(button);
        if (ddrmButton->getName() != "funky4"){  // Ignore funky4 as we don't have a preset for it
            
            // If button has been enabled
            if (ddrmButton->getToggleState()){
                // Tell processor to load corresponding slider values
                processor->loadToneSelectorPreset(ddrmButton->getName(), ddrmButton->getAppliesToChannel());
                // Tell DDRMInterface to store which tone has been selected
                processor->ddrmInterface->setSelectedToneSelector(ddrmButton->getName(), ddrmButton->getAppliesToChannel());
            } else {
                // If button has just been disabled, also notify DDRMInterface
                processor->ddrmInterface->setSelectedToneSelectorToNone(ddrmButton->getAppliesToChannel());
            }
            
            // Set allRow1ButtonsAreOff (used for optimization)
            if (ddrmButton->getAppliesToChannel() == 1 && ddrmButton->getToggleState()){
                allRow1ButtonsAreOff = false;
            } else if (ddrmButton->getAppliesToChannel() == 2 && ddrmButton->getToggleState()){
                allRow2ButtonsAreOff = false;
            }
            
            // Set all other buttons in the same row to OFF
            if (ddrmButton->getAppliesToChannel() == 1){
                for (int i=0; i<buttonsRow1.size(); i++){
                    if (buttonsRow1[i]->getName() != ddrmButton->getName()){
                        buttonsRow1[i]->setToggleState(false, NotificationType::dontSendNotification);
                    }
                }
            } else if (ddrmButton->getAppliesToChannel() == 2){
                for (int i=0; i<buttonsRow2.size(); i++){
                    if (buttonsRow2[i]->getName() != ddrmButton->getName()){
                        buttonsRow2[i]->setToggleState(false,  NotificationType::dontSendNotification);
                    }
                }
            }
        }
    }
    
    DDRMToneSelectorButtonComponent* getButtonWithName(const String& name, int row)
    {
        if (row == 1){
            for (int i=0; i<buttonsRow1.size(); i++){
                if (buttonsRow1[i]->getName() == name){
                    return buttonsRow1[i];
                }
            }
        } else if (row == 2) {
            for (int i=0; i<buttonsRow2.size(); i++){
                if (buttonsRow2[i]->getName() == name){
                    return buttonsRow2[i];
                }
            }
        }
        throw std::invalid_argument("Invalid name/row argument");
    }
    
    void actionListenerCallback (const String &message) override
    {
        if (message.startsWith(String(ACTION_SET_TONE_SELECTOR_BUTTONS_ROW1_OFF))){
            if (!allRow1ButtonsAreOff){
                setRow1ButtonsToOff();
            }
        }
        else if (message.startsWith(String(ACTION_SET_TONE_SELECTOR_BUTTONS_ROW2_OFF))){
            if (!allRow2ButtonsAreOff){
                setRow2ButtonsToOff();
            }
        }
        else if (message.startsWith(String(ACTION_SET_TONE_SELECTOR_BUTTONS_ROW1))){
            setRow1ButtonsToOff();
            String toneName = processor->ddrmInterface->getSelectedToneSelector(1);
            if (toneName != String(EMPTY_TONE_SELECTOR_NAME)){
                DDRMToneSelectorButtonComponent* button = getButtonWithName(toneName, 1);
                button->setToggleState(true, NotificationType::dontSendNotification);
            }
        }
        else if (message.startsWith(String(ACTION_SET_TONE_SELECTOR_BUTTONS_ROW2))){
            setRow2ButtonsToOff();
            String toneName = processor->ddrmInterface->getSelectedToneSelector(2);
            if (toneName != String(EMPTY_TONE_SELECTOR_NAME)){
                DDRMToneSelectorButtonComponent* button = getButtonWithName(toneName, 2);
                button->setToggleState(true, NotificationType::dontSendNotification);
            }
        }
    }
    
private:
    DdrmtimbreSpaceAudioProcessor* processor;
    
    DDRMToneSelectorButtonComponent string1Button;
    DDRMToneSelectorButtonComponent string2Button;
    DDRMToneSelectorButtonComponent string3Button;
    DDRMToneSelectorButtonComponent string4Button;
    DDRMToneSelectorButtonComponent brass1Button;
    DDRMToneSelectorButtonComponent brass2Button;
    DDRMToneSelectorButtonComponent brass3Button;
    DDRMToneSelectorButtonComponent fluteButton;
    DDRMToneSelectorButtonComponent epianoButton;
    DDRMToneSelectorButtonComponent bassButton;
    DDRMToneSelectorButtonComponent clav1Button;
    DDRMToneSelectorButtonComponent clav2Button;
    DDRMToneSelectorButtonComponent harpsi1Button;
    DDRMToneSelectorButtonComponent harpsi2Button;
    DDRMToneSelectorButtonComponent organ1Button;
    DDRMToneSelectorButtonComponent organ2Button;
    DDRMToneSelectorButtonComponent guitar1Button;
    DDRMToneSelectorButtonComponent guitar2Button;
    DDRMToneSelectorButtonComponent funky1Button;
    DDRMToneSelectorButtonComponent funky2Button;
    DDRMToneSelectorButtonComponent funky3Button;
    DDRMToneSelectorButtonComponent funky4Button;
    
    std::vector<DDRMToneSelectorButtonComponent*> buttonsRow1;
    std::vector<DDRMToneSelectorButtonComponent*> buttonsRow2;
    
    bool allRow1ButtonsAreOff;
    bool allRow2ButtonsAreOff;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DDRMToneSelectorComponent);
};
