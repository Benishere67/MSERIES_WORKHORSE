const int ButtonPin1 = 8;
const int ButtonPin2 = 13;

int Pin1 = 9; 
int Pin2 = 10; 
int Pin3 = 11; 
int Pin4 = 12; 
int _step = 0; 
boolean dir;// false=clockwise, true=counter clockwise
int count=0;
void setup() 
{ 
 pinMode(Pin1, OUTPUT);  
 pinMode(Pin2, OUTPUT);  
 pinMode(Pin3, OUTPUT);  
 pinMode(Pin4, OUTPUT); 

 pinMode(ButtonPin1, INPUT);
 pinMode(ButtonPin2, INPUT);
} 
 void loop() 
{ 
  if(ButtonPin1==HIGH){
    dir = false;
  }else{
    dir = true;
  }
  if(ButtonPin2==HIGH){
    
  }else{
   switch(_step){ 
     case 0: 
       digitalWrite(Pin1, LOW);  
       digitalWrite(Pin2, LOW); 
       digitalWrite(Pin3, LOW); 
       digitalWrite(Pin4, HIGH); 
     break;  
     case 1: 
       digitalWrite(Pin1, LOW);  
       digitalWrite(Pin2, LOW); 
       digitalWrite(Pin3, HIGH); 
       digitalWrite(Pin4, HIGH); 
     break;  
     case 2: 
       digitalWrite(Pin1, LOW);  
       digitalWrite(Pin2, LOW); 
       digitalWrite(Pin3, HIGH); 
       digitalWrite(Pin4, LOW); 
     break;  
     case 3: 
       digitalWrite(Pin1, LOW);  
       digitalWrite(Pin2, HIGH); 
       digitalWrite(Pin3, HIGH); 
       digitalWrite(Pin4, LOW); 
     break;  
     case 4: 
       digitalWrite(Pin1, LOW);  
       digitalWrite(Pin2, HIGH); 
       digitalWrite(Pin3, LOW); 
       digitalWrite(Pin4, LOW); 
     break;  
     case 5: 
       digitalWrite(Pin1, HIGH);  
       digitalWrite(Pin2, HIGH); 
       digitalWrite(Pin3, LOW); 
       digitalWrite(Pin4, LOW); 
     break;  
       case 6: 
       digitalWrite(Pin1, HIGH);  
       digitalWrite(Pin2, LOW); 
       digitalWrite(Pin3, LOW); 
       digitalWrite(Pin4, LOW); 
     break;  
     case 7: 
       digitalWrite(Pin1, HIGH);  
       digitalWrite(Pin2, LOW); 
       digitalWrite(Pin3, LOW); 
       digitalWrite(Pin4, HIGH); 
     break;  
     default: 
       digitalWrite(Pin1, LOW);  
       digitalWrite(Pin2, LOW); 
       digitalWrite(Pin3, LOW); 
       digitalWrite(Pin4, LOW); 
     break;  
   }
 } 
 if(dir){ 
   _step++; 
 }else{ 
   _step--; 
 } 
 if(_step>7){ 
   _step=0; 
 } 
 if(_step<0){ 
   _step=7; 
 } 
 delay(20); 

}
