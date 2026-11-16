🛡️ Arduino Motion Security System

<p align="center">
<img src="https://img.shields.io/badge/Arduino-UNO-00979D?style=for-the-badge&logo=arduino&logoColor=white" />
<img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" />
<img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge" />
</p>

<p align="center">
<b>A simple motion detection security system built with Arduino UNO.</b>
<br>
Uses a PIR motion sensor, 4x4 keypad, buzzer and three LED indicators.
</p>

📌 About the Project

The Arduino Motion Security System is an electronic alarm project designed to detect movement and indicate the current security status.

The system can be armed and disarmed using a 4x4 matrix keypad. During the arming and disarming process, a yellow LED flashes for 5 seconds.

When the system is armed, the green LED stays ON. When the system is disarmed, the red LED stays ON.

If the PIR sensor detects movement while the system is armed, the buzzer generates an audible alarm.

⚙️ Features
🔐 Keypad Security Control – Arm and disarm the system using the # key.
⏳ Arming Delay – 5-second transition before the system becomes armed.
🟡 Yellow LED – Flashes during arming and disarming.
🟢 Green LED – Indicates that the system is armed.
🔴 Red LED – Indicates that the system is disarmed.
👁️ Motion Detection – Detects movement using a PIR sensor.
🔊 Audible Alarm – Buzzer activates when movement is detected.
🧰 Components
Component	Quantity
Arduino UNO	1
PIR Motion Sensor	1
4x4 Matrix Keypad	1
Buzzer	1
Red LED	1
Yellow LED	1
Green LED	1
1kΩ Resistors	3
Connecting Wires	As needed
🔌 Pin Configuration
Component	Arduino Pin
Buzzer	D10
PIR Sensor	D9
Red LED	D11
Yellow LED	D12
Green LED	D13
Keypad Rows	D1, D2, D3, D4
Keypad Columns	D5, D6, D7, D8
💡 LED Status Indicators
System State	🔴 Red	🟡 Yellow	🟢 Green
Disarmed	ON	OFF	OFF
Arming	OFF	FLASHING	OFF
Armed	OFF	OFF	ON
Disarming	OFF	FLASHING	OFF

Only one LED is active at a time.

🚀 How It Works
When Arduino starts, the system is disarmed and the red LED turns ON.
Press # on the keypad to start arming.
The yellow LED flashes for 5 seconds.
After the transition, the green LED turns ON, indicating that the system is armed.
The PIR sensor monitors the surroundings for movement.
When movement is detected, the buzzer generates an alarm.
Press # again to start disarming.
The yellow LED flashes for another 5 seconds.
After disarming, the red LED turns ON.
📦 Libraries

The project uses the following Arduino library:

Keypad Library

Install it using the Arduino IDE Library Manager.

🖥️ Software
Arduino IDE
Arduino UNO board support
Keypad library
📁 Project Structure
text
Arduino-Motion-Security-System/
│
├── README.md
├── security_system.ino
└── images/
    ├── circuit.png
    └── wiring.png

🔧 Possible Improvements
Add a PIN code for arming and disarming.
Add an alarm activation countdown.
Add an LCD display for system status.
Add an alarm reset function.
Add an adjustable alarm duration.
👨‍💻 Author

Created as an Arduino electronics and programming project.

<p align="center">
<b>🔐 Arduino Motion Security System</b>
<br>
<i>Simple hardware. Smart security.</i>
</p>
