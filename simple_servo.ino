/* Simple Servo Driver */
#include <Servo.h>

#define SERVO_PIN 11

Servo my_servo;

void setup() 
{
  Serial.begin(9600);
  my_servo.attach(SERVO_PIN);
  Serial.println("Inited");
}

void loop() 
{
  int servo_val;

  for (servo_val = 10; servo_val<=170; servo_val += 10)
  {
    my_servo.write(servo_val);
    Serial.print("Servo: ");
    Serial.println(servo_val);
    delay(1000);
  }

}
