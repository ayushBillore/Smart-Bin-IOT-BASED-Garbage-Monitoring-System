#define BLYNK_TEMPLATE_ID "TMPL3MulK_2IK"
#define BLYNK_TEMPLATE_NAME "Garbage IOT"
#define BLYNK_AUTH_TOKEN "8EfvrksPESnSIXfMg291nvo2RZBkrU5Y"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "8EfvrksPESnSIXfMg291nvo2RZBkrU5Y";
char ssid[] = "Galaxy A21s7768";
char pass[] = "owwy8495";

BlynkTimer timer;

int trigPin = 2;//D4
int echoPin = 0;//D3
int led = 14;
int buzzerPin = 16;

double T, P;
char status;

void setup() {
  //pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //timer.setInterval(100L, distance);
  //timer.setInterval(100L, percentage);
}

void loop() {
  long duration, distance;
  float percentage;

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  // Calculate the percentage difference from 100 cm
  percentage = ((100.0 - distance) / 100.0) * 100.0;

  if (distance < 24) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  if (distance <= 8) {
    tone(buzzerPin, 1000); // Change 1000 to your desired frequency in Hertz
  } else {
    noTone(buzzerPin);
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Blynk.virtualWrite(V0, distance);
  Serial.print(" cm, Percentage Difference: ");
  Serial.print(percentage);
  Blynk.virtualWrite(V1, percentage);
  Serial.println("%");
  delay(500);


  Blynk.run();
  timer.run();
}