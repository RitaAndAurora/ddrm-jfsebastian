/*
  ==============================================================================

    AboutComponent.h
    Created: 2 Jul 2019 5:44:21pm
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "defines.h"

class AboutComponent: public Component
{
public:
    
    AboutComponent ()
    {
        text.setMultiLine (true);
        text.setReturnKeyStartsNewLine (true);
        text.setReadOnly (true);
        text.setScrollbarsShown (true);
        text.setCaretVisible (false);
        text.setColour (TextEditor::backgroundColourId, Colour (0xff1C262A));
        text.setColour (TextEditor::outlineColourId, Colour (0x1c000000));
        text.setText(""
         "About\n-----\n\n"
         "J.F. Sebastian, named after a former genetic designer of the Tyrell Corporation, provides new ways to control and explore the sonic possibilities of the CS80-inspired Deckard's Dream synthesiser (DDRM). It works both as a stand-alone app and as an audio plug-in with automatable parameters.\n\n"
         "With J.F. Sebastian you can import DDRM bank files, edit patches and export them. When you import a bank file, a Timbre Space will be created which will allow you to navigate all the presets in a colorful space and create new ones. Just click anywhere on the Timbre Space and play the synth. Click on another point to get a new preset. Close points in the space will result in similar sounding presets.\n\n"
         "J.F. Sebastian also includes a CS80-like tone selector that allows you to use the original presetting system of the CS80 in the DDRM. Simply click on the buttons of the upper row and lower row to configure slider positions for channel I and II respectively.\n\n"
         "Communication between J.F. Sebastian and DDRM happens over MIDI. Make sure you have properly configured MIDI IN/OUT settings of both J.F. Sebastian and DDRM.\n\n"
         "Please check out " + String(MORE_INFO_URL) + " for more information about J.F. Sebastian and how to use it.\n\n"
         "\nCredits, licenses, acknowledgements\n-------------------------------\n\n"
         "J.F. Sebastian has been ideated and developed by Rita & Aurora, a sort of fancy branding name I've given to my audio-developer self.\n\n"
         "J.F. Sebastian uses the following open source software libraries: tapkee (BSD 3-clause), delaunator-cpp (MIT) and juce (GPLv3); and is released under GPLv3 software license.  Source code is available at https://example.com.\n\n"
         "Enormous thanks to Paul Shiling for creating the great CS80 presets bank that has been used for the tone selector.\n\n"
         "Also thanks to Black Corporation for making such a great synth!\n\n");
        
        addAndMakeVisible(text);
    }
    
    void resized () override
    {
        text.setBounds (0, 0, getWidth(), getHeight());
    }
    
private:
    TextEditor text;
            
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AboutComponent);
};
