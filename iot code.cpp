// Ultrasonic Sensor Pins
const int trig_pin = 9; // Ultrasonic Sensor Trigger Pin
const int echo_pin = 10; // Ultrasonic Sensor Echo Pin

// Smoke Sensor Pin
const int smokeSensorPin = A0; // Analog pin for smoke sensor

// Buzzer Pin
const int buzzer = 8; // Digital pin for buzzer

// LED Pin
const int ledPin = 6; // Digital pin for LED

float timing = 0.0;
float distance = 0.0;

// Function to read the smoke sensor data
int readSmokeSensor() {
  unsigned int sensorValue = analogRead(smokeSensorPin);  // Read the analog value from the smoke sensor
  unsigned int outputValue = map(sensorValue, 0, 1023, 0, 255); // Map the 10-bit data to 8-bit data

  if (outputValue > 65) {
    analogWrite(ledPin, outputValue); // Generate PWM signal for the LED
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED
  }

  return sensorValue; // Return the smoke sensor value
}

void setup() {
  Serial.begin(9600);

  // Initialize Pins
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // Turn off buzzer and LED initially
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // ---------------- Ultrasonic Sensor Part ----------------
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  timing = pulseIn(echo_pin, HIGH);
  distance = (timing * 0.034) / 2; // Calculate distance in cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // ---------------- Smoke Sensor Part ----------------
  int smokeValue = readSmokeSensor();
  Serial.print("Smoke Level: ");
  Serial.println(smokeValue);

  // ---------------- Buzzer Conditions ----------------
  // If distance is less than or equal to 50 cm OR smoke level is below threshold, sound the buzzer
  if (distance <= 50 || smokeValue > 400) {
    tone(buzzer, 500); // Sound the buzzer at 500 Hz
  } else {
    noTone(buzzer); // Turn off the buzzer
  }

  delay(500); // Delay for stability
}
