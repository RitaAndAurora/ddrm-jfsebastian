//
//  DDRMControlPanelComponent.h
//  DDRMControlPanelComponent.h
//
//  Created by Frederic Font Corbera on 24/04/2019.
//  Copyright © 2019 Rita&AuroraAudio. All rights reserved.
//


#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "DDRMInterface.h"
#include "CustomLookAndFeel.h"
#include "defines.h"

class DDRMControlPanelComponent: public Component

{
public:
    DDRMControlPanelComponent ()
    {
    }
    
    ~DDRMControlPanelComponent ()
    {
    }
    
    void initialize (DdrmtimbreSpaceAudioProcessor* p)
    {
        // Set processor object
        processor = p;
        
        // Configure look and feel classes
        yellowSlider.setColour (Slider::thumbColourId, Colour(CS80COLOR_YELLOW));
        greenSlider.setColour (Slider::thumbColourId, Colour(CS80COLOR_GREEN));
        blackSlider.setColour (Slider::thumbColourId, Colour(CS80COLOR_BLACK));
        redSlider.setColour (Slider::thumbColourId, Colour(CS80COLOR_RED));
        whiteSlider.setColour (Slider::thumbColourId, Colour(CS80COLOR_WHITE));
        graySlider.setColour (Slider::thumbColourId, Colour(CS80COLOR_GREY));
        
        // Configure sliders
        // --> Start auto-generated code B
        // Slider DDRM_SPEED_VCO_1
        sliderDDRM_SPEED_VCO_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_SPEED_VCO_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_SPEED_VCO_1.setLookAndFeel (&whiteSlider);
        sliderDDRM_SPEED_VCO_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_SPEED_VCO_1);
        sliderAttachmentDDRM_SPEED_VCO_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_SPEED_VCO_1", sliderDDRM_SPEED_VCO_1));
        sliderDDRM_SPEED_VCO_1.textFromValueFunction = [](double value) {
            return String::formatted("PWM Speed: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_PWM_VCO_1
        sliderDDRM_PWM_VCO_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_PWM_VCO_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_PWM_VCO_1.setLookAndFeel (&greenSlider);
        sliderDDRM_PWM_VCO_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_PWM_VCO_1);
        sliderAttachmentDDRM_PWM_VCO_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_PWM_VCO_1", sliderDDRM_PWM_VCO_1));
        sliderDDRM_PWM_VCO_1.textFromValueFunction = [](double value) {
            return String::formatted("PWM Amount: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_PW_VCO_1
        sliderDDRM_PW_VCO_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_PW_VCO_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_PW_VCO_1.setLookAndFeel (&greenSlider);
        sliderDDRM_PW_VCO_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_PW_VCO_1);
        sliderAttachmentDDRM_PW_VCO_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_PW_VCO_1", sliderDDRM_PW_VCO_1));
        sliderDDRM_PW_VCO_1.textFromValueFunction = [](double value) {
            return String::formatted("PW: %.0f%%", 100.0 * ((0.4 * value / 127.0) + 0.5));
        };
        // Slider DDRM_SQR_VCO_1
        sliderDDRM_SQR_VCO_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_SQR_VCO_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_SQR_VCO_1.setLookAndFeel (&blackSlider);
        sliderDDRM_SQR_VCO_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_SQR_VCO_1);
        sliderAttachmentDDRM_SQR_VCO_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_SQR_VCO_1", sliderDDRM_SQR_VCO_1));
        sliderDDRM_SQR_VCO_1.setRange(sliderDDRM_SQR_VCO_1.getMinimum(), sliderDDRM_SQR_VCO_1.getMaximum(), sliderDDRM_SQR_VCO_1.getMaximum());
        sliderDDRM_SQR_VCO_1.textFromValueFunction = [](double value) {
            if (value <= 64){ return "Square: ON"; } else { return "Square OFF";}
        };
        // Slider DDRM_SAW_VCO_1
        sliderDDRM_SAW_VCO_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_SAW_VCO_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_SAW_VCO_1.setLookAndFeel (&blackSlider);
        sliderDDRM_SAW_VCO_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_SAW_VCO_1);
        sliderAttachmentDDRM_SAW_VCO_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_SAW_VCO_1", sliderDDRM_SAW_VCO_1));
        sliderDDRM_SAW_VCO_1.setRange(sliderDDRM_SAW_VCO_1.getMinimum(), sliderDDRM_SAW_VCO_1.getMaximum(), sliderDDRM_SAW_VCO_1.getMaximum());
        sliderDDRM_SAW_VCO_1.textFromValueFunction = [](double value) {
            if (value <= 64){ return "Sawtooth: ON"; } else { return "Sawtooth OFF";}
        };
        // Slider DDRM_NOISE_VCO_1
        sliderDDRM_NOISE_VCO_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_NOISE_VCO_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_NOISE_VCO_1.setLookAndFeel (&graySlider);
        sliderDDRM_NOISE_VCO_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_NOISE_VCO_1);
        sliderAttachmentDDRM_NOISE_VCO_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_NOISE_VCO_1", sliderDDRM_NOISE_VCO_1));
        sliderDDRM_NOISE_VCO_1.textFromValueFunction = [](double value) {
            return String::formatted("Noise: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_HPF_VCF_1
        sliderDDRM_HPF_VCF_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_HPF_VCF_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_HPF_VCF_1.setLookAndFeel (&greenSlider);
        sliderDDRM_HPF_VCF_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_HPF_VCF_1);
        sliderAttachmentDDRM_HPF_VCF_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_HPF_VCF_1", sliderDDRM_HPF_VCF_1));
        sliderDDRM_HPF_VCF_1.textFromValueFunction = [](double value) {
            return String::formatted("HPF: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_RESh_VCF_1
        sliderDDRM_RESh_VCF_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_RESh_VCF_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_RESh_VCF_1.setLookAndFeel (&redSlider);
        sliderDDRM_RESh_VCF_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_RESh_VCF_1);
        sliderAttachmentDDRM_RESh_VCF_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_RESh_VCF_1", sliderDDRM_RESh_VCF_1));
        sliderDDRM_RESh_VCF_1.textFromValueFunction = [](double value) {
            return String::formatted("RESh: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_LPF_VCF_1
        sliderDDRM_LPF_VCF_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_LPF_VCF_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_LPF_VCF_1.setLookAndFeel (&greenSlider);
        sliderDDRM_LPF_VCF_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_LPF_VCF_1);
        sliderAttachmentDDRM_LPF_VCF_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_LPF_VCF_1", sliderDDRM_LPF_VCF_1));
        sliderDDRM_LPF_VCF_1.textFromValueFunction = [](double value) {
            return String::formatted("LPF: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_RESl_VCF_1
        sliderDDRM_RESl_VCF_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_RESl_VCF_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_RESl_VCF_1.setLookAndFeel (&redSlider);
        sliderDDRM_RESl_VCF_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_RESl_VCF_1);
        sliderAttachmentDDRM_RESl_VCF_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_RESl_VCF_1", sliderDDRM_RESl_VCF_1));
        sliderDDRM_RESl_VCF_1.textFromValueFunction = [](double value) {
            return String::formatted("RESl: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_IL_VCF_1
        sliderDDRM_IL_VCF_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_IL_VCF_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_IL_VCF_1.setLookAndFeel (&blackSlider);
        sliderDDRM_IL_VCF_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_IL_VCF_1);
        sliderAttachmentDDRM_IL_VCF_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_IL_VCF_1", sliderDDRM_IL_VCF_1));
        sliderDDRM_IL_VCF_1.textFromValueFunction = [](double value) {
            return String::formatted("IL: %.2f%", -5.0 * value / 127.0);
        };
        // Slider DDRM_AL_VCF_1
        sliderDDRM_AL_VCF_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_AL_VCF_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_AL_VCF_1.setLookAndFeel (&blackSlider);
        sliderDDRM_AL_VCF_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_AL_VCF_1);
        sliderAttachmentDDRM_AL_VCF_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_AL_VCF_1", sliderDDRM_AL_VCF_1));
        sliderDDRM_AL_VCF_1.textFromValueFunction = [](double value) {
            return String::formatted("AL: %.2f%", 5.0 * value / 127.0);
        };
        // Slider DDRM_A_VCF_1
        sliderDDRM_A_VCF_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_A_VCF_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_A_VCF_1.setLookAndFeel (&blackSlider);
        sliderDDRM_A_VCF_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_A_VCF_1);
        sliderAttachmentDDRM_A_VCF_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_A_VCF_1", sliderDDRM_A_VCF_1));
        sliderDDRM_A_VCF_1.textFromValueFunction = [](double value) {
            return String::formatted("A: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_D_VCF_1
        sliderDDRM_D_VCF_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_D_VCF_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_D_VCF_1.setLookAndFeel (&blackSlider);
        sliderDDRM_D_VCF_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_D_VCF_1);
        sliderAttachmentDDRM_D_VCF_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_D_VCF_1", sliderDDRM_D_VCF_1));
        sliderDDRM_D_VCF_1.textFromValueFunction = [](double value) {
            return String::formatted("D: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_R_VCF_1
        sliderDDRM_R_VCF_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_R_VCF_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_R_VCF_1.setLookAndFeel (&yellowSlider);
        sliderDDRM_R_VCF_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_R_VCF_1);
        sliderAttachmentDDRM_R_VCF_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_R_VCF_1", sliderDDRM_R_VCF_1));
        sliderDDRM_R_VCF_1.textFromValueFunction = [](double value) {
            return String::formatted("R: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_VCF_VCA_1
        sliderDDRM_VCF_VCA_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_VCF_VCA_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_VCF_VCA_1.setLookAndFeel (&graySlider);
        sliderDDRM_VCF_VCA_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_VCF_VCA_1);
        sliderAttachmentDDRM_VCF_VCA_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_VCF_VCA_1", sliderDDRM_VCF_VCA_1));
        sliderDDRM_VCF_VCA_1.textFromValueFunction = [](double value) {
            return String::formatted("VCF Level: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_SINE__VCA_1
        sliderDDRM_SINE__VCA_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_SINE__VCA_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_SINE__VCA_1.setLookAndFeel (&graySlider);
        sliderDDRM_SINE__VCA_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_SINE__VCA_1);
        sliderAttachmentDDRM_SINE__VCA_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_SINE__VCA_1", sliderDDRM_SINE__VCA_1));
        sliderDDRM_SINE__VCA_1.textFromValueFunction = [](double value) {
            return String::formatted("Sine Level: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_A_VCA_1
        sliderDDRM_A_VCA_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_A_VCA_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_A_VCA_1.setLookAndFeel (&blackSlider);
        sliderDDRM_A_VCA_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_A_VCA_1);
        sliderAttachmentDDRM_A_VCA_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_A_VCA_1", sliderDDRM_A_VCA_1));
        sliderDDRM_A_VCA_1.textFromValueFunction = [](double value) {
            return String::formatted("A: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_D_VCA_1
        sliderDDRM_D_VCA_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_D_VCA_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_D_VCA_1.setLookAndFeel (&blackSlider);
        sliderDDRM_D_VCA_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_D_VCA_1);
        sliderAttachmentDDRM_D_VCA_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_D_VCA_1", sliderDDRM_D_VCA_1));
        sliderDDRM_D_VCA_1.textFromValueFunction = [](double value) {
            return String::formatted("D: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_S_VCA_1
        sliderDDRM_S_VCA_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_S_VCA_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_S_VCA_1.setLookAndFeel (&blackSlider);
        sliderDDRM_S_VCA_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_S_VCA_1);
        sliderAttachmentDDRM_S_VCA_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_S_VCA_1", sliderDDRM_S_VCA_1));
        sliderDDRM_S_VCA_1.textFromValueFunction = [](double value) {
            return String::formatted("S: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_R_VCA_1
        sliderDDRM_R_VCA_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_R_VCA_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_R_VCA_1.setLookAndFeel (&yellowSlider);
        sliderDDRM_R_VCA_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_R_VCA_1);
        sliderAttachmentDDRM_R_VCA_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_R_VCA_1", sliderDDRM_R_VCA_1));
        sliderDDRM_R_VCA_1.textFromValueFunction = [](double value) {
            return String::formatted("R: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_LEVEL_VCA_1
        sliderDDRM_LEVEL_VCA_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_LEVEL_VCA_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_LEVEL_VCA_1.setLookAndFeel (&graySlider);
        sliderDDRM_LEVEL_VCA_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_LEVEL_VCA_1);
        sliderAttachmentDDRM_LEVEL_VCA_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_LEVEL_VCA_1", sliderDDRM_LEVEL_VCA_1));
        sliderDDRM_LEVEL_VCA_1.textFromValueFunction = [](double value) {
            return String::formatted("Channel Level: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_INIT_BR_TOUCH_1
        sliderDDRM_INIT_BR_TOUCH_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_INIT_BR_TOUCH_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_INIT_BR_TOUCH_1.setLookAndFeel (&greenSlider);
        sliderDDRM_INIT_BR_TOUCH_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_INIT_BR_TOUCH_1);
        sliderAttachmentDDRM_INIT_BR_TOUCH_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_INIT_BR_TOUCH_1", sliderDDRM_INIT_BR_TOUCH_1));
        sliderDDRM_INIT_BR_TOUCH_1.textFromValueFunction = [](double value) {
            return String::formatted("Initial Brilliance: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_INIT_LEV_TOUCH_1
        sliderDDRM_INIT_LEV_TOUCH_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_INIT_LEV_TOUCH_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_INIT_LEV_TOUCH_1.setLookAndFeel (&graySlider);
        sliderDDRM_INIT_LEV_TOUCH_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_INIT_LEV_TOUCH_1);
        sliderAttachmentDDRM_INIT_LEV_TOUCH_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_INIT_LEV_TOUCH_1", sliderDDRM_INIT_LEV_TOUCH_1));
        sliderDDRM_INIT_LEV_TOUCH_1.textFromValueFunction = [](double value) {
            return String::formatted("Initial Level: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_AT_BR_TOUCH_1
        sliderDDRM_AT_BR_TOUCH_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_AT_BR_TOUCH_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_AT_BR_TOUCH_1.setLookAndFeel (&greenSlider);
        sliderDDRM_AT_BR_TOUCH_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_AT_BR_TOUCH_1);
        sliderAttachmentDDRM_AT_BR_TOUCH_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_AT_BR_TOUCH_1", sliderDDRM_AT_BR_TOUCH_1));
        sliderDDRM_AT_BR_TOUCH_1.textFromValueFunction = [](double value) {
            return String::formatted("After Brilliance: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_AT_LEV_TOUCH_1
        sliderDDRM_AT_LEV_TOUCH_1.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_AT_LEV_TOUCH_1.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_AT_LEV_TOUCH_1.setLookAndFeel (&graySlider);
        sliderDDRM_AT_LEV_TOUCH_1.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_AT_LEV_TOUCH_1);
        sliderAttachmentDDRM_AT_LEV_TOUCH_1.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_AT_LEV_TOUCH_1", sliderDDRM_AT_LEV_TOUCH_1));
        sliderDDRM_AT_LEV_TOUCH_1.textFromValueFunction = [](double value) {
            return String::formatted("After Level: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_SPEED_VCO_2
        sliderDDRM_SPEED_VCO_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_SPEED_VCO_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_SPEED_VCO_2.setLookAndFeel (&whiteSlider);
        sliderDDRM_SPEED_VCO_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_SPEED_VCO_2);
        sliderAttachmentDDRM_SPEED_VCO_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_SPEED_VCO_2", sliderDDRM_SPEED_VCO_2));
        sliderDDRM_SPEED_VCO_2.textFromValueFunction = [](double value) {
            return String::formatted("PWM Speed: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_PWM_VCO_2
        sliderDDRM_PWM_VCO_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_PWM_VCO_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_PWM_VCO_2.setLookAndFeel (&greenSlider);
        sliderDDRM_PWM_VCO_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_PWM_VCO_2);
        sliderAttachmentDDRM_PWM_VCO_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_PWM_VCO_2", sliderDDRM_PWM_VCO_2));
        sliderDDRM_PWM_VCO_2.textFromValueFunction = [](double value) {
            return String::formatted("PWM Amount: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_PW_VCO_2
        sliderDDRM_PW_VCO_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_PW_VCO_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_PW_VCO_2.setLookAndFeel (&greenSlider);
        sliderDDRM_PW_VCO_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_PW_VCO_2);
        sliderAttachmentDDRM_PW_VCO_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_PW_VCO_2", sliderDDRM_PW_VCO_2));
        sliderDDRM_PW_VCO_2.textFromValueFunction = [](double value) {
            return String::formatted("PW: %.0f%%", 100.0 * ((0.4 * value / 127.0) + 0.5));
        };
        // Slider DDRM_SQR_VCO_2
        sliderDDRM_SQR_VCO_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_SQR_VCO_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_SQR_VCO_2.setLookAndFeel (&blackSlider);
        sliderDDRM_SQR_VCO_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_SQR_VCO_2);
        sliderAttachmentDDRM_SQR_VCO_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_SQR_VCO_2", sliderDDRM_SQR_VCO_2));
        sliderDDRM_SQR_VCO_2.setRange(sliderDDRM_SQR_VCO_2.getMinimum(), sliderDDRM_SQR_VCO_2.getMaximum(), sliderDDRM_SQR_VCO_2.getMaximum());
        sliderDDRM_SQR_VCO_2.textFromValueFunction = [](double value) {
            if (value <= 64){ return "Square: ON"; } else { return "Square OFF";}
        };
        // Slider DDRM_SAW_VCO_2
        sliderDDRM_SAW_VCO_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_SAW_VCO_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_SAW_VCO_2.setLookAndFeel (&blackSlider);
        sliderDDRM_SAW_VCO_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_SAW_VCO_2);
        sliderAttachmentDDRM_SAW_VCO_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_SAW_VCO_2", sliderDDRM_SAW_VCO_2));
        sliderDDRM_SAW_VCO_2.setRange(sliderDDRM_SAW_VCO_2.getMinimum(), sliderDDRM_SAW_VCO_2.getMaximum(), sliderDDRM_SAW_VCO_2.getMaximum());
        sliderDDRM_SAW_VCO_2.textFromValueFunction = [](double value) {
            if (value <= 64){ return "Sawtooth: ON"; } else { return "Sawtooth OFF";}
        };
        // Slider DDRM_NOISE_VCO_2
        sliderDDRM_NOISE_VCO_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_NOISE_VCO_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_NOISE_VCO_2.setLookAndFeel (&graySlider);
        sliderDDRM_NOISE_VCO_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_NOISE_VCO_2);
        sliderAttachmentDDRM_NOISE_VCO_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_NOISE_VCO_2", sliderDDRM_NOISE_VCO_2));
        sliderDDRM_NOISE_VCO_2.textFromValueFunction = [](double value) {
            return String::formatted("Noise: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_HPF_VCF_2
        sliderDDRM_HPF_VCF_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_HPF_VCF_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_HPF_VCF_2.setLookAndFeel (&greenSlider);
        sliderDDRM_HPF_VCF_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_HPF_VCF_2);
        sliderAttachmentDDRM_HPF_VCF_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_HPF_VCF_2", sliderDDRM_HPF_VCF_2));
        sliderDDRM_HPF_VCF_2.textFromValueFunction = [](double value) {
            return String::formatted("HPF: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_RESh_VCF_2
        sliderDDRM_RESh_VCF_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_RESh_VCF_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_RESh_VCF_2.setLookAndFeel (&redSlider);
        sliderDDRM_RESh_VCF_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_RESh_VCF_2);
        sliderAttachmentDDRM_RESh_VCF_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_RESh_VCF_2", sliderDDRM_RESh_VCF_2));
        sliderDDRM_RESh_VCF_2.textFromValueFunction = [](double value) {
            return String::formatted("RESh: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_LPF_VCF_2
        sliderDDRM_LPF_VCF_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_LPF_VCF_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_LPF_VCF_2.setLookAndFeel (&greenSlider);
        sliderDDRM_LPF_VCF_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_LPF_VCF_2);
        sliderAttachmentDDRM_LPF_VCF_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_LPF_VCF_2", sliderDDRM_LPF_VCF_2));
        sliderDDRM_LPF_VCF_2.textFromValueFunction = [](double value) {
            return String::formatted("LPF: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_RESl_VCF_2
        sliderDDRM_RESl_VCF_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_RESl_VCF_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_RESl_VCF_2.setLookAndFeel (&redSlider);
        sliderDDRM_RESl_VCF_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_RESl_VCF_2);
        sliderAttachmentDDRM_RESl_VCF_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_RESl_VCF_2", sliderDDRM_RESl_VCF_2));
        sliderDDRM_RESl_VCF_2.textFromValueFunction = [](double value) {
            return String::formatted("RESl: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_IL_VCF_2
        sliderDDRM_IL_VCF_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_IL_VCF_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_IL_VCF_2.setLookAndFeel (&blackSlider);
        sliderDDRM_IL_VCF_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_IL_VCF_2);
        sliderAttachmentDDRM_IL_VCF_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_IL_VCF_2", sliderDDRM_IL_VCF_2));
        sliderDDRM_IL_VCF_2.textFromValueFunction = [](double value) {
            return String::formatted("IL: %.2f%", -5.0 * value / 127.0);
        };
        // Slider DDRM_AL_VCF_2
        sliderDDRM_AL_VCF_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_AL_VCF_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_AL_VCF_2.setLookAndFeel (&blackSlider);
        sliderDDRM_AL_VCF_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_AL_VCF_2);
        sliderAttachmentDDRM_AL_VCF_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_AL_VCF_2", sliderDDRM_AL_VCF_2));
        sliderDDRM_AL_VCF_2.textFromValueFunction = [](double value) {
            return String::formatted("AL: %.2f%", 5.0 * value / 127.0);
        };
        // Slider DDRM_A_VCF_2
        sliderDDRM_A_VCF_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_A_VCF_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_A_VCF_2.setLookAndFeel (&blackSlider);
        sliderDDRM_A_VCF_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_A_VCF_2);
        sliderAttachmentDDRM_A_VCF_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_A_VCF_2", sliderDDRM_A_VCF_2));
        sliderDDRM_A_VCF_2.textFromValueFunction = [](double value) {
            return String::formatted("A: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_D_VCF_2
        sliderDDRM_D_VCF_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_D_VCF_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_D_VCF_2.setLookAndFeel (&blackSlider);
        sliderDDRM_D_VCF_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_D_VCF_2);
        sliderAttachmentDDRM_D_VCF_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_D_VCF_2", sliderDDRM_D_VCF_2));
        sliderDDRM_D_VCF_2.textFromValueFunction = [](double value) {
            return String::formatted("D: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_R_VCF_2
        sliderDDRM_R_VCF_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_R_VCF_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_R_VCF_2.setLookAndFeel (&yellowSlider);
        sliderDDRM_R_VCF_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_R_VCF_2);
        sliderAttachmentDDRM_R_VCF_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_R_VCF_2", sliderDDRM_R_VCF_2));
        sliderDDRM_R_VCF_2.textFromValueFunction = [](double value) {
            return String::formatted("R: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_VCF_VCA_2
        sliderDDRM_VCF_VCA_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_VCF_VCA_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_VCF_VCA_2.setLookAndFeel (&graySlider);
        sliderDDRM_VCF_VCA_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_VCF_VCA_2);
        sliderAttachmentDDRM_VCF_VCA_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_VCF_VCA_2", sliderDDRM_VCF_VCA_2));
        sliderDDRM_VCF_VCA_2.textFromValueFunction = [](double value) {
            return String::formatted("VCF Level: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_SINE__VCA_2
        sliderDDRM_SINE__VCA_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_SINE__VCA_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_SINE__VCA_2.setLookAndFeel (&graySlider);
        sliderDDRM_SINE__VCA_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_SINE__VCA_2);
        sliderAttachmentDDRM_SINE__VCA_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_SINE__VCA_2", sliderDDRM_SINE__VCA_2));
        sliderDDRM_SINE__VCA_2.textFromValueFunction = [](double value) {
            return String::formatted("Sine Level: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_A_VCA_2
        sliderDDRM_A_VCA_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_A_VCA_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_A_VCA_2.setLookAndFeel (&blackSlider);
        sliderDDRM_A_VCA_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_A_VCA_2);
        sliderAttachmentDDRM_A_VCA_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_A_VCA_2", sliderDDRM_A_VCA_2));
        sliderDDRM_A_VCA_2.textFromValueFunction = [](double value) {
            return String::formatted("A: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_D_VCA_2
        sliderDDRM_D_VCA_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_D_VCA_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_D_VCA_2.setLookAndFeel (&blackSlider);
        sliderDDRM_D_VCA_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_D_VCA_2);
        sliderAttachmentDDRM_D_VCA_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_D_VCA_2", sliderDDRM_D_VCA_2));
        sliderDDRM_D_VCA_2.textFromValueFunction = [](double value) {
            return String::formatted("D: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_S_VCA_2
        sliderDDRM_S_VCA_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_S_VCA_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_S_VCA_2.setLookAndFeel (&blackSlider);
        sliderDDRM_S_VCA_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_S_VCA_2);
        sliderAttachmentDDRM_S_VCA_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_S_VCA_2", sliderDDRM_S_VCA_2));
        sliderDDRM_S_VCA_2.textFromValueFunction = [](double value) {
            return String::formatted("S: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_R_VCA_2
        sliderDDRM_R_VCA_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_R_VCA_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_R_VCA_2.setLookAndFeel (&yellowSlider);
        sliderDDRM_R_VCA_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_R_VCA_2);
        sliderAttachmentDDRM_R_VCA_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_R_VCA_2", sliderDDRM_R_VCA_2));
        sliderDDRM_R_VCA_2.textFromValueFunction = [](double value) {
            return String::formatted("R: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_LEVEL_VCA_2
        sliderDDRM_LEVEL_VCA_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_LEVEL_VCA_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_LEVEL_VCA_2.setLookAndFeel (&graySlider);
        sliderDDRM_LEVEL_VCA_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_LEVEL_VCA_2);
        sliderAttachmentDDRM_LEVEL_VCA_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_LEVEL_VCA_2", sliderDDRM_LEVEL_VCA_2));
        sliderDDRM_LEVEL_VCA_2.textFromValueFunction = [](double value) {
            return String::formatted("Channel Level: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_INIT_BR_TOUCH_2
        sliderDDRM_INIT_BR_TOUCH_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_INIT_BR_TOUCH_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_INIT_BR_TOUCH_2.setLookAndFeel (&greenSlider);
        sliderDDRM_INIT_BR_TOUCH_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_INIT_BR_TOUCH_2);
        sliderAttachmentDDRM_INIT_BR_TOUCH_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_INIT_BR_TOUCH_2", sliderDDRM_INIT_BR_TOUCH_2));
        sliderDDRM_INIT_BR_TOUCH_2.textFromValueFunction = [](double value) {
            return String::formatted("Initial Brilliance: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_INIT_LEV_TOUCH_2
        sliderDDRM_INIT_LEV_TOUCH_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_INIT_LEV_TOUCH_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_INIT_LEV_TOUCH_2.setLookAndFeel (&graySlider);
        sliderDDRM_INIT_LEV_TOUCH_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_INIT_LEV_TOUCH_2);
        sliderAttachmentDDRM_INIT_LEV_TOUCH_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_INIT_LEV_TOUCH_2", sliderDDRM_INIT_LEV_TOUCH_2));
        sliderDDRM_INIT_LEV_TOUCH_2.textFromValueFunction = [](double value) {
            return String::formatted("Initial Level: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_AT_BR_TOUCH_2
        sliderDDRM_AT_BR_TOUCH_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_AT_BR_TOUCH_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_AT_BR_TOUCH_2.setLookAndFeel (&greenSlider);
        sliderDDRM_AT_BR_TOUCH_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_AT_BR_TOUCH_2);
        sliderAttachmentDDRM_AT_BR_TOUCH_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_AT_BR_TOUCH_2", sliderDDRM_AT_BR_TOUCH_2));
        sliderDDRM_AT_BR_TOUCH_2.textFromValueFunction = [](double value) {
            return String::formatted("After Brilliance: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_AT_LEV_TOUCH_2
        sliderDDRM_AT_LEV_TOUCH_2.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_AT_LEV_TOUCH_2.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_AT_LEV_TOUCH_2.setLookAndFeel (&graySlider);
        sliderDDRM_AT_LEV_TOUCH_2.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_AT_LEV_TOUCH_2);
        sliderAttachmentDDRM_AT_LEV_TOUCH_2.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_AT_LEV_TOUCH_2", sliderDDRM_AT_LEV_TOUCH_2));
        sliderDDRM_AT_LEV_TOUCH_2.textFromValueFunction = [](double value) {
            return String::formatted("After Level: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_COARSE_PITCH
        sliderDDRM_COARSE_PITCH.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_COARSE_PITCH.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_COARSE_PITCH.setLookAndFeel (&blackSlider);
        sliderDDRM_COARSE_PITCH.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_COARSE_PITCH);
        sliderAttachmentDDRM_COARSE_PITCH.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_COARSE_PITCH", sliderDDRM_COARSE_PITCH));
        sliderDDRM_COARSE_PITCH.textFromValueFunction = [](double value) {
            return String::formatted("Pitch Coarse: %.0f%%", (-200.0 * ((value - 64.0) / 127.0) -0.5));  // Needs last -0.5 to match [-100, +100]
        };
        // Slider DDRM_FINE_PITCH
        sliderDDRM_FINE_PITCH.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_FINE_PITCH.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_FINE_PITCH.setLookAndFeel (&blackSlider);
        sliderDDRM_FINE_PITCH.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_FINE_PITCH);
        sliderAttachmentDDRM_FINE_PITCH.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_FINE_PITCH", sliderDDRM_FINE_PITCH));
        sliderDDRM_FINE_PITCH.textFromValueFunction = [](double value) {
            return String::formatted("Pitch Fine: %.0f%%", (-200.0 * ((value - 64.0) / 127.0) -0.5));  // Needs last -0.5 to match [-100, +100]
        };
        // Slider DDRM_DETUNE_CH2_PITCH
        sliderDDRM_DETUNE_CH2_PITCH.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_DETUNE_CH2_PITCH.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_DETUNE_CH2_PITCH.setLookAndFeel (&whiteSlider);
        sliderDDRM_DETUNE_CH2_PITCH.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_DETUNE_CH2_PITCH);
        sliderAttachmentDDRM_DETUNE_CH2_PITCH.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_DETUNE_CH2_PITCH", sliderDDRM_DETUNE_CH2_PITCH));
        sliderDDRM_DETUNE_CH2_PITCH.textFromValueFunction = [](double value) {
            return String::formatted("Detune Ch II: %.0f%%", (-200.0 * ((value - 64.0) / 127.0) -0.5));  // Needs last -0.5 to match [-100, +100]
        };
        // Slider DDRM_FEET_1_FEET
        sliderDDRM_FEET_1_FEET.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_FEET_1_FEET.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_FEET_1_FEET.setLookAndFeel (&whiteSlider);
        sliderDDRM_FEET_1_FEET.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_FEET_1_FEET);
        sliderAttachmentDDRM_FEET_1_FEET.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_FEET_1_FEET", sliderDDRM_FEET_1_FEET));
        sliderDDRM_FEET_1_FEET.setRange(sliderDDRM_FEET_1_FEET.getMinimum(), sliderDDRM_FEET_1_FEET.getMaximum(), sliderDDRM_FEET_1_FEET.getMaximum()/5);
        sliderDDRM_FEET_1_FEET.textFromValueFunction = [](double value) {
            float midiValue = 127.0 - value;
            if (midiValue >= 0 && midiValue < 22){
                return "Feet I: 16'";
            } else if (midiValue >= 22 && midiValue < 43){
                return "Feet I: 8'";
            } else if (midiValue >= 43 && midiValue < 64){
                return "Feet I: 5 1/3'";
            } else if (midiValue >= 64 && midiValue < 85){
                return "Feet I: 4'";
            } else if (midiValue >= 85 && midiValue < 106){
                return "Feet I: 2 2/3'";
            } else {
                return "Feet I: 2'";
            }
        };
        // Slider DDRM_FEET_2_FEET
        sliderDDRM_FEET_2_FEET.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_FEET_2_FEET.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_FEET_2_FEET.setLookAndFeel (&whiteSlider);
        sliderDDRM_FEET_2_FEET.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_FEET_2_FEET);
        sliderAttachmentDDRM_FEET_2_FEET.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_FEET_2_FEET", sliderDDRM_FEET_2_FEET));
        sliderDDRM_FEET_2_FEET.setRange(sliderDDRM_FEET_2_FEET.getMinimum(), sliderDDRM_FEET_2_FEET.getMaximum(), sliderDDRM_FEET_2_FEET.getMaximum()/5);
        sliderDDRM_FEET_2_FEET.textFromValueFunction = [](double value) {
            float midiValue = 127.0 - value;
            if (midiValue >= 0 && midiValue < 22){
                return "Feet II: 16'";
            } else if (midiValue >= 22 && midiValue < 43){
                return "Feet II: 8'";
            } else if (midiValue >= 43 && midiValue < 64){
                return "Feet II: 5 1/3'";
            } else if (midiValue >= 64 && midiValue < 85){
                return "Feet II: 4'";
            } else if (midiValue >= 85 && midiValue < 106){
                return "Feet II: 2 2/3'";
            } else {
                return "Feet II: 2'";
            }
        };
        // Slider DDRM_FUNCTION_SUB_OSC
        sliderDDRM_FUNCTION_SUB_OSC.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_FUNCTION_SUB_OSC.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_FUNCTION_SUB_OSC.setLookAndFeel (&blackSlider);
        sliderDDRM_FUNCTION_SUB_OSC.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_FUNCTION_SUB_OSC);
        sliderAttachmentDDRM_FUNCTION_SUB_OSC.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_FUNCTION_SUB_OSC", sliderDDRM_FUNCTION_SUB_OSC));
        sliderDDRM_FUNCTION_SUB_OSC.setRange(sliderDDRM_FUNCTION_SUB_OSC.getMinimum(), sliderDDRM_FUNCTION_SUB_OSC.getMaximum(), sliderDDRM_FUNCTION_SUB_OSC.getMaximum()/5);
        sliderDDRM_FUNCTION_SUB_OSC.textFromValueFunction = [](double value) {
            float midiValue = 127.0 - value;
            if (midiValue >= 0 && midiValue < 22){
                return "Sub Osc Function: Sin";
            } else if (midiValue >= 22 && midiValue < 43){
                return "Sub Osc Function: Tri";
            } else if (midiValue >= 43 && midiValue < 64){
                return "Sub Osc Function: Inv Tri";
            } else if (midiValue >= 64 && midiValue < 85){
                return "Sub Osc Function: Sqr";
            } else if (midiValue >= 85 && midiValue < 106){
                return "Sub Osc Function: Rnd";
            } else {
                return "Sub Osc Function: Ext";
            }
        };
        // Slider DDRM_SPEED_SUB_OSC
        sliderDDRM_SPEED_SUB_OSC.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_SPEED_SUB_OSC.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_SPEED_SUB_OSC.setLookAndFeel (&whiteSlider);
        sliderDDRM_SPEED_SUB_OSC.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_SPEED_SUB_OSC);
        sliderAttachmentDDRM_SPEED_SUB_OSC.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_SPEED_SUB_OSC", sliderDDRM_SPEED_SUB_OSC));
        sliderDDRM_SPEED_SUB_OSC.textFromValueFunction = [](double value) {
            return String::formatted("Sub Osc Speed: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_VCO_SUB_OSC
        sliderDDRM_VCO_SUB_OSC.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_VCO_SUB_OSC.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_VCO_SUB_OSC.setLookAndFeel (&whiteSlider);
        sliderDDRM_VCO_SUB_OSC.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_VCO_SUB_OSC);
        sliderAttachmentDDRM_VCO_SUB_OSC.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_VCO_SUB_OSC", sliderDDRM_VCO_SUB_OSC));
        sliderDDRM_VCO_SUB_OSC.textFromValueFunction = [](double value) {
            return String::formatted("Sub Osc VCO Amount: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_VCF_SUB_OSC
        sliderDDRM_VCF_SUB_OSC.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_VCF_SUB_OSC.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_VCF_SUB_OSC.setLookAndFeel (&greenSlider);
        sliderDDRM_VCF_SUB_OSC.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_VCF_SUB_OSC);
        sliderAttachmentDDRM_VCF_SUB_OSC.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_VCF_SUB_OSC", sliderDDRM_VCF_SUB_OSC));
        sliderDDRM_VCF_SUB_OSC.textFromValueFunction = [](double value) {
            return String::formatted("Sub Osc VCF Amount: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_VCA_SUB_OSC
        sliderDDRM_VCA_SUB_OSC.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_VCA_SUB_OSC.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_VCA_SUB_OSC.setLookAndFeel (&graySlider);
        sliderDDRM_VCA_SUB_OSC.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_VCA_SUB_OSC);
        sliderAttachmentDDRM_VCA_SUB_OSC.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_VCA_SUB_OSC", sliderDDRM_VCA_SUB_OSC));
        sliderDDRM_VCA_SUB_OSC.textFromValueFunction = [](double value) {
            return String::formatted("Sub Osc VCA Amount: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_MIX
        sliderDDRM_MIX.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_MIX.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_MIX.setLookAndFeel (&blackSlider);
        sliderDDRM_MIX.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_MIX);
        sliderAttachmentDDRM_MIX.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_MIX", sliderDDRM_MIX));
        sliderDDRM_MIX.textFromValueFunction = [](double value) {
            float percentageCh1 = 100.0 * value / 127.0;
	        float percentageCh2 = 100.0 - 100.0 * value / 127.0;
	        return String::formatted("Mix: %.0f%% I - %.0f%% II", percentageCh1, percentageCh2);
        };
        // Slider DDRM_BRILL
        sliderDDRM_BRILL.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_BRILL.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_BRILL.setLookAndFeel (&greenSlider);
        sliderDDRM_BRILL.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_BRILL);
        sliderAttachmentDDRM_BRILL.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_BRILL", sliderDDRM_BRILL));
        sliderDDRM_BRILL.textFromValueFunction = [](double value) {
            return String::formatted("Brilliance: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_RESSO
        sliderDDRM_RESSO.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_RESSO.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_RESSO.setLookAndFeel (&redSlider);
        sliderDDRM_RESSO.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_RESSO);
        sliderAttachmentDDRM_RESSO.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_RESSO", sliderDDRM_RESSO));
        sliderDDRM_RESSO.textFromValueFunction = [](double value) {
            return String::formatted("Ressonance: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_INITIAL_TOUCH
        sliderDDRM_INITIAL_TOUCH.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_INITIAL_TOUCH.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_INITIAL_TOUCH.setLookAndFeel (&whiteSlider);
        sliderDDRM_INITIAL_TOUCH.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_INITIAL_TOUCH);
        sliderAttachmentDDRM_INITIAL_TOUCH.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_INITIAL_TOUCH", sliderDDRM_INITIAL_TOUCH));
        sliderDDRM_INITIAL_TOUCH.textFromValueFunction = [](double value) {
            return String::formatted("Initial Pitch Bend: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_SPEED_TOUCH
        sliderDDRM_SPEED_TOUCH.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_SPEED_TOUCH.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_SPEED_TOUCH.setLookAndFeel (&whiteSlider);
        sliderDDRM_SPEED_TOUCH.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_SPEED_TOUCH);
        sliderAttachmentDDRM_SPEED_TOUCH.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_SPEED_TOUCH", sliderDDRM_SPEED_TOUCH));
        sliderDDRM_SPEED_TOUCH.textFromValueFunction = [](double value) {
            return String::formatted("Touch Response Sub Osc Speed: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_VCO_TOUCH
        sliderDDRM_VCO_TOUCH.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_VCO_TOUCH.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_VCO_TOUCH.setLookAndFeel (&whiteSlider);
        sliderDDRM_VCO_TOUCH.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_VCO_TOUCH);
        sliderAttachmentDDRM_VCO_TOUCH.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_VCO_TOUCH", sliderDDRM_VCO_TOUCH));
        sliderDDRM_VCO_TOUCH.textFromValueFunction = [](double value) {
            return String::formatted("Touch Response Sub Osc VCO Amount: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_VCF_TOUCH
        sliderDDRM_VCF_TOUCH.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_VCF_TOUCH.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_VCF_TOUCH.setLookAndFeel (&greenSlider);
        sliderDDRM_VCF_TOUCH.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_VCF_TOUCH);
        sliderAttachmentDDRM_VCF_TOUCH.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_VCF_TOUCH", sliderDDRM_VCF_TOUCH));
        sliderDDRM_VCF_TOUCH.textFromValueFunction = [](double value) {
            return String::formatted("Touch Response Sub Osc VCF Amount: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_BR_LOW_KBRD
        sliderDDRM_BR_LOW_KBRD.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_BR_LOW_KBRD.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_BR_LOW_KBRD.setLookAndFeel (&greenSlider);
        sliderDDRM_BR_LOW_KBRD.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_BR_LOW_KBRD);
        sliderAttachmentDDRM_BR_LOW_KBRD.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_BR_LOW_KBRD", sliderDDRM_BR_LOW_KBRD));
        sliderDDRM_BR_LOW_KBRD.textFromValueFunction = [](double value) {
            return String::formatted("Brilliance Low: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_BR_HIGH_KBRD
        sliderDDRM_BR_HIGH_KBRD.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_BR_HIGH_KBRD.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_BR_HIGH_KBRD.setLookAndFeel (&greenSlider);
        sliderDDRM_BR_HIGH_KBRD.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_BR_HIGH_KBRD);
        sliderAttachmentDDRM_BR_HIGH_KBRD.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_BR_HIGH_KBRD", sliderDDRM_BR_HIGH_KBRD));
        sliderDDRM_BR_HIGH_KBRD.textFromValueFunction = [](double value) {
            return String::formatted("Brilliance High: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_LEV_LOW_KBRD
        sliderDDRM_LEV_LOW_KBRD.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_LEV_LOW_KBRD.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_LEV_LOW_KBRD.setLookAndFeel (&graySlider);
        sliderDDRM_LEV_LOW_KBRD.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_LEV_LOW_KBRD);
        sliderAttachmentDDRM_LEV_LOW_KBRD.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_LEV_LOW_KBRD", sliderDDRM_LEV_LOW_KBRD));
        sliderDDRM_LEV_LOW_KBRD.textFromValueFunction = [](double value) {
            return String::formatted("Level Low: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_LEV_HIGH_KBRD
        sliderDDRM_LEV_HIGH_KBRD.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_LEV_HIGH_KBRD.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_LEV_HIGH_KBRD.setLookAndFeel (&graySlider);
        sliderDDRM_LEV_HIGH_KBRD.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_LEV_HIGH_KBRD);
        sliderAttachmentDDRM_LEV_HIGH_KBRD.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_LEV_HIGH_KBRD", sliderDDRM_LEV_HIGH_KBRD));
        sliderDDRM_LEV_HIGH_KBRD.textFromValueFunction = [](double value) {
            return String::formatted("Level High: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_GLIDE_MODE_GLIDE
        sliderDDRM_GLIDE_MODE_GLIDE.setSliderStyle (Slider::LinearHorizontal);
        sliderDDRM_GLIDE_MODE_GLIDE.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_GLIDE_MODE_GLIDE.setLookAndFeel (&blackSlider);
        sliderDDRM_GLIDE_MODE_GLIDE.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_GLIDE_MODE_GLIDE);
        sliderAttachmentDDRM_GLIDE_MODE_GLIDE.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_GLIDE_MODE_GLIDE", sliderDDRM_GLIDE_MODE_GLIDE));
        sliderDDRM_GLIDE_MODE_GLIDE.setRange(sliderDDRM_GLIDE_MODE_GLIDE.getMinimum(), sliderDDRM_GLIDE_MODE_GLIDE.getMaximum(), sliderDDRM_GLIDE_MODE_GLIDE.getMaximum()/2);
        sliderDDRM_GLIDE_MODE_GLIDE.textFromValueFunction = [](double value) {
            float midiValue = value;
            if (midiValue >= 0 && midiValue < 32){
                return "Glide Mode: Portamento";
            } else if (midiValue >= 32 && midiValue < 85){
                return "Glide Mode: None";
            } else {
                return "Glide Mode: Glissando";
            }
        };
        // Slider DDRM_GLIDE_TIME_GLIDE
        sliderDDRM_GLIDE_TIME_GLIDE.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_GLIDE_TIME_GLIDE.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_GLIDE_TIME_GLIDE.setLookAndFeel (&whiteSlider);
        sliderDDRM_GLIDE_TIME_GLIDE.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_GLIDE_TIME_GLIDE);
        sliderAttachmentDDRM_GLIDE_TIME_GLIDE.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_GLIDE_TIME_GLIDE", sliderDDRM_GLIDE_TIME_GLIDE));
        sliderDDRM_GLIDE_TIME_GLIDE.textFromValueFunction = [](double value) {
            return String::formatted("Glide Time: %.1f", 10.0 * (value / 127.0));
        };
        // Slider DDRM_SUSTAIN_MODE
        sliderDDRM_SUSTAIN_MODE.setSliderStyle (Slider::LinearHorizontal);
        sliderDDRM_SUSTAIN_MODE.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_SUSTAIN_MODE.setLookAndFeel (&blackSlider);
        sliderDDRM_SUSTAIN_MODE.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_SUSTAIN_MODE);
        sliderAttachmentDDRM_SUSTAIN_MODE.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_SUSTAIN_MODE", sliderDDRM_SUSTAIN_MODE));
        sliderDDRM_SUSTAIN_MODE.setRange(sliderDDRM_SUSTAIN_MODE.getMinimum(), sliderDDRM_SUSTAIN_MODE.getMaximum(), sliderDDRM_SUSTAIN_MODE.getMaximum());
        sliderDDRM_SUSTAIN_MODE.textFromValueFunction = [](double value) {
            if (value <= 64){ return "Sustain Mode: I"; } else { return "Sustain Mode: II";}
        };
        // Slider DDRM_SUSTAIN_TIME
        sliderDDRM_SUSTAIN_TIME.setSliderStyle (Slider::LinearVertical);
        sliderDDRM_SUSTAIN_TIME.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        sliderDDRM_SUSTAIN_TIME.setLookAndFeel (&yellowSlider);
        sliderDDRM_SUSTAIN_TIME.setPopupDisplayEnabled (true, true, this, -1);
        addAndMakeVisible (&sliderDDRM_SUSTAIN_TIME);
        sliderAttachmentDDRM_SUSTAIN_TIME.reset(new AudioProcessorValueTreeState::SliderAttachment (processor->parameters, "DDRM_SUSTAIN_TIME", sliderDDRM_SUSTAIN_TIME));
        sliderDDRM_SUSTAIN_TIME.textFromValueFunction = [](double value) {
            return String::formatted("Sustain Time: %.1f", 10.0 * (value / 127.0));
        };
        // --> End auto-generated code B
    }
    
    void paint (Graphics& g) override
    {
        Image background = ImageCache::getFromMemory (BinaryData::DDRM_PANEL_OVERLAY_png, BinaryData::DDRM_PANEL_OVERLAY_pngSize);
        g.drawImage (background, getLocalBounds().toFloat());
    }

    void resized() override
    {
        // Position sliders
        // --> Start auto-generated code C
        sliderDDRM_SPEED_VCO_1.setBounds (0.000 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_SPEED_VCO_1
        sliderDDRM_PWM_VCO_1.setBounds (0.036 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_PWM_VCO_1
        sliderDDRM_PW_VCO_1.setBounds (0.071 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_PW_VCO_1
        sliderDDRM_SQR_VCO_1.setBounds (0.107 * getWidth(), 0.100 * getHeight(), 0.036 * getWidth(), 0.134 * getHeight()); // Slider DDRM_SQR_VCO_1
        sliderDDRM_SAW_VCO_1.setBounds (0.143 * getWidth(), 0.100 * getHeight(), 0.036 * getWidth(), 0.134 * getHeight()); // Slider DDRM_SAW_VCO_1
        sliderDDRM_NOISE_VCO_1.setBounds (0.179 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_NOISE_VCO_1
        sliderDDRM_HPF_VCF_1.setBounds (0.236 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_HPF_VCF_1
        sliderDDRM_RESh_VCF_1.setBounds (0.272 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_RESh_VCF_1
        sliderDDRM_LPF_VCF_1.setBounds (0.308 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_LPF_VCF_1
        sliderDDRM_RESl_VCF_1.setBounds (0.343 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_RESl_VCF_1
        sliderDDRM_IL_VCF_1.setBounds (0.379 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_IL_VCF_1
        sliderDDRM_AL_VCF_1.setBounds (0.415 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_AL_VCF_1
        sliderDDRM_A_VCF_1.setBounds (0.451 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_A_VCF_1
        sliderDDRM_D_VCF_1.setBounds (0.486 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_D_VCF_1
        sliderDDRM_R_VCF_1.setBounds (0.522 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_R_VCF_1
        sliderDDRM_VCF_VCA_1.setBounds (0.580 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_VCF_VCA_1
        sliderDDRM_SINE__VCA_1.setBounds (0.615 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_SINE__VCA_1
        sliderDDRM_A_VCA_1.setBounds (0.651 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_A_VCA_1
        sliderDDRM_D_VCA_1.setBounds (0.687 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_D_VCA_1
        sliderDDRM_S_VCA_1.setBounds (0.723 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_S_VCA_1
        sliderDDRM_R_VCA_1.setBounds (0.758 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_R_VCA_1
        sliderDDRM_LEVEL_VCA_1.setBounds (0.794 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_LEVEL_VCA_1
        sliderDDRM_INIT_BR_TOUCH_1.setBounds (0.852 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_INIT_BR_TOUCH_1
        sliderDDRM_INIT_LEV_TOUCH_1.setBounds (0.888 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_INIT_LEV_TOUCH_1
        sliderDDRM_AT_BR_TOUCH_1.setBounds (0.923 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_AT_BR_TOUCH_1
        sliderDDRM_AT_LEV_TOUCH_1.setBounds (0.959 * getWidth(), 0.000 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_AT_LEV_TOUCH_1
        sliderDDRM_SPEED_VCO_2.setBounds (0.000 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_SPEED_VCO_2
        sliderDDRM_PWM_VCO_2.setBounds (0.036 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_PWM_VCO_2
        sliderDDRM_PW_VCO_2.setBounds (0.071 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_PW_VCO_2
        sliderDDRM_SQR_VCO_2.setBounds (0.107 * getWidth(), 0.434 * getHeight(), 0.036 * getWidth(), 0.134 * getHeight()); // Slider DDRM_SQR_VCO_2
        sliderDDRM_SAW_VCO_2.setBounds (0.143 * getWidth(), 0.434 * getHeight(), 0.036 * getWidth(), 0.134 * getHeight()); // Slider DDRM_SAW_VCO_2
        sliderDDRM_NOISE_VCO_2.setBounds (0.179 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_NOISE_VCO_2
        sliderDDRM_HPF_VCF_2.setBounds (0.236 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_HPF_VCF_2
        sliderDDRM_RESh_VCF_2.setBounds (0.272 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_RESh_VCF_2
        sliderDDRM_LPF_VCF_2.setBounds (0.308 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_LPF_VCF_2
        sliderDDRM_RESl_VCF_2.setBounds (0.343 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_RESl_VCF_2
        sliderDDRM_IL_VCF_2.setBounds (0.379 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_IL_VCF_2
        sliderDDRM_AL_VCF_2.setBounds (0.415 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_AL_VCF_2
        sliderDDRM_A_VCF_2.setBounds (0.451 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_A_VCF_2
        sliderDDRM_D_VCF_2.setBounds (0.486 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_D_VCF_2
        sliderDDRM_R_VCF_2.setBounds (0.522 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_R_VCF_2
        sliderDDRM_VCF_VCA_2.setBounds (0.580 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_VCF_VCA_2
        sliderDDRM_SINE__VCA_2.setBounds (0.615 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_SINE__VCA_2
        sliderDDRM_A_VCA_2.setBounds (0.651 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_A_VCA_2
        sliderDDRM_D_VCA_2.setBounds (0.687 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_D_VCA_2
        sliderDDRM_S_VCA_2.setBounds (0.723 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_S_VCA_2
        sliderDDRM_R_VCA_2.setBounds (0.758 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_R_VCA_2
        sliderDDRM_LEVEL_VCA_2.setBounds (0.794 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_LEVEL_VCA_2
        sliderDDRM_INIT_BR_TOUCH_2.setBounds (0.852 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_INIT_BR_TOUCH_2
        sliderDDRM_INIT_LEV_TOUCH_2.setBounds (0.888 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_INIT_LEV_TOUCH_2
        sliderDDRM_AT_BR_TOUCH_2.setBounds (0.923 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_AT_BR_TOUCH_2
        sliderDDRM_AT_LEV_TOUCH_2.setBounds (0.959 * getWidth(), 0.334 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_AT_LEV_TOUCH_2
        sliderDDRM_COARSE_PITCH.setBounds (0.000 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_COARSE_PITCH
        sliderDDRM_FINE_PITCH.setBounds (0.036 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_FINE_PITCH
        sliderDDRM_DETUNE_CH2_PITCH.setBounds (0.071 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_DETUNE_CH2_PITCH
        sliderDDRM_FEET_1_FEET.setBounds (0.129 * getWidth(), 0.668 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_FEET_1_FEET
        sliderDDRM_FEET_2_FEET.setBounds (0.165 * getWidth(), 0.668 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_FEET_2_FEET
        sliderDDRM_FUNCTION_SUB_OSC.setBounds (0.223 * getWidth(), 0.668 * getHeight(), 0.036 * getWidth(), 0.334 * getHeight()); // Slider DDRM_FUNCTION_SUB_OSC
        sliderDDRM_SPEED_SUB_OSC.setBounds (0.258 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_SPEED_SUB_OSC
        sliderDDRM_VCO_SUB_OSC.setBounds (0.294 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_VCO_SUB_OSC
        sliderDDRM_VCF_SUB_OSC.setBounds (0.330 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_VCF_SUB_OSC
        sliderDDRM_VCA_SUB_OSC.setBounds (0.366 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_VCA_SUB_OSC
        sliderDDRM_MIX.setBounds (0.423 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_MIX
        sliderDDRM_BRILL.setBounds (0.459 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_BRILL
        sliderDDRM_RESSO.setBounds (0.495 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_RESSO
        sliderDDRM_INITIAL_TOUCH.setBounds (0.553 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_INITIAL_TOUCH
        sliderDDRM_SPEED_TOUCH.setBounds (0.588 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_SPEED_TOUCH
        sliderDDRM_VCO_TOUCH.setBounds (0.624 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_VCO_TOUCH
        sliderDDRM_VCF_TOUCH.setBounds (0.660 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_VCF_TOUCH
        sliderDDRM_BR_LOW_KBRD.setBounds (0.718 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_BR_LOW_KBRD
        sliderDDRM_BR_HIGH_KBRD.setBounds (0.753 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_BR_HIGH_KBRD
        sliderDDRM_LEV_LOW_KBRD.setBounds (0.789 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_LEV_LOW_KBRD
        sliderDDRM_LEV_HIGH_KBRD.setBounds (0.825 * getWidth(), 0.710 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_LEV_HIGH_KBRD
        sliderDDRM_GLIDE_MODE_GLIDE.setBounds (0.883 * getWidth(), 0.851 * getHeight(), 0.061 * getWidth(), 0.167 * getHeight()); // Slider DDRM_GLIDE_MODE_GLIDE
        sliderDDRM_GLIDE_TIME_GLIDE.setBounds (0.896 * getWidth(), 0.668 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_GLIDE_TIME_GLIDE
        sliderDDRM_SUSTAIN_MODE.setBounds (0.954 * getWidth(), 0.851 * getHeight(), 0.046 * getWidth(), 0.167 * getHeight()); // Slider DDRM_SUSTAIN_MODE
        sliderDDRM_SUSTAIN_TIME.setBounds (0.959 * getWidth(), 0.668 * getHeight(), 0.036 * getWidth(), 0.250 * getHeight()); // Slider DDRM_SUSTAIN_TIME
        // --> End auto-generated code C
    }
    
private:
    DdrmtimbreSpaceAudioProcessor* processor;
    
    // Look and feel objects
    CustomLookAndFeel yellowSlider;
    CustomLookAndFeel greenSlider;
    CustomLookAndFeel blackSlider;
    CustomLookAndFeel redSlider;
    CustomLookAndFeel whiteSlider;
    CustomLookAndFeel graySlider;
    
    // Slider declarations
    // --> Start auto-generated code A
    Slider sliderDDRM_SPEED_VCO_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_SPEED_VCO_1;
    Slider sliderDDRM_PWM_VCO_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_PWM_VCO_1;
    Slider sliderDDRM_PW_VCO_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_PW_VCO_1;
    Slider sliderDDRM_SQR_VCO_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_SQR_VCO_1;
    Slider sliderDDRM_SAW_VCO_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_SAW_VCO_1;
    Slider sliderDDRM_NOISE_VCO_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_NOISE_VCO_1;
    Slider sliderDDRM_HPF_VCF_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_HPF_VCF_1;
    Slider sliderDDRM_RESh_VCF_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_RESh_VCF_1;
    Slider sliderDDRM_LPF_VCF_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_LPF_VCF_1;
    Slider sliderDDRM_RESl_VCF_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_RESl_VCF_1;
    Slider sliderDDRM_IL_VCF_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_IL_VCF_1;
    Slider sliderDDRM_AL_VCF_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_AL_VCF_1;
    Slider sliderDDRM_A_VCF_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_A_VCF_1;
    Slider sliderDDRM_D_VCF_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_D_VCF_1;
    Slider sliderDDRM_R_VCF_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_R_VCF_1;
    Slider sliderDDRM_VCF_VCA_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_VCF_VCA_1;
    Slider sliderDDRM_SINE__VCA_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_SINE__VCA_1;
    Slider sliderDDRM_A_VCA_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_A_VCA_1;
    Slider sliderDDRM_D_VCA_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_D_VCA_1;
    Slider sliderDDRM_S_VCA_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_S_VCA_1;
    Slider sliderDDRM_R_VCA_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_R_VCA_1;
    Slider sliderDDRM_LEVEL_VCA_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_LEVEL_VCA_1;
    Slider sliderDDRM_INIT_BR_TOUCH_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_INIT_BR_TOUCH_1;
    Slider sliderDDRM_INIT_LEV_TOUCH_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_INIT_LEV_TOUCH_1;
    Slider sliderDDRM_AT_BR_TOUCH_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_AT_BR_TOUCH_1;
    Slider sliderDDRM_AT_LEV_TOUCH_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_AT_LEV_TOUCH_1;
    Slider sliderDDRM_SPEED_VCO_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_SPEED_VCO_2;
    Slider sliderDDRM_PWM_VCO_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_PWM_VCO_2;
    Slider sliderDDRM_PW_VCO_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_PW_VCO_2;
    Slider sliderDDRM_SQR_VCO_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_SQR_VCO_2;
    Slider sliderDDRM_SAW_VCO_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_SAW_VCO_2;
    Slider sliderDDRM_NOISE_VCO_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_NOISE_VCO_2;
    Slider sliderDDRM_HPF_VCF_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_HPF_VCF_2;
    Slider sliderDDRM_RESh_VCF_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_RESh_VCF_2;
    Slider sliderDDRM_LPF_VCF_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_LPF_VCF_2;
    Slider sliderDDRM_RESl_VCF_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_RESl_VCF_2;
    Slider sliderDDRM_IL_VCF_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_IL_VCF_2;
    Slider sliderDDRM_AL_VCF_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_AL_VCF_2;
    Slider sliderDDRM_A_VCF_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_A_VCF_2;
    Slider sliderDDRM_D_VCF_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_D_VCF_2;
    Slider sliderDDRM_R_VCF_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_R_VCF_2;
    Slider sliderDDRM_VCF_VCA_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_VCF_VCA_2;
    Slider sliderDDRM_SINE__VCA_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_SINE__VCA_2;
    Slider sliderDDRM_A_VCA_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_A_VCA_2;
    Slider sliderDDRM_D_VCA_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_D_VCA_2;
    Slider sliderDDRM_S_VCA_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_S_VCA_2;
    Slider sliderDDRM_R_VCA_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_R_VCA_2;
    Slider sliderDDRM_LEVEL_VCA_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_LEVEL_VCA_2;
    Slider sliderDDRM_INIT_BR_TOUCH_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_INIT_BR_TOUCH_2;
    Slider sliderDDRM_INIT_LEV_TOUCH_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_INIT_LEV_TOUCH_2;
    Slider sliderDDRM_AT_BR_TOUCH_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_AT_BR_TOUCH_2;
    Slider sliderDDRM_AT_LEV_TOUCH_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_AT_LEV_TOUCH_2;
    Slider sliderDDRM_COARSE_PITCH;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_COARSE_PITCH;
    Slider sliderDDRM_FINE_PITCH;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_FINE_PITCH;
    Slider sliderDDRM_DETUNE_CH2_PITCH;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_DETUNE_CH2_PITCH;
    Slider sliderDDRM_FEET_1_FEET;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_FEET_1_FEET;
    Slider sliderDDRM_FEET_2_FEET;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_FEET_2_FEET;
    Slider sliderDDRM_FUNCTION_SUB_OSC;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_FUNCTION_SUB_OSC;
    Slider sliderDDRM_SPEED_SUB_OSC;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_SPEED_SUB_OSC;
    Slider sliderDDRM_VCO_SUB_OSC;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_VCO_SUB_OSC;
    Slider sliderDDRM_VCF_SUB_OSC;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_VCF_SUB_OSC;
    Slider sliderDDRM_VCA_SUB_OSC;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_VCA_SUB_OSC;
    Slider sliderDDRM_MIX;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_MIX;
    Slider sliderDDRM_BRILL;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_BRILL;
    Slider sliderDDRM_RESSO;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_RESSO;
    Slider sliderDDRM_INITIAL_TOUCH;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_INITIAL_TOUCH;
    Slider sliderDDRM_SPEED_TOUCH;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_SPEED_TOUCH;
    Slider sliderDDRM_VCO_TOUCH;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_VCO_TOUCH;
    Slider sliderDDRM_VCF_TOUCH;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_VCF_TOUCH;
    Slider sliderDDRM_BR_LOW_KBRD;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_BR_LOW_KBRD;
    Slider sliderDDRM_BR_HIGH_KBRD;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_BR_HIGH_KBRD;
    Slider sliderDDRM_LEV_LOW_KBRD;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_LEV_LOW_KBRD;
    Slider sliderDDRM_LEV_HIGH_KBRD;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_LEV_HIGH_KBRD;
    Slider sliderDDRM_GLIDE_MODE_GLIDE;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_GLIDE_MODE_GLIDE;
    Slider sliderDDRM_GLIDE_TIME_GLIDE;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_GLIDE_TIME_GLIDE;
    Slider sliderDDRM_SUSTAIN_MODE;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_SUSTAIN_MODE;
    Slider sliderDDRM_SUSTAIN_TIME;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentDDRM_SUSTAIN_TIME;
    // --> End auto-generated code A
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DDRMControlPanelComponent);
};
