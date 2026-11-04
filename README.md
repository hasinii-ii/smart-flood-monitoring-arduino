# Smart Flood Monitoring and Alert System

A three-level flood alert system built on Arduino Uno. An HC-SR04 ultrasonic sensor measures the distance to the water surface, and the firmware classifies it as Safe, Warning, or Danger, driving LEDs and a buzzer accordingly.

Simulated using Wokwi : [ Open in Wokwi ](https://wokwi.com/projects/479605436532812801)

## Features
- Ultrasonic distance measurement using the HC-SR04 sensor
- Three-level alert logic: Safe, Warning, and Danger
- Separate green, yellow, and red LED indicators
- Buzzer alerts with different behaviour for Warning and Danger
- Serial Monitor output for distance and current status
- Basic handling of missing ultrasonic echo readings

## Components
- Arduino Uno
- HC-SR04 Ultrasonic sensor
- Green, yellow, and red LEDs
- Passive buzzer
- 220 Ω resistors
- Jumper wires

## Pin Connections
| Component | Arduino pin |
| --- | --- |
| HC-SR04 TRIG | D2 |
| HC-SR04 ECHO | D3 |
| Green LED | D5 |
| Yellow LED | D6 |
| Red LED | D7 |
| Buzzer | D8 |

The HC-SR04 Ultrasonic sensor's VCC and GND are connected to the Arduino's power 5V and ground pins respectively. Each LED uses its own current-limiting resistor.

## Alert Logic
| State | Measured distance | LED behaviour | Buzzer |
| --- | --- | --- | --- |
| Safe | Greater than 200 cm | Green ON | Off |
| Warning | 100-200 cm | Yellow ON | Short beep every 1 s |
| Danger | Less than 100 cm | Red blinks | Continuous tone |
| Sensor fault | No echo | All LEDs OFF | Off, "No echo detected" printed |

## How It Works
1. The Arduino sends a trigger pulse to the HC-SR04 sensor.
2. The sensor returns an echo pulse whose duration is measured using 'pulseIn()'.
3. The distance is calculated using the echo duration and the approximate speed of sound:
   Disatnce (cm) =Duration (µs) * 0.0343 / 2 (round trip)
4. The measured distance determines the current alert state.
5. The LEDs and buzzer indicate the state, while the Serial Monitor displays the distance and status.
6. The program uses 'millis()' - based timing for periodic sensor measurements and red LED blinking. This avoids using long blocking delays for these operations.
7. If no echo is received, all outputs turns off and a fault message is printed.

## Circuit and results
Circuit-
![Circuit Diagram](https://github.com/user-attachments/assets/8ece1ed3-7de2-49fd-905e-01085b0ab42f)
SAFE-
![Safe state](https://github.com/user-attachments/assets/04fed38e-1be8-4828-8596-9d93209b7af4)
WARNING-
![Warning state](https://github.com/user-attachments/assets/29ab1609-1340-4882-b755-a8641ca77879)
DANGER-
![Danger state](https://github.com/user-attachments/assets/7242ce5a-8717-49a8-83e5-baead0bd0531)

## How to run
Open 'Smart_Flood_Monitoring_and_Alert_System/Smart_Flood_Monitoring_and_Alert_System.ino' in the Arduino IDE ( or the Wokwi ), upload, and open the Serial Monitor at 9600 baud. To run it without hardware, open the Wokwi simulation link above, press Play, and click the ultrasonic sensor to change the distance.

## Limitations and Future Improvements
- Simulated only; not yet tested on hardware
- No filtering or hysteresis is implemented, so noisy readings near a threshold can flip states.
- The HC-SR04 is not designed for direct exposure to water.
- Future improvements can include a waterproof sensor, wireless notifications, and a monitoring dashboard.

## Author
Hasini Nagabhyrava | ECE, IIITDM Kancheepuram | [LinkedIn Link](www.linkedin.com/in/hasini-nagabhyrava-05884638a)

## License
MIT
