// Adafruit Motor Shield V2 Library - Version: Latest 
#include <Adafruit_MotorShield.h>

// Adafruit PWM Servo Driver Library - Version: Latest 
#include <Adafruit_PWMServoDriver.h>

/*

*/

#include <Stepper.h>
#include <Wire.h>


int count;
  
// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS12 = Adafruit_MotorShield();
// Or, create it with a different I2C address (say for stacking)


// Connect a stepper motor with 200 steps per revolution (1.8 degree)
Adafruit_StepperMotor *stepperMotor1 = AFMS12.getStepper(200, 1);
Adafruit_StepperMotor *stepperMotor2 = AFMS12.getStepper(200, 2);
//Adafruit_StepperMotor *stepperMotor3 = AFMS34.getStepper(200, 1);
//Adafruit_StepperMotor *stepperMotor4 = AFMS34.getStepper(200, 2);

void setup() {
  count = 0;
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("All Steppers test!");

  AFMS12.begin();  // create with the default frequency 1.6KHz
  //AFMS34.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  stepperMotor1->setSpeed(200);  // 200 rpm
  stepperMotor2->setSpeed(200);  // 200 rpm
  //stepperMotor3->setSpeed(200);  // 200 rpm
  //stepperMotor4->setSpeed(200);  // 200 rpm
}

void loop() {
  stepperMotor1->step(200, FORWARD, DOUBLE); 
  delay(4000);
  stepperMotor2->step(200, BACKWARD, DOUBLE); 
}
