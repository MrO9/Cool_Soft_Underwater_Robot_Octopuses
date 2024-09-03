// Adafruit Motor Shield V2 Library - Version: Latest 
#include <Adafruit_MotorShield.h>

// Adafruit PWM Servo Driver Library - Version: Latest 
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

/*

*/

#include <Stepper.h>
#include <Wire.h>


Adafruit_MotorShield AFMS1 = Adafruit_MotorShield();

Servo myservo; 

int i; 
int x;                              
int y;
int val;
int solenoidPin = 4;
int secondsolenoidPin = 6;


Adafruit_StepperMotor *myMotor1 = AFMS1.getStepper(200, 1);
Adafruit_StepperMotor *myMotor3 = AFMS1.getStepper(200, 2);



int count;
void setup() {

  

  Serial.begin(9600);





  AFMS1.begin();
  myMotor1->setSpeed(500);  // 10 rpm  
  myMotor3->setSpeed(500);
  pinMode(solenoidPin, OUTPUT);
  pinMode(secondsolenoidPin, OUTPUT);
  pinMode(13, OUTPUT);




}

void loop(){
  digitalWrite(solenoidPin, LOW);
  digitalWrite(secondsolenoidPin, HIGH);
  x = analogRead(A0);
  y = analogRead(A1);
  //Serial.println(y);  
  Serial.println(x); 

if(x == 1022 || x == 1023){
  myMotor1->step(200, FORWARD, DOUBLE); 
  myMotor3->step(200, FORWARD, DOUBLE); 
  digitalWrite(13, HIGH);

}
if(x== 1023 || x == 1022){
  digitalWrite(solenoidPin, HIGH);
  digitalWrite(secondsolenoidPin, LOW);

}

if(x == 0){
  myMotor1->step(200, BACKWARD, DOUBLE); 
  myMotor3->step(200, BACKWARD, DOUBLE);
  digitalWrite(13, LOW);

}
if(y == 509 || y == 510){
  myMotor1->release();
  myMotor3->release();
}


myMotor1->release();
myMotor3->release();

} 





