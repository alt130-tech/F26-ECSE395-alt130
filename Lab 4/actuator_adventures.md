# Lab 4 actuator adventures
#### By Alex Thornton

---

## Lab 4 Objectives

This is the 3rd lab working with the ESP32 and it will focus on connecting actuators to the ESP32.

## How the Assignment Was Completed and Contents 

Using Platform.IO and Windows Software

This markdown includes the location of the code for testing the TT Motors functionality and different code parameters is found in the TTMotor.cpp and TTMotorRotate.cpp is the location for the code that has custom function for TTMotor to turn clockwise for 5 seconds and stop and counter for 5 seconds. It also includes the location of the code for testing the servos functionality and different parameter effects in the ServoMotor.cpp and ServoMotorRandom.cpp is the location for the code tha has a custon function for the servo to randomly spin to new angles and then delay for a random amount of time and go again.

All of these .cpp files are in the lab 4 folder, under src. To implement the code for the TTMotor all that is needed is to connect an esp32 to a breadboard and then hook up a motor drive to the power supply at a max current of .15 Amps and a max voltage of 3v, then attach the TTMotor to the motor drive. To implement the code for the Servo all that is needed is to connect and esp32 to a breadboard and then connect a servo to a power supply at a max current of .75 Amps and a max voltage of 5v. 

### Steps to Completion

1. Followed the lab instructions to build the circuit for the TT Motor
2. Uploaded the TTMotor code to my ESP32 and edited the code to put the set up potion in the loop so it would run.
3. Modified the analogWrite() value
4. swapped the analogWrite() values
5. Modified the Delay()
6. Opened TTMotorRotate to edit and comment on
7. Then followed the lab instructions to make it spin clockwise for 5, stop for 2, counter for 5, stop for 2, repeat
8. Skipped the extra credit cause I truly do not understand this
9. Picked out the servo and placed the TTMotor Back
10. Set up the circuit according to the lab manual
11. Uploaded the ServoMotor Code to observe the function
12. I changed the minPulseWidth
13. I changed the maxPulseWidth
14. I changed setPeriodHertz
15. I changed the rotationrange
16. I changed the delay
17. Opened ServoMotorRandom and edited the code so the servo turned to random angles with random delays

### Observations

- Step 3: changing the analogWrite() value from 255 to 150 and now the motor is spinning much lower.
- Step 4: swapping the analogwrite() values from 255, 0 to 0, 255 made the motor spin in the opposite direction
- Step 5: Modifying the delay changes how long the motor spins for and is then off for
- Step 12: I changed the minPulseWidth() from 500 to 1000, it now stops short of making the full 180 degree rotation
- Step 13: I changed the maxPulseWidth() from 2500 to 2000, it also caused it to fall short of a full 180 degree rotation
- Step 14: I changed the setPeriodHertz to 25 from 50 and the movement of the servo looks less smooth
- Step 15: I changed the rotationRange from 180 to 90 and kept the 500 and 2500 values and now it goes about 90 degrees and    a lot faster than before
- Step 16: I changed the delay from 15 to 500 and that was the worst choice ever the servo took half a second to move every    pulse

## Images Of Circuit Set Up
<img width="567" height="756" alt="Untitled design (1)" src="https://github.com/user-attachments/assets/17c0d6f5-c731-4e8d-b96c-01581a18f72a" />
<img width="535" height="714" alt="Untitled design" src="https://github.com/user-attachments/assets/0115ca7b-77a2-46a4-ab20-d803ad8b6ab3" />




## Reflection
1. This assignment took 3 hours. As of right now I still have to push things to github which I struggle with
2. This I rate a high difficulty. 
3. I couldn't understand the instructions very well and observing changes in something that is spinning is very difficult especially when I don't really know what I'm looking for. I still do not feel comfortable with the servo and how the changes in 'angle' or pulsewidths really do anything
4. After this lab emotions are low. I don't feel great in this course and I feel like I'm back over my head and just lucky that my group knows how to work with this stuff.

