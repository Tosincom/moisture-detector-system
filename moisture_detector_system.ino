const int SOIL_PIN = A0;
const int GREEN_LED = 8;
const int RED_LED = 9;
const int BUZZER = 7;
const int RELAY = 6;
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
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RELAY, HIGH);
    noTone(BUZZER);
  } else {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(RELAY, LOW);
    tone(BUZZER, 1000);
  }

  delay(500);
}
