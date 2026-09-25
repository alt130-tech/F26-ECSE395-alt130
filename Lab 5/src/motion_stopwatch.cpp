#include <Arduino.h>
//alt130
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define OLED_RESET -1//no reset pin
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);//initialize the display with the correct width, height, and I2C address


// Define the pin number for the PIR sensor
const int pirPin = A1;

int state = 0;//set pir to low

unsigned long startTime = 0;//stopwatch start time
unsigned long elapsedTime = 0;//no time has elapsed yet
bool running = true;//starts the stop watch immediately when program starts, for futur I would like to hook up a sound to alert exactly when that happpens

void setup() {
  pinMode(pirPin, INPUT); 
  Serial.begin(9600);      
  Wire.begin(22,20);// Initialize I2C with custom SDA and SCL pins

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {// Initialize the OLED display
    Serial.println(F("SSD1306 allocation failed"));// Check if the display was initialized 
    for (;;)
      ;
  }

  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  
  startTime = millis(); // Start the stopwatch
  
}

void loop() {

//help from the gfx library and sample code from adafruit
if (running && digitalRead(pirPin) == HIGH) {//check if the stopwatch is going and if motion has been detected
    running = false;//if it has stop watch shouldn't keep updating time
    elapsedTime = millis() - startTime; // Lock in the final time
  }

    // Calculate elapsed time
    unsigned long timeToDisplay = running ? (millis() - startTime) : elapsedTime;//cool shorthand for if else statements, if running is true then timeToDisplay = millis() - startTime, else timeToDisplay = elapsedTime
  
  int minutes = (timeToDisplay / 60000) % 60;//minutes
  int seconds = (timeToDisplay / 1000) % 60;//seconds
  int centiseconds = (timeToDisplay % 1000) / 10; // 0-99 hundredths of a second

  // Update Display
  //Only using this stopwatch for times under a minute because ideally people would run between bases in less than a minute
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(F("STOPWATCH"));
  
  //displaying the time neatly
  display.setCursor(0, 25);
  if (seconds < 10) display.print("0");
  display.print(seconds);
  display.print(".");
  if (centiseconds < 10) display.print("0");
  display.print(centiseconds);
  
  display.display();
  delay(10); // Refresh rate limit
}
