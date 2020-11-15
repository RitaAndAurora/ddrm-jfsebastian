//
//  defines.h
//  DDRMTimbreSpace
//
//  Created by Frederic Font Corbera on 22/02/2019.
//  Copyright © 2019 Rita&AuroraAudio. All rights reserved.
//

#pragma once

#define MORE_INFO_URL "https://ritaandaurora.github.io/ddrm-jfsebastian"
#define DONATE_URL "https://ritaandaurora.github.io/ddrm-jfsebastian/donate"
#define SOURCE_CODE_URL "https://github.com/ritaandaurora/ddrm-jfsebastian"

#define ACTION_LOG_PREFIX "LOG:"
#define LOG_IN_UI 0
#define LOG_IN_CONSOLE 0
#define LOG_INDIVIDUAL_PARAMETER_CHANGES 0
#define LOG_MIDI_IN 0

#define REFRESH_MIDI_DEVICES_TIMER_INTERVAL_MS 1000  // Set to 0 to disable the timer
#define MIDI_IN_SAME_CC_TIME_THRESHOLD_MS 25

#define DDRM_PRESET_NUM_BYTES 98
#define DDRM_VOICE_NUM_BYTES 26

#define EMPTY_PRESET_SUM_THRESHOLD 5.0
#define EMPTY_PRESET_SUM_UPPER_THRESHOLD 999999.0  // Not really used in JF Sebast

#define ACTION_LOAD_TS_SOLUTION "ACTION_LOAD_TS_SOLUTION:"
#define ACTION_SET_IS_COMPUTING_TS_SOLUTION "ACTION_SET_IS_COMPUTING_TS_SOLUTION:"
#define ACTION_LOAD_SELECTED_POINT_DATA "ACTION_LOAD_SELECTED_POINT_DATA:"
#define ACTION_REPAINT "ACTION_REPAINT:"
#define ACTION_LOAD_INTERPOLATED_PRESET "ACTION_LOAD_INTERPOLATED_PRESET:"
#define ACTION_SET_TONE_SELECTOR_BUTTONS_ROW1_OFF "ACTION_SET_TONE_SELECTOR_BUTTONS_ROW1_OFF:"
#define ACTION_SET_TONE_SELECTOR_BUTTONS_ROW2_OFF "ACTION_SET_TONE_SELECTOR_BUTTONS_ROW2_OFF:"
#define ACTION_SET_TONE_SELECTOR_BUTTONS_ROW1 "ACTION_SET_TONE_SELECTOR_BUTTONS_ROW1"
#define ACTION_SET_TONE_SELECTOR_BUTTONS_ROW2 "ACTION_SET_TONE_SELECTOR_BUTTONS_ROW2"
#define ACTION_SET_TS_SLIDERS_OUT_OF_SYNC "ACTION_SET_TS_SLIDERS_OUT_OF_SYNC:"
#define ACTION_SET_TS_SLIDERS_IN_SYNC "ACTION_SET_TS_SLIDERS_IN_SYNC:"
#define ACTION_SET_TS_XY_TO_PRESET_NUMBER "ACTION_SET_TS_XY_TO_PRESET_NUMBER:"
#define ACTION_SET_CURRENT_PRESET_NAME "ACTION_SET_CURRENT_PRESET_NAME:"
#define ACTION_SET_CURRENT_PRESET_NAME_OUT_OF_SYNC "ACTION_SET_CURRENT_PRESET_NAME_OUT_OF_SYNC:"
#define ACTION_SET_CURRENT_PRESET_NAME_IN_SYNC "ACTION_SET_CURRENT_PRESET_NAME_IN_SYNC:"
#define ACTION_CURRENT_PRESENT_SAVED_TO_BANK "ACTION_CURRENT_PRESENT_SAVED_TO_BANK"
#define ACTION_BANK_FILE_LOADED "ACTION_BANK_FILE_LOADED:"
#define ACTION_UPDATED_MIDI_DEVICE_SETTINGS "ACTION_UPDATED_MIDI_DEVICE_SETTINGS:"
#define ACTION_REFRESH_MIDI_DEVICE_LISTS "ACTION_REFRESH_MIDI_DEVICE_LISTS:"
#define ACTION_UPDATE_UI_SCALE_FACTOR "ACTION_UPDATE_UI_SCALE_FACTOR:"
#define ACTION_MIDI_ENABLE_AUTO_SCAN "ACTION_MIDI_ENABLE_AUTO_SCAN"
#define ACTION_MIDI_DISABLE_AUTO_SCAN "ACTION_MIDI_DISABLE_AUTO_SCAN"
#define ACTION_MIDI_TRIGGER_DEVICE_SCAN "ACTION_MIDI_TRIGGER_DEVICE_SCAN"

