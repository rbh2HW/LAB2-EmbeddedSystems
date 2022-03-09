

//#include <stdio.h>
//#include <ctype.h>

//#include <sys/times.h>
//#include <SoftwareSerial.h>

#define SLOTX 4
#define CYCLEX 5
#define SLOT_T 5000

#define potMax 4095


#define SignalB 21 //GPIO21
#define pushButton1 23 //GPIO23
#define analogPot 35 //GPIO22
#define LEDerrorCode 25

#define squareWave 34 //GPIO22


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
void one() {
  //Serial.println("task1");
  digitalWrite(SignalB, HIGH);
  delayMicroseconds(50);
  digitalWrite(SignalB, LOW);
  delayMicroseconds(50);
}

int digitalSwitchState = 0;
void two() {

  //  Serial.println("task2");
  digitalSwitchState = digitalRead(pushButton1);


}

int oscilloscopeFrequency = 0;
void three() {
  //  Serial.println("task3");
  //  boolean found = false;
  //  boolean start = false;
  //  int squareReading = 0;
  float mark1;
  //  float mark2;



  //  while(!squareReading){
  //    squareReading=digitalRead(squareWave);
  //  }
  //  mark1=millis();
  //  while(squareReading){
  //    squareReading=digitalRead(squareWave);
  //  }
  //  mark2=millis();
  //  while(!found){
  //    Serial.println("task3 Finding");
  //
  //    squareReading=digitalRead(squareWave);
  //
  //      if(squareReading=1) {
  //        if(!start){
  //        mark1=millis();
  //        start=true;
  //        }
  //        else{
  //        delay(40); // taken from the minimum of 2.5%
  //      }
  //      }else{
  //        if(start){
  //          mark2=millis();
  //          found = true;
  //        }
  //      }
  //
  //
  //  }

  mark1 = pulseIn(squareWave, HIGH);
  //  mark2 = pulseIn(squareWave, LOW);
  float period = mark1 * 2; //is in microseconds
  float freq = 1e6 / period; //dividing by 1e6 as this is 1micro in second as you need to scale it
  oscilloscopeFrequency = freq;

  //   float freq=period;

  //   oscilloscopeFrequency = 1/period;

  //  float onTime=mark2-mark1;

  //  oscilloscopeFrequency=1/onTime;
  //  Serial.println(period);
  //  Serial.println("oscfrequency is: ");
  //  Serial.println(oscilloscopeFrequency);
  //    Serial.println("frequency is: ");
  //  Serial.println(freq);

}

int firstFour = 1;
float arrayValue[] = {0, 0, 0, 0};
void four() {
  //    Serial.println("task4");
  float potValue;
  potValue = analogRead(analogPot);
  //  Serial.println(potValue);
  //  float arrayValueV2[] = {0, 0, 0, 0};
  //  arrayValueV2[2:4]=arrayValue[1:3];

  if (firstFour < 4) { //this adds index and number for the first 4 values obtained for the average
    arrayValue[(firstFour - 1)] = potValue;
    firstFour++;

  } else {
    //with new array delete the last value from it and add the new value at index 1


    arrayValue[3] = arrayValue[2];
    arrayValue[2] = arrayValue[1];
    arrayValue[1] = arrayValue[0];



    arrayValue[0] = potValue;
    //    arrayValue = arrayValueV2;
    //    arrayValue[0:3]=arrayValueV2[0:3];
  }

}

int global_average = 0;
void five() {
  //    Serial.println("task5");
  int local_average = 0;
  for (int i = 0; i < firstFour; i++) {
    //    Serial.println("task 5 Iteration: ");
    //    Serial.println(i);
    local_average = local_average + arrayValue[i];
  }

  local_average = local_average / firstFour;
  global_average = local_average;
}

void six() {
  //  Serial.println("task6");
  for (int i = 0; i < 1000; i++) {
    __asm__ __volatile__ ("nop");
  }
}

int error_code = 0;

void seven() {

  //  Serial.println("task7");
  if (global_average > (potMax / 2)) {
    error_code = 1;
  } else {
    error_code = 0;
  }

}
void eight() {
  //  Serial.println("task8");
  if (error_code)
    digitalWrite(LEDerrorCode, HIGH);
  else
    digitalWrite(LEDerrorCode, LOW);
}

//char buffer[7];
//char dataStr[100] = "";

void nine() {
  //need to store:
  //state of the digital input (switch)
  //frequency value (Hz as integer)
  //filtered analog input (average reading)

  //  Serial.println("task9");

  //  dataStr[0] = 0;

  //  dtostrf (digitalSwitchState, 5, 2, buffer);  //5 is minimum width, 1 is precision; float value is copied onto buff
  //  strcat( dataStr, buffer); //append the converted float
  //  strcat( dataStr, ", "); //append the delimiter
  //  //
  //  dtostrf(oscilloscopeFrequency, 5, 2, buffer);  //5 is minimum width, 1 is precision; float value is copied onto buff
  //  strcat( dataStr, buffer); //append the converted float
  //  strcat( dataStr, ", "); //append the delimiter
  //  //
  //  dtostrf(global_average, 5, 2, buffer);  //5 is minimum width, 1 is precision; float value is copied onto buff
  //  strcat( dataStr, buffer); //append the converted float
  //  strcat( dataStr, ", "); //terminate correctly
  //  Serial.println(dataStr);

  Serial.print(digitalSwitchState);
  Serial.print(",");

  Serial.print(oscilloscopeFrequency);
  Serial.print(",");

  Serial.print(global_average);
  Serial.println(",");


}

unsigned long tick = 1;

void burn() {
  //  Serial.println("burning time");
  delayMicroseconds(900);
//  tick++;

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
struct TASKTIMER {
  void (*task)();
  unsigned long period;
} TaskTimers[] {
  {one, 16},
  {two, 200},
  {three, 1000},
  {four, 42},
  {five, 42},
  {six, 100},
  {seven, 333},
  {eight, 333},
  {nine, 5000}
};

//void (*mypointer[][])(void)(void)={
// {one,two,three,four,five},
//   {burn,burn,burn,burn,burn},
//  {burn,burn,burn,burn,burn}};


unsigned long beforemillis = 0;
void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime;
  float mark1;
  float mark2;

  boolean testingVariable = false;
  //for(int slot=0; slot<SLOTX; slot++){
  //    int counter=1;
  tick = millis();
  while (beforemillis == tick) {
    tick = millis();
  }
  beforemillis=tick;
  //  mark1 = micros();
  for (int i = tick; i < (tick + 16); i++) {
    for (auto &taskTimer : TaskTimers) {



      //    one();


      //
      if (((i % taskTimer.period) == 0.0) ) {
        testingVariable = true;
        //        mark1 = micros();
        //    seven();
        //        mark2 = micros();
        //        Serial.println(mark2 - mark1);
        //         three();

        //
        //          (*mypointer[slot])();

        //

        //
        //(*mypointer[slot])();

        taskTimer.task();

        //        Serial.println(testingVariable);


        //       mark1= millis();
        //(*mypointer[slot])();


        //        taskTimer.task();
        //        mark2 = millis();
        //        float computeTime=mark2-mark1;
        //        Serial.println("task:");
        //        Serial.println(counter);
        //        Serial.println(computeTime);
        //        counter++;
        //      tick++;
      }
    }

    if (!testingVariable) {
      burn();
      i++;
    }
  }
  //
  //  mark2 = micros();

  //  Serial.println(mark2 - mark1);

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
