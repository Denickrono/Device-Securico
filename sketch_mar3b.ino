// Pin definitions
const int tiltSwitchPin = 2;    // Tilt switch connected to D2
const int armButtonPin = 3;     // Arm button connected to D3
const int deactivateButtonPin = 4; // Deactivate button connected to D4
const int buzzerPin = 5;        // Buzzer connected to D5

// System states
bool systemArmed = false;       // Tracks if the system is armed
bool alarmTriggered = false;    // Tracks if the alarm is triggered

void setup() {
  // Initialize pins
  pinMode(tiltSwitchPin, INPUT);
  pinMode(armButtonPin, INPUT);
  pinMode(deactivateButtonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  // Start with buzzer off
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  // Check if the arm button is pressed
  if (digitalRead(armButtonPin) == HIGH) {
    systemArmed = true; // Arm the system
    delay(500); // Debounce delay
  }

  // If the system is armed, monitor the tilt switch
  if (systemArmed) {
    if (digitalRead(tiltSwitchPin) == HIGH) { // Tilt switch detects motion
      alarmTriggered = true; // Trigger the alarm
    }
  }

  // If the alarm is triggered, sound the buzzer
  if (alarmTriggered) {
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
  }

  // Check if the deactivate button is pressed
  if (digitalRead(deactivateButtonPin) == HIGH) {
    systemArmed = false; // Disarm the system
    alarmTriggered = false; // Stop the alarm
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
    delay(500); // Debounce delay
  }
}
