#include <RedBot.h>

// Instantiate the motor control class. This only needs to be done once
RedBotMotor motor;

int motorSpeed=100;
int grow=5;

void setup()
{ 
}

void loop()
{  
  motor.drive(motorSpeed);   // drive a bit
  
  delay(2);
  motorSpeed += grow;
  if(motorSpeed >= 255 || motorSpeed <= 100)
  {
    grow = grow * -1; 
  }
 
  delay(500);
}