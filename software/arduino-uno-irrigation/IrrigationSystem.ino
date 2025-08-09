// Pin configuration
const int moisturePin = A0;   // Soil sensor analog pin
const int relayPin = 3;       // Relay module control pin

// Threshold value for moisture
const int threshold = 500;    // Adjust this based on calibration

void setup() {
  Serial.begin(9600);          // Start serial monitor
  pinMode(moisturePin, INPUT); // Moisture sensor as input
  pinMode(relayPin, OUTPUT);   // Relay pin as output
  digitalWrite(relayPin, HIGH); // Ensure pump is OFF initially
}

void loop() {
  int moistureValue = analogRead(moisturePin); // Read soil moisture
  Serial.print("Soil Moisture: ");
  Serial.println(moistureValue);

  if (moistureValue < threshold) {
    Serial.println("Soil is dry. Turning ON pump.");
    digitalWrite(relayPin, LOW); // Relay ON → Pump ON
  } else {
    Serial.println("Soil is wet. Turning OFF pump.");
    digitalWrite(relayPin, HIGH); // Relay OFF → Pump OFF
  }

  delay(2000); // Wait before next reading
}