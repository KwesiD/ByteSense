#include <MIDI.h>
byte midi_start = 0xfa;
byte midi_stop = 0xfc;
byte midi_clock = 0xf8;
byte midi_continue = 0xfb;
int play_flag = 0;
byte data;

struct MySettings : public midi::DefaultSettings
{
  static const long BaudRate = 115200;
};
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MySettings);
void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);  // Listen to all incoming messages
}

void loop() {
 data = Serial.read();
 
if(data==midi_start){
  play_flag=1;
}
else if (data==midi_continue){
  play_flag=1;
}
else if(data==midi_stop){
  play_flag=0;
}

if((data==midi_clock)&&(play_flag==1)){
  sync();
}

}

void sync() {
  MIDI.sendNoteOn(50,69,1);
}

