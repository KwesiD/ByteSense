#include <HIDSerial.h> //includes library for serial monitoring

//SquareWear v2.2

#define BUTTON 3  //Analog input A3 (same as arduino)
HIDSerial serial; //create a new serial object
const float factor = (3.3/1023.0); //Converts analog input valuess (0-1023) to voltage (SquareWear ouputs max of 3.3V) 

void setup() {
  serial.begin();
}

void loop() {
 float voltage = analogRead(BUTTON) * factor;  //read analog input and multiply it by the factor
 serial.println(voltage);
}
  
