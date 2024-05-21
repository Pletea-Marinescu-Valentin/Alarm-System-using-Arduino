// Declare pins for motors and sensors
const int smokeSensorPin = A0;
const int vibrationSensorPin = 3;

const int ledPin = 2;
const int buzzerPin = 10;
const int barrierMotorPin = 4;
const int barrierMotorPinRight = 5;
const int barrierMotorPinLeft = 6;
const int windowMotorPin = 7;
const int windowMotorPinRight = 8;
const int windowMotorPinLeft = 9;
const int fanMotorPin = 13;

bool windowOpen = false;
bool barrierDown = false;

// Define time for a quarter rotation (in milliseconds) - barrier
const int quarterRotationTime = 4;
// Define time for appropriate motor rotation for the window
const int windowRotationTime = 35;

void setup() {
  // Initialize pins for motors and sensors
  pinMode(barrierMotorPin, OUTPUT);
  pinMode(barrierMotorPinRight, OUTPUT);
  pinMode(barrierMotorPinLeft, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  tone(buzzerPin, 1000, 1000);

  pinMode(windowMotorPin, OUTPUT);
  pinMode(windowMotorPinRight, OUTPUT);
  pinMode(windowMotorPinLeft, OUTPUT);

  pinMode(fanMotorPin, OUTPUT);

  pinMode(vibrationSensorPin, INPUT);
  pinMode(smokeSensorPin, INPUT);

  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  // Read the vibration sensor
  int vibration = readVibrationSensor();

  // Read the smoke sensor
  int smoke = readSmokeSensor();

  // Debugging - display the read values
  Serial.print("Vibration: ");
  Serial.print(vibration);
  Serial.print(" | Smoke: ");
  Serial.println(smoke);

  digitalWrite(fanMotorPin, LOW);

  // Check the vibration sensor
  if (vibration == 0) {
    if (!barrierDown) {
      Serial.println("Vibration sensor activated!");
      // Lower the barrier (slow quarter rotation)
      digitalWrite(barrierMotorPin, HIGH);
      digitalWrite(barrierMotorPinRight, HIGH);
      digitalWrite(barrierMotorPinLeft, LOW);
      delay(quarterRotationTime); // Quarter rotation
      digitalWrite(ledPin, HIGH);
      digitalWrite(buzzerPin, HIGH);
      tone(buzzerPin, 440);
      turnOffBarrier(); // Stop the barrier

      barrierDown = true;

      delay(5000);
    }
  } else {
    if (barrierDown) {
      // Raise the barrier (slow quarter rotation)
      digitalWrite(barrierMotorPin, HIGH);
      digitalWrite(barrierMotorPinLeft, HIGH);
      digitalWrite(barrierMotorPinRight, LOW);
      delay(quarterRotationTime); // Quarter rotation
      digitalWrite(ledPin, LOW);
      digitalWrite(buzzerPin, LOW);
      noTone(buzzerPin);
      turnOffBarrier(); // Stop the barrier
      barrierDown = false;
    }
  }
  delay(100); // A small delay to avoid rapid sensor readings

  // Check the smoke sensor
  if (smoke > 170) {
    if (!windowOpen) {
      Serial.println("Smoke sensor activated!");
      // Open the window and start the fan
      digitalWrite(windowMotorPin, HIGH);
      digitalWrite(windowMotorPinLeft, HIGH);
      digitalWrite(windowMotorPinRight, LOW);
      delay(windowRotationTime);
      digitalWrite(ledPin, HIGH);
      digitalWrite(buzzerPin, HIGH);
      tone(buzzerPin, 523);
      turnOffWindow(); // Stop the window
      windowOpen = true;
    }
    digitalWrite(fanMotorPin, HIGH);
    delay(5000);
  } else {
    if (windowOpen) {
      digitalWrite(windowMotorPin, HIGH);
      digitalWrite(windowMotorPinRight, HIGH);
      digitalWrite(windowMotorPinLeft, LOW);
      delay(windowRotationTime);
      digitalWrite(ledPin, LOW);
      digitalWrite(buzzerPin, LOW);
      noTone(buzzerPin);
      turnOffWindow(); // Stop the window
      windowOpen = false;
    }
    digitalWrite(fanMotorPin, LOW);
  }

  delay(100); // A small delay to avoid rapid sensor readings
}

long readVibrationSensor() {
  long measurement = digitalRead(vibrationSensorPin);
  return measurement;
}

long readSmokeSensor() {
  long sensorValue = analogRead(smokeSensorPin);
  long outputValue = map(sensorValue, 0, 1023, 0, 255);
  return outputValue;
}

void turnOffBarrier() {
  // This command is used to stop the motor
  digitalWrite(barrierMotorPin, LOW);
  digitalWrite(barrierMotorPinRight, LOW);
  digitalWrite(barrierMotorPinLeft, LOW);
}

void turnOffWindow() {
  // This command is used to stop the motor
  digitalWrite(windowMotorPin, LOW);
  digitalWrite(windowMotorPinRight, LOW);
  digitalWrite(windowMotorPinLeft, LOW);
}
