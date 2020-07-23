#include <ros.h>

/*
3-axis robot arm demo V1 with button control
*/

// Define Constants

// Connections to driver
const int dirPin1 = 2;  // Direction for axis 1
const int stepPin1 = 3; // Step for axis 1

const int dirPin2 = 4;  // Direction for axis 2
const int stepPin2 = 5; // Step for axis 2

const int dirPin3 = 6;  // Direction for axis 3
const int stepPin3 = 7; // Step for axis 3

int btn1cval = 0; //value for dir 1 axis 1
int btn1c = 8; //pin for dir 1 axis 1

int btn1ccwval = 0; //value for dir 2 axis 1
int btn1ccw = 9; //pin for dir 2 axis 1

int btn2cval = 0; //value for dir 1 axis 2
int btn2c = 10; //pin for dir 1 axis 2

int btn2ccwval = 0; //value for dir 2 axis 2
int btn2ccw = 11; //pin for dir 2 axis 2

int btn3cval = 0; //value for dir 1 axis 3
int btn3c = 12; //pin for dir 1 axis 3

int btn3ccwval = 0; //value for dir 2 axis 3
int btn3ccw = 13; //pin for dir 2 axis 3


// Motor steps per rotation
const int STEPS_PER_REV = 6400;
 
void setup() {
  
  // Setup the motor pins as Outputs
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
    pinMode(stepPin2,OUTPUT); 
  pinMode(dirPin2,OUTPUT);
    pinMode(stepPin3,OUTPUT); 
  pinMode(dirPin3,OUTPUT);
  
    // Setup the button pins as Inputs
  pinMode(btn1c, INPUT); 
  pinMode(btn1ccw, INPUT);
  pinMode(btn2c, INPUT);
  pinMode(btn2ccw, INPUT);
  pinMode(btn3c, INPUT);
  pinMode(btn3ccw, INPUT);
  
}
void loop() {
  
  //read buttons
  btn1cval = digitalRead(btn1c);
  btn1ccwval = digitalRead(btn1ccw);
  btn2cval = digitalRead(btn2c);
  btn2ccwval = digitalRead(btn2ccw);
  btn3cval = digitalRead(btn3c);
  btn3ccwval = digitalRead(btn3ccw);
  
  
  //control for axis 1
  
  if(btn1cval != 0){
  // Set axis 1 motor direction clockwise
  digitalWrite(dirPin1,HIGH); 
  
  // Spin motor one step
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500); 
  }
  else if (btn1ccwval != 0){
      // Set axis 1 motor direction counter-clockwise
  digitalWrite(dirPin1,LOW); 
  
  // Spin motor one step
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(500);
  }

//control for axis 2
  
  if(btn2cval != 0){
  // Set axis 1 motor direction clockwise
  digitalWrite(dirPin2,HIGH); 
  
  // Spin motor one step
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500); 
  }
  else if (btn2ccwval != 0){
      // Set axis 1 motor direction counter-clockwise
  digitalWrite(dirPin2,LOW); 
  
  // Spin motor one step
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(500);
  }
  
  //control for axis 3
  
  if(btn3cval != 0){
  // Set axis 1 motor direction clockwise
  digitalWrite(dirPin3,HIGH); 
  
  // Spin motor one step
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500); 
  }
  else if (btn3ccwval != 0){
      // Set axis 1 motor direction counter-clockwise
  digitalWrite(dirPin3,LOW); 
  
  // Spin motor one step
    digitalWrite(stepPin3,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin3,LOW); 
    delayMicroseconds(500);
  }

//overall loop delay (test this)
delayMicroseconds(500);

}
