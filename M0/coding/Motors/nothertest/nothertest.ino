int pwmPin = 3; // PWM pin connected to motor controller
int joystickX = A4; // Joystick X-axis connected to A4
int buttonPin = 7; // Joystick button connected to pin 7
int motorSpeed = 0; // Variable to store motor speed
float exponent = 1.5; // Exponent for curve adjustment
bool paused = false; // Pause state
int motorDirectionPin = 4; // Additional pin to control motor direction, if required by your motor controller

void setup() {
  pinMode(pwmPin, OUTPUT);
  pinMode(motorDirectionPin, OUTPUT); // Setup the motor direction control pin
  pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with internal pull-up resistor
  Serial.begin(9600); // Initialize serial communication at 9600 bps
  Serial.println("Starting system..."); // Initial message on serial monitor
}

void loop() {
  int xValue = analogRead(joystickX); // Read the joystick X-axis
  int buttonState = digitalRead(buttonPin); // Read the button state

  // Report joystick X-axis and button state
  Serial.print("Joystick X: ");
  Serial.print(xValue);
  Serial.print(" | Button State: ");
  Serial.print(buttonState == HIGH ? "Released" : "Pressed");
  Serial.print(" | Motor Speed: ");
  Serial.print(motorSpeed);
  Serial.print(" | Paused: ");
  Serial.println(paused ? "Yes" : "No");

  // Check button state
  if (buttonState == LOW) { // Button is pressed
    if (!paused) {
      paused = true; // Toggle pause state
      motorSpeed = 0; // Reset motor speed to 0
      analogWrite(pwmPin, 0); // Immediately stop motor
      Serial.println("Motor paused");
      delay(500); // Debounce delay
    } else {
      paused = false; // Resume operation
      Serial.println("Motor resumed");
      delay(500); // Debounce delay
    }
  }

  if (!paused) {
    // Convert joystick range from (0-1023) to (-512 to 511)
    int adjustedValue = xValue - 512;

    // Apply exponential curve for finer control
    float expValue = pow(adjustedValue / 512.0, exponent);

    // Determine direction based on sign of joystick value
    if (adjustedValue > 10) {
      digitalWrite(motorDirectionPin, HIGH); // Forward direction
      motorSpeed = (int)(expValue * 255);
    } else if (adjustedValue < -10) {
      digitalWrite(motorDirectionPin, LOW); // Reverse direction
      motorSpeed = (int)(-expValue * 255);
    } else {
      motorSpeed = 0; // Stop motor if within dead zone
    }
    analogWrite(pwmPin, abs(motorSpeed)); // Apply absolute speed value to PWM
  }

  delay(100);
}
