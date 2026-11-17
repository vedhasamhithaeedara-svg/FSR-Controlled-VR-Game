
const uint8_t FSR_PIN = A0;
const uint32_t SAMPLE_PERIOD_US = 2000; 
int samples[WINDOW_SIZE] = {0};
long sum = 0;
int sampleIndex = 0;
int sampleCount = 0;

uint32_t nextTick;
void setup() {
  Serial.begin(115200);
  analogReference(DEFAULT);

  nextTick = micros() + SAMPLE_PERIOD_US;
}

void loop() {

  while ((int32_t)(micros() - nextTick) < 0) {
  }
  nextTick += SAMPLE_PERIOD_US;

  int raw = analogRead(FSR_PIN);

  if (sampleCount == WINDOW_SIZE) {
    sum -= samples[sampleIndex];
  } else {
    sampleCount++;
  }
  samples[sampleIndex] = raw;
  sum += raw;

  sampleIndex = (sampleIndex + 1) % WINDOW_SIZE;

  int filteredValue = (int)(
      (float)sum / sampleCount + 0.5f
  );

  Serial.println(filteredValue);
}
