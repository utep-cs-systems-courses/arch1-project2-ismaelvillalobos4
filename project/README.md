# Project 2 Blinky-Buzzy Toy

The purpose of this project was to understand the MSP430's architecture and
how the launchpad board work - leds, buzzer and switches work in unison.
To successfully complete the lab, we were to make a toy that had changing
lights, made use of the buttons on the launchpad (green) board and made noise.

## Functions of the toy:

* The toy will start of with a red LED on and no noise, kind of a standby or off state.
* When any of the switches on the green board is pressed down, a unique song
  is played foreach and the red LED turns off and the green LED is lit.
* When a button is released, the toy goes back into the initial, standby state
  with no noise and just the red LED on.

## Running Toy:

* Make sure the MSP430 is connected via USB.
* Open up the /src folder.
* Type "make load" and enter.
* The file will be loaded onto the MSP430. Play away!
* To clean contents, run "make clean".


