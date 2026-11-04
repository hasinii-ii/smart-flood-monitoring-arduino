# Smart Flood Monitoring and Alert System

# 1. Project Overview
The Smart Flood Monitoring and Alert System is an Arduino Uno-based prototype designed to monitor water levels using an ultrasonic sensor and provide alerts based on the measured distance.
The system classifies the detected water level into three conditions: Safe, Warning, and Danger. LEDs and a buzzer provide visual and audio alerts.

# 2. Objectives
- Measure the distance between the ultrasonic sensor and the water surface.
- Classify conditions into three alert levels.
- Provide visual indications using LEDs.
- Generate audio alerts using a buzzer.
- Display distance readings and system status through the Serial Monitor.

# 3. Components Used
| Component | Quantity |
| --- | --- |
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Green LED | 1 |
| Yellow LED | 1 |
| Red LED | 1 |
| Buzzer | 1 |
| 220 Ω Resistors | 3 |
| Jumper wires | As required |

# 4. Pin Configuration
| Component | Arduino Pin |
| --- | --- |
| HC-SR04 TRIG | D2 |
| HC-SR04 ECHO | D3 |
| Green LED | D5 |
| Yellow LED | D6 |
| Red LED | D7 |
| Buzzer | D8 |

# 5. Working Principle
The HC-SR04 ultrasonic sensor measures the distance to the water surface by transmitting ultrasonic waves and measuring the time taken for the reflected waves to return.
The distance is calculated using:
Distance = ( Time × 0.0343 ) / 2
Based on the measured distance, the system activates the corresponding alert.
# Alert Conditions
| Distance | Condition | Indication |
| --- | --- | --- |
| Greater than 200 cm | Safe | Green LED ON |
| 100-200 cm | Warning | Yellow LED ON and intermittent buzzer |
| Less than 100 cm | Danger | Red LED blinking and continuous buzzer |

If no echo is detected, the system switches off all outputs and displays an error message on the Serial Monitor.

# 6. Software Implementation
The system is programmed using Arduino C/C++.
The implementation includes:
- Ultrasonic distance measurement using the HC-SR04 sensor.
- Conditional logic for the three alert levels.
- LED and buzzer control.
- 'millis()'-based timing for periodic measurements and LED blinking.
- Sensor timeout handling to detect missing echo signals.
- Serial Monitor output for distance and status information.

# 7. Simulation and Testing
The project was implemented and tested in the Wokwi online simulator.
The following conditions were verified:
- Safe condition
- Warning condition
- Danger condition
- No-echo sensor condition
The simulation demonstrates the expected behavior of the alert system under different distance conditions.
Wokwi Simulation: [Link](https://wokwi.com/projects/479605436532812801)

# 8. Limitations
- The current implementation is a simulation-based prototype and has not yet been tested with physical hardware.
- The HC-SR04 sensor is not waterproof.
- The system currently uses fixed distance thresholds.
- The prototype does not include wireless communication or remote monitoring.

# 9. Future Improvements
- Integrate waterproof ultrasonic sensors for practical deployment.
- Add Wi-Fi connectivity for remote monitoring.
- Send alerts through a mobile application or cloud platform.
- Implement data logging and historical water-level analysis.
- Improve measurement reliability using filtering and hysteresis.

# 10. Conclusion
The project demonstrates a basic embedded system for water-level monitoring and flood alert generation. By combining ultrasonic sensing, LED indicators, and buzzer alerts, the prototype provides a simple three-level warning mechanism. The Wokwi simulation validates the basic functionality and provides a foundation for future hardware implementation.
