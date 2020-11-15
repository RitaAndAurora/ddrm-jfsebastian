/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
DdrmtimbreSpaceAudioProcessorEditor::DdrmtimbreSpaceAudioProcessorEditor (DdrmtimbreSpaceAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    customLookAndFeel.scaleFactor = processor.uiScaleFactor;
    LookAndFeel::setDefaultLookAndFeel(&customLookAndFeel);
    
    uiWrapper.initialize(&processor, this);
    
    addAndMakeVisible (uiViewport);
    uiViewport.setViewedComponent(static_cast<Component*>(&uiWrapper), false);
    setSize (10, 10); // this is re-set later
    
    // Get screen height
    Rectangle<int> r = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
    screenHeight = r.getHeight();
    
    // Disable resize
    setResizable(false, false);
    
    resized();
}

DdrmtimbreSpaceAudioProcessorEditor::~DdrmtimbreSpaceAudioProcessorEditor()
{
    uiViewport.setViewedComponent(nullptr);
}

void DdrmtimbreSpaceAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::black);
}

void DdrmtimbreSpaceAudioProcessorEditor::resized ()
{
    uiViewport.setScrollBarsShown(!processor.neverShowScrollbars, !processor.neverShowScrollbars, true, true);  // configure scroll bars
    
    uiViewport.setBounds(getBounds());

    int maxHeight = (int)(screenHeight * 0.95);  // take maximum of 90% of the height of the screen
    if (maxHeight == 0){
        maxHeight = 100; // This can happen when not everything is initialised (?), make sure we don't set a size of 0 or JUCE will complain
    }
    
    int width = uiWrapper.sizeWidth;
    if (!processor.neverShowScrollbars) {
        if (uiWrapper.sizeHeight > maxHeight){
            width += uiViewport.getScrollBarThickness();
        }
    }
    
    setSize (width, jmin(uiWrapper.sizeHeight, maxHeight)); // max plugin window UI size
}


//==============================================================================


UIWrapperComponent::UIWrapperComponent ()
{
    setSize (10, 10);  // Is re-set when running resize()
}

UIWrapperComponent::~UIWrapperComponent()
{
    processor->removeActionListener(this);
}


void UIWrapperComponent::initialize (DdrmtimbreSpaceAudioProcessor* p, DdrmtimbreSpaceAudioProcessorEditor* e)
{
    // Set processor object
    editor = e;
    processor = p;
    processor->addActionListener(this);  // Receive messages from processor
    
    // bg image
    bgImage = ImageCache::getFromMemory (BinaryData::UIBackground_png, BinaryData::UIBackground_pngSize);
    
    // Init header and footer components
    header.initialize(processor);
    addAndMakeVisible (header);
    footer.initialize(processor);
    addAndMakeVisible (footer);
    
    // Add logo component (does not need initialization)
    addAndMakeVisible (logo);
    
    // Init MIDI settings panel
    midiSettingsPanel.initialize(processor);
    addAndMakeVisible (midiSettingsPanel);
    
    // Init preset control component
    presetControlPanel.initialize(processor);
    addAndMakeVisible (presetControlPanel);
    
    // Add view button (after preset controls to be on top)
    viewButton.addListener (this);
    viewButton.setButtonText("View...");
    addAndMakeVisible (viewButton);
    
    // Init DDRM contorl panel component
    ddrmControlPanel.initialize(processor);
    addAndMakeVisible (ddrmControlPanel);
    ddrmControlPanelExtra.initialize(processor);
    addAndMakeVisible (ddrmControlPanelExtra);
    
    // Init timbre space component
    timbreSpace.initialize(processor);
    addAndMakeVisible (timbreSpace);
    
    // Init DDRM tone selector component
    ddrmToneSelector.initialize(processor);
    addAndMakeVisible (ddrmToneSelector);

    // Logging area
    if (LOG_IN_UI == 1){
        addAndMakeVisible (logArea);
        logArea.setMultiLine (true);
        logArea.setReturnKeyStartsNewLine (true);
        logArea.setReadOnly (true);
        logArea.setScrollbarsShown (true);
        logArea.setCaretVisible (false);
        logArea.setPopupMenuEnabled (true);
        logArea.setColour (TextEditor::backgroundColourId, Colour (0x32ffffff));
        logArea.setColour (TextEditor::outlineColourId, Colour (0x1c000000));
        logArea.setColour (TextEditor::shadowColourId, Colour (0x16000000));
    }
    
    wasInitialized = true;
    resized();
}



//==============================================================================
void UIWrapperComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.drawImage(bgImage, getLocalBounds().toFloat());
}

