# Advanced Farming using IoT

This project implements an intelligent and sustainable farming solution using Internet of Things (IoT) technology. It combines automated irrigation, ultrasonic pest deterrence, and remote environmental monitoring to optimize agricultural practices, conserve resources, and improve crop yields.

---

## Features

- **Automated Irrigation**  
  Measures soil moisture and automatically waters plants as needed, conserving water and preventing over-irrigation.

- **Ultrasonic Pest Deterrent**  
  A humane and eco-friendly system using rotating ultrasonic sensors to detect and repel pests without harmful chemicals.

- **Real-Time Environmental Monitoring**  
  Continuously tracks soil moisture, temperature, humidity, and water tank levels.

- **Remote Control & Monitoring**  
  Integrated with the ESP-32 and Blynk app for easy remote access and control via smartphone.

---

## Hardware Components

### Microcontrollers
- **Arduino UNO** – Controls automated irrigation logic.
- **Arduino Nano** – Manages the ultrasonic pest deterrent.
- **ESP-32** – Enables Wi-Fi connectivity and data communication.

### Sensors
- **Soil Moisture Sensor** – Detects soil moisture levels.
- **Ultrasonic Sensor** – Detects nearby pests.
- **DHT-11 Sensor** – Measures ambient temperature and humidity.
- **Water Level Sensor** – Monitors the water tank level.

### Actuators & Others
- **5V DC Pump** – Provides water for irrigation.
- **28BYJ-48 Stepper Motor** – Rotates the ultrasonic sensor for broader detection.
- **Buzzer** – Emits high-frequency sound to scare pests.
- **Relay Module** – Switches the DC pump on/off.
- **ULN2003 Driver** – Drives the stepper motor.

---

## Software & Tools

- **Arduino IDE** – For firmware development and deployment.
- **Blynk App** – For remote monitoring and real-time alerts via mobile UI.

---

## Methodology

### 1. Automated Irrigation  
The Arduino UNO reads the soil moisture sensor. If moisture is below a threshold (e.g., 70%), it activates a relay to turn on the water pump. Once sufficient moisture is detected, it turns off the pump automatically.

### 2. Ultrasonic Pest Deterrent  
The Arduino Nano rotates an ultrasonic sensor across a 180° arc using a stepper motor. When pests are detected, a buzzer is triggered to emit ultrasonic sounds that deter them.

### 3. Remote Monitoring  
The ESP-32 collects environmental data (from DHT-11 and water level sensor) and sends it to the Blynk cloud. Users can monitor live data and receive alerts via their mobile devices.

---

## Experiments & Results

-  **Water Conservation**: Reduced water usage by ~50% compared to traditional methods.
-  **Increased Yield**: Improved crop growth due to consistent moisture levels.
-  **Effective Pest Control**: Significant reduction in crop damage by pests.
-  **Eco-Friendly**: Eliminated the use of chemical pesticides and reduced water wastage.

---

## Future Enhancements

- Integration of solar power for energy independence.
- Addition of AI for crop disease detection using image processing.
- GSM module integration for offline SMS alerts.

---

## License

This project is open-source and available under the [MIT License](LICENSE).