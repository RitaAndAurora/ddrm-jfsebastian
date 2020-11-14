/*
  ==============================================================================

    CustomLookAndFeel.h
    Created: 26 Jul 2019 9:00:21am
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#pragma once


class CustomLookAndFeel: public LookAndFeel_V4
{
public:
    CustomLookAndFeel()
    {
        // Init fonts
        cs80Font = Typeface::createSystemTypefaceFor(BinaryData::RobotoCondensed_ttf, BinaryData::RobotoCondensed_ttfSize);
        tsHudFont = Typeface::createSystemTypefaceFor(BinaryData::MODENINE_TTF, BinaryData::MODENINE_TTFSize);
        defaultFont = Typeface::createSystemTypefaceFor(Font(defaultFontSize));
        
        // Specify custom colors
        setColour (ResizableWindow::backgroundColourId, Colour (0xff1C262A));
        setColour (PopupMenu::backgroundColourId, Colour (0xff1C262A));
        setColour (PopupMenu::highlightedBackgroundColourId, Colour (0xff3b5058));
        setColour (ComboBox::backgroundColourId, Colour (0xff1C262A));
        setColour (TextButton::buttonColourId, Colour (0xff1C262A));
        setColour (BubbleComponent::backgroundColourId, Colour (0xff1C262A));
        setColour (AlertWindow::backgroundColourId, Colour (0xff1d303b));
        setColour (AlertWindow::outlineColourId, Colour (0xff3b5058));
    }
    
    ~CustomLookAndFeel()
    {
    }
    
    Font getTextButtonFont (TextButton&, int buttonHeight) override
    {
        Font font = Font(defaultFont);
        font.setHeight(defaultFontSize * scaleFactor);
        return font;
    }
    
    Font getLabelFont (Label&) override
    {
        Font font = Font(defaultFont);
        font.setHeight(defaultFontSize * scaleFactor);
        return font;
    }
    
    Font getSliderPopupFont (Slider&) override
    {
        Font font = Font(defaultFont);
        font.setHeight(defaultFontSize);
        return font;
    }
    
    Font getAlertWindowMessageFont () override
    {
        Font font = Font(defaultFont);
        font.setHeight(defaultFontSize);
        return font;
    }
    
    Font getAlertWindowTitleFont () override
    {
        Font font = Font(defaultFont);
        font.setHeight(defaultFontSize * 1.2);
        font.setBold(true);
        return font;
    }
    
    void drawComboBox (Graphics& g, int width, int height, bool,
                       int, int, int, int, ComboBox& box) override
    {
        auto cornerSize = box.findParentComponentOfClass<ChoicePropertyComponent>() != nullptr ? 0.0f : 3.0f;
        Rectangle<int> boxBounds (0, 0, width, height);

        g.setColour (box.findColour (ComboBox::backgroundColourId));
        g.fillRoundedRectangle (boxBounds.toFloat(), cornerSize);

        g.setColour (box.findColour (ComboBox::outlineColourId));
        g.drawRoundedRectangle (boxBounds.toFloat().reduced (0.5f, 0.5f), cornerSize, 1.0f);

        Rectangle<int> arrowZone (width - 15, 0, 10, height - 2);
        Path path;
        path.startNewSubPath (arrowZone.getX() + 3.0f, arrowZone.getCentreY() - 2.0f);
        path.lineTo (static_cast<float> (arrowZone.getCentreX()), arrowZone.getCentreY() + 3.0f);
        path.lineTo (arrowZone.getRight() - 3.0f, arrowZone.getCentreY() - 2.0f);

        g.setColour (box.findColour (ComboBox::arrowColourId).withAlpha ((box.isEnabled() ? 0.9f : 0.2f)));
        g.strokePath (path, PathStrokeType (2.0f));
    }
    
    void positionComboBoxText (ComboBox& box, Label& label) override
    {
        label.setBounds (1, 1,
                         box.getWidth() - 15,
                         box.getHeight() - 2);

        label.setFont (getComboBoxFont (box));
    }
    
    // Defaults
    float defaultFontSize = 14.0;
    
    // Make fonts public so it can be accessed from outside if needed
    Typeface::Ptr cs80Font;
    Typeface::Ptr tsHudFont;
    Typeface::Ptr defaultFont;
    
    // Scale factor (used to improve font rendering)
    float scaleFactor = 1.0;
};
