/****************************************************************
Main CPP for RedBot whisker bumper.

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
#include <Energia.h>
                                 
// Standard class constructor, assumes that you want to halt the motors on a
//  bump. A more skilled programmer than I could figure out the error message
//  I get if I try to use the brake() function that's a part of the RedBotMotor
//  class; I worked around it by making a globally available one.
RedBotBumper::RedBotBumper(int pin) : pin(pin)
{
  pinMode(pin, INPUT_PULLUP);
  attachInterrupt(pin, brake, FALLING);
}

// Bonus points constructor, which allows the user to connect a custom function
//  to a bumper.
RedBotBumper::RedBotBumper(int pin, void(*functionPointer)(void)) : pin(pin)
{
  pinMode(pin, INPUT_PULLUP);
  attachInterrupt(pin, functionPointer, FALLING);
}

int RedBotBumper::pressed(void)
{
  return digitalRead(pin);
}

// Non-class function that puts the brakes on. This is the default behavior if
//  the user doesn't specify a custom function for the bumper trigger.
void brake(void)
{
  digitalWrite(L_CTRL_1, HIGH);
  digitalWrite(L_CTRL_2, HIGH);
  analogWrite(PWM_L, 0);
  digitalWrite(R_CTRL_1, HIGH);
  digitalWrite(R_CTRL_2, HIGH);
  analogWrite(PWM_R, 0);
}
