# J.F. Sebastian - User Manual


## 1. Overview

J. F. Sebastian, named after a former genetic designer of the *Tyrell Corporation*, provides new ways to control and explore the sonic possibilities of the CS80-inspired Deckard's Dream synthesiser (DDRM). It works both as a **stand-alone app** and as an **audio plug-in**.

J.F. Sebastian interfaces with the DDRM and turns its sliders into audio plugin parameters that can be *modulated and automated* from your DAW. With J.F. Sebastian you can import DDRM bank files, edit patches and export them. When you import a bank file, a *timbre Space* will be created which will allow you to navigate all the presets in a colorful space and create new ones. J.F. Sebastian also includes a *CS80-like tone selector* that allows you to use the original presetting system of the CS80 in the DDRM.

Here is a screenshot of J.F. Sebastian with the different parts of the interface highlighted. The sections below describe each one of them.

<p align="center">
<img src="docs/screenshot_highlighted.png"  width="700px" />
</p>

## 2. Using J.F. Sebastian

### 2.1 Loading J.F. Sebastian as an audio plugin

J.F. Sebastian can run as a **stand-alone application** or as an **audio plugin** inside your DAW. When running as an audio plugin it works as an **audio effect** but effectively acts as a *bypass effect* for all the audio received in the input (i.e. it passes the input audio to the output and leaves it unaffected). The typical setup is to create a *MIDI/external instrument* track in your DAW which routes MIDI to the DDRM and receives the audio signal from DDRM. In that track J.F. Sebastian can be placed as an effect.

The good side of loading J.F. Sebastian as a plugin is that it allows the DAW to control DDRM's parameters, enabling **parameter automtation** and any other sort of **modulation capabilities** offered by the DAW.


### 2.2 MIDI configuration

J.F. Sebastian communicates with DDRM over MIDI. When loaded as an audio plugin it acts as an intermediary between the DAW and DDRM, exposing DDRM sliders as audio parameters of the plugin and then modifying them accordingly using MIDI *control change* messages.

The MIDI configuration section includes dropdowns for configuring the MIDI **input/output devices** as well the **MIDI channels** to communicate with DDRM. Note that when loaded as a plugin, J.F. Sebastian's MIDI configuration is **completely independent from the DAW MIDI configuration** of the channel where J.F. Sebastian is loaded. Therefore in bypasses the MIDI in/out of the channel and only sends/receives from its own devices and channels.

#### 2.2.1 MIDI input

MIDI input is used to receive MIDI data from the DDRM which allows to update the slider values when sliders are moved in the real hardware unit. **MIDI input configuration is optional** as J.F. Sebastian can opererate without it.

To configure MIDI input please select the device from the dropdown menu to which DDRM is sending messages. If your DDRM is connected over USB, you should see a device named **Deckard's Dream**. You also need to select the MIDI channel where DDRM sends the messages.

#### 2.2.2 MIDI output

MIDI output is used to send MIDI data to the DDRM and control its sliders *remotely*. **MIDI output configuration is mandatory** as otherwise J.F. Sebastian has no way to communicate with the DDRM.

To configure MIDI output please select the device from the dropdown menu that will send messages to DDRM. If your DDRM is connected over USB, you should see a device named **Deckard's Dream**. You also need to select the MIDI channel where DDRM is listening.

Note that J.F. Sebastian only sends MIDI *control change* messages to the DDRM and does not handle any other kind of MIDI data. To send *note on/off* messages to the DDRM you need to configure the routing independently of J.F. Sebastian.


### 2.3 Bank file loader

#### 2.3.1 Loading a bank file

Use the `Load bank file...` button to load a DDRM bank file (file extension *.p*). Bank files contain up to 128 presets. Once loaded, you can use the left and right arrow buttons to navigate among the existing presets. You can also type the preset number you want to go to by clicking on the preset number. By default, J.F. Sebastian loads the official **factory presets** provided by Black Corporation.

When a bank file is loaded, a new Timbre Space is built based on all the presets contained in the bank (more info in [Section 2.4](TODO:link)).

When navigating the different presets of a bank, you'll see how both the sliders on the screen and the sound of the DDRM change according to the selected preset. You'll also see how the selected point in the Timbre Space moves at each preset change. This indicates the point in the Timbre Space that corresponds to the selected preset (more info in [Section 2.4](TODO:link)).

Finally, note that if any parameter changes its value after loading a specific preset, the symbol * apprears next to the preset number to indicate that the sliders are no longer *in sync* with the stored values of that preset.

#### 2.3.2 Saving the current preset to a specific bank location

Use the `Save to bank location...` button to save the current preset (the slider values shown in the DDRM panel in J.F. Sebastian) to another location in the bank. When pressing the button a dialog will appear asking you to introduce the bank location to which the preset should be saved. This operation will overwrite any existing preset information in that location.


#### 2.3.3 Saving the bank file

With J.F. Sebastian it is possible to export all the presets into a new bank file and save it to disk. You can do that by pressing the `Save bank file...` button and specifying the location where the bank file should be saved. If not specified, the file extension *.p* will be automatically added to the filename.

