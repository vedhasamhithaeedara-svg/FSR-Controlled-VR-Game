
const int FSR_PIN = A0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  unsigned long time_ms = millis();

  int value = analogRead(FSR_PIN);

  Serial.print(time_ms);
  Serial.print(",");
  Serial.println(value);

  delay(5);  // Approximately 200 samples/second
}
