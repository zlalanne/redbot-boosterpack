# RedBot BoosterPack

![Imgur](http://i.imgur.com/Buku8nl.jpg "RedBot BoosterPack")

This project is a port of Sparkfun's RedBot Mainboard to BoosterPack form to be used with TI LaunchPads + Energia

Please check the GitHub issue tracker for any known hardware/software issues

## Changes from SparkFun's RedBot Mainboard
* Removed Atmega328 and replaced with BoosterPack headers. BoosterPack should work with any 40-pin launchpad that follows the [BoosterPack pinout standard](http://www.ti.com/ww/en/launchpad/img/launchpad-byob-pinout.png)
* Removed XBee to make board cheaper, if XBee needed get another BoosterPack
* Made sizes of caps/resistors larger to make soldering easier
* Most of the logic now runs on 3.3V since the F5529 is 3.3V as well
* Removed USB connection that was using for programming device, programming is handled on the LaunchPad

## Additional Hardware Support
One of the great features about the RedBot ecosystem is the number of products SparkFun has come out with that plug into the RedBot. 

The following are currently fully supported:
* [Magician Chasis (including motors)](https://www.sparkfun.com/products/10825)
* [RedBot Buzzer](https://www.sparkfun.com/products/12567)

The following are under development
* [RedBot Sensor - Line Follower](https://www.sparkfun.com/products/11769). Needs software support
* [RedBot Sensor - Mechanical Bumper](https://www.sparkfun.com/products/11999). Needs software support
* [RedBot Sensor - Wheel Encoder](https://www.sparkfun.com/products/12617). Needs software support
* [RedBot Sensor - Accelerometer](https://www.sparkfun.com/products/12589). Issue with v1.0 of board, needs software support

## Repository Contents
* **/Firmware/RedBot** - RedBot Energia library
* **/Hardware** - Eagle PCB layout and schematic files along with BOM

## License Information
License is inherited from [SparkFun's RedBot repository](https://github.com/sparkfun/RedBot)

All contents of this repository are released under [Creative Commons Share-alike 3.0](http://creativecommons.org/licenses/by-sa/3.0/).
