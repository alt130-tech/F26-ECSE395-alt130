/*#include <Arduino.h>

// function prototype
int voltage(float analogvalue);

// Put your potentiometer pin assignment here
const int sensorPin = A1;

void setup() {
    Serial.begin(115200);
}

void loop() {
    // This is the line for printing in the serial
    //Serial.println(voltage(analogRead(sensorPin)));
    int sensorValue = analogRead(sensorPin);//alt130 I think this new line is just storing the value read from the pin and converting it possibly to an int rather than a float, also it no longer prints the value directly.
    float sensorVoltage = (sensorValue * 3.3) / 4095.0;//alt130 this line stores the voltage of the pot in a float variable by calculating the voltage based on the sensor value read from the pin, the max of the sensor 4095
    Serial.println(sensorVoltage);
    delay(75); //alt130 this the delay in the loop for how often the value is read and printed from the potentiometer.
}

// function to calculate output voltage
int voltage(float analogvalue){
    int voltage;
    //analogRead(sensorPin); gives us 0-4095 values
    //use the formula (Analog value*Reference voltage) / (Sensor Resolution) to calculate the output voltage
    return voltage;
}*/