void UIWrapperComponent::resized()
{
    if (!wasInitialized){
        return;
    }
    
    float scale = processor->uiScaleFactor;
    
    float unitMargin = 10 * scale;
    float unitRowHeight = 20 * scale;
    float fullWidth = 800 * scale;
    float footerWidth = 170 * scale;
    
    float headerHeight = 1.5 * unitRowHeight;
    float midiSettingsHeight = 1 * unitRowHeight;
    float presetLoaderHeight = 1 * unitRowHeight;
    float timbreSpaceHeight = 18 * unitRowHeight;
    float ddrmToneSelectorHeight = 7 * unitRowHeight;
    float ddrmControlPanelheight = 14 * unitRowHeight;
    float ddrmControlPanelExtraHeight = 1 * unitRowHeight;
    float footerHeight = 1 * unitRowHeight;
    float logAreaHeight = 3 * unitRowHeight;
    
    bool _showTimbreSpace = true;
    bool _showToneSelector = true;
    bool _showLogArea = LOG_IN_UI == 1;
    
    float accumulatedHeight = 0;
    
    float raLogoHeight = (headerHeight + midiSettingsHeight + presetLoaderHeight + 1 * unitMargin) * 0.85;
    logo.setBounds(getWidth() - raLogoHeight * 2.2 - unitMargin * 1.5, unitMargin, raLogoHeight * 2.2, raLogoHeight);  // 2.2 = aspect ratio of logo image
    
    header.setBounds(unitMargin, accumulatedHeight + unitMargin, fullWidth, headerHeight);
    accumulatedHeight += unitMargin + headerHeight;
    
    midiSettingsPanel.setBounds(unitMargin, accumulatedHeight + unitMargin, fullWidth, midiSettingsHeight);
    accumulatedHeight += unitMargin + midiSettingsHeight;
    
    presetControlPanel.setBounds (unitMargin, accumulatedHeight + unitMargin, fullWidth, presetLoaderHeight);
    viewButton.setBounds(fullWidth - (unitRowHeight * 3 - unitMargin), accumulatedHeight + unitMargin, unitRowHeight * 3, unitRowHeight);
    accumulatedHeight += unitMargin + presetLoaderHeight;
    
    if (_showTimbreSpace){
        timbreSpace.setBounds (unitMargin, accumulatedHeight + unitMargin, fullWidth, timbreSpaceHeight);
        accumulatedHeight += unitMargin + timbreSpaceHeight;
    }
    
    if (_showToneSelector){
        ddrmToneSelector.setBounds (unitMargin, accumulatedHeight + unitMargin, fullWidth, ddrmToneSelectorHeight);
        accumulatedHeight += unitMargin + ddrmToneSelectorHeight;
    }
    
    ddrmControlPanel.setBounds (unitMargin,  accumulatedHeight, fullWidth, ddrmControlPanelheight); // No add unitMargin, already in ddrmControlPanel
    accumulatedHeight += ddrmControlPanelheight;
    
    ddrmControlPanelExtra.setBounds(unitMargin,  accumulatedHeight, fullWidth - footerWidth, ddrmControlPanelExtraHeight); // No add unitMargin, already in ddrmControlPanel
    // NOTE: don't accumulate height here as ddrm control panel extra is at same height as footer
    
    footer.setBounds(fullWidth - footerWidth + unitMargin, accumulatedHeight, footerWidth, footerHeight); // No add unitMargin, already in ddrmControlPanel
    accumulatedHeight += footerHeight;
    
    if (_showLogArea){
        logArea.setBounds (unitMargin, accumulatedHeight + unitMargin, fullWidth, logAreaHeight);
        accumulatedHeight += unitMargin + logAreaHeight;
    }
    
    setSize(fullWidth +  2 * unitMargin, accumulatedHeight + unitMargin);
    sizeWidth = fullWidth +  2 * unitMargin;  // used by the viewport
    sizeHeight = accumulatedHeight + unitMargin;  // used by the viewport
    
    editor->resized();
}

//==============================================================================
void UIWrapperComponent::actionListenerCallback (const String &message)
{
    if (message.startsWith(String(ACTION_LOG_PREFIX))){
        logMessageInUI(message.substring(String(ACTION_LOG_PREFIX).length()));
    } else if (message.startsWith(String(ACTION_UPDATE_UI_SCALE_FACTOR))){
        editor->customLookAndFeel.scaleFactor = processor->uiScaleFactor;
        resized();  // No need to update any local member here as scale factor is stored in processor
    }
}

void UIWrapperComponent::buttonClicked (Button* button)
{
    int selectedActionID = -1;
    
    if (button == &viewButton)
    {
        PopupMenu zoomSubMenu;
        zoomSubMenu.addItem (MENU_OPTION_ID_ZOOM_60, "60%");
        zoomSubMenu.addItem (MENU_OPTION_ID_ZOOM_70, "70%");
        zoomSubMenu.addItem (MENU_OPTION_ID_ZOOM_80, "80%");
        zoomSubMenu.addItem (MENU_OPTION_ID_ZOOM_90, "90%");
        zoomSubMenu.addItem (MENU_OPTION_ID_ZOOM_100, "100%");
        
        PopupMenu m;
        m.addSubMenu ("Zoom", zoomSubMenu);
        
        int neverShowScrollbarsTicked = processor->neverShowScrollbars;
        m.addItem (MENU_OPTION_TOGGLE_NEVER_SHOW_SCROLLBARS, "Hide scrollbars", true, neverShowScrollbarsTicked);
                    
        selectedActionID = m.showAt(button);
    }
    
    if (selectedActionID > 0){
        processMenuAction(selectedActionID);
    }
}

void UIWrapperComponent::processMenuAction(int actionID)
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
    } else if (actionID == MENU_OPTION_TOGGLE_NEVER_SHOW_SCROLLBARS){
        processor->neverShowScrollbars = !processor->neverShowScrollbars;
        resized();
    }
}

void UIWrapperComponent::logMessageInUI (const String& message)
{
    logArea.moveCaretToEnd();
    logArea.insertTextAtCaret(message);
}
