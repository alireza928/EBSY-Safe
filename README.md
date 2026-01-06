**🔐 Arduino Safe Security System**
📌 Project Overview

This project is an Arduino-based safe security system that unlocks using a 3-digit button code.
Three push buttons are used to enter the code, and two LEDs indicate whether access is granted or denied.


⚙️ How It Works

The system starts in a locked state (Red LED ON)

The user enters a 3-digit code using three buttons

Each button represents a number:

Button 1 → 1

Button 2 → 2

Button 3 → 3

After 3 button presses:

✅ Correct code → Green LED turns ON for 3 seconds

❌ Incorrect code → Red LED blinks 3 times

The system then resets and waits for the next attempt

🔢 Access Code

The default access code is:

3 - 1 - 1


You can change the code in the Arduino sketch by editing:

int PassCode[] = {3, 1, 1};

🧰 Components Used

Arduino Uno (or compatible)

3 × Push buttons

2 × LEDs (Red & Green)

2 × 220Ω resistors (for LEDs)

Breadboard

Jumper wires

🔌 Pin Configuration
Component	Arduino Pin
Button 1	Pin 2
Button 2	Pin 3
Button 3	Pin 4
Red LED	Pin 6
Green LED	Pin 7

Buttons use internal pull-up resistors, so:

One side of each button → Arduino pin

Other side → GND

🚀 How to Use

Upload the code to your Arduino

Open Serial Monitor (9600 baud)

Press buttons to enter the code

Watch the LEDs for feedback:

🟢 Green = Access Granted

🔴 Red = Access Denied

🛠️ Features

Internal pull-up resistors (no external button resistors needed)

Button press detection on release

Visual feedback using LEDs

Automatic reset after each attempt

📈 Possible Improvements

Add a buzzer for sound feedback

Add a lockout after multiple failed attempts

Store the code in EEPROM

Use an LCD display for feedback

👨‍💻 Author

[Alireza]
EBSY – Arduino – Safe
