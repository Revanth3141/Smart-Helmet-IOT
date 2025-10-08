# Smart-Helmet-IOT
# Smart Helmet Safety System 🚨🪖

This project is an **IoT-based Smart Helmet prototype** designed to enhance rider safety by integrating multiple sensors for accident detection and hazard alerts. The system uses an ultrasonic sensor to measure obstacle distance, a smoke sensor for fire/smoke detection, and a buzzer + LED for alert notifications.  

## 🔧 Features
- **Obstacle Detection**: Ultrasonic sensor triggers buzzer when an object is closer than 50 cm.  
- **Smoke Detection**: Smoke sensor detects harmful gases/fire smoke and activates alerts.  
- **Alert System**: Buzzer and LED provide real-time safety warnings.  
- **Serial Monitoring**: Distance and smoke levels are displayed on the serial monitor.  

## 🛠️ Hardware Requirements
- Arduino Uno / Nano  
- Ultrasonic Sensor (HC-SR04)  
- Smoke Sensor (MQ-2/MQ-135)  
- Buzzer  
- LED  
- Jumper wires & Breadboard  

## 💻 Code
The Arduino source code for this project is available in [`smart_helmet.ino`](smart_helmet.ino).  

## ⚙️ Circuit Diagram
*(Add your circuit diagram image here if you have one, e.g. `circuit.png`)*  

## 🚀 How to Run
1. Connect the components as per the circuit diagram.  
2. Upload the `smart_helmet.ino` file to Arduino using Arduino IDE.  
3. Open Serial Monitor at 9600 baud to view sensor readings.  
4. Test by bringing an object closer than 50 cm or exposing smoke near the sensor.  

## 🎥 Demo Video
Watch the live implementation here:  
👉 [Smart Helmet Demo](https://drive.google.com/file/d/1e7vpcdQ_dCt_k6o3nuJYTqVUl7P_1yNn/view?usp=sharing)  

## 📜 License
This project is open-sourced under the [MIT License](LICENSE). Feel free to use and improve it.  

---
