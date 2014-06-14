/****************************************************************
Main CPP for RedBot. This file handles the pin change interrupts
and how we multiplex between the different potential causes of
a pin change interrupt.

This code is beerware; if you use it, please buy me (or any other
SparkFun employee) a cold beverage next time you run into one of
us at the local.

21 Jan 2014- Mike Hord, SparkFun Electronics

Code developed in Arduino 1.0.5, on an SparkFun Redbot v12.
****************************************************************/
/****************************************************************
Migrated to Energia by Zack Lalanne
****************************************************************/

#include "RedBot.h"
//#include <avr/interrupt.h>
#include <Energia.h>

// We need to track what the prior state of our pins for various PCINTS was;
//  this varies by interrupt. These values are initialized to the "all high"
//  state; we don't want any low-to-high transitions at beginning of code
//  execution to be caught.
volatile byte lastPC0PinState = 0x0E;  // For pins 9, 10, 11, PB1-3
volatile byte lastPC1PinState = 0x3F;  // For pins A0-A5/14-19, PC0-5
volatile byte lastPC2PinState = 0x08;  // For pin 3, PD3

// We need some way to exclude short transients on the encoder inputs; we'll do
//  that by capturing the most recent rise time with millis() and ignoring
//  falling edges that happen within 20ms of a rise.
volatile unsigned long lastRRise = 0;
volatile unsigned long lastLRise = 0;
#define  ENC_HIGH_DELAY   10

byte PBMask = 0;
byte PCMask = 0;
byte PDMask = 0;

volatile byte pinFunction[10];     // Store the currently assigned fucntion
                                       //  of the PCINT associated with each pin
                                       //  in this array. Array indices are of
                                       //  the type "PCINT_pinname".
                                       