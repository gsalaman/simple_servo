# Simple Servo
In this repo, we'll show how to control a servo.

## Parts
You will need:
* a redboard-uno
* a servo

## Connections
Each servo has 3 lines of input.  One (usually red) is the power source.  One (usually black) is ground.  The other is the control line.  

Hook up the red line to +5v, the black to GND, and the other line to pin 11.

## The sketch
We'll be using this sketch:
```
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
```
Here's what's going on:  

Arduino supplies a library for servo control.  We need to attach the control line for that servo to a given pin...11 in our case.  Then we can call the "write" function to set the servo to a given angle.

## Servo particulars
A lot of servos have issues getting to their edges (0 or 180 degrees).  Because of this, in our example, we're only going from  10 degrees to 170.  Play with your servo to see the range.

Sometimes you will get "jitter" on your servo.  Part of the time this is due to not enough current driving the servo...if this is the case, use a separate 5v source for the servo itself.  Some of the time it's because the timimg of the control line is getting messed up due to other events happening in your processing.  

In order to get rid of both of these, you can use a separate driver board for your servo, but that's outside of the scope of these excercises.

## A closer look at timing
The servo itself uses Pulse Width Modulation (PWM) to figure out where it needs to position itself.  What this means is that your arduino is sending pulses to the servo...and the width of those pulses determines the servo's position.  You can look at the control line on an oscilloscope to see this happening.
