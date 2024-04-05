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

int step_number_1 = 0;
int step_number_2 = 0;
int step_number_3 = 0;

int joystickX = 0;
int threshold = 554; // Adjust this threshold to your joystick's neutral position

void setup() {
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
  
  pinMode(STEPPER_PIN_5, OUTPUT);
  pinMode(STEPPER_PIN_6, OUTPUT);
  pinMode(STEPPER_PIN_7, OUTPUT);
  pinMode(STEPPER_PIN_8, OUTPUT);
  
  pinMode(STEPPER_PIN_9, OUTPUT);
  pinMode(STEPPER_PIN_10, OUTPUT);
  pinMode(STEPPER_PIN_11, OUTPUT);
  pinMode(STEPPER_PIN_12, OUTPUT);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  joystickX = analogRead(A4); // Read the X-axis of the joystick
  
  // Determine the direction based on the threshold
  if (joystickX > threshold) {
    moveStepper(&step_number_1, STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
    moveStepper(&step_number_2, STEPPER_PIN_5, STEPPER_PIN_6, STEPPER_PIN_7, STEPPER_PIN_8);
    moveStepper(&step_number_3, STEPPER_PIN_9, STEPPER_PIN_10, STEPPER_PIN_11, STEPPER_PIN_12);
  } else {
    moveStepperReverse(&step_number_1, STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
    moveStepperReverse(&step_number_2, STEPPER_PIN_5, STEPPER_PIN_6, STEPPER_PIN_7, STEPPER_PIN_8);
    moveStepperReverse(&step_number_3, STEPPER_PIN_9, STEPPER_PIN_10, STEPPER_PIN_11, STEPPER_PIN_12);
  }
  delay(2); // Adjust delay for desired speed
}

void moveStepper(int *step_number, int pin1, int pin2, int pin3, int pin4) {
  switch (*step_number) {
    case 0:
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      break;
    case 1:
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      break;
    case 2:
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, LOW);
      break;
    case 3:
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, HIGH);
      break;
  }
  
  (*step_number)++;
  if (*step_number > 3) {
    *step_number = 0;
  }
}

void moveStepperReverse(int *step_number, int pin1, int pin2, int pin3, int pin4) {
  switch (*step_number) {
    case 0:
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, HIGH);
      break;
    case 1:
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, LOW);
      break;
    case 2:
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      break;
    case 3:
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      break;
  }
  
  (*step_number)++;
  if (*step_number > 3) {
    *step_number = 0;
  }
}
