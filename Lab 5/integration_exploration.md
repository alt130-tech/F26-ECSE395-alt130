# Lab 5 integration exploration
#### By Alex Thornton

---

## Lab 5 Objectives

This is the final lab working with the ESP32 and we will be working on integrating sensors and actuators.

## How the Assignment Was Completed and Contents 

Using Platform.IO and Windows Software

This markdown includes the location of the code for integrating the PIR Motion Sensor Module and the OLED Display Module. The purpose of itegrating this sensor and actuator was to develop a stopwatch that stops and displays the elapsed time on the OLED when motion was detected by the PIR. The code to comlete this can be found in folder Lab 5, folder src, motion_stopwatch.cpp.




### Steps to Completion

1. I chose my sensor (PIR Motion) and my actuator (OLED display)
2. I followed the wiring diagram on the Sunfounder site to the best of my ability for the PIR, that was mostly straight forward. I then folloed the wiring diagram for the OLED but this was harder because I had to change the MISO pin to the SCL pin and that took some trial and error but otherwise went smoothly.
3. I first worried about getting the motion sensor working so I copied the sample code from Sunfounder and that was working once I updated the pin (A1) and baud rate (9600).
4. Then I worried about making sure the OLED would display (this is where the trial and error came into play trying different pins). Eventuall I got it to display the sample code from Sunfounder.
5. Then I worked on merging them. I looked up the libraries needed for a stopwatch and to display the arduino's internal clock on the OLED. I found millis() was the internal clock and made it operate like a stopwatch.
6. Once I could get the time counting up like I wanted it to, I worked on getting it to stop. I made the time freeze on the screen and to stop updating when PIR pin went high.

## Images Of Circuit Set Up With Descriptions
<img width="3024" height="4032" alt="Untitled design (2)" src="https://github.com/user-attachments/assets/53f1f4a5-7635-40b5-b9cd-c61073c0a944" />

On the left of the board with the CWRU sticker is the ESP32 then next to it on the board is the OLED display. Off the board is the PIR sensor. The white bulb is what is detecting motion.

The feather's 3V pin is wired to both the OLED and PIR VCC/VDD pins.
The feather's gnd pin is wired to the PIR gnd pin.
The feather's SDA pin is wired to the OLED SDA pin and the feather's SCL pin is wired to the OLED SCK pin.
The feather's A1 pin is wired to the PIR out pin.




## Reflection
1. This assignment took 2 hours 
2. This I rate a medium difficulty
3. Just trying to figure out the pins and honeslty what I wanted to do that was within reason. I love getting to be creative like this but my scope is always too wide. Also just like the coding. I've never used C++ so having to go through and figure out that syntax while not knowing arduinos that well just takes me a while.
4. I'm back up. I don't know how I feel for this course. My group mates are great so I'm excited and feel supported. And I think this gave me the confidence to finally start the personal project I've been wanting to develop so yay.
