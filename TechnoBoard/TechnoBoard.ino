#include <MIDI.h>
#include <IRremote.h>


/*Midi flags*/
byte midi_start = 0xfa;
byte midi_stop = 0xfc;
byte midi_clock = 0xf8;
byte midi_continue = 0xfb;
int play_flag = 0;
byte data;
/***********/

/*Pin Setup*/
int irPin = 13; //digital pin 13
int gyroPin = 0; //analog pin 0 for x axis on gyroscope
int soundPin = 1; //analog pin 1 for sound sensor
int photoPin = 2;
int potPin = 3;
/***********/

/*Counter Setup*/
int tempo;
int drumCounter = 0;
int counterDrums = 0;
int brightCounter = 0;
/***************/


/*MIDI Setup*/
struct MySettings : public midi::DefaultSettings
{
  static const long BaudRate = 115200;
};

MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MySettings);
/*************/

/*IR Setup*/
IRrecv irrecv(irPin);
decode_results irCode;
/***********/

/*Channel Table*/
int drumChannel = 1;
int irChannel = 2; //IR
int brightChannel = 3;
int pitchChannel = 4; //sends to bass channel 
int bassChannel = 4;  
/**************/



void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);  // Listen to all incoming messages
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  tempo = getPot(); //set the tempo from potentiometer
  MIDI.sendControlChange(16,tempo,10); //channel 10 is a "magic channel" -Denis
  int velocity = getSoundLevel();
  setPitchBend();
  

  setData();
  
  if((data == midi_clock) && (play_flag == 1)){
    
    if(drumCounter == 0) {
      syncDrums(velocity); //TODO: Change from velocity to something else (or remove)
      
    }

     if(brightCounter == 0) {
      syncBright(getBrightness());
      
    }
      
    drumCounter = (drumCounter+1) % 11; //11 is the magic number 
    brightCounter = (brightCounter+1) % 7;
  }

  String IR = getIR();
  if(IR != "none"){
    getChord(IR);
  }

  

}

void setData(){
  data = Serial.read();
  while (data != (midi_start) && data != (midi_stop) && data != (midi_clock) && data != (midi_continue)) {
    data = Serial.read();
  } 
  
  if(data == midi_start){
    play_flag = 1;
  }
  else if(data == midi_continue){
    play_flag = 1;
  }
  else if(data == midi_stop){
    play_flag = 0;
    drumCounter = 0;
    brightCounter = 0;
  }
}

int getPot(){
  return ((analogRead(potPin)/1023.0)*127.0); 
}

int getBrightness(){
  int photoVal = ((analogRead(photoPin) / 250.0) * 127);
  if(photoVal < 20){
    photoVal = 20;
  }
  return photoVal;
}

/*
 * Gets the value from the sound sensor module
 */
int getSoundLevel(){
    //TODO: Scale better
    int soundLevel = (((analogRead(soundPin)-50)/70)*127) + 40;
    if(soundLevel > 127){
      soundLevel = 127;
    }
    
    return soundLevel;
}

/*
 * Get the value (scaled) from the gyroscope
 * (x values only)
 */
int getXTilt(){
   int x = (analogRead(gyroPin) / 512.0) * 16383;
   return x;
}


String getIR(){
  if (irrecv.decode(&irCode)) {
    
    String code = padBytes(String(irCode.value,HEX)); //pads the bytes to an even number
    irrecv.resume(); // Receive the next value
    return code;
  }
  else{
    return "none";
  }
}


/* Adds padding to the bytes to give an 
 * even number of bytes.
 */
String padBytes(String hex){
  int len = hex.length();
  if(len%2 == 1){
    hex = "0" + hex;
  }
  return hex;
}

void playChord(String chord[]){
  int len = sizeof(chord)*2;
  //Serial.println("Len = " + String(len));
  for(int i = 0;i < len;i++){
    //MIDI.sendNoteOn(strtoul(chord[i].c_str(),NULL,16),69,irChannel);
   // Serial.print(chord[i] + "|");
  }
  //Serial.println();
}

void getChord(String hex){
  String chord[hex.length()/2] = {};
  for(int i = 0;i < hex.length()/2;i++){
    chord[i] = String(hex[(2*i)]) + String(hex[(2*i)+1]);
    //Serial.println("Note: " + chord[i]);
  }
  playChord(chord);
}
/*Note playing functions*/
void setPitchBend(){
  MIDI.sendPitchBend(getXTilt(),bassChannel);
}

void sync() {
  MIDI.sendNoteOn(50,69,1);
}

void syncDrums(int velocity) {
  MIDI.sendNoteOn(42,velocity,drumChannel);
}

void syncBass(int velocity) {
  MIDI.sendNoteOn(50,velocity,bassChannel);
}

void syncBright(int note){
  MIDI.sendNoteOn(note,69,brightChannel);
}


