# Smart Home Security System
### ESP32 · Blynk IoT · Multi-Sensor Monitoring

> A real-time IoT security solution that monitors environmental hazards and intrusion events, delivers instant alerts via Blynk, and autonomously triggers safety responses — all from a single ESP32 microcontroller.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Stack](#software-stack)
- [Circuit & Pin Configuration](#circuit--pin-configuration)
- [Blynk Dashboard Configuration](#blynk-dashboard-configuration)
- [System Logic](#system-logic)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Simulation](#simulation)
- [Roadmap](#roadmap)
- [License](#license)

---

## Overview

The **Smart Home Security System** is an IoT-based embedded project that provides continuous, automated monitoring of a home environment. Built on the **ESP32** microcontroller and integrated with the **Blynk IoT platform**, the system uses four sensors to detect temperature spikes, gas leakage, open flames, and unauthorized motion.

When a hazard is detected, the system reacts immediately — activating an alarm buzzer, switching a relay (to cut power or trigger an external device), updating LED status indicators, and pushing real-time notifications to the user's smartphone through Blynk Cloud.

---

## Features

- Real-time temperature and humidity monitoring
- LPG/smoke/methane gas leakage detection
- Open flame detection via infrared flame sensor
- Human motion detection using a PIR sensor
- Automated alarm (buzzer) and relay control on hazard detection
- Live sensor dashboard on Blynk IoT with gauges and status LEDs
- Instant push notifications for each alert type
- Event logging to Blynk Cloud

---

## Hardware Requirements

| Component | Qty |
|---|---|
| ESP32 Development Board | 1 |
| DHT22 Temperature & Humidity Sensor | 1 |
| MQ2 Gas Sensor | 1 |
| PIR Motion Sensor | 1 |
| Flame Sensor | 1 |
| Relay Module | 1 |
| Buzzer | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| 10 kΩ Pull-up Resistor (for DHT22) | 1 |
| Breadboard | 1 |
| Jumper Wires | As required |

---

## Software Stack

| Tool / Platform | Purpose |
|---|---|
| Arduino IDE | Firmware development |
| ESP32 Board Package | ESP32 support for Arduino IDE |
| Blynk IoT Platform | Cloud dashboard & push notifications |
| Wokwi Simulator | Circuit simulation & testing |
| Git & GitHub | Version control |
| C / C++ | Programming language |

**Required Arduino Libraries:**

- `Blynk` — Blynk IoT connectivity
- `DHTesp` — DHT22 sensor support

---

## Circuit & Pin Configuration

| Component | ESP32 GPIO |
|---|---|
| DHT22 Data | GPIO 27 |
| PIR Motion Sensor | GPIO 15 |
| Flame Sensor | GPIO 4 |
| MQ2 Analog Output | GPIO 35 |
| Relay Module | GPIO 2 |
| Buzzer | GPIO 14 |

> **Note:** GPIO 35 is input-only on ESP32 — suitable for the MQ2 analog output. Ensure a 10 kΩ pull-up resistor is connected on the DHT22 data line.

---

## Blynk Dashboard Configuration

| Virtual Pin | Widget | Purpose |
|---|---|---|
| V0 | Gauge | Temperature (°C) |
| V1 | Gauge | Humidity (%) |
| V2 | Gauge | Gas Level (raw ADC) |
| V3 | LED | Motion Detection Status |
| V4 | LED | Relay Status |
| V5 | LED | Flame Detection Status |

---

## System Logic

### Normal State

All sensors read within safe thresholds. The buzzer and relay remain OFF. The dashboard reflects live sensor values.

### Alert Thresholds

| Condition | Threshold |
|---|---|
| Temperature | > 50 °C |
| Gas Level | > 3800 (ADC raw value) |
| Flame Detected | Sensor output LOW |
| Motion Detected | PIR output HIGH |

### Emergency Response (any threshold breached)

1. Buzzer activates immediately
2. Relay switches ON (can control external load or cut power)
3. Blynk dashboard LED indicators update
4. Push notification sent to user via Blynk app
5. Event logged to Blynk Cloud
6. System continues monitoring

### Operational Flow

```
Read Sensors → Upload to Blynk Cloud → Update Dashboard
     ↓
Check Thresholds
     ↓
Hazard Detected? → YES → Activate Buzzer + Relay → Send Notification → Log Event
     ↓
    NO
     ↓
Continue Loop
```

---

## Project Structure

```
Smart-Home-Security-System/
│
├── sketch.ino          # Main Arduino firmware
├── diagram.json        # Wokwi circuit diagram
├── libraries.txt       # Required library list
├── README.md
│
└── assets/
    ├── circuit-diagram.png
    ├── dashboard.png
    └── simulation.png
```

---

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/Sanjaykumar9441/Smart-Home-Security-System.git
cd Smart-Home-Security-System
```

### 2. Install Arduino Libraries

In Arduino IDE, go to **Sketch → Include Library → Manage Libraries** and install:

- `Blynk`
- `DHTesp`

### 3. Configure Blynk Credentials

Open `sketch.ino` and update the following with your Blynk project credentials:

```cpp
#define BLYNK_TEMPLATE_ID   "your_template_id"
#define BLYNK_TEMPLATE_NAME "your_template_name"
#define BLYNK_AUTH_TOKEN    "your_auth_token"
```

Also update your Wi-Fi credentials:

```cpp
char ssid[] = "your_wifi_ssid";
char pass[] = "your_wifi_password";
```

### 4. Flash the ESP32

- Connect the ESP32 to your PC via USB.
- Select the correct **Board** and **Port** in Arduino IDE.
- Click **Upload**.
- Open **Serial Monitor** (115200 baud) to verify the connection and sensor output.

---

## Simulation

This project can be tested fully in the browser using **Wokwi** — no hardware required.

🔗 **[Open in Wokwi Simulator](https://wokwi.com/projects/466559156265556993)**

In the simulator, you can:

- Observe live sensor readings
- Trigger fire, gas leak, and motion conditions interactively
- Verify buzzer and relay responses
- Confirm Blynk dashboard updates in real time

---

## Roadmap

Planned enhancements for future versions:

- [ ] GSM-based SMS alert system
- [ ] IP camera surveillance integration
- [ ] AI-powered anomaly and threat detection
- [ ] Firebase Cloud Storage for event history
- [ ] Email notification support
- [ ] Voice assistant integration (Alexa / Google Home)
- [ ] Dedicated mobile application

---

## Developer

**Chitturi Sanjay Kumar**  
Electronics & Communication Engineering
Aditya University, Surampalem
GitHub: [github.com/Sanjaykumar9441](https://github.com/Sanjaykumar9441)

---

## License

This project is open-source and available for educational and research purposes. You are free to use, modify, and distribute it with attribution.