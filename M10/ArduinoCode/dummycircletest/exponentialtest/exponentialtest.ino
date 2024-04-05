#include <AccelStepper.h>

// Define stepper motor connections and motor interface type
#define motorInterfaceType 4

#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12

#define STEPPER_PIN_5 4
#define STEPPER_PIN_6 5
#define STEPPER_PIN_7 6
#define STEPPER_PIN_8 7

#define STEPPER_PIN_9 A0
#define STEPPER_PIN_10 8
#define STEPPER_PIN_11 2
#define STEPPER_PIN_12 3

// Motor 1
AccelStepper stepper1(motorInterfaceType, STEPPER_PIN_1, STEPPER_PIN_3, STEPPER_PIN_2, STEPPER_PIN_4);
// Motor 2
AccelStepper stepper2(motorInterfaceType, STEPPER_PIN_5, STEPPER_PIN_7, STEPPER_PIN_6, STEPPER_PIN_8);
// Motor 3
AccelStepper stepper3(motorInterfaceType, STEPPER_PIN_9, STEPPER_PIN_11, STEPPER_PIN_10, STEPPER_PIN_12);

// Joystick pins
const int joyXPin = A4;
const int buttonPin = A2;

// Variable to track the pause state
boolean isPaused = false;

void setup() {
  // Initialize the stepper motors with a maximum speed and acceleration
  stepper1.setMaxSpeed(1000);
  stepper1.setAcceleration(500);
  
  stepper2.setMaxSpeed(1000);
  stepper2.setAcceleration(500);
  
  stepper3.setMaxSpeed(1000);
  stepper3.setAcceleration(500);

  // Initialize the joystick button pin as an input
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

// Function to apply exponential curve
float exponentialSpeed(int input, float exponent) {
  // Normalize joystick input to range -1 to 1
  float normalizedInput = (input - 512.0) / 512.0;
  // Apply exponential curve
  float expOutput = pow(normalizedInput, exponent);
  // Scale back to motor speed range
  return expOutput * 725; // Adjust the multiplier to match your motor's speed range
}

void loop() {
  static unsigned long lastButtonPress = 0;
  // Read the state of the button
  if (digitalRead(buttonPin) == LOW && millis() - lastButtonPress > 500) {
    // Toggle pause state and remember the last button press time
    isPaused = !isPaused;
    lastButtonPress = millis();
  }
  
  if (!isPaused) {
    // Read the joystick value
    int joyX = analogRead(joyXPin);

    // Apply exponential mapping
    float speed = exponentialSpeed(joyX, 3); // Exponent can be adjusted for desired curve sensitivity

    // Set the speed of the motors
    stepper1.setSpeed(speed);
    stepper2.setSpeed(speed);
    stepper3.setSpeed(speed);
    
    // Move the steppers
    stepper1.runSpeed();
    stepper2.runSpeed();
    stepper3.runSpeed();
  }
}
