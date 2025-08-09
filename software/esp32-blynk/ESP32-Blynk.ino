#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "Your_Template_Name"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"

#define BLYNK_PRINT Serial
#include <WiFi.h>
//#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// Blynk and WiFi credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = " ";  // Your WiFi SSID
char pass[] = " ";  // Your WiFi Password

BlynkTimer timer;

// DHT Sensor Setup
#define DHTPIN 27       // Pin for DHT11 sensor
#define DHTTYPE DHT11   // DHT11 Sensor type
DHT dht(DHTPIN, DHTTYPE);

// Water Level Sensor Setup
#define WATER_LEVEL_PIN 34  // Pin for Water Level Sensor

// Function to send sensor data to Blynk
void sendSensor()
{
  // Reading temperature and humidity from DHT sensor
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // use dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Sending temperature and humidity to Blynk
  Blynk.virtualWrite(V0, t);  // Virtual Pin V0 for temperature
  Blynk.virtualWrite(V1, h);  // Virtual Pin V1 for humidity

  Serial.print("Temperature : ");
  Serial.print(t);
  Serial.print("    Humidity : ");
  Serial.println(h);

  // Reading water level from analog sensor
  int waterLevelValue = analogRead(WATER_LEVEL_PIN);
  
  // Convert water level value to a percentage (optional)
  float waterLevelPercentage = (waterLevelValue / 4095.0) * 100.0;

  // Sending water level to Blynk
  Blynk.virtualWrite(V2, waterLevelPercentage);  // Virtual Pin V2 for water level

  Serial.print("Water Level : ");
  Serial.print(waterLevelPercentage);
  Serial.println("%");
}

void setup()
{   
  Serial.begin(115200);

  // Connect to Blynk
  Blynk.begin(auth, ssid, pass);

  // Initialize the DHT sensor
  dht.begin();

  // Set timer to read sensor values every second (1000 ms)
  timer.setInterval(1000L, sendSensor);  // 1 second interval
}

void loop()
{
  Blynk.run();
  timer.run();  // Run the Blynk timer
}