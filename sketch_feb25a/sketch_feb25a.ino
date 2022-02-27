
#define SLOTX 4
#define CYCLEX 5
#define SLOT_T 5000


void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:
  pinMode(SignalA, OUTPUT); //signalA from 15
  pinMode(SignalB, OUTPUT); //signalB from 21

  pinMode(pushButton1, INPUT); //disable stream pulse button
  pinMode(analogPot, INPUT); //mode selection button

  


}

void (*ttable[SLOTX][CYCLEX])(){
  {task1,task2,task3,task4,task5},
  {burn,burn,burn,burn,burn},
  {burn,burn,burn,burn,burn}
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime= millis();


  
}


void task1(){
  //watchdog timer, same length
      digitalWrite(SignalB, HIGH); //starting signal
    delayMicroSeconds(signalBDelay); //starting signal
    digitalWrite(SignalB, LOW); //starting signal
    
}

int task2(){
  
 
  
}

void task3(){
  
}
void task4(){
  return digitalRead(PushButton);
}
void task5(){
  
}
void task6(){
  
}
void task7(){
  
}
void task8(){
  
}
void task9(){
  
}
