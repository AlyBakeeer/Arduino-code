int switchPin = 2; // The pin for the switch
int ledPin = 13; // The pin for the LED

void setup() {
  pinMode(switchPin, INPUT_PULLUP); // Set the switch pin as input with pull-up resistor
  pinMode(ledPin, OUTPUT); // Set the LED pin as output

  Serial.begin(9600); // Start the serial communication
}

void loop() {
  // Read the state of the switch
  int switchState = digitalRead(switchPin);

  // Send switch status to PC
  Serial.print("Switch status: ");
  Serial.println(switchState);

  // Look for incoming serial data
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');

    if (command == "led_on") {
      digitalWrite(ledPin, HIGH); // Turn on the LED
      Serial.println("LED is now ON");
    } else if (command == "led_off") {
      digitalWrite(ledPin, LOW); // Turn off the LED
      Serial.println("LED is now OFF");
    }
  }

  delay(500); // Delay for stability
}