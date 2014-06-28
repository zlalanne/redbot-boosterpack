#include <RedBot.h>

RedBotMotor motor;
RedBotBumper bumper = RedBotBumper(5, bumped);
  
bool Stop = false;

void setup()
{
}

void loop()
{  
  motor.drive(255);   // Drive
  
  if(Stop == true) {
    
    // Wait and check if bumper is still being pressed
    delay(20);
    if(bumper.pressed() == LOW) {
      motor.stop();
      while(1);
    } else {
      Stop = false;
    }
  }
}

void bumped(void) {
  Stop = true;
}
