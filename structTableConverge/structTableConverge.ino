

//#include <stdio.h>
//#include <ctype.h>

//#include <sys/times.h>
//#include <SoftwareSerial.h>

#define SLOTX 4
#define CYCLEX 5
#define SLOT_T 5000


#define SignalB 21 //GPIO21
#define pushButton1 23 //GPIO23
#define analogPot 22 //GPIO22

#define squareWave 19 //GPIO22


//typedef char specialfunc();
//specialfunc *mypointer(double,int);


void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:
  
  pinMode(SignalB, OUTPUT); //signalB from 21

  pinMode(pushButton1, INPUT); //disable stream pulse button
  pinMode(analogPot, INPUT); //mode selection button
  pinMode(squareWave, INPUT);
  


}





//void (*ttable[SLOTX][CYCLEX])(void)={
   //{task1,task2,task3,task4,task5},
   //  {burn,burn,burn,burn,burn},
  //  {burn,burn,burn,burn,burn}};

//void one(void);
//void two(void);
//void three(void);
//void four(void);
//void five(void);
void one(){
Serial.println("task1");
    digitalWrite(SignalB,HIGH);
    delayMicroseconds(50);
    digitalWrite(SignalB,LOW);
}

void two(){
  
 Serial.println("task2");
     digitalRead(SignalB);

  
}

void three(){
  Serial.println("task3");
  boolean found=false;
  boolean start = false;
  int squareReading;
  long unsigned int mark1;
  long unsigned int mark2;
  long unsigned int onTime;
  while(!found){
    squareReading=digitalRead(squareWave);
      if(squareReading) {
        if(!start){
        mark1=millis();
        start=true;
        }
        else{
        delay(40); // taken from the minimum of 2.5%
      }
      }else{
        if(start){
          mark2=millis();
          found = true;
        }
      }
      
     
  }
  onTime=mark2-mark1;
  
}

float arrayValue[]={0,0,0,0};
void four(){
  Serial.println("task4");
  float potValue;
  potValue=analogRead(analogPot);
  float arrayValueV2[]={0,0,0,0};
//  arrayValueV2[2:4]=arrayValue[1:3];
  }


void five(){
  Serial.println("task5");
  int average=0;
  for(int i=0; i<4;i++){
    Serial.println("task 5 Iteration: ");
    Serial.println(i);
    average=arrayValue[i];
  }
  
  average=average/4;
}
void six(){
  Serial.println("task6");
  
}
void seven(){
  Serial.println("task7");
}
void eight(){
  Serial.println("task8");
}
void nine(){
  Serial.println("task9");
}

void burn(){
Serial.println("burning time");
    
}

//each task
//void (*mypointer[])(void)={
//  one,
//  two,
//  three,
//  four,
//  five,
//  six,
//  seven,
//  eight,
//  nine
//          };
//        
struct TASKTIMER{
  void (*task)();
  unsigned long period;
} TaskTimers[]{
  {one,5},
  {two,200},
  {three,1000},
  {four,41},
  {five,41},
  {six,100},
  {seven,333},
  {eight,333},
  {nine,5000}
};
                  
//void (*mypointer[][])(void)(void)={
  // {one,two,three,four,five},
  //   {burn,burn,burn,burn,burn},
  //  {burn,burn,burn,burn,burn}};
  

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime= millis();
  int tick=0;


   boolean testingVariable;
  //for(int slot=0; slot<SLOTX; slot++){

    for(auto &taskTimer: TaskTimers){
        testingVariable=(currentTime/taskTimer.period)%2;
        Serial.println(testingVariable);
        if (testingVariable){
        //(*mypointer[slot])();
        taskTimer.task();
        delay(1000);
        }else{
          burn();
        }
  
  
    }


  
//  for(int slot=0; slot<SLOTX; slot++){
//
////       if ( *mypointer[slot]()){
////          
////       }
//         one();
//         two();
//         three();
//         four();
//         five();
//         six();
//         seven();
//         eight();
//         nine();
//        
//        tick++;
//    }
  
}
