#include <Arduino.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


/*
  This code reads the digital input from a PIR (passive infrared) motion sensor connected to pin 2. 
  If the digital input is HIGH, it prints the message "Somebody here!" to the serial monitor.
  
  Board: ESP32 Development Board
  Component: PIR (passive infrared) motion sensor(HC-SR501)
*/

// Define the pin number for the PIR sensor
const int pirPin = A1;
// Declare and initialize the state variable
int state = 0;

unsigned long startTime = 0;
unsigned long elapsedTime = 0;
bool running = true;

void setup() {
  pinMode(pirPin, INPUT);  // Set the PIR pin as an input
  Serial.begin(9600);      // Start serial communication with a baud rate of 9600
  Wire.begin(22,20);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  
  startTime = millis(); // Start the stopwatch
  
}

void loop() {

if (running && digitalRead(pirPin) == HIGH) {
    running = false;
    elapsedTime = millis() - startTime; // Lock in the final time
  }

    // Calculate elapsed time
    unsigned long timeToDisplay = running ? (millis() - startTime) : elapsedTime;
  
  int minutes = (timeToDisplay / 60000) % 60;
  int seconds = (timeToDisplay / 1000) % 60;
  int centiseconds = (timeToDisplay % 1000) / 10; // 0-99 hundredths of a second

  // Update Display
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(F("STOPWATCH"));
  
  display.setCursor(0, 25);
  if (seconds < 10) display.print("0");
  display.print(seconds);
  display.print(".");
  if (centiseconds < 10) display.print("0");
  display.print(centiseconds);
  
  display.display();
  delay(10); // Refresh rate limit
}
