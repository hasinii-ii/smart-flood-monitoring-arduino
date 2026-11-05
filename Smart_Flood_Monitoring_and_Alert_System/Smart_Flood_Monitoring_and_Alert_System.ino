
const int trigPin = 2;
const int echoPin = 3;

const int greenLED = 5;
const int yellowLED = 6;
const int redLED = 7;
const int buzzer = 8;

const float SAFE_CM = 200.0;
const float DANGER_CM = 100.0;

unsigned long lastMeasure = 0;
unsigned long lastBlink = 0;

const unsigned long MEASURE_INTERVAL = 250;
const unsigned long BLINK_INTERVAL = 200;

float distance = 0;
bool redOn = false;
bool sensorOK = false;

enum State { SAFE, WARNING, DANGER };
State currentState = SAFE;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(trigPin, LOW);
  allOff();

  Serial.begin(9600);
}

void allOff() {
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  noTone(buzzer);
}

void loop() {
  unsigned long now = millis();

  // Read the sensor
  if (now - lastMeasure >= MEASURE_INTERVAL) {
    lastMeasure = now;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    unsigned long duration = pulseIn(echoPin, HIGH, 30000UL);

    if (duration == 0) {
      sensorOK = false;
      allOff();
      Serial.println("No echo detected");
      return;
    }

    sensorOK = true;
    distance = duration * 0.0343 / 2.0;

    if (distance > SAFE_CM) {
      currentState = SAFE;
    }
    else if (distance >= DANGER_CM) {
      currentState = WARNING;
    }
    else {
      currentState = DANGER;
    }

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm | Status: ");

    if (currentState == SAFE) Serial.println("SAFE");
    else if (currentState == WARNING) Serial.println("WARNING");
    else Serial.println("DANGER");
  }

  if (!sensorOK) {
    allOff();
    return;
  }

  // SAFE: Green only
  if (currentState == SAFE) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    noTone(buzzer);
    redOn = false;
  }

  // WARNING: Yellow only, intermittent buzzer
  else if (currentState == WARNING) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
    redOn = false;

    // Beep briefly every 1 second
    if (now % 1000 < 200) {
      tone(buzzer, 1000);
    } else {
      noTone(buzzer);
    }
  }

  // DANGER: Red blinks, buzzer sounds continuously
  else {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);

    if (now - lastBlink >= BLINK_INTERVAL) {
      lastBlink = now;
      redOn = !redOn;
    }

    digitalWrite(redLED, redOn ? HIGH : LOW);
    tone(buzzer, 2000);
  }
}
