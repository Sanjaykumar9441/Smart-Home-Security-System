#define BLYNK_TEMPLATE_ID "TMPL3pUAKR8hh"
#define BLYNK_TEMPLATE_NAME "Smart Home Security System"
#define BLYNK_AUTH_TOKEN "qsdIqEvbnAR0ttwHmGXCxDbbpHI5TYqU"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHTesp.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define DHTPIN 27

const int motion_sensor_pin = 15;
const int flame_sensor_pin = 4;
const int gas_sensor_pin = 35;
const int relay_pin = 2;
const int buzzer_pin = 14;

DHTesp dht;
BlynkTimer timer;

void sendSensorData() {

  bool danger = false;

  // =====================
  // DHT22 SENSOR
  // =====================

  TempAndHumidity data = dht.getTempAndHumidity();

  Blynk.virtualWrite(V0, data.temperature);
  Blynk.virtualWrite(V1, data.humidity);

  Serial.print("Temperature: ");
  Serial.println(data.temperature);

  Serial.print("Humidity: ");
  Serial.println(data.humidity);

  if (data.temperature > 50) {

    danger = true;

    Serial.println("Over Temperature Detected!");

    Blynk.logEvent(
      "warning_message",
      "Over Temperature Detected!"
    );

    tone(buzzer_pin, 1000);
    delay(300);
    noTone(buzzer_pin);
  }

  // =====================
  // PIR MOTION SENSOR
  // =====================

  int motion = digitalRead(motion_sensor_pin);

  Blynk.virtualWrite(V3, motion);

  if (motion == HIGH) {

    danger = true;

    Serial.println("Motion Detected!");

    Blynk.logEvent(
      "warning_message",
      "Motion Detected!"
    );

    tone(buzzer_pin, 700);
    delay(300);
    noTone(buzzer_pin);
  }

  // =====================
// FLAME SENSOR
// =====================

int flame = digitalRead(flame_sensor_pin);

Serial.print("Flame Value: ");
Serial.println(flame);

// LED ON only when fire detected
Blynk.virtualWrite(V5, flame == LOW);

if (flame == LOW) {

  danger = true;

  Serial.println("Fire Detected!");

  Blynk.logEvent(
    "warning_message",
    "Fire Detected!"
  );

  tone(buzzer_pin, 1200);
  delay(300);
  noTone(buzzer_pin);
}

  // =====================
  // MQ2 GAS SENSOR
  // =====================

  int gasValue = analogRead(gas_sensor_pin);

  Blynk.virtualWrite(V2, gasValue);

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  if (gasValue > 3800) {

    danger = true;

    Serial.println("Gas Leakage Detected!");

    Blynk.logEvent(
      "warning_message",
      "Gas Leakage Detected!"
    );

    tone(buzzer_pin, 900);
    delay(300);
    noTone(buzzer_pin);
  }

  // =====================
  // RELAY CONTROL
  // =====================

  if (danger) {

    digitalWrite(relay_pin, HIGH);
    Blynk.virtualWrite(V4, 1);

  } else {

    digitalWrite(relay_pin, LOW);
    Blynk.virtualWrite(V4, 0);
  }

  Serial.println("----------------------");
}

void setup() {

  Serial.begin(115200);

  pinMode(motion_sensor_pin, INPUT);
  pinMode(flame_sensor_pin, INPUT_PULLUP);
  pinMode(relay_pin, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);

  digitalWrite(relay_pin, LOW);

  dht.setup(DHTPIN, DHTesp::DHT22);

  Blynk.begin(
    BLYNK_AUTH_TOKEN,
    ssid,
    pass
  );

  timer.setInterval(
    2000L,
    sendSensorData
  );
}

void loop() {

  Blynk.run();
  timer.run();
}