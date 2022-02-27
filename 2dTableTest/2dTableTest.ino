//#include <stdio.h>
//#include <ctype.h>

//#include <sys/times.h>


#define SLOTX 4
#define CYCLEX 5
#define SLOT_T 5000


#define SignalB 21 //GPIO21
#define pushButton1 23 //GPIO23
#define analogPot 22 //GPIO22

//typedef char specialfunc();
//specialfunc *mypointer(double,int);


void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:
  
  pinMode(SignalB, OUTPUT); //signalB from 21

  pinMode(pushButton1, INPUT); //disable stream pulse button
  pinMode(analogPot, INPUT); //mode selection button

  


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
    
}

void two(){
  
 Serial.println("task2");
  
}

void three(){
  Serial.println("task3");
}
void four(){
  Serial.println("task4");
}
void five(){
  Serial.println("task5");
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

void (*mypointer[])(void)={
  one,
  two,
  three,
  four,
  five
          };
                          
//void (*mypointer[][])(void)(void)={
 //  {one,two,three,four,five},
 //   {burn,burn,burn,burn,burn},
  // {burn,burn,burn,burn,burn}};

  void (*mypointer[][])(void)(void)={
   {one,two,three,four,five},
   {burn,burn,burn,burn,burn},
   {burn,burn,burn,burn,burn}};
  

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime= millis();

   


  for(int slot=0; slot<SLOTX; slot++){
    


     for (int cycle=0;cycle<CYCLEX;cycle++){
        (*mypointer[slot][cycle])();
        delay(1000);
      }
  
  
    }
  
}
