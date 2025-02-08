
# 🛠 Smart Industrial Condition Monitoring System
**An advanced IoT-based industrial monitoring system using STM32 & ESP32 with CAN, I2C, UART, SPI, and MQTT cloud integration.**

---

## 📌 Project Overview
This project is designed to monitor critical **industrial parameters** such as:
✅ **Temperature & Humidity** (SHT31)  
✅ **Vibration** (MPU6050)  
✅ **Distance/Motion Detection** (HC-SR04)  
✅ **Additional Analog Sensors via SPI ADC**  

It uses **STM32 and ESP32** to collect and transmit sensor data through **CAN Bus, UART, and MQTT** for real-time monitoring via **ThingsBoard, Node-RED, or Grafana**.

---

## 🎯 Features
🔹 **Multi-sensor Data Collection** – I2C, UART, SPI integration for various sensors  
🔹 **Industrial-grade Communication** – CAN Bus for long-range and reliable communication  
🔹 **Cloud Integration** – Real-time data monitoring via MQTT  
🔹 **Edge Processing** – Intelligent alerts for abnormal conditions  
🔹 **Scalable & Modular** – Can be extended with additional sensors  

---

## 🏗 System Architecture
```
[Sensors] → [STM32 Board 1 (Sensor Node)] → [CAN Bus] → [STM32 Board 2 (Gateway Node)] → [UART] → [ESP32 (Cloud Node)] → [MQTT] → [Cloud Dashboard]
```

### 📡 Hardware Used
1️⃣ **STM32F407VGTX Board 1 (Sensor Node)**
   - **MPU6050 (I2C)** → Vibration Detection  
   - **SHT31 (I2C)** → Temperature & Humidity  
   - **HC-SR04 (UART)** → Distance Measurement  
   - **SPI ADC (Optional)** → Additional Analog Sensors  

2️⃣ **STM32F407VGTX Board 2 (Gateway Node)**
   - **Receives CAN data**  
   - **Performs edge processing**  
   - **Forwards critical alerts via UART**  

3️⃣ **ESP32 (Cloud Node)**
   - **Receives UART data from STM32**  
   - **Uploads data to the cloud using MQTT**  
   - **Dashboard Integration (ThingsBoard, Node-RED, Grafana)**  

---

## 📂 Project Code Structure
```
📁 Smart-Industrial-Monitoring/
│── 📁 stm32_sensor_node/
│   ├── 📄 stm32_sensor_node.c  (I2C, SPI, UART, CAN Tx)
│   ├── 📄 mpu6050.h / .c       (I2C Communication)
│   ├── 📄 sht31.h / .c         (I2C Communication)
│   ├── 📄 hc_sr04.h / .c       (UART Communication)
│   ├── 📄 spi_adc.h / .c       (SPI Communication)
│   ├── 📄 can_comm.h / .c      (CAN Tx)
│── 📁 stm32_gateway_node/
│   ├── 📄 stm32_gateway_node.c (CAN Rx, UART Tx)
│── 📁 esp32_cloud_gateway/
│   ├── 📄 esp32_cloud_gateway.cpp (WiFi, MQTT, Dashboard)
│── 📄 README.md  (Documentation)
```

---

## 🔧 Installation & Setup Guide
### 1️⃣ Hardware Connections
| **Component**    | **Interface** | **STM32 Pin** |
|-----------------|--------------|--------------|
| MPU6050        | I2C          | PB8, PB9     |
| SHT31          | I2C          | PB8, PB9     |
| HC-SR04        | UART         | USART2 TX/RX |
| SPI ADC        | SPI          | PA5, PA6, PA7 |
| CAN Transceiver| CAN Bus      | PB12, PB13   |

---

### 2️⃣ Software Setup
#### **For STM32 (Using STM32CubeIDE)**
1. Open **STM32CubeIDE**, create a new project for **STM32F407VGT6**.  
2. Configure **I2C, UART, SPI, and CAN** in **CubeMX**.  
3. Copy and paste the provided `stm32_sensor_node.c` and `stm32_gateway_node.c`.  
4. Build and flash the code to your STM32 boards.  

#### **For ESP32 (Using Arduino IDE)**
1. Install **Arduino IDE** and ESP32 Board Support Package.  
2. Install the required **MQTT Library (`PubSubClient`)**.  
3. Open **`esp32_cloud_gateway.cpp`**, update WiFi credentials.  
4. Upload the code to ESP32.  

---

## 🌐 Cloud Dashboard (ThingsBoard / Node-RED)
1️⃣ **ThingsBoard Setup**
- Create an account at [ThingsBoard.io](https://thingsboard.io).  
- Create a **new device** and obtain the **MQTT Token**.  
- Update the MQTT token in `esp32_cloud_gateway.cpp`.  

2️⃣ **Node-RED Integration**
- Install **Node-RED** and **MQTT broker (Mosquitto)** on a **local server or Raspberry Pi**.  
- Configure **MQTT Input Node** to receive sensor data.  
- Display data on **Gauge, Chart, and Notification Nodes**.  

---

## 🎯 Expected Output
- **Real-time Sensor Data**: Temperature, Humidity, Vibration, Distance displayed on the cloud.  
- **Alerts for Abnormal Readings**: Notifications for excessive vibration, temperature, or motion detection.  
- **Scalability**: Additional sensors can be integrated without major changes.  

---

## 🛠 Troubleshooting
| **Issue** | **Possible Cause** | **Solution** |
|-----------|-------------------|--------------|
| No CAN Communication | Incorrect Wiring | Check CAN transceiver connections |
| No MQTT Data | Wrong WiFi/MQTT Credentials | Verify SSID, Password, MQTT Broker |
| Sensors Not Responding | Incorrect I2C Address | Scan I2C devices using an I2C scanner |

---

## 📜 License
This project is open-source under the **MIT License**. Feel free to modify and expand the project.

---

## 🤝 Contributing
If you'd like to contribute, please **fork the repository**, make your changes, and submit a **pull request**.

---

## 💬 Need Help?
If you have any questions, feel free to reach out! 🚀  
🔹 **GitHub:** [github.com/satyadevgithub](https://github.com/satyadevgithub)  
🔹 **LinkedIn:** [linkedin.com/in/satya-dev-mishra](https://linkedin.com/in/satya-dev-mishra)  
🔹 **Email:** ceo@satyadevmishra.com  
