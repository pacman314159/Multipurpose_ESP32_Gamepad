#include <Arduino.h>

const int interval = 400;

void setup(){
  pinMode(13, 1);
  Serial.begin(19200);
}

void loop(){
  Serial.println("helloworld");
  digitalWrite(13, HIGH);
  delay(interval);
  digitalWrite(13, LOW);
  delay(interval);
}
