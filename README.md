# 🗑️ Smart Dustbin with Level Monitoring

A smart dustbin system that automatically opens its lid when someone approaches and monitors the fill level using ultrasonic sensors. Fill level data is sent to the Blynk IoT platform for remote monitoring.

---

## 📦 Project Overview

The system is divided into two components:

### 1. Arduino-Based Lid Control
- Uses an ultrasonic sensor (HC-SR04) and a servo motor
- Opens the lid when an object is detected within 8 cm

### 2. ESP32-Based Level Monitoring
- Measures the dustbin fill level using another ultrasonic sensor
- Displays status using LEDs
- Sends data to the Blynk app

---

## 🔧 Hardware Requirements

### Arduino Lid Controller
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- Jumper wires
- USB or battery power supply

### ESP32 Level Monitor
- ESP32 DevKitC
- HC-SR04 Ultrasonic Sensor
- Red & Green LEDs
- 220-330 ohm resistors
- Jumper wires
- WiFi access

---

## 💻 Software Requirements

- Arduino IDE
- Libraries:
  - `Servo.h` (Arduino)
  - `WiFi.h` & `BlynkSimpleEsp32.h` (ESP32)
- Blynk App (Template ID: `TMPL3wle_lEp_`)

---

## 🚀 Installation

### 🔌 Arduino Setup
1. Connect:
   - TRIG → Pin 7
   - ECHO → Pin 6
   - Servo Signal → Pin 9
2. Open `dustbin_lid_control.ino` in Arduino IDE
3. Install `Servo` library
4. Upload code to Arduino board

### 🌐 ESP32 Setup
1. Connect:
   - TRIG → GPIO5
   - ECHO → GPIO18
   - Red LED → GPIO4
   - Green LED → GPIO2
2. Open `dustbin_level_monitoring.ino`
3. Install `WiFi` and `BlynkSimpleEsp32` libraries
4. Update WiFi credentials and `BLYNK_AUTH_TOKEN`
5. Upload code to ESP32 board

### 📱 Blynk App Setup
1. Create a new project with Template ID `TMPL3wle_lEp_`
2. Add a Gauge widget on Virtual Pin `V0`
3. Copy Auth Token into the ESP32 code

---

## 📂 Files

| File | Description |
|------|-------------|
| `dustbin_lid_control.ino` | Arduino code for automatic lid |
| `dustbin_level_monitoring.ino` | ESP32 code for fill-level monitoring & Blynk |

---

## 🛠️ Usage

### 🕹️ Lid Control
- When someone is within 8 cm, the lid opens
- Waits 5 seconds before closing
- Debounce added to prevent frequent triggers

### 📊 Level Monitoring
- Measures bin fill level every 2 seconds
- Converts depth to percentage (based on 17 cm max)
- Red LED lights up ≥90%, otherwise green
- Sends level data to Blynk app

---

## ⚙️ Notes

- Align sensors carefully to avoid false readings
- Adjust depth constant if your bin height differs
- Tune servo angles if needed (open: 70°, close: 110°, stop: 90°)
- Ensure proper WiFi and Auth Token for ESP32 connectivity

---

## 🌐 Remote Monitoring Example

![Blynk Gauge](https://img.shields.io/badge/Blynk-Monitoring-green) *(Add your own screenshot here)*

---

## 🙌 Contribution & License

Feel free to fork and customize.

