#define SignalB 21 //GPIO21
#define analogPot 35 //GPIO22

void setup() {
  // put your setup code here, to run once:
  pinMode(analogPot, INPUT); //mode selection button
  pinMode(squareWave, INPUT);
  pinMode(SignalB, OUTPUT); //signalB from 21
}

void one() {
  //Serial.println("task1");
  digitalWrite(SignalB, HIGH);
  delayMicroseconds(50);
  digitalWrite(SignalB, LOW);
}

int digitalSwitchState = 0;
void two() {

  //  Serial.println("task2");
  digitalSwitchState = digitalRead(SignalB);


}

void loop() {
  // put your main code here, to run repeatedly:
//  one();
  delay(1);
  Serial.println(digitalSwitchState)

}
