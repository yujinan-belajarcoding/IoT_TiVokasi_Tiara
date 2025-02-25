#include <Arduino.h>

// put function declarations here:
int Merah= 23;
int Kuning= 25;
int Hijau= 33;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(23, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(33, OUTPUT);
}

void loop() {
  digitalWrite(23, HIGH);// put your main code here, to run repeatedly:
  delay(5000); // this speeds up the simulation
  digitalWrite(23, LOW);
  delay(5000);

  digitalWrite(25, HIGH);
  delay(5000);
  digitalWrite(25, LOW);
  delay(5000);

  digitalWrite(33, HIGH);
  delay(5000);
  digitalWrite(33, LOW);
  delay(5000);
}