TaskHandle_t Task1;
TaskHandle_t Task2;
TaskHandle_t Task3;
TaskHandle_t Task4;
TaskHandle_t Task5;
TaskHandle_t Task6;
TaskHandle_t Task7;
TaskHandle_t Task8;
TaskHandle_t Task9;


const int led_1 = 32;
const int led_2 = 25;

void setup() {
  Serial.begin(115200); 
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);

  xTaskCreatePinnedToCore(Task1code,"Task1",10000,NULL,1,&Task1,0);                         
  delay(500); 

  xTaskCreatePinnedToCore(Task2code,"Task2",10000,NULL,1,&Task2,1);          
    delay(500); 
      xTaskCreatePinnedToCore(Task3code,"Task3",10000,NULL,1,&Task3,0);                         
  delay(500); 

  xTaskCreatePinnedToCore(Task4code,"Task4",10000,NULL,1,&Task4,1);          
    delay(500); 
      xTaskCreatePinnedToCore(Task5code,"Task5",10000,NULL,1,&Task5,0);                         
  delay(500); 

  xTaskCreatePinnedToCore(Task6code,"Task6",10000,NULL,1,&Task6,1);          
    delay(500); 
      xTaskCreatePinnedToCore(Task7code,"Task7",10000,NULL,1,&Task7,0);                         
  delay(500); 

  xTaskCreatePinnedToCore(Task8code,"Task8",10000,NULL,1,&Task8,1);          
    delay(500); 
      xTaskCreatePinnedToCore(Task9code,"Task9",10000,NULL,1,&Task9,1);          
    delay(500); 
}

void Task1code( void * parameter ){
  Serial.print("Task1 is running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(led_1, HIGH);
    delay(500);
    digitalWrite(led_1, LOW);
    delay(500);
  } 
}

void Task2code( void * parameter ){
  Serial.print("Task2 is running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(led_2, HIGH);
    delay(1000);
    digitalWrite(led_2, LOW);
    delay(1000);
  }
}
void Task3code( void * parameter ){
  Serial.print("Task1 is running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(led_1, HIGH);
    delay(500);
    digitalWrite(led_1, LOW);
    delay(500);
  } 
}

void Task4code( void * parameter ){
  Serial.print("Task2 is running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(led_2, HIGH);
    delay(1000);
    digitalWrite(led_2, LOW);
    delay(1000);
  }
}
void Task5code( void * parameter ){
  Serial.print("Task1 is running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(led_1, HIGH);
    delay(500);
    digitalWrite(led_1, LOW);
    delay(500);
  } 
}

void Task6code( void * parameter ){
  Serial.print("Task2 is running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(led_2, HIGH);
    delay(1000);
    digitalWrite(led_2, LOW);
    delay(1000);
  }
}
void Task7code( void * parameter ){
  Serial.print("Task2 is running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(led_2, HIGH);
    delay(1000);
    digitalWrite(led_2, LOW);
    delay(1000);
  }
}
void Task8code( void * parameter ){
  Serial.print("Task1 is running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(led_1, HIGH);
    delay(500);
    digitalWrite(led_1, LOW);
    delay(500);
  } 
}

void Task9code( void * parameter ){
  Serial.print("Task2 is running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(led_2, HIGH);
    delay(1000);
    digitalWrite(led_2, LOW);
    delay(1000);
  }
}

void loop() {
  
}
