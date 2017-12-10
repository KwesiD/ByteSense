#include <MIDI.h>


int photocellPin = 0;
int xpin = 3;
int ypin = 2;
int zpin = 1;
int potPin = 4;
int tempPin = 5;
int soundPin = 11; //digital pin


//MIDI_CREATE_DEFAULT_INSTANCE();
struct MySettings : public midi::DefaultSettings
{
  static const long BaudRate = 115200;
};
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MySettings);
void setup() {
  // Set MIDI baud rate:
  //Serial.begin(115200);
  pinMode(13, INPUT); //echo pin
  pinMode(12, OUTPUT); //trig pin
  pinMode(11,INPUT);
  MIDI.begin(MIDI_CHANNEL_OMNI);  // Listen to all incoming messages
}

void loop() {
  // put your main code here, to run repeatedly:
  /*digitalWrite(12, LOW); //turn off trig as a precaution
  delayMicroseconds(2); //2 microsecond delay
  digitalWrite(12, HIGH); //sends the sound out from the trig
  delayMicroseconds(10); //short 10 microsecond delay
  digitalWrite(12, LOW); //turn off trig
  long distVal = pulseIn(13, HIGH,1000); //time out in 1 millisecond (1000 microseconds)
  //delay(100);
  distVal = (((distVal) / 58.0) / 400.0) * 127;*/
  int x = (analogRead(xpin) / 512.0) * 16383;
  int y = (analogRead(ypin) / 512.0) * 127;
  int z = ((analogRead(zpin) / 512.0) * 16383);
  float tempVoltage = (analogRead(tempPin)*5.0)/1024.0;
  float temp = (tempVoltage - 0.5)*100; 
  temp = (temp * (9.0/5.0)) + 32;
 // Serial.println(temp);
 if(digitalRead(soundPin) == LOW){
  Serial.println("Loud");
 }
 
  int photoVal = ((analogRead(photocellPin) / 200.0) * 127);
  //Serial.println(photoVal);
  // noteOn(0x90, distVal, 0x45);
  //noteOn(0x90,photoVal,0x45);
  //Serial.println(z);
  //>>MIDI.sendPitchBend((x),1);
  //MIDI.sendNoteOn(50, 69 , 1);
  //MIDI.sendPitchBend((x),1);
  //MIDI.read();
  //delay(analogRead(potPin));
  //>>MIDI.sendNoteOn(distVal,69,2);
  //MIDI.read();
  //MIDI.sendNoteOn(photoVal, 127, 2);
  //>>delay(analogRead(potPin));


  
  //delay(500);

}


void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
