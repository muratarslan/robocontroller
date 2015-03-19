#define DEBUG

const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int robotButton = 5;
const int motorButton = 6;
const int kickButton = 7;
const int spinnerButton = 8;

int buttonState = 0;  
int buttonState2 = 0; 
int lastButtonState = 0; 
int lastButtonState2 = 0;
int buttonCounter = -1;


void setup(){
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(robotButton, INPUT);
  pinMode(motorButton, INPUT);
  pinMode(kickButton, INPUT);
  pinMode(spinnerButton, INPUT);
}


void loop(){
  
 buttonState = digitalRead(robotButton);
 buttonState2 = digitalRead(motorButton);


  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      robotSelect();
    }
     lastButtonState = buttonState;
  }
  
  
    if (buttonState2 != lastButtonState2) {
      if (buttonState2 == HIGH) {
      motorCommand();
    }
     lastButtonState2 = buttonState2;
  }
  
  
 
  led();

}

void motorCommand(){
 #ifdef DEBUG
  Serial.print("Sending motorCommand ");
  Serial.println(buttonCounter);
 #endif
}


void robotSelect(){
  delay(100);
  
  if (buttonCounter <= 6)
    buttonCounter++;
  else
    buttonCounter = 0;
    
  #ifdef DEBUG
   Serial.print("Robot ID:  ");
   Serial.println(buttonCounter);
 #endif
}



void led(){
  if (buttonCounter == 0){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (buttonCounter == 1){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (buttonCounter == 2){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if (buttonCounter == 3){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if (buttonCounter == 4){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }
  else if (buttonCounter == 5){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }
  else if (buttonCounter == 6){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  else{
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
      
}
