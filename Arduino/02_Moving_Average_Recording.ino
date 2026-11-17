
const float DURATION_S = 20.0f;
const bool START_ON_KEY = true;
const bool SEND_TIMESTAMP = true;

const uint8_t FSR_PIN = A0;

const uint32_t SAMPLE_PERIOD_US = 2000;  
const int WINDOW_SIZE = 12;

const uint32_t TOTAL_SAMPLES =
    (uint32_t)(DURATION_S * 1000000.0f / SAMPLE_PERIOD_US);

int samples[WINDOW_SIZE] = {0};
long sum = 0;
int sampleIndex = 0;
int sampleCount = 0;

uint32_t nextTick;
uint32_t startMs;
uint32_t recordedSamples = 0;

void setup() {
  Serial.begin(115200);
  analogReference(DEFAULT);

  if (START_ON_KEY) {
    Serial.println("# Type any character and press Send to start recording...");

    while (Serial.available() == 0) {
    }

    while (Serial.available() > 0) {
      Serial.read();
    }
  }

  if (SEND_TIMESTAMP) {
    Serial.println("time_ms,value");
  }

  startMs = millis();
  nextTick = micros() + SAMPLE_PERIOD_US;
}

void loop() {

  if (recordedSamples >= TOTAL_SAMPLES) {
    Serial.println("# done");

    while (true) {
    }
  }

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

  if (SEND_TIMESTAMP) {
    Serial.print(millis() - startMs);
    Serial.print(",");
  }

  Serial.println(filteredValue);

  recordedSamples++;
}
