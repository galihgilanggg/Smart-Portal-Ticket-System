# Smart Portal Ticket System

An Arduino-based automated parking gate and ticket system prototype. This project features vehicle detection, an automated boom barrier, a real-time parked vehicle counter, and an ambient light-responsive illumination system.

## 📌 Key Features
* **Vehicle Detection:** Uses an ultrasonic sensor to detect approaching vehicles.
* **Automated Gate Operation:** A servo motor acts as the boom barrier, opening upon authorized entry.
* **Push-Button Entry:** Simulates a ticket dispenser button to grant access.
* **Real-Time Counter:** An I2C LCD continuously displays the quantity of vehicles currently parked inside.
* **Smart Auto-Lighting:** An LDR (Light Dependent Resistor) detects low-light environments and automatically turns on the street/gate LED.
* **Audio-Visual Feedback:** Integrates Red/Green LEDs and a buzzer to guide the user (e.g., Stop, Push Button, Proceed).

## 🛠️ Hardware Setup

### Required Components
* 1x Arduino (Nano/Uno)
* 1x HC-SR04 Ultrasonic Sensor
* 1x Servo Motor (SG90 or similar)
* 1x 16x2 I2C LCD Display
* 1x LDR (Photoresistor)
* 1x Push Button
* 1x Active Buzzer
* 3x LEDs (Red, Green, White/Clear)
* Resistors (for LEDs, Button, and LDR voltage divider)
* Jumper Wires & Breadboard

### Pin Configuration (Wiring)
Based on the provided `.ino` and schematic, wire the components as follows:

| Component | Arduino Pin | Description |
| :--- | :--- | :--- |
| **Ultrasonic HC-SR04** | `Trig: 7`, `Echo: 6` | Detects vehicle distance |
| **Servo Motor** | `Pin 3` (PWM) | Controls the gate barrier |
| **Buzzer** | `Pin 5` | Audio feedback for entry |
| **Red LED** | `Pin 10` | Indicator: Stop / Vehicle Detected |
| **Green LED** | `Pin 9` | Indicator: Access Granted |
| **White LED** | `Pin 8` | Auto-lighting for dark conditions |
| **Push Button** | `Pin 13` | Simulates taking a ticket |
| **LDR Sensor** | `Pin A3` | Ambient light measurement |
| **I2C LCD** | `SDA`, `SCL` | Displays system status and counter |

## 🔄 System Workflow (How It Works)

1. **Standby Mode:** The LCD displays the current number of parked vehicles (`Vehicle Parked qty`).
2. **Vehicle Approach:** When a vehicle is detected within 10 cm by the ultrasonic sensor, the Red LED turns on. The LCD prompts the driver to push the button ("=====Welcome======", "Push the Button").
3. **Entry Granted:** When the button is pressed, the Green LED lights up, the buzzer beeps, and the LCD displays "Silahkan Masuk" (Please Enter). The servo motor opens the gate, and the vehicle counter increments by 1.
4. **Environment Monitoring:** The LDR continuously monitors ambient light. If the light value drops below the threshold (indicating night/darkness), the White LED turns on automatically to illuminate the portal area.

## 🚀 How to Use
1. Clone this repository to your local machine.
2. Open the `.ino` file using the Arduino IDE.
3. Install the required libraries via the Arduino Library Manager:
   - `LiquidCrystal_I2C` (by Frank de Brabander or Marco Schwartz)
   - `Servo` (Built-in)
4. Select your Arduino board and COM Port, then click **Upload**.
5. Assemble the hardware according to the pinout table or the provided Fritzing schematic.
