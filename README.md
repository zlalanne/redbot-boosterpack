# RedBot BoosterPack

This project is a port of Sparkfun's RedBot Mainboard to BoosterPack form to be used with TI LaunchPads + Energia

Please check the GitHub issue tracker for any known hardware/software issues

## Changes from SparkFun's RedBot Mainboard
* Removed Atmega328 and replaced with BoosterPack headers. BoosterPack should work with any 40-pin launchpad that follows the [BoosterPack pinout standard](http://www.ti.com/ww/en/launchpad/img/launchpad-byob-pinout.png)
* Removed XBee to make board cheaper, if XBee needed get another BoosterPack
* Made sizes of caps/resistors larger to make soldering easier
* Most of the logic now runs on 3.3V since the F5529 is 3.3V as well
* Removed USB connection that was using for programming device, programming is handled on the LaunchPad

## Repository Contents
* **/Firmware/RedBot** - RedBot Energia library
* **/Hardware** - Eagle PCB layout and schematic files along with BOM

## License Information
License is inherited from [SparkFun's RedBot repository](https://github.com/sparkfun/RedBot)

All contents of this repository are released under [Creative Commons Share-alike 3.0](http://creativecommons.org/licenses/by-sa/3.0/).