The bank files generated by J.F. Sebastian can be copied to the DDRM drive and DDRM will be able to read them. Note that when loading presets from J.F. Sebastian all non-MIDI-controllable parameters are ignored. However, when loading the bank file directly in DDRM any extra patch settings that might be stored in the file will be loaded as well. Check the [limitations](TODO:link) section of this manual for more information about this issue.



### 2.4 The Timbre Space

<p align="center">
<img src="docs/tsA.png" width="500px" />
<img src="docs/tsB.png" width="500px" />
<img src="docs/tsC.png" width="500px" />
<img src="docs/tsD.png" width="500px" />
</p>


<p align="center">
<img src="docs/ts_highlighted.png" width="300px" />
</p>


### 2.5 CS80-like Tone Selector

<p align="center">
<img src="docs/tone_selector.png" width="600px" />
</p>


J.F. Sebastian incorportates a tone selector similar to the one that the original CS80 incorporated. The upper row of the tone selector will affect DDRM's channel I parameters, while the lower row will affect channel II. Only one button per row at a time can be selected. Simply click on the buttons of the upper row and lower row to configure slider positions for channel I and II respectively.

When a button is selected it will be highlighted. However, if any parameter is changed after the button is selected, it will become *unselected* again to indicate that the slider values are no longer *in sync* with the expected values for channel I or channel II button.

Note that `Funky 4` button in the lower row does not work. Maybe there's some dust accumulated which should be cleaned...


### 2.6 DDRM panel

<p align="center">
<img src="docs/ddrm_panel.png" width="700px" />
</p>

J.F. Sebastian has a *virtual* representation of DDRM's hardware controls in the form of nice rounded sliders. The controls are layed down in the same way as in the hardware unit. Control names are not directly visible on screen, but are shown in a popup when hovering  over the controls with the mouse.

If MIDI output is properly configured, moving the sliders in J.F. Sebastian will control the corresponding sliders in the DDRM hardware unit. Similarly, if MIDI input is properly configured, moving the sliders in the hardware unit will cause the sliders in J.F. Sebastian interface to move.

All sliders and buttons are exposed as **audio parameters** to the DAW, meaning that their movement can be **recorded**, **automated** and **modulated** if the DAW has such capabilities.

Double-clicking the sliders will set them to the center position.

Note that the pannel incorporates two extra controls in the lower-right side - `Sustain time` and `Sustain mode` - which are not in the hardware unit. These are additional MIDI-controllable parameters that are only included as hardware controls in the DDRM expander. 


### 2.7 DDRM panel lower buttons

J.F. Sebastian incorporates a number of features to **edit and manage the slider values** which can be accessed using the buttons below the DDRM sliders. Here is an explanation of what these do:

 * `Import...`: text text
   *  `From patch file`: text text
   *  `From voice file to channel I/II`: text text

 * `Save...`: text text
   *  `To patch file`: text text
   *  `Channel I/II to voice file`: text text

 * `Copy...`: text text
   *  `From channel I to channel II`: text text
   *  `From channel II to channel I`: text text
   *  `Swap channels`: text text

 * `Randomize...`: text text
   *  `Patch [5%-100%]`: text text
   *  `Channel I [5%-100%]`: text text
   *  `Channel II [5%-100%]`: text text

* `Send to synth...`: text text - no need to trigger this manually when navigating presets or moving controls, but to make sure DDRM is loaded with what's on J.F. Sebastian screen
   *  `Patch`: text text
   *  `Channel I`: text text
   *  `Channel II`: text text



## 3. Known bugs and limitations

- only MIDI controllable parameters, what happens to other options when exporting bank file for example?
- Add link to repository issues section
- add note about the MIDI IN->MIDI OUT loop to docs
- midi speed, so far experiment sshow good results
- juce feedback loop warning


## 4. Licensing

J.F. Sebastian is released under the **GPLv3** open source software license (see LICENSE file). J.F. Sebastian uses the following open source software libraries: 

 * [tapkee](http://tapkee.lisitsyn.me), available under BSD 3-clause license 
 * [delaunator-cpp](https://github.com/delfrrr/delaunator-cpp), available underMIT license
 * [juce](https://juce.com), available under GPLv3 license 
 
J.F. Sebastian uses some fonts released under open licenses as well:

 * [roboto](https://fonts.google.com/specimen/Roboto), available under Apache 2 license
 * [modenine](https://www.dafont.com/modenine.font), available under custom "freely distributable" license (see license file in `Resources/fonts`)
 * [blade runner](https://www.dafont.com/blade-runner-movie-font.font), tagged as "100% free" font



## 5. Credits and acknowledgements

J.F. Sebastian has been ideated and developed by [Rita & Aurora](https://ritaandaurora.github.io), a sort of fancy branding name I've given to my audio-developer [self](https://ffont.github.io).

Enormous thanks to Paul Shiling for creating the great CS80 presets bank that has been used for the tone selector. Also thanks to Black Corporation for making such a great synth!

<p align="center">
<img src="docs/Rita&AuroraAudioLogo-square.png" width="250" />
</p>
