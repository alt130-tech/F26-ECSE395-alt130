#include <Arduino.h>

//alt130, pin defined as A1
const int sensorPin = A1;

const int ledPin = 13; //alt130 defining the led pin to 13, where it is built into the esp 32


void setup() {
  Serial.begin(115200);

  pinMode(sensorPin,INPUT); //alt130 defining the sensor pin as an input
  pinMode(ledPin,OUTPUT); //alt130 defining the led pin as an output

}

void loop() {
  //This line should print out the values from the sensor by Serial.println(??);
  if (analogRead(sensorPin) > 0){
    Serial.println("Touch Detected");
    digitalWrite(ledPin, HIGH); //alt130 turning on the led when touch is detected
  }
  else{
    Serial.println("No Touch Detected");
    digitalWrite(ledPin, LOW); //alt130 turning off the led when no touch is detected
  }
  
  delay(50); 
  //the frequency is every 50 ms I didn't change this from the original becuase I like how often it checks if the touchis there or not, however the message printed will display whether touch is detected or not
}

