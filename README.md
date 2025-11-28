# Smart Home Automation & Security System using ARM7 (LPC2129)

## 📌 Overview
This project implements a **multi-node Smart Home Automation and Security System** using the **ARM7 LPC2129** microcontroller.  
Multiple sensor nodes communicate with a **Main LCD Node** through the **CAN protocol**, enabling centralized real-time monitoring.

The system includes **IR-based gate control**, **RFID authentication**, and **LDR-based light automation**, making it suitable for home security and energy-efficient automation.

---

## 🧠 Features

### 🔹 Node 1 – IR Sensor: Gate Automation
- Detects human presence using IR sensor  
- Automatically opens the gate using a DC motor  
- Sends **“Person Detected / No Person”** to Main Node via CAN  

### 🔹 Node 2 – RFID Authentication
- Verifies authorized users with RFID tags  
- Sends:  
  - **Person 1 Entered**  
  - **Person 2 Entered**  
  - **Unauthorized Entry Attempt**  
- Real-time status sent to Main Node via CAN  

### 🔹 Node 3 – LDR-Based Light Automation
- Turns **light ON at night**  
- Turns **light OFF during day**  
- Sends **Light ON/OFF** updates to Main Node  

### 🔹 Node 4 – Main LCD Node
- Acts as the **central controller**  
- Receives CAN messages from all nodes  
- Displays:  
  - IR Node status  
  - RFID Node status  
  - Light automation status  

---

## 🛰 Communication
- All nodes communicate using the **CAN Protocol**  
- Provides reliable, fast, multi-node data transfer  
- Ensures robust operation for automation systems  

---

## 🛠 Technologies Used
- **ARM7 LPC2129 Microcontroller**  
- **Embedded C**  
- **CAN Protocol**  
- **IR Sensor, RFID Reader, LDR**  
- **Motor Driver (Gate Control)**  
- **16x2 LCD**  
- **Keil uVision, Flash Magic**  
