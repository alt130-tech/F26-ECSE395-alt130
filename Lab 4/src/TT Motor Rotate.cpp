/* #include <Arduino.h>
//alt130
// TODO: Define your pins
// Hint: Look at your wiring. Which pins did you use?
const int MOTOR_B_1A = A1; // Replaced with my pin numbers
const int MOTOR_B_1B = A0; // 

void setup() {
  // TODO: Initialize Serial communication
  Serial.begin(115200);//matching the baud rate of the serial monitor

  // TODO: Set your motor pins as OUTPUTs
  pinMode(MOTOR_B_1A, OUTPUT); // outputs like in the other skeleton code
  pinMode(MOTOR_B_1B, OUTPUT);

  Serial.println("Should've Stuck to BME");
}

void loop() {
  // --- SECTION 1: Clokwise (5s) ---
  Serial.println("Clockwise");
  
  // TODO: Write HIGH to one pin and LOW to the other
  digitalWrite(MOTOR_B_1A, LOW);
  digitalWrite(MOTOR_B_1B, HIGH);//turning on the motor

  delay(5000);// 5 seconds on

  // --- SECTION 2: Stop (2s) ---
  Serial.println("Stop");
  
  // TODO: Turn off the motor
  digitalWrite(MOTOR_B_1A, LOW);//turning off the motor
  digitalWrite(MOTOR_B_1B, LOW);

  delay(2000);//2 second stop

  // --- SECTION 3: Counterclockwise (5s) ---
  Serial.println("Counterclockwise");
  
  // TODO: Write HIGH to one pin and LOW to the other
  digitalWrite(MOTOR_B_1A, HIGH);//turning the motor back on
  digitalWrite(MOTOR_B_1B, LOW);

  delay(5000);//5 seocnds on

  // --- SECTION 4: Stop (2s) ---
  Serial.println("Goodbye");
  
  // TODO: Turn off the motor
  digitalWrite(MOTOR_B_1A, LOW);
  digitalWrite(MOTOR_B_1B, LOW);//turn off motor

  delay(2000);//for two seconds
}


// Note:
// - Please uncomment the necessary lines and fill in the blank to complete the assignment. */