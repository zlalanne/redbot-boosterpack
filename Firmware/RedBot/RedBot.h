/****************************************************************
Core header file for all the various RedBot functions.

There is additional license info below regarding the use of the
SoftwareSerial library from Arduino 1.0.5; I had good and sound
reasons for creating a derivative class rather than asking users
to simply use the existing library, which are documented below.

This code is beerware; if you use it, please buy me (or any other
SparkFun employee) a cold beverage next time you run into one of
us at the local.

21 Jan 2014- Mike Hord, SparkFun Electronics

Code developed in Arduino 1.0.5, on an SparkFun Redbot v12.
****************************************************************/
/****************************************************************
Migrated to Energia by Zack Lalanne
****************************************************************/

#ifndef RedBot_h
#define RedBot_h

#include <Energia.h>

// Pin aliases for the motor controller.
#define    L_CTRL_1   34
#define    L_CTRL_2   33
#define    PWM_L      40

#define    R_CTRL_1   32
#define    R_CTRL_2   31
#define    PWM_R      39

// PCINT functionality aliases. Each PCINT has a value set up when the
//  class member gets created, and the PCINT service routine will handle
//  the choosing the appropriate response to the interrupt.
#define NOT_IN_USE    0
#define WHISKER       1
#define LENCODER      2
#define RENCODER      3
#define SW_SERIAL     4

#define PCINT_A0      0
#define PCINT_A1      1
#define PCINT_A2      2
#define PCINT_A3      3
#define PCINT_A4      4
#define PCINT_A5      5
#define PCINT_3       6
#define PCINT_9       7
#define PCINT_10      8
#define PCINT_11      9

enum WHEEL {LEFT, RIGHT, BOTH}; // Variable for which wheel you're interested in
                  //  when you do things in the encoder class.

// These three functions need to work from within multiple classes, so we keep
//  them separate and add them as friend functions where appropriate.
void setPinChangeInterrupt(int pin, byte role); // The "role" of each pin is
                  //  stored in an array which is accessed in the interrupt
                  //  handler to determine what should be done on a falling edge
                  //  PC interrupt.
void pinFunctionHandler(byte pinIndex); // This is the function which actually
                  //  handles the legwork after the interrupt has identified
                  //  which pin caught the interrupt.
void brake(void); // Globally accessible motor brake. I couldn't figure out how
                  //  to set a function pointer to the RedBotMotor class
                  //  function, and it's a small function, so I just made a
                  //  global in the library.
void PC0Handler(byte PBTemp);
void PC1Handler(byte PCTemp);
void PC2Handler(byte PDTemp);


// This class handles motor functionality. I expect one instance of this at the
//  start of a piece of RedBot code.
class RedBotMotor
{
  public:
    RedBotMotor();          // Constructor. Mainly sets up pins.
    void drive(int speed);  // Drive in direction given by sign, at speed given
                            //  by magnitude of the parameter.
    void pivot(int speed);  // Pivot more or less in place. Turns motors in
                            //  opposite directions. Positive values correspond
                            //  to anti-clockwise rotation.
    void rightDrive(int speed); // Drive just the left motor, as drive().
    void leftDrive(int speed);  // Drive just the right motor, as drive().
    void stop();            // Stop motors, but allow them to coast to a halt.
    void brake();           // Quick-stop the motors, shorting the leads.
    void rightStop();       // Stop right motor, as with stop().
    void leftStop();        // Stop left motor, as with stop().
    void leftBrake();       // Quick-stop left motor, as with brake().
    void rightBrake();      // Quick-stop right motor, as with brake().
  private:
    void leftFwd(byte speed); // These functions are pretty self-explanatory,
    void leftRev(byte speed); //  and are called by the above functions once
    void rightFwd(byte speed);//  sign has been used to determine direction.
    void rightRev(byte speed);
};

// This handles the physical wire-whisker type bumper.
class RedBotBumper
{
  public:
    RedBotBumper(int pin); // Simple constructor; when the bumper gets hit, the
                           //  motors will stop.
    RedBotBumper(int pin, void(*functionPointer)(void)); // If the user wishes
                           //  to do something other than stop on a whisker,
                           //  bump, they can write a function to do so, and
                           //  use this constructor.
    int pressed();        // Check if bumper is pressed
  private:
    int pin;
    void setBumpFunction(int pin, void(*functionPointer)(void));
};


#endif