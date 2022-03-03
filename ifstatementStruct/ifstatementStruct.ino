

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
#define LEDerrorCode 25

#define squareWave 19 //GPIO22


//typedef char specialfunc();
//specialfunc *mypointer(double,int);


void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:
  
  pinMode(SignalB, OUTPUT); //signalB from 21
  pinMode(LEDerrorCode, OUTPUT);
  
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

int digitalSwitchState=0;
void two(){
  
 Serial.println("task2");
     digitalSwitchState=digitalRead(SignalB);

  
}

int oscilloscopeFrequency;
void three(){
  Serial.println("task3");
  boolean found=false;
  boolean start = false;
  int squareReading;
  long unsigned int mark1;
  long unsigned int mark2;
  long unsigned int onTime;
  
  while(!found){
    Serial.println("task3 Finding");
    
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
  oscilloscopeFrequency=1/onTime;
}

float arrayValue[]={0,0,0,0};
void four(){
  Serial.println("task4");
  float potValue;
  potValue=analogRead(analogPot);
  float arrayValueV2[]={0,0,0,0};
//  arrayValueV2[2:4]=arrayValue[1:3];
  }

int global_average=0;
void five(){
  Serial.println("task5");
  int local_average=0;
  for(int i=0; i<4;i++){
    Serial.println("task 5 Iteration: ");
    Serial.println(i);
    global_average=arrayValue[i];
  }
  
  local_average=local_average/4;
  global_average=local_average;
}

void six(){
  Serial.println("task6");
  for(int i=0; i<1000; i++){
    __asm__ __volatile__ ("nop");
  }
}

int error_code=0;

void seven(){
  
  Serial.println("task7");
  if(global_average > (3.3/2)){
    error_code=1;
    }else{
      error_code=0;
    }
    
}
void eight(){
  Serial.println("task8");
  digitalWrite(LEDerrorCode,HIGH);
}

char buffer[7];
char dataStr[100] = "";

void nine(){
  //need to store:
  //state of the digital input (switch)
  //frequency value (Hz as integer)
  //filtered analog input (average reading)
  
  Serial.println("task9");

    dataStr[0]=0;
    
  dtostrf (digitalSwitchState, 5, 2, buffer);  //5 is minimum width, 1 is precision; float value is copied onto buff
 strcat( dataStr, buffer); //append the converted float
 strcat( dataStr, ", "); //append the delimiter
//
// dtostrf(oscilloscopeFrequency, 5, 2, buffer);  //5 is minimum width, 1 is precision; float value is copied onto buff
// strcat( dataStr, buffer); //append the converted float
// strcat( dataStr, ", "); //append the delimiter
//
// dtostrf(global_average, 5, 2, buffer);  //5 is minimum width, 1 is precision; float value is copied onto buff
// strcat( dataStr, buffer); //append the converted float
// strcat( dataStr, 0); //terminate correctly 
// Serial.println(dataStr);
 
  
}

int tick=0;

void burn(){
Serial.println("burning time");
    tick++;
    
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
  unsigned long currentTime;
   unsigned long mark1;
    unsigned long mark2;

   boolean testingVariable;
  //for(int slot=0; slot<SLOTX; slot++){
    int counter=1;
    delay(1000);
    for(auto &taskTimer: TaskTimers){
      testingVariable=1;
      Serial.println("testing");
      Serial.println(counter);
      
      while(testingVariable !=0){
        
        
        currentTime= millis();
        testingVariable=(currentTime/taskTimer.period)%9;
        Serial.println(testingVariable);
        if (testingVariable ==0){
          
       mark1= millis();
        //(*mypointer[slot])();
        taskTimer.task();
        mark2 = millis();
        float computeTime=mark2-mark1;
        Serial.println("task:");
        Serial.println(counter);
        Serial.println(computeTime);
        counter++;
        }else{
          burn();
        }
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
