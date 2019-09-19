# J.F. Sebastian, a Deckard's Dream companion tool

![J.F. Sebastian screenshot](docs/screenshot_1000.png)

## Overview

J. F. Sebastian, named after a former genetic designer of the *Tyrell Corporation*, provides new ways to control and explore the sonic possibilities of the CS80-inspired Deckard's Dream synthesiser (DDRM). It works both as a **stand-alone app** and as an **audio plug-in** with automatable parameters.

With J.F. Sebastian you can import DDRM bank files, edit patches and export them. When you import a bank file, a *timbre Space* will be created which will allow you to navigate all the presets in a colorful space and create new ones. Just click anywhere on the timbre Space and play the synth. Click on another point to get a new preset. Close points in the space will result in similar sounding presets.

J.F. Sebastian also includes a *CS80-like tone selector* that allows you to use the original presetting system of the CS80 in the DDRM. Simply click on the buttons of the upper row and lower row to configure slider positions for channel I and II respectively.

Check out the video below for an introduction to J.F. Sebastian and its features:

<iframe width="560" height="315" src="https://www.youtube.com/embed/cHdO393UwKI" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>


## Help

Please check the [user manual](MANUAL.md) for an explanation of the different features of J.F. Sebastian and how to use them.


## Building J.F. Sebastian

J.F. Sebastian uses the JUCE library and can be built following standard JUCE-building workflows. This repository includes project files for *XCode* (macOS) and *Visual Studio 2019* (windows) under the `Builds` folder. You can open the Projcer file `JFSebastian.jucer` to create exporters for other platforms or edit the configuration of current project files.


## Licensing

J.F. Sebastian is released under the **GPLv3** open source software license (see [LICENSE](https://github.com/ritaandaurora/ddrm-jfsebastian/blob/master/LICENSE) file) with the code being available at  [https://github.com/ritaandaurora/ddrm-jfsebastian](https://github.com/ritaandaurora/ddrm-jfsebastian). J.F. Sebastian uses the following open source software libraries: 

 * [tapkee](http://tapkee.lisitsyn.me), available under BSD 3-clause license 
 * [delaunator-cpp](https://github.com/delfrrr/delaunator-cpp), available underMIT license
 * [juce](https://juce.com), available under GPLv3 license 
 
J.F. Sebastian uses some fonts released under open licenses as well:

 * [roboto](https://fonts.google.com/specimen/Roboto), available under Apache 2 license
 * [modenine](https://www.dafont.com/modenine.font), available under custom "freely distributable" license (see license file in `Resources/fonts`)
 * [blade runner](https://www.dafont.com/blade-runner-movie-font.font), tagged as "100% free" font


## Credits and acknowledgements

J.F. Sebastian has been ideated and developed by [Rita & Aurora](https://ritaandaurora.github.io), a sort of fancy branding name I've given to my audio-developer [self](https://ffont.github.io).

Enormous thanks to Paul Shilling for creating the great CS80 presets bank that has been used for the tone selector. Also thanks to Black Corporation for making such a great synth!

<p align="center">
<img src="docs/Rita&AuroraAudioLogo-square.png" width="250" />
</p>
