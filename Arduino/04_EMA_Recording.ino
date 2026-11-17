
const float DURATION_S = 20.0f;
const bool START_ON_KEY = true;
const bool SEND_TIMESTAMP = true;

const uint8_t FSR_PIN = A0;

const uint32_t SAMPLE_PERIOD_US = 2000; 
const float ALPHA = 0.15f;

const uint32_t TOTAL_SAMPLES =
    (uint32_t)(DURATION_S * 1000000.0f / SAMPLE_PERIOD_US);

float filtered = 0.0f;
bool firstSample = true;

uint32_t nextTick;
uint32_t startMs;
uint32_t sampleCount = 0;

void setup() {
  Serial.begin(115200);
  analogReference(DEFAULT);

  if (START_ON_KEY) {
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
  if (sampleCount >= TOTAL_SAMPLES) {
    Serial.println("# done");

    while (true) {
    }
  }

  while ((int32_t)(micros() - nextTick) < 0) {
  }

  nextTick += SAMPLE_PERIOD_US;

  int raw = analogRead(FSR_PIN);

  if (firstSample) {
    filtered = raw;
    firstSample = false;
  } else {
    filtered = ALPHA * raw + (1.0f - ALPHA) * filtered;
  }

  int value = (int)(filtered + 0.5f);

  if (SEND_TIMESTAMP) {
    Serial.print(millis() - startMs);
    Serial.print(",");
  }

  Serial.println(value);

  sampleCount++;
}
