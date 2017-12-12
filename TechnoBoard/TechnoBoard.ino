#include <IRremote.h>

int irPin = 13; //digital pin 13
int gyroPin = 0; //analog pin 0 for x axis on gyroscope
int soundPin = 1; //analog pin 1 for sound sensor
int photoPin = 2;
int potPin = 3;

 
IRrecv irrecv(irPin);
decode_results irCode;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  Serial.println("Brightness: " + String(getBrightness()));
  Serial.println("Sound Level: " + String(getSoundLevel()));
  Serial.println("Potentiometer: " + String(getPot()));
  Serial.println("IR: " + getIR());
  Serial.println("X Tilt: " + String(getXTilt()));
  Serial.println("-------------------------------");
}


int getPot(){
  return analogRead(potPin);  
}

int getBrightness(){
  int photoVal = ((analogRead(photoPin)));// / 200.0) * 127);
  return photoVal;
}

/*
 * Gets the value from the sound sensor module
 */
int getSoundLevel(){
    int soundLevel = analogRead(soundPin);
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

