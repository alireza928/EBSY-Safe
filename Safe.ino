// This is a const so the values doesn't change
const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int RedLED = 6;
const int GreenLED = 7;

// This is a int so the values does change
int PassCode[] = {3, 1, 1}; // this is the code to open the safe
int EnteredCode[3];        // this is the value of the code
int Position = 0;

// Variables to track button states false/true
bool button1Pressed = false;
bool button2Pressed = false;
bool button3Pressed = false;

// This is the setup part
void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);

  digitalWrite(RedLED, HIGH);
  digitalWrite(GreenLED, LOW);

  // Serial monitor settings
  Serial.begin(9600);
  Serial.println("=================================");
  Serial.println("Security System Is Turned on!");
  Serial.println("Enter 3-digit code: X-X-X");
  Serial.println("Button 1 (left) = 1");
  Serial.println("Button 2 (middle) = 2");
  Serial.println("Button 3 (right) = 3");
  Serial.println("=================================");
}

// This is a loop for the codes
void loop() {

  // Button 1 (L)
  if (digitalRead(button1) == LOW && !button1Pressed) {
    button1Pressed = true;
  }
  if (digitalRead(button1) == HIGH && button1Pressed) {
    EnteredCode[Position] = 1;
    Serial.print("Button 1 pressed - Digit ");
    Serial.print(Position + 1);
    Serial.println("/3 entered");
    Position++;
    button1Pressed = false;
    delay(50);
  }

  // Button 2 (M)
  if (digitalRead(button2) == LOW && !button2Pressed) {
    button2Pressed = true;
  }
  if (digitalRead(button2) == HIGH && button2Pressed) {
    EnteredCode[Position] = 2;
    Serial.print("Button 2 pressed - Digit ");
    Serial.print(Position + 1);
    Serial.println("/3 entered");
    Position++;
    button2Pressed = false;
    delay(50);
  }

  // Button 3 (R)
  if (digitalRead(button3) == LOW && !button3Pressed) {
    button3Pressed = true;
  }
  if (digitalRead(button3) == HIGH && button3Pressed) {
    EnteredCode[Position] = 3;
    Serial.print("Button 3 pressed - Digit ");
    Serial.print(Position + 1);
    Serial.println("/3 entered");
    Position++;
    button3Pressed = false;
    delay(50);
  }

  // Check code after 3 digits
  if (Position >= 3) {
    bool correct = true;

    for (int i = 0; i < 3; i++) {
      if (EnteredCode[i] != PassCode[i]) {
        correct = false;
      }
    }

    if (correct) {
      Serial.println("ACCESS GRANTED");
      digitalWrite(RedLED, LOW);
      digitalWrite(GreenLED, HIGH);
      delay(3000);
      digitalWrite(GreenLED, LOW);
      digitalWrite(RedLED, HIGH);
    } else {
      Serial.println("ACCESS DENIED");
      for (int i = 0; i < 3; i++) {
        digitalWrite(RedLED, LOW);
        delay(300);
        digitalWrite(RedLED, HIGH);
        delay(300);
      }
    }

    // Reset
    Position = 0;
    Serial.println("=================================");
  }
}
