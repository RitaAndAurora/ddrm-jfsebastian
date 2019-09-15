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

J.F. Sebastian can run as a **stand-alone application** or as an **audio plugin**.

### 2.2 MIDI configuration

J.F. Sebastian communicates with DDRM over MIDI. When loaded as an audio plugin it acts as an intermediary between the DAW and DDRM, exposing DDRM sliders as audio parameters of the plugin and then modifying them accordingly using MIDI control change messages.

The MIDI configuration section includes dropdowns for configuring the MIDI **input/output devices** as well the **MIDI channels** to communicate with DDRM. Note that when loaded as a plugin, J.F. Sebastian's MIDI configuration is **completely independent from the DAW MIDI configuration** of the channel where J.F. Sebastian is loaded. Therefore in bypasses the MIDI in/out of the channel and only sends/receives from its own devices and channels.

#### 2.2.1 MIDI input

MIDI input is used to receive MIDI data from the DDRM which allows to update the slider values when sliders are moved in the real hardware unit. **MIDI input configuration is optional** as J.F. Sebastian can opererate without it.

To configure MIDI input please select the device from the dropdown menu to which DDRM is sending messages. If your DDRM is connected over USB, you should see a device named **Deckard's Dream**. You also need to select the MIDI channel where DDRM sends the messages.

#### 2.2.2 MIDI output

MIDI output is used to send MIDI data to the DDRM and control its sliders *remotely*. **MIDI output configuration is mandatory** as otherwise J.F. Sebastian has no way to communicate with the DDRM.

To configure MIDI output please select the device from the dropdown menu that will send messages to DDRM. If your DDRM is connected over USB, you should see a device named **Deckard's Dream**. You also need to select the MIDI channel where DDRM is listening.

Note that J.F. Sebastian only sends MIDI control change messages to the DDRM and does not handle any other kind of MIDI data. To send note on/off messages to the DDRM you need to configure the routing independently of J.F. Sebastian.


### 2.3 Bank file loader


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

 Simply click on the buttons of the upper row and lower row to configure slider positions for channel I and II respectively.



### 2.6 DDRM panel

<p align="center">
<img src="docs/ddrm_panel.png" width="700px" />
</p>



### 2.7 DDRM panel extra controls



## 3. Known bugs and limitations


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

J.F. Sebastian has been ideated and developed by [Rita & Aurora](), a sort of fancy branding name I've given to my audio-developer [self](https://ffont.github.io).

Enormous thanks to Paul Shiling for creating the great CS80 presets bank that has been used for the tone selector. Also thanks to Black Corporation for making such a great synth!

<p align="center">
<img src="docs/Rita&AuroraAudioLogo-square.png" width="250" />
</p>
