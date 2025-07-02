
#define BLYNK_TEMPLATE_ID "TMPL3wle_lEp_"
#define BLYNK_TEMPLATE_NAME "Esp32 Level Monitoring"
#define BLYNK_AUTH_TOKEN "eOzz5XX8jRNh5k8YftOXCsG1E_Iv97Om"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "MyWifii";     // Enter your WiFi SSID
char pass[] = "123456789"; // Enter your WiFi password

#define TRIG_PIN 5        // D1 = GPIO5
#define ECHO_PIN 18       // GPIO18

// LED pins
#define RED_LED_PIN 4     // D4 = GPIO2
#define GREEN_LED_PIN 2   // D2 = GPIO4

long duration;
float distance_cm;
float level_percent;

BlynkTimer timer;

void measureLevel() {
  // Trigger ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure echo duration
  duration = pulseIn(ECHO_PIN, HIGH);

  // Convert duration to distance in cm
  distance_cm = duration * 0.034 / 2;

  // Clamp reading
  if (distance_cm > 17) distance_cm = 17;
  if (distance_cm < 0) distance_cm = 0;

  // Calculate fill percentage
  level_percent = ((17.0 - distance_cm) / 17.0) * 100.0;

  // Clamp percentage
  level_percent = constrain(level_percent, 0, 100);

  // Debug output
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.print(" cm | Fill Level: ");
  Serial.print(level_percent);
  Serial.println(" %");

  // Send to Blynk virtual pin V0
  Blynk.virtualWrite(V0, (int)level_percent);

  // LED control logic
  if (level_percent >= 90.0) {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
  } else {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  // Turn off both LEDs initially
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);

  Blynk.begin(auth, ssid, pass);

  timer.setInterval(2000L, measureLevel);  // Measure every 2 seconds
}

void loop() {
  Blynk.run();
  timer.run();
}

