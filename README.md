# Alarm  System

## The objectives of the proposed project
- Overall objective: Develop an automated safety system that detects smoke and vibration and reacts accordingly.
- Specific objectives
  -	Smoke/Gas detection with a dedicated sensor.

  -	Vibration detection with a vibration sensor.

  -	Automated control of a barrier, a window and a fan according to the signals received from the sensors.

  -	System testing and validation in a simulated environment.

## Description of the proposed and implemented solution with the presentation of the functionalities related to the solution
- Hardware Components:
  -	Gas Sensor MQ-2
  -	Vibration Sensor tilt SW 520-D
  -	10k ohm Rezistor
  - 2x DC Motor for Fan and Window
  - Miniature motor for barrier
  - Arduino NANO Board
  - Breadboard
  - Wire M-M and M-F
  - 2x Shift Register L293D
  - Red LED
  - 330 ohm Resistor
  - Buzz Passiv
- Software Components:
  - Sensors and motors control code
- Functionalities:
  - Smoke and vibration detection
  - Barrier motor control to lower and raise the barrier.
  - Window motor control to open and close the window.
  - Fan activation in case of smoke detection.
 	
  I proposed an automated safety system that uses smoke and vibration sensors to automatically control a barrier and a window. The system is able to react quickly to sensor signals, lowering the barrier, opening the window and starting the fan in case of detection of vibrations (anti-burglary) or smoke (fire). Also, if the system is triggered, an alarm will sound and an LED will light up.

  As for the mechanism to lower and raise the barrier in front of the door, in case of detecting strong vibrations, we used a SW-520D vibration sensor, a sensor that is used in bomb making. On the Breadboard it is placed vertically, and inside there are two balls placed on top of each other, being the initial state that will return 1-logic. In case of a strong vibration, and according to the principle of action and reaction, the two balls will not touch in a short time, the ball above will be slightly raised, thus returning logic 0.

  These results lead to a reverse logic in terms of the code and functionality offered by the Arduino board, thus we considered the following scenario: the difference between the case where someone would want to break into a building and the case where a guest comes and knocks on the door, failing to generate a strong enough vibration to activate the sensor.

  When the vibration sensor no longer detects anything, the barrier will rise to its original position and the alarm will stop.


	The fire system release is equipped with an MQ2 gas sensor that is used to detect gas leaks in small or large rooms and is a precautionary method for fires or poisoning. The sensor has high sensitivity and the main gases it targets are LPG, isobutane, propane, methane, alcohol, hydrogen and smoke. The sensor has a comparator so it can read analog data in real time or find out if the gas concentration has exceeded a certain limit. On the software side, a certain limit of the value obtained by the sensor is set in the code, which leads to its sensitivity and how the process works. When the limit of the obtained value exceeds the imposed value, the fire system is activated, so the two DC motors will start, one will open the window in the room, and the other will start the fan next to the window. The fan has an important role, given the fact that certain gases or fumes are very dense, as it is not enough just to open a window to reduce the danger as much as possible. It will also start the fire alarm consisting of a passive buzz that generates a sound and a red LED will light up.

  If the sensor returns values that do not exceed the imposed limit, then the system will return to the initial position, so the window will close, the fan and the alarm will stop.

  As for the rotation of the motors, the fan motor only rotates in one direction, as it only has the role of taking the smoke or gas out, not being necessary for the reverse rotation, but in the case of the barrier and window specific motors, we used 2x Shift Register L293D to be able to rotate the two motors in both directions, because after the alarm has been triggered and the danger has been removed, the system must return to its original position.
 
 
## Testing the solution
- Test procedure:
  - Smoke sensor testing: controlled gas generation and observation of system response.
  - Vibration sensor testing: simulating some vibrations and observing the system response.
  - Motor testing: checking the movement of the barrier, the window and the fan according to the sensor signals.
  - Fire and burglar alarm testing: verification of alarm activation and deactivation, based on several possible scenarios.

- Results:
  - The smoke sensor triggered the opening of the window and the start of the fan.
  - The vibration sensor triggered the lowering of the barrier.
  - Barrier and window movement was correct and as expected.
  - The alarm was properly triggered.








