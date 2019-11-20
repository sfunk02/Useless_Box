//Switch Servo
//Sam Funk
//Uses a switch to turn a servo in both directions.

#include <Servo.h>    //Adds the servo library

Servo myServo;    //Names the servo

int servoPin = 9;
int btn1Pin = 11;
int btn2Pin = 12;
int btn1State = 0;
int btn2State = 0;
int angle = 0;

void setup() {
  Serial.begin(9600);
  pinMode(btn1Pin, INPUT);
  pinMode(btn2Pin, INPUT);
  myServo.attach(servoPin);
}

void loop() {
  btn1State = digitalRead(btn1Pin);
  btn2State = digitalRead(btn2Pin);
  if (btn1State == HIGH && angle < 180) {       //When I press Button 1
    Serial.println("Button 1 is on");           //the serial monitor displays that the button is on
    myServo.write(angle + 5);                   //and the servo turns clockwise.
    angle = (angle + 5);
  }
  if (btn2State == HIGH && angle > 0) {
    Serial.println("Button 2 is on");
    myServo.write(angle - 5);
    angle = (angle - 5);
  }
}

      //Credit to: https://www.instructables.com/id/How-to-usa-a-Servo-motor-Arduino-Tutorial/
