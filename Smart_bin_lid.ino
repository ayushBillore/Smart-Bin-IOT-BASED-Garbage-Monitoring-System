#include <Servo.h>

Servo myservo;

// Ultrasonic sensor pins
const int trigPin = 7;
const int echoPin = 6;

// Distance threshold in cm
const int openThreshold = 8;

void setup() {
  myservo.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration;
  int distance;

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cms
  distance = duration * 0.034 / 2;

  // Check if distance is below threshold
  if (distance <= openThreshold) {

    // Open lid
    myservo.write(70);  // Reverse direction (open)
    delay(1000);        // Run to open fully
    myservo.write(90);  // Stop
    delay(5000);        // Wait 5 seconds

    // Close lid
    myservo.write(110); // Forward direction (close)
    delay(1000);        // Run to close fully
    myservo.write(90);  // Stop

    delay(1000);        // Optional pause before checking again
  }

  delay(200);  // Small delay to avoid rapid triggering
}
