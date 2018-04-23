//http://forum.arduino.cc/index.php?topic=314569.0

#include "pitches.h"

int notes[] = {
NOTE_B0,NOTE_C1,NOTE_D1,NOTE_E1,NOTE_F1,NOTE_G1,NOTE_A1,
NOTE_B1,NOTE_C2,NOTE_D2,NOTE_E2,NOTE_F2,NOTE_G2,NOTE_A2,
NOTE_B2,NOTE_C3,NOTE_D3,NOTE_E3,NOTE_F3,NOTE_G3,NOTE_A3,
NOTE_B3,NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,
NOTE_B4,NOTE_C5,NOTE_D5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_A5,
NOTE_B5,NOTE_C6,NOTE_D6,NOTE_E6,NOTE_F6,NOTE_G6,NOTE_A6};

int Tone = 0;
int speaker1Pin = 2;
int speaker2Pin = 4;
const int ldrPin = A2;
const int ldrPin2 = A4;
const int slowthreshold = 1000;
const int mediumthreshold = 512;
const int fastthreshold = 15;

void setup() {
Serial.begin(9600);
pinMode(ldrPin, INPUT);
pinMode(ldrPin2, INPUT);
}

void loop() {

int sensor1Value = analogRead(A1); // 0 – 1023
int sensor2Value = analogRead(ldrPin);
int sensor3Value = analogRead(ldrPin2);
Serial.print("frequency: ");
Serial.println(sensor2Value);
Serial.print("delay: ");
Serial.println(sensor3Value);
Serial.print("speed: ");
Serial.println(sensor1Value);

int sp33d = sensor1Value;
int pitch1 = sensor2Value/24;
int pitch2 = sensor3Value/24;

if (sensor1Value < fastthreshold){
noTone(speaker1Pin);
  tone(speaker2Pin, notes[pitch2], 200);
  delay(fastthreshold);
  noTone(speaker2Pin);
  tone(speaker1Pin, notes[pitch1], 200);
  delay(fastthreshold);
}
if (fastthreshold < sensor1Value) {
  noTone(speaker1Pin);
  tone(speaker2Pin, notes[pitch2], 200);
  delay(sp33d);
  noTone(speaker2Pin);
  tone(speaker1Pin, notes[pitch1], 200);
  delay(sp33d);
}
}
