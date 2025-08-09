#include <Stepper.h>
#include <Arduino.h>

const int pinToGround = 2;
const int trigPin = 3; // Trigger pin of ultrasonic sensor
const int echoPin = 4; // Echo pin of ultrasonic sensor
const int buzzerPin = 5; // Buzzer pin
long duration;
int distance_cm;
int threshold = 20; // Threshold distance in centimeters for activating the buzzer

// Define the motor pins
const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 10;
const int IN4 = 11;


// initialize the stepper library with the number of steps per revolution
// for the 28BYJ-48 motor, it's 2048 steps per revolution (or 4096 half-steps)
Stepper myStepper(2048, IN1, IN3, IN2, IN4);

void setup() {
  // set the speed of the stepper motor in rpm
  myStepper.setSpeed(5);

pinMode(pinToGround, OUTPUT); // Set pin as output

    // Define pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

}

void loop() {
  // rotate the motor one revolution in the other direction
  myStepper.step(-1024);
  // rotate the motor one revolution in one direction
  myStepper.step(1024);

digitalWrite(pinToGround, LOW); // Set the pin to ground
  delay(1000); // Wait for a second
 
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo signal
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  distance_cm = duration * 0.034 / 2;

  // Print the distance to serial monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

 // Activate buzzer if an obstacle is within the threshold distance
  if (distance_cm <= threshold) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  // Delay before the next measurement
  delay(500);

}