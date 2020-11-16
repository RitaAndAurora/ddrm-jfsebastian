# J.F. Sebastian - User Manual


## Table of contents


  * [Overview](#overview)
  * [1. Installation](#1-installation)
     * [1.1 Compatibility notes](#11-compatibility-notes)
     * [1.2 Release notes](#12-release-notes)
  * [2. Using J.F. Sebastian](#2-using-jf-sebastian)
     * [2.1 Loading J.F. Sebastian as an audio plugin](#21-loading-jf-sebastian-as-an-audio-plugin)
     * [2.2 MIDI configuration](#22-midi-configuration)
        * [2.2.1 MIDI input](#221-midi-input)
        * [2.2.2 MIDI output](#222-midi-output)
        * [2.2.3 Automatic scanning of MIDI devices](#223-automatic-scanning-of-midi-devices)
     * [2.3 Bank file loader](#23-bank-file-loader)
        * [2.3.1 Loading a bank file](#231-loading-a-bank-file)
        * [2.3.2 Saving the current patch to a specific bank location](#232-saving-the-current-patch-to-a-specific-bank-location)
        * [2.3.3 Saving the bank file](#233-saving-the-bank-file)
     * [2.4 The Timbre Space](#24-the-timbre-space)
     * [2.5 CS80-like Tone Selector](#25-cs80-like-tone-selector)
     * [2.6 DDRM panel](#26-ddrm-panel)
     * [2.7 DDRM panel lower buttons](#27-ddrm-panel-lower-buttons)
     * [2.8 The Randomizer](#28-the-randomizer)
     * [2.9 UI size](#29-ui-size)
  * [3. Known bugs and limitations](#3-known-bugs-and-limitations)
  * [4. Licensing](#4-licensing)
  * [5. Credits and acknowledgements](#5-credits-and-acknowledgements)
  * [6. Support J.F. Sebastian development](#6-support-jf-sebastian-development)



## Overview

J. F. Sebastian, named after a former [genetic designer](https://bladerunner.fandom.com/wiki/J.F._Sebastian) of the [Tyrell Corporation](https://bladerunner.fandom.com/wiki/Tyrell_Corporation), provides new ways to control and explore the sonic possibilities of the [Deckard's Dream](https://www.deckardsdream.com) synthesiser (DDRM). It works both as a **stand-alone app** and as an **audio plug-in**.

The DDRM is an awesome synthesizer designed by [Black Corporation](http://black-corporation.com) in Japan and inspired by the all mighty [Yamaha CS80](https://reverbmachine.com/blog/exploring-the-yamaha-cs-80). If you're reading this... you most probably know all about it :)

J.F. Sebastian interfaces with the DDRM and turns its sliders into audio plugin parameters that can be *modulated and automated* from your DAW. With J.F. Sebastian you can import DDRM bank files, edit patches and export them. When you import a bank file, a *Timbre Space* will be created which will allow you to navigate all the patches in a colorful space and create new ones. J.F. Sebastian also includes a *CS80-like tone selector* that allows you to use the original presetting system of the CS80 in the DDRM.

Here is a screenshot of J.F. Sebastian with the different parts of the interface highlighted. The sections below describe each one of them.

<p align="center">
<img src="docs/screenshot_highlighted.png"  width="700px" />
</p>

## 1. Installation

Installation of J.F. Sebastian should be straight-forward as we provide installer packages which should place all the files in the corresponding locations. Here are the steps to follow:

 1. Go to the [J.F. Sebastian download page](http://github.com/ritaandaurora/ddrm-jfsebastian/releases) and get the **macOS** or **windows** installer (depending on your platform).
 2. Run the installer and click `next`/`continue` buttons until installation finishes. We recommend you to use the default installation options. The installer will copy files in the following locations:

 *macOS*
 
  * Stand-alone app: `/Applications/`
  * VST2: `/Library/Audio/Plug-Ins/VST/`
  * VST3: `/Library/Audio/Plug-Ins/VST3/`
  * AU: `/Library/Audio/Plug-Ins/Components/`

 *windows*
 
  * Stand-alone app: `c:\Program Files (x86)\JFSebastian\`
  * VST2: `c:\Program Files (x86)\Common Files\VST2\`
  * VST3: `c:\Program Files (x86)\Common Files\VST3\`

 3. Run the stand-aloone app from the directory it has been installed or either open your favorite DAW. J.F. Sebastian should appear in the list of available plugins. If that is not the casem you might need to trigger a *re-scanning* of the plugins folder by the DAW. If after doing that J.F. Sebastian still does not appear, make sure your DAW is looking for plugins in the default locations listed above.


### 1.1 Compatibility notes

 * J.F. Sebastian should be compatibale with all major DAWs supporting either Audio Units (**AU**) or **VST2/VST3** plugins. 
 * Note that J.F. Sebastian is **64-bit** so it might not work with old versions of DAWs. 
 * We did not compile an **AAX** version of the plugin, but if users request it (please use our [issue tracker](https://github.com/ritaandaurora/ddrm-jfsebastian/issues)) we will consider adding it.
 * We have successfully tested J.F. Sebastian in the setups listed below. Other setups should work as well but we have not tested them.
   * macOS (10.14) / Stand-alone
   * macOS (10.14) / Bitwig Studio 2/3
   * macOS (10.14) / Logic Pro X
   * macOS (10.14) / Live 10
   * windows 10 / Stand-alone
   * windows 10 / Bitwig Studio 3

### 1.2 Release notes

**Version 1.2**

 * Improved the way patches are interpolated when using the Timbre Space. Now when you select points in the space which correspond to specific patches, these should sound much more similar to the patches themselves.
 * Fix MIDI devices bug which would render some MIDI interfaces unselectable in some complex studio setups.
 * Add `View...` button to the lower-right corner of J.F. Sebastian.
 * Improved rendering of scaled UI sizes (including new 60% option).
 * Added scrolling option to UI.
 * Several internal improvements and optimizations.


**Version 1.1**

 * Improved labeling of some controls so A, D, S, R don't get confused in the plugin parameter list shown by plugin hosts.
 * Corrected value shown of inverted controls in the performance section so these show 0.0 when set at the top and 10.0 when set at the bottom.
 * Added VST2 compatibility for Windows and macOS.
 * Added option to scale UI at 70%, 80%, 90% and 100% to better fit in smaller screens. Use the `Zoom...` button in the lower right corener of J.F. Sebastian's window.
 * Added option to turn on and off auto-scanning of MIDI devices. Auto-scanning of MIDI devices seemed to be problematic in some setups and would automatically diconnect DDRM USB device when selected in MIDI OUT. Now this feature can be disabled so that device does not get disconnected.
 * Compensate for bug in DDRM firmware which makes SQR and SAW buttons on channel II to send wrong MIDI CC numbers. This caused some problems when MIDI IN was enabled in J.F. Sebastian which now have been fixed.
 * Fix memory leak in handling MIDI interfaces (nerd stuff, not very relevant for end users).



## 2. Using J.F. Sebastian

### 2.1 Loading J.F. Sebastian as an audio plugin

J.F. Sebastian can run as a **stand-alone application** or as an **audio plugin** inside your DAW. When running as an audio plugin it works as an **audio effect** but effectively acts as a *bypass effect* for all the audio received in the input (i.e. it passes the input audio to the output and leaves it unaffected). The typical setup is to create a *MIDI/external instrument* track in your DAW which routes MIDI to the DDRM and receives the audio signal from DDRM. In that track J.F. Sebastian can be placed as an effect.

The good side of loading J.F. Sebastian as a plugin is that it allows the DAW to control DDRM's parameters, enabling **parameter automation** and any other sort of **modulation capabilities** offered by the DAW.


### 2.2 MIDI configuration

J.F. Sebastian communicates with DDRM over MIDI. When loaded as an audio plugin it acts as an intermediary between the DAW and DDRM, exposing DDRM sliders as audio parameters of the plugin and then modifying them accordingly using MIDI *control change* messages.

The MIDI configuration section includes dropdowns for configuring the MIDI **input/output devices** as well the **MIDI channels** to communicate with DDRM. Note that when loaded as a plugin, J.F. Sebastian's MIDI configuration is **completely independent from the DAW MIDI configuration** of the channel where J.F. Sebastian is loaded. Therefore in bypasses the MIDI in/out of the channel and only sends/receives from its own devices and channels.

#### 2.2.1 MIDI input

MIDI input is used to receive MIDI data from the DDRM which allows to update the slider values when sliders are moved in the real hardware unit. **MIDI input configuration is optional** as J.F. Sebastian can operate without it.

To configure MIDI input please select the device from the dropdown menu to which DDRM is sending messages. If your DDRM is connected over USB, you should see a device named **Deckard's Dream**. You also need to select the MIDI channel where DDRM sends the messages.

#### 2.2.2 MIDI output

MIDI output is used to send MIDI data to the DDRM and control its sliders *remotely*. **MIDI output configuration is mandatory** as otherwise J.F. Sebastian has no way to communicate with the DDRM.

To configure MIDI output please select the device from the dropdown menu that will send messages to DDRM. If your DDRM is connected over USB, you should see a device named **Deckard's Dream**. You also need to select the MIDI channel where DDRM is listening.

Note that J.F. Sebastian only sends MIDI *control change* messages to the DDRM and does not handle any other kind of MIDI data. To send *note on/off* messages to the DDRM you need to configure the routing independently of J.F. Sebastian.

Note also that for J.F. Sebastian to work, **DDRM needs to have "CC receive" option enabled**. You'll find that option in the MIDI settings menu of DDRM.


#### 2.2.3 Automatic scanning of MIDI devices

J.F. Sebastian will continuously check if new MIDI devices are connected or disconnected from your computer to updated the options of the lists of available devices for MIDI input and output. This allows to connect MIDI devices while J.F. Sebastian is already runnning and have them avialalbe in the menus. However, it has been reported that in some situations this feature causes devices to disconnect and not work properly with J.F. Sebastian. For this reason, as of version 1.1 we introduced a new feature that will allow to **enable or disable the automatic scanning of MIDI devices**.

To enable or disable automatic scanning of midi devices click on the `Settings...` button on the lower-right corner of J.F. Sebastian, and choose the `MIDI device scan` option. An option named `Auto-scan MIDI devices` will appear ticked (&#10003;) if automatic scanning is enabled. Click on that option to toggle it. Additionally, only when `Auto-scan MIDI devices` is disabled, an extra option named `Scan devices now` will appear enabled. Click on that to trigger a *one-time* update of the currently available MIDI devices.


### 2.3 Bank file loader

#### 2.3.1 Loading a bank file

Use the `Load bank file...` button to load a DDRM bank file (file extension *.p*). Bank files contain up to 128 patches. Once loaded, you can use the left and right arrow buttons to navigate among the existing patches. You can also type the patch number you want to go to by clicking on the patch number. By default, J.F. Sebastian loads the official **factory patches** provided by Black Corporation.

When a bank file is loaded, a new Timbre Space is built based on all the patches contained in the bank (more info in [Section 2.4](#24-the-timbre-space)).

When navigating the different patches of a bank, you'll see how both the sliders on the screen and the sound of the DDRM change according to the selected patch. You'll also see how the selected point in the Timbre Space moves at each patch change. This indicates the point in the Timbre Space that corresponds to the selected patch (more info in [Section 2.4](#24-the-timbre-space)).

Finally, note that if any parameter changes its value after loading a specific patch, the symbol * appears next to the patch number to indicate that the sliders are no longer *in sync* with the stored values of that patch.

#### 2.3.2 Saving the current patch to a specific bank location

Use the `Save to bank location...` button to save the current patch (the slider values shown in the DDRM panel in J.F. Sebastian) to another location in the bank. When pressing the button a dialog will appear asking you to introduce the bank location to which the patch should be saved. This operation will overwrite any existing patch information in that location.


#### 2.3.3 Saving the bank file

With J.F. Sebastian it is possible to export all the patches into a new bank file and save it to disk. You can do that by pressing the `Save bank file...` button and specifying the location where the bank file should be saved. If not specified, the file extension *.p* will be automatically added to the filename.

The bank files generated by J.F. Sebastian can be copied to the DDRM drive and DDRM will be able to read them. Note that when loading patches from J.F. Sebastian all non-MIDI-controllable parameters are ignored. However, when loading the bank file directly in DDRM any extra patch settings that might be stored in the file will be loaded as well. Check the [limitations](#3-known-bugs-and-limitations) section of this manual for more information about this issue.



### 2.4 The Timbre Space

The Timbre Space is an innovative feature of J.F. Sebastian that allows to **explore the sonic possibilities of DDRM in completely new ways**. Every time a bank file is loaded, J.F. Sebastian creates a new Timbre Space which projects all the presents of that bank file into a *colorful* 2-dimensional space. **Simply click anywhere in the Timbre Space to generate new patches for DDRM**. Here you can see a [video of the Timbre Space in action](https://youtu.be/cHdO393UwKI?t=44).

The Timbre Space uses **machine learning** to analyze the distribution of parameters values in a given bank file and to create a 2-dimensional representation of it in which patches are organized according to *some notion of similarity*. Here are some examples of spaces created using different DDRM bank files:

<p align="center">
<img src="docs/tsA.png" width="500px" />
<img src="docs/tsB.png" width="500px" />
<img src="docs/tsC.png" width="500px" />
<img src="docs/tsD.png" width="500px" />
</p>

The Timbre Space contains a triangle mesh in which each triangle edge corresponds to the position of one of the bank's patches after its projection into the 2-dimensional space. Clicking on any point in the space will create a new patch based on the 3 patches of the enclosing triangle. **Close points in the Timbre Space are expected to produce similar sounding patches**.

<p align="center">
<img src="docs/ts_highlighted.png" width="300px" />
</p>

When selecting a point in the space, the patch numbers in which the new patch is based are displayed on screen (see picture above). If any of DDRM controls is changed after a specific point of the Timbre Space is loaded, the patch numbers on screen will disappear to indicate that the slider values are no longer *in sync* with the values of the selected Timbre Space position.

The selected position in the Timbre Space is also exposed by J.F. Sebastian as two **audio parameters** named **Space X** and **Space Y**. These parameters can also be automated. 


### 2.5 CS80-like Tone Selector

<p align="center">
<img src="docs/tone_selector.png" width="600px" />
</p>


J.F. Sebastian incorporates a tone selector similar to the one that the original CS80 incorporated. The upper row of the tone selector will affect DDRM's channel I parameters, while the lower row will affect channel II. Only one button per row at a time can be selected. Simply click on the buttons of the upper row and lower row to configure slider positions for channel I and II respectively. Here you can see a [video of the Tone Selector in action](https://youtu.be/cHdO393UwKI?t=128).

When a button is selected it will be highlighted. However, if any parameter is changed after the button is selected, it will become *unselected* again to indicate that the slider values are no longer *in sync* with the expected values for channel I or channel II button.

Note that `Funky 4` button in the lower row does not work. Maybe there's some dust accumulated which should be cleaned...


### 2.6 DDRM panel

<p align="center">
<img src="docs/ddrm_panel.png" width="700px" />
</p>

J.F. Sebastian has a *virtual* representation of DDRM's hardware controls in the form of nice rounded sliders. The controls are laid down in the same way as in the hardware unit. Control names are not directly visible on screen, but are shown in a popup when hovering  over the controls with the mouse.

If MIDI output is properly configured, moving the sliders in J.F. Sebastian will control the corresponding sliders in the DDRM hardware unit. Similarly, if MIDI input is properly configured, moving the sliders in the hardware unit will cause the sliders in J.F. Sebastian interface to move.

All sliders and buttons are exposed as **audio parameters** to the DAW, meaning that their movement can be **recorded**, **automated** and **modulated** if the DAW has such capabilities. Here is a [video example of parameter modulation and automation](https://youtu.be/cHdO393UwKI?t=170) usig J.F. Sebastian and [Bitwig Studio](https://www.bitwig.com) (a great DAW you shoudl check out!). **Warning**: it is possible to record/automate the position in the timbre space using the parameters `Space X` and `Space Y`; when doing that take into account that these will make all other audio parameters to change therefore it is not advised to record/automate timbre space position plus other parameters at the same time.

Double-clicking the sliders will set them to the center position.

Note that the panel incorporates two extra controls in the lower-right side - `Sustain time` and `Sustain mode` - which are not in the hardware unit. These are additional MIDI-controllable parameters that are only included as hardware controls in the DDRM expander. 


### 2.7 DDRM panel lower buttons

J.F. Sebastian incorporates a number of features to **edit and manage the slider values** which can be accessed using the buttons below the DDRM sliders. Here is an explanation of what these do:

 * `Import...`: use this button to load a DDRM patch from either a *patch* file or a *voice* (channel) file. These file types store individual patches and voices respectively (instead of the whole contents of a bank file). *patch* and *voice* files are compatible with [Spektroaudio's DDRM editor](http://spektroaudio.com/deckards-dream-editor) and with [Ando's DDRM editor](https://drive.google.com/file/d/1xMHwV3TBTWAK5WPEw8NV0F6aiztP5ZnF/view?fbclid=IwAR2PQ81T-RIw0eQ8rtDKhi9R42i6s5xhgJjm-TmtUaHYMLSERUbs9Iirk3c) as well. Clicking the button will display a menu with the following options:
   *  `From patch file`: will open a dialog to select the *patch* file you want to load. Patch files have extension *.ddpatch*. Patch files contain parameter settings for both channels of DDRM plus the performance controls section.
   *  `From voice file to channel I/II`: will open a dialog to select the *voice* file you want to load in the chosen channel (I or II). Patch files have extension *.ddvoice*. Voice files contain parameter settings for a single DDRM channel controls.

 * `Save...`: use this button to store the current DDRM patch into a *patch* file or a *voice* file (see menu option above more more information). Clicking the button will display a menu with the following options:
   *  `To patch file`: will open a dialog in which the filename of the *patch* file to save can be specified. The *patch* file will store both channel settings and the performance controls of the current patch.
   *  `Channel I/II to voice file`: will open a dialog in which the filename of the *voice* file to save can be specified. The *voice* file will store the settings of the selected channel of the current patch.

 * `Copy...`: use this button to copy control settings from DDRM channels. Clicking the button will display a menu with the following options:
   *  `From channel I to channel II`: copy the slider settings from channel I to channel II.
   *  `From channel II to channel I`: copy the slider settings from channel II to channel I.
   *  `Swap channels`: swap slider settings of both channels.

 * `Randomize!`: use this button to add some randomization to the slider values of the current patch. See [The Randomizer](#28-the-randomizer) section below for more information about that option.

* `Send to synth...`: use this button to synchronize the DDRM with the slider values of J.F. Sebastian. Note that when navigating patches, using the Timbre Space, the tone selector, or when moving sliders in J.F. Sebastian, DDRM is also updated accordingly and there is no need to *manually* send values to the synth. however, in some occasions it might be useful to re-send all control values to DDRM to make sure it is in sync.  Clicking the button will display a menu with the following options:
   *  `Patch`: send values corresponding to the full patch (both channels and performance section).
   *  `Channel I/II`: send only the values of the selected channel.

### 2.8 The Randomizer

J.F. Sebastian incorporates a feature to create slight (or wild!) variations of the currently loaded patch. This is called the **Randomizer**. Clicking on the `Randomize!` button in the lower part of the interface will instantly create a variation of the current patch. Using the `Settings...` button on the lower right side of J.F. Sebastian and chosing the `Randomizer settings` menu you can set some options to decide how the Randomizer will change the patch:

* `Affected controls`: using that menu option you can select which controls will be affected by the Randomizer when pressing the `Randomize!` button. You can enable or disable the controls of Channel I, Channel II and the performance controls section.

* `Amount`: using that menu you can choose how much will each parameter be randomized when pressing the `Randomize!` button. Range goes from 5% (small variation with respect to the current parameter value) to 100% (completely new random value). 

Randomizer settings are stored with J.F. Sebastian's internal state and will be remembered between J.F. Sebastian runs.



### 2.9 UI size

J.F. Sebastian incorporates an option to adjust the size of the UI to match smaller screens. You can adjust the size clicking in the `Settings...` button in the upper-right corner of J.F. Sebastian and selecting the `Zoom` sub-menu. Available options are 60%, 70%, 80%, 90% and 100% of the original size. The zoom preference is stored togeether with other J.F. Sebastian properties so the preference is remembered in different runs of the app both running as stand-alone or as a plugin.

Furthermore, J.F. Sebastian can scroll the UI horizontally or vertically if it does not fit all on the screen. If that is the case, scrollbar(s) will appear. You can choose to hide scrollbars (but still be able to scroll using the mouse) by ticking the `Hide scrollbars` option in the `View...` menu.


## 3. Known bugs and limitations

What follows is a list of known J.F. Sebastian bugs and limitations of the software. Please, for **bug reports** and **feature requests** visit [https://github.com/ritaandaurora/ddrm-jfsebastian/issues](https://github.com/ritaandaurora/ddrm-jfsebastian/issues).

 * J.F. Sebastian uses MIDI to communicate with DDRM and update its parameter values. However, as of firmware version 1.3.0, **not all parameters in DDRM are currently controllable via MIDI**. All the sliders and buttons in the front panel can be controlled via MIDI, but not other *hidden* parameters like envelope ranges, etc. What this means in practice is that loading patches from J.F. Sebastian **might not produce the exact same results** than loading them from the bank files copied in DDRM because the hidden controls can't be updated. Hopefully future updates of DDRM firmware will allow full MIDI control so that J.F. Sebastian (and other tools) can be updated accordingly.
 
 * **DDRM firmware does not implement any method for dumping bank or slider values over MIDI**. Therefore, J.F. Sebastian has no way of knowing what's the current slider values in DDRM and displaying them. Hopefully this will be addressed in future DDRM firmware update and J.F. Sebastian updated accordingly :)

 * Communication with DDRM is **limited to the speed at which MIDI messages can be transmitted**. Automation and modulation of parameters is therefore subject to that. We did some testing and the message throughput seems to be quite good, specially using MIDI over USB, but still that could be a limitation for very fast modulations.

 * DDRM is very sensitive to MIDI in-out loops and MIDI control might not work properly if the messages that DDRM sends are put back into its input. J.F. Sebastian avoid creating such loops when both MIDI input and MIDI output are configured, but it can easily happen (it indeed happened to me!) that a feedback loop is created by mistake in the DAW. If you observe strange behaviour in J.F. Sebastian controlling DDRM (specially if some buttons in the tone selector section do not seem to work), **make sure you have not accidentally created a MIDI feedback loop**.   

 * When using J.F. Sebastian in stand-alone mode, it could happen that a **warning is displayed about potential audio feedback loops**. This is can be solved by clicking on the `Settings...` button that will appear next to the warning and unticking the *Mute audio input* checkbox. J.F. Sebastian will remember this choice so the warning is not displayed again. This is a bug that will be addressed in future updates of J.F. Sebastian as J.F. Sebastian uses no audio and the warning should never appear.

 * In some particular setups, **Deckard's Dream USB interface can't be selected in MIDI IN/OUT settings**. The device is correctly listed but when selected it gets unselected again. This was a bug **fixed in J.F. Sebastian v1.2**. Please make sure your app/plugins are updated.
 
 * Some users reported **issues using J.F. Sebastian as a plugin in Reaper and under Windows**. This is because MIDI devices are "locked" by the Reaper process and J.F. Sebastian can't talk directly to DDRM. This can be fixed by configuring J.F. Sebastian to `Run as > Separate process` as in the screenshot below. Many thanks to David Berndsen for the tip (and the screenshot)!
 
<p align="center">
<img src="docs/jf_settings_reaper_windows.png" width="800px" />
</p>


## 4. Licensing

J.F. Sebastian is released under the **GPLv3** open source software license (see [LICENSE](https://github.com/ritaandaurora/ddrm-jfsebastian/blob/master/LICENSE) file) with the code being available at  [https://github.com/ritaandaurora/ddrm-jfsebastian](https://github.com/ritaandaurora/ddrm-jfsebastian). J.F. Sebastian uses the following open source software libraries: 

 * [tapkee](http://tapkee.lisitsyn.me), available under BSD 3-clause license 
 * [delaunator-cpp](https://github.com/delfrrr/delaunator-cpp), available underMIT license
 * [juce](https://juce.com), available under GPLv3 license 
 
J.F. Sebastian uses some fonts released under open licenses as well:

 * [roboto](https://fonts.google.com/specimen/Roboto), available under Apache 2 license
 * [modenine](https://www.dafont.com/modenine.font), available under custom "freely distributable" license (see license file in `Resources/fonts`)
 * [blade runner](https://www.dafont.com/blade-runner-movie-font.font), tagged as "100% free" font



## 5. Credits and acknowledgements

J.F. Sebastian has been ideated and developed by [Rita & Aurora](https://ritaandaurora.github.io), a sort of fancy branding name I've given to my audio-developer [self](https://ffont.github.io).

Enormous thanks to Paul Shilling for creating the great CS80 presets bank that has been used for the tone selector. Also thanks to Black Corporation for making such a great synth!


## 6. Support J.F. Sebastian development

If you want to support the development of J.F. Sebastian and similar tools you can consider [making a donation](https://ritaandaurora.github.io/ddrm-jfsebastian/donate). That will make me very happy :)

<br>
<br>
<p align="center">
<img src="docs/Rita&AuroraAudioLogo-square.png" width="250" />
</p>
