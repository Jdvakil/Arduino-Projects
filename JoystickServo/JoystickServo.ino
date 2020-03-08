/**
   This class controls two servo motors using a joystick.
   @author Jay Darshan Vakil
   @version March 7th, 2020
*/
#include <Servo.h>
Servo firstServo; //Servo object to control a servo
Servo secondServo;//Second servo object to control the other servo
const int xVal = 6;//The x value from the joystick; uses the analog pin 6
const int yVal = 7;//The y value from the joystick; uses the analog pin 7
const int button = 3;//The button of the joystick; digital pin 3

/**
 * This method is the setup method for the class, it sets the arduino pins aside for input or output.
 */
void setup() {
  pinMode(xVal, INPUT);//this sets the arduino analog pin 6 to input
  pinMode(yVal, INPUT);//this sets the arduino analog pin 7 to input
  pinMode(button, INPUT);//this sets the arduino digital pin 3 to input
  firstServo.attach(9);//This instantiates the digital pwm pin 9 for the servo
  secondServo.attach(10);//This instantiates the digital pwm pin 10 for the servo
}

/**
 * This method carries out the commands in the method in a loop.
 */
void loop() {
  int readXVal = analogRead(xVal);//This reads the xVal from the x value input pin
  int readYVal = analogRead(yVal);//This reads the yVal from the y value input pin
  readXVal = map(readXVal, 0, 1024, 0, 180);//This maps the analog read value (reads from 0 to 1024) to the position of the servo
  firstServo.write(readXVal);//This writes the servo position
  readYVal = map(readYVal, 0, 1024, 0, 180);//This maps the analog read value (reads from 0 to 1024) to the position of the servo
  secondServo.write(readYVal);//write the servo position
  
}