#define PRESET_NAME_DEFAULT_TEXT "-"
#define PRESET_NAME_MODIFIED_TEXT "*"
#define PRESET_NAME_PREFIX "#"

#define EMPTY_TONE_SELECTOR_NAME  ""

#define DDRM_PARAMETER_ID_PREFIX "DDRM_"
#define SPACE_X_PARAMETER_ID "space_x"
#define SPACE_X_PARAMETER_NAME "Space X"
#define SPACE_Y_PARAMETER_ID "space_y"
#define SPACE_Y_PARAMETER_NAME "Space Y"
#define MIN_MILLISECONDS_BETWEEN_TIMBRE_SPACE_UPDATES 10
#define MIN_MILLISECONDS_FOR_MOUSE_DRAG_UPDATE 0

#define CS80COLOR_YELLOW 0xFFfffa0c
#define CS80COLOR_WHITE 0xFFfafafa
#define CS80COLOR_RED 0xFFff221e
#define CS80COLOR_GREEN 0xFF047c54
#define CS80COLOR_BLACK 0xFF000000
#define CS80COLOR_GREY 0xFFe6e6e6

#define STATE_MAIN_STATE_IDENTIFIER "DDRMState"

#define STATE_AUDIO_PARAMETERS_IDENTIFIER "DDRMAudioParameters"

#define STATE_UI_SCALE_FACTOR "UISacleFactor"

#define STATE_PRESET_BANK_IDENTIFIER "DDRMPresetBank"
#define STATE_PRESET_IDENTIFIER "DDRMPreset"
#define STATE_PRESET_BYTES_IDENTIFIER "bytes"
#define STATE_PRESET_IDX_IDENTIFIER "id"
#define STATE_BANK_FILENAME_IDENTIFIER "filename"
#define STATE_CURRENT_PRESET_IDX "currentPresetIdx"
#define STATE_CURRENT_PRESET_OUT_OF_SYNC "currentPresetOutOfSyncWithSliders"

#define STATE_TIMBRE_SPACE_IDENTIFIER "TimbreSpace"
#define STATE_TIMBRE_SPACE_SELECTED_POINT_X_IDENTIFIER "selectedPointX"
#define STATE_TIMBRE_SPACE_SELECTED_POINT_Y_IDENTIFIER "selectedPointY"
#define STATE_TIMBRE_SPACE_SELECTED_TRIANGLE_IDX_IDENTIFIER "selectedTriangleIdx"
#define STATE_TIMBRE_SPACE_SELECTED_PRESET_IDX_IDENTIFIER "selectedPresetIdx"
#define STATE_TIMBRE_SPACE_OUT_OF_SYNC "synthSlidersOutOfSync"

#define STATE_SELECTED_TONE_SELECTOR_ROW1 "toneSelectorRow1"
#define STATE_SELECTED_TONE_SELECTOR_ROW2 "toneSelectorRow2"

#define STATE_NEVER_SHOW_SCROLLBARS "neverShowScrollbars"

#define STATE_MIDI_OUTPUT_DEVICE_NAME "midiOutputDeviceName"
#define STATE_MIDI_INPUT_DEVICE_NAME "midiInputDeviceName"
#define STATE_MIDI_INPUT_CHANNEL "midiInputChannel"
#define STATE_MIDI_OUTPUT_CHANNEL "midiOutputChannel"
#define STATE_MIDI_AUTOSCAN_ENABLED "midiDevicesAutoScanEnabled"

#define TIMBRE_SPACE_SOLUTION_IDENTIFIER "TimbreSpaceSolution"
#define TIMBRE_SPACE_SOLUTION_POINTS_IDENTIFIER "solutionPoints"
#define TIMBRE_SPACE_SOLUTION_POINT_IDENTIFIER "solutionPoint"
#define TIMBRE_SPACE_SOLUTION_TRIANGLES_IDENTIFIER "solutionTriangles"
#define TIMBRE_SPACE_SOLUTION_TRIANGLE_IDENTIFIER "solutionTriangle"

#define MENU_OPTION_ID_IMPORT_FROM_PATCH_FILE 1
#define MENU_OPTION_ID_IMPORT_FROM_VOICE_FILE_TO_VOICE_1 2
#define MENU_OPTION_ID_IMPORT_FROM_VOICE_FILE_TO_VOICE_2 3

