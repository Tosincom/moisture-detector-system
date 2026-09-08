// Smart Plant Care System
// Reads soil moisture, shows status on LEDs, sounds a buzzer,
// and switches a relay to simulate turning a water pump on/off.

const int SOIL_PIN = A0;   // soil moisture sensor (analog output)
const int GREEN_LED = 8;   // lights up when soil is wet enough
const int RED_LED = 9;     // lights up when soil is too dry
const int BUZZER = 7;      // sounds when soil is wet (see note below)
const int RELAY = 6;       // simulated water pump switch

// Calibrated from real readings taken with this exact sensor:
//   Open air  = 1023 (driest)
//   Tap water = 381  (wettest)
//   Garden soil = 533
// Threshold is the midpoint between air and water.
const int DRY_THRESHOLD = 702;

void setup() {
  Serial.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RELAY, OUTPUT);
}

void loop() {
  int raw = analogRead(SOIL_PIN);
  Serial.println(raw);

  if (raw > DRY_THRESHOLD) {
    // Soil is dry
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RELAY, HIGH);   // "pump" turns on
    noTone(BUZZER);
  } else {
    // Soil is wet enough
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(RELAY, LOW);    // "pump" turns off
    tone(BUZZER, 1000);          // buzzes to confirm a wet reading
  }

  delay(500);
}
