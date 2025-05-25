// --- Include Libraries ---
#include <WiFi.h>
#include <HTTPClient.h>
#include <ESP32Servo.h>
#include "HX711.h"

// --- Wi-Fi Credentials & API URL ---
const char* ssid = "Riyaz";
const char* password = "riyaz786";
const char* serverName = "https://minidobi.onrender.com/status";

// --- Hardware Pin Definitions ---
// Buzzer
#define BUZZER_PIN 13

// Relays
#define RELAY1_PIN 14
#define RELAY2_PIN 27

// Servos
#define SERVO1_PIN 17
#define SERVO2_PIN 18
#define SERVO3_PIN 19
#define SERVO4_PIN 21

// Stepper Motor Pins
#define STEPPER_IN1 32
#define STEPPER_IN2 33
#define STEPPER_IN3 25
#define STEPPER_IN4 26

// Vibration Sensor
#define VIBRATION_PIN 34

// HX711 Load Cell
#define HX711_DT 4
#define HX711_SCK 5

// LEDs
#define LED1_PIN 2    // Also used by API response
#define LED2_PIN 12
#define LED3_PIN 15
#define LED4_PIN 22

// LDR Sensor
#define LDR_PIN 35

// --- Global Objects ---
Servo servo1, servo2, servo3, servo4;
HX711 scale;

void setup() {
  Serial.begin(115200);

  // --- Setup Wi-Fi ---
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");

  // --- Pin Modes ---
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  pinMode(VIBRATION_PIN, INPUT);

  // --- Servo Attach ---
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  servo3.attach(SERVO3_PIN);
  servo4.attach(SERVO4_PIN);

  // --- Stepper Pins ---
  pinMode(STEPPER_IN1, OUTPUT);
  pinMode(STEPPER_IN2, OUTPUT);
  pinMode(STEPPER_IN3, OUTPUT);
  pinMode(STEPPER_IN4, OUTPUT);

  // --- HX711 Start ---
  scale.begin(HX711_DT, HX711_SCK);

  // --- Initial States ---
  digitalWrite(RELAY1_PIN, LOW);
  digitalWrite(RELAY2_PIN, LOW);
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
  digitalWrite(LED4_PIN, LOW);
}
