#include <MIDI.h>

int photocellPin = 0;
int xpin = 3;
int ypin = 2;
int zpin = 1;

void setup() {
  // Set MIDI baud rate:
  Serial.begin(9600);  
  pinMode(13,INPUT); //echo pin
  pinMode(12,OUTPUT); //trig pin
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12,LOW); //turn off trig as a precaution
  delayMicroseconds(2); //2 microsecond delay  
  digitalWrite(12,HIGH); //sends the sound out from the trig
  delayMicroseconds(10); //short 10 microsecond delay
  digitalWrite(12,LOW); //turn off trig
  long distVal = ((pulseIn(13,HIGH)/58.0)/400)*127;
  int x = (analogRead(xpin)/512.0)*127;
  int y = (analogRead(ypin)/512.0)*127;
  int z = (analogRead(zpin)/512.0)*127;
  noteOn(
  
  int photoVal = ((analogRead(photocellPin)/200.0)*127);
  //Serial.println(photoVal);
  noteOn(0x90,distVal,0x45);
  noteOn(0x90,photoVal,0x45);
  
  delay(100);
  
}


void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
