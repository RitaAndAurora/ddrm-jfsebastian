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
        font.setHeight(defaultFontSize);
        return font;
    }
    
    Font getLabelFont (Label&) override
    {
        Font font = Font(defaultFont);
        font.setHeight(defaultFontSize);
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
    
    // Defaults
    float defaultFontSize = 14.0;
    
    // Make fonts public so it can be accessed from outside if needed
    Typeface::Ptr cs80Font;
    Typeface::Ptr tsHudFont;
    Typeface::Ptr defaultFont;
};
