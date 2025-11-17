void setup() {
  Serial.begin(9600);
  Serial.println("Listening...");
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    Serial.print("BT -> ");
    Serial.println(c);
  }
}
