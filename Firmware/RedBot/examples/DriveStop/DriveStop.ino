#include <RedBot.h>

RedBotMotor motor;

void setup()
{
}

void loop()
{  
  motor.drive(255);   // drive a bit
  delay(500);         // wait a bit
  motor.brake();      // stop
  delay(200);         // wait for stop to finish
}