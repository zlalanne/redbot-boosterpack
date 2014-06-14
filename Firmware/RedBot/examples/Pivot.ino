#include <RedBot.h>

RedBotMotor motor;

void setup()
{
}

void loop()
{  
    motor.pivot(100);   // turn a bit

    delay(750);         // wait for stop to finish
    
    motor.pivot(-100);  // turn the other way a bit

    delay(750);         // wait for stop to finish
}
