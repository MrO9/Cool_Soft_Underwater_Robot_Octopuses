#include <IRremote.h>
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

#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define CIRCLE 'C'
#define CROSS 'X'
#define TRIANGLE 'T'
#define SQUARE 'S'
#define START 'A'
#define PAUSE 'P'

Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x60);
Adafruit_MotorShield AFMS2 = Adafruit_MotorShield(0x61);  

Adafruit_StepperMotor *myMotor1 = AFMS.getStepper(200, 1);
Adafruit_StepperMotor *myMotor2 = AFMS.getStepper(200, 2);
Adafruit_StepperMotor *myMotor3 = AFMS2.getStepper(200, 1);
Adafruit_StepperMotor *myMotor4 = AFMS2.getStepper(200, 2);

char command;

void setup() {
  Serial.begin(9600);  // Set the baud rate for serial communication
  // Initialize any other necessary setup code here
  AFMS.begin();
  AFMS2.begin();
  myMotor1->setSpeed(500);  // 10 rpm  
  myMotor2->setSpeed(500);
  myMotor3->setSpeed(500);
  myMotor4->setSpeed(500);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();
    Serial.println(command);
    executeCommand(command);
  }
  // Continue with other tasks in your main loop
}

void executeCommand(char command) {
  switch (command) {
    case FORWARD:
      // Perform action for moving forward
      digitalWrite(13, HIGH);
      myMotor1->step(200, FORWARD, DOUBLE); 
      myMotor2->step(200, BACKWARD, DOUBLE); 
      myMotor3->step(200, BACKWARD, DOUBLE); 
      myMotor4->step(200, BACKWARD, DOUBLE); 
      break;
    case BACKWARD:
      // Perform action for moving backward
      myMotor2->step(200, BACKWARD, DOUBLE);
      digitalWrite(13, HIGH);
      //myMotor1->step(200, FORWARD, DOUBLE);
      //myMotor2->step(200, BACKWARD, DOUBLE);
      //myMotor3->step(200, BACKWARD, DOUBLE); 
      //myMotor4->step(200, BACKWARD, DOUBLE); 
      break;
    case LEFT:
      // Perform action for turning left
      break;
    case RIGHT:
      // Perform action for turning right
      break;
    case CIRCLE:
      // Perform action for circle
      break;
    case CROSS:
      // Perform action for immediate stop or crossing
      break;
    case TRIANGLE:
      // Perform action for toggling a state (e.g., LED on/off)
      break;
    case SQUARE:
      // Perform action for retrieving and sending status information
      break;
    case START:
      // Perform action for starting a process or operation
      break;
    case PAUSE:
      // Perform action for pausing a process or operation
      digitalWrite(13, LOW);
      myMotor1->release();
      myMotor2->release();
      myMotor3->release();
      myMotor4->release();
      break;
    default:
      // Invalid command received
      break;
  }
}