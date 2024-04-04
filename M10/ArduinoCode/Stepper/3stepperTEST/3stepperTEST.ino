//Written By Nikodem Bartnik - nikodembartnik.pl
#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12
int step_number = 0;
int PS = 0;
void setup() {

  
    pinMode(STEPPER1_PIN_1, OUTPUT);
    pinMode(STEPPER1_PIN_2, OUTPUT);
    pinMode(STEPPER1_PIN_3, OUTPUT);
    pinMode(STEPPER1_PIN_4, OUTPUT);

    pinMode(STEPPER2_PIN_1, OUTPUT);
    pinMode(STEPPER2_PIN_2, OUTPUT);
    pinMode(STEPPER2_PIN_3, OUTPUT);
    pinMode(STEPPER2_PIN_4, OUTPUT);

    pinMode(STEPPER3_PIN_1, OUTPUT);
    pinMode(STEPPER3_PIN_2, OUTPUT);
    pinMode(STEPPER3_PIN_3, OUTPUT);
    pinMode(STEPPER3_PIN_4, OUTPUT);
   
  


}

void loop() {

 while(PS < 100){
  OneStep(false);
  delay(20);
  PS++;
 }
 PS = 0;

}


void OneStep(bool dir){
    if(dir){
switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
} 
  }else{
    switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
 
  
} 
  }
step_number++;
  if(step_number > 3){
    step_number = 0;
  }
}