#define MENU_OPTION_ID_SAVE_PATCH_TO_PATCH_FILE 4
#define MENU_OPTION_ID_SAVE_VOICE_1_TO_VOICE_FILE 5
#define MENU_OPTION_ID_SAVE_VOICE_2_TO_VOICE_FILE 6

#define MENU_OPTION_ID_SEND_PATCH_TO_SYNTH 7
#define MENU_OPTION_ID_SEND_VOICE_1_TO_SYNTH 8
#define MENU_OPTION_ID_SEND_VOICE_2_TO_SYNTH 9

#define MENU_OPTION_ID_COPY_VOICE_1_TO_VOICE_2 10
#define MENU_OPTION_ID_COPY_VOICE_2_TO_VOICE_1 11
#define MENU_OPTION_ID_SWAP_VOICES 12

#define MENU_OPTION_ID_RANDOMIZE_PATCH_5_ID 13
#define MENU_OPTION_ID_RANDOMIZE_PATCH_10_ID 14
#define MENU_OPTION_ID_RANDOMIZE_PATCH_25_ID 15
#define MENU_OPTION_ID_RANDOMIZE_PATCH_50_ID 16
#define MENU_OPTION_ID_RANDOMIZE_VOICE_1_5_ID 17
#define MENU_OPTION_ID_RANDOMIZE_VOICE_1_10_ID 18
#define MENU_OPTION_ID_RANDOMIZE_VOICE_1_25_ID 19
#define MENU_OPTION_ID_RANDOMIZE_VOICE_1_50_ID 20
#define MENU_OPTION_ID_RANDOMIZE_VOICE_2_5_ID 21
#define MENU_OPTION_ID_RANDOMIZE_VOICE_2_10_ID 22
#define MENU_OPTION_ID_RANDOMIZE_VOICE_2_25_ID 23
#define MENU_OPTION_ID_RANDOMIZE_VOICE_2_50_ID 24
#define MENU_OPTION_ID_RANDOMIZE_PATCH_100_ID 25
#define MENU_OPTION_ID_RANDOMIZE_VOICE_1_100_ID 26
#define MENU_OPTION_ID_RANDOMIZE_VOICE_2_100_ID 27

#define MENU_OPTION_ID_ZOOM_50 28
#define MENU_OPTION_ID_ZOOM_75 29
#define MENU_OPTION_ID_ZOOM_100 30
#define MENU_OPTION_ID_ZOOM_60 31
#define MENU_OPTION_ID_ZOOM_70 32
#define MENU_OPTION_ID_ZOOM_80 33
#define MENU_OPTION_ID_ZOOM_90 34

#define MENU_OPTION_MIDI_SET_AUTOSCAN_ON 35
#define MENU_OPTION_MIDI_SET_AUTOSCAN_OFF 36
#define MENU_OPTION_MIDI_SCAN_NOW 37

#define MENU_OPTION_TOGGLE_NEVER_SHOW_SCROLLBARS 100

#define DIMENSIONALITY_REDUCTION_METHOD_PCA "pca"
#define DIMENSIONALITY_REDUCTION_METHOD_TSNE "tsne"
#define DIMENSIONALITY_REDUCTION_METHOD_MDS "mds"
#define DIMENSIONALITY_REDUCTION_METHOD_DEFAULT DIMENSIONALITY_REDUCTION_METHOD_MDS


typedef std::array<uint8, DDRM_VOICE_NUM_BYTES> DDRMVoiceBytes;
typedef std::array<uint8, DDRM_PRESET_NUM_BYTES> DDRMPresetBytes;
typedef std::pair<String, double> SynthControlIdValuePair;
typedef std::vector<SynthControlIdValuePair> SynthControlIdValuePairs;

typedef std::vector<std::vector<float>> timbreSpaceInputDataMatrix;

struct PresetDistanceStruct {
    int presetIdx;
    float presetDist;
    float presetWeight;  // Number that will be multiplied to the preset value to do the interpolation
};
typedef std::vector<PresetDistanceStruct> PresetDistancePairsToInterpolate;

typedef std::array<int64, 129> TimestampsLastCCSent; // Use 129 positions instead of 128 to not crash if using 1-indexed MIDI CC numbers (see docs in DdrmtimbreSpaceAudioProcessor::handleIncomingMidiMessage)
