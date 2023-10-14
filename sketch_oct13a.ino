int led_pin = 13;
int switch_pin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);  
  pinMode(switch_pin, INPUT);  
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readString();  
    if (command == "led_on\n") {
      digitalWrite(led_pin, HIGH);   
    } else if (command == "led_off\n") {
      digitalWrite(led_pin, LOW);  
    }
  }
  if (digitalRead(switch_pin) == HIGH) {
    Serial.println("Switch Pressed");
    delay(200); 
  }
}