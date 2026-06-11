# 🏠 Smart Home Security System using ESP32 & Blynk IoT

![ESP32](https://img.shields.io/badge/ESP32-IoT-blue)
![Blynk](https://img.shields.io/badge/Blynk-Cloud-green)
![Arduino](https://img.shields.io/badge/Arduino-C%2B%2B-orange)
![IEEE](https://img.shields.io/badge/IEEE-Student%20Project-red)
[![Wokwi Simulation](https://img.shields.io/badge/Wokwi-Simulation-blue)](https://wokwi.com/projects/466559156265556993)

## 📌 Overview

The **Smart Home Security System** is an IoT-based safety and monitoring solution developed using **ESP32**, **Blynk IoT**, and multiple sensors. The system continuously monitors environmental conditions and security threats, providing real-time alerts and remote monitoring through the Blynk cloud platform.

The project is capable of detecting:

* 🌡️ High Temperature
* 💧 Humidity Levels
* 🚶 Motion/Intrusion
* 🔥 Fire Detection
* ⛽ Gas Leakage

Whenever a hazardous condition is detected, the system automatically:

* Activates a buzzer alarm
* Turns ON the relay
* Sends a notification through Blynk
* Updates live data on the dashboard

---

# 🌐 Wokwi Simulation

Try the live simulation here:

👉 https://wokwi.com/projects/466559156265556993

You can interact with the sensors, monitor real-time values, and test the Smart Home Security System directly in the browser without any hardware.

# 🚀 Features

✅ Real-Time Sensor Monitoring

✅ Motion Detection Using PIR Sensor

✅ Fire Detection Using Flame Sensor

✅ Gas Leakage Detection Using MQ2 Sensor

✅ Temperature & Humidity Monitoring

✅ Blynk Cloud Integration

✅ Mobile Notifications & Alerts

✅ Relay-Based Emergency Response

✅ Remote Dashboard Monitoring

---

# 🛠 Hardware Components

| Component                           | Quantity    |
| ----------------------------------- | ----------- |
| ESP32 Development Board             | 1           |
| DHT22 Temperature & Humidity Sensor | 1           |
| PIR Motion Sensor                   | 1           |
| MQ2 Gas Sensor                      | 1           |
| Flame Sensor                        | 1           |
| Relay Module                        | 1           |
| Buzzer                              | 1           |
| LED + Resistor                      | 1           |
| Push Button (Testing)               | 1           |
| Jumper Wires                        | As Required |

---

# 💻 Software & Platforms

* Arduino IDE
* Wokwi Simulator
* Blynk IoT Platform
* GitHub

---

# 📊 Blynk Dashboard

The dashboard provides real-time monitoring of:

| Virtual Pin | Parameter        |
| ----------- | ---------------- |
| V0          | Temperature      |
| V1          | Humidity         |
| V2          | Gas Value        |
| V3          | Motion Detection |
| V4          | Relay Status     |
| V5          | Flame Detection  |

---

# ⚙️ Working Principle

### Temperature Monitoring

The DHT22 sensor continuously measures temperature and humidity. If the temperature exceeds the predefined threshold, an alert is generated.

### Motion Detection

The PIR sensor detects human movement and triggers an intrusion alert.

### Fire Detection

The flame sensor identifies the presence of fire and immediately activates the alarm system.

### Gas Leakage Detection

The MQ2 sensor monitors combustible gases. When gas concentration exceeds the safety threshold, the system triggers an emergency response.

### Emergency Response

When any danger is detected:

1. Relay is activated
2. Buzzer alarm sounds
3. Notification is sent via Blynk
4. Dashboard status updates in real-time

---

# 📷 Project Images

## Circuit Diagram

<img src="images/circuit.png" width="800">

## Blynk PC Dashboard

<img src="images/PC Dashboard.png" width="800">

## Blynk Mobile Dashboard

<img src="images/Mobile Dashboard.jpeg" width="800">

---

# 🔌 Circuit Connections

| Device            | ESP32 Pin |
| ----------------- | --------- |
| DHT22 Data        | GPIO 27   |
| PIR Output        | GPIO 15   |
| Flame Sensor      | GPIO 4    |
| MQ2 Analog Output | GPIO 35   |
| Relay IN          | GPIO 2    |
| Buzzer            | GPIO 14   |

---

# 📈 System Architecture

Sensors → ESP32 → Blynk Cloud → Dashboard & Notifications

---

# 🎯 Applications

* Smart Homes
* Home Security Systems
* Fire Safety Monitoring
* Gas Leakage Detection
* IoT Learning Projects
* Smart Building Automation

---

# 🔮 Future Enhancements

* Camera Integration
* GSM Alert System
* Voice Assistant Support
* Mobile App Control
* AI-Based Threat Detection
* Cloud Data Analytics

---

# 👨‍💻 Author

**Chitturi Sanjay Kumar**

Electronics & Communication Engineering

Aditya University, Surampalem

IoT & Embedded Systems Enthusiast

---

# ⭐ Support

If you found this project useful:

⭐ Star this repository

🍴 Fork this repository

📢 Share with others

---

## License

This project is developed for educational and research purposes.