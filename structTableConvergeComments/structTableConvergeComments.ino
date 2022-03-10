#define SLOTX 4
#define CYCLEX 5
#define SLOT_T 5000

#define potMax 4095


#define SignalB 21 //GPIO21
#define pushButton1 23 //GPIO23
#define analogPot 35 //GPIO22
#define LEDerrorCode 25

#define squareWave 34 //GPIO22

void setup() {
  Serial.begin(9600);

  pinMode(SignalB, OUTPUT); //signalB from 21
  pinMode(LEDerrorCode, OUTPUT);

  pinMode(pushButton1, INPUT); //disable stream pulse button
  pinMode(analogPot, INPUT); //mode selection button
  pinMode(squareWave, INPUT);
}

void one() {
  //this is the watchdog waveform task
  digitalWrite(SignalB, HIGH);
  delayMicroseconds(50);
  digitalWrite(SignalB, LOW);
  delayMicroseconds(50);
}

int digitalSwitchState = 0;
void two() {


  digitalSwitchState = digitalRead(pushButton1);


}

int oscilloscopeFrequency = 0;
void three() {
  float mark1;


  mark1 = pulseIn(squareWave, HIGH);
  //  mark2 = pulseIn(squareWave, LOW);
  float period = mark1 * 2; //is in microseconds
  float freq = 1e6 / period; //dividing by 1e6 as this is 1micro in second as you need to scale it
  oscilloscopeFrequency = freq;

}

//creating global variables which are accessed for potentiometer average value
int firstFour = 1;
float arrayValue[] = {0, 0, 0, 0};
void four() {

  float potValue;
  potValue = analogRead(analogPot);


  if (firstFour < 4) { //this adds index and number for the first 4 values obtained for the average
    //this is an edge condition
    arrayValue[(firstFour - 1)] = potValue;
    firstFour++;

  } else {
    //if there are 4 values in the array do this
    //with array delete the last value from it and add the new value at index 1
    arrayValue[3] = arrayValue[2];
    arrayValue[2] = arrayValue[1];
    arrayValue[1] = arrayValue[0];
    arrayValue[0] = potValue;

  }

}

int global_average = 0;
void five() {
  int local_average = 0;
  //for looping over certain amount of values, allows average of 1,2,3 and not average initial 0
  for (int i = 0; i < firstFour; i++) {
    //sum values
    local_average = local_average + arrayValue[i];
  }
  //divide by the amount of values in the array
  local_average = local_average / firstFour;
  global_average = local_average;
}

void six() {
  //no op task, does it required amount of times
  for (int i = 0; i < 1000; i++) {
    __asm__ __volatile__ ("nop");
  }
}

int error_code = 0;
void seven() {
  if (global_average > (potMax / 2)) {
    error_code = 1;
  } else {
    error_code = 0;
  }

}

void eight() {
  //condition for led code taking global variable and if there is an error then put led on
  if (error_code)
    digitalWrite(LEDerrorCode, HIGH);
  else
    digitalWrite(LEDerrorCode, LOW);
}

void nine() {
  //outputting to serial for csv
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
  //  delayMicroseconds(1);
  tick++;

}


struct TASKTIMER {
  void (*task)();
  unsigned long period;
} TaskPeriods[] {
  {one, 16000},
  {two, 200000},
  {three, 1000000},
  {four, 42000},
  {five, 42000},
  {six, 100000},
  {seven, 333000},
  {eight, 333000},
  {nine, 5000000}
};


unsigned long currentTime = 0;
void loop() {

  //  boolean testingVariable = false;

  currentTime++;
  //auto generating the datatype, & operator is point acess operator accessing the pointer struct
  for (auto &taskTimer : TaskPeriods) {



    //if the current clock time is divisable by the period of the task then execute the task
    if (((currentTime % taskTimer.period) == 0) ) {
      //      testingVariable = true;


      taskTimer.task();


    }


  }
}
