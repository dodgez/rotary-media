#define CLOCK_PIN 2
#define DIRECTION_PIN 3
#define BUTTON_PIN 4

int currentClockState = LOW;
int lastClockState = LOW;
int currentButtonState = HIGH;
int lastButtonState = HIGH;

void setup() {
  pinMode(CLOCK_PIN, INPUT);
  pinMode(DIRECTION_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(9600);

  lastClockState = digitalRead(CLOCK_PIN);
  lastButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  currentClockState = digitalRead(CLOCK_PIN);
  // Only read on leading edge
  if (currentClockState != lastClockState && currentClockState == HIGH){
    Serial.print("{\"direction\":\"");
    if (digitalRead(DIRECTION_PIN) != currentClockState) {
      Serial.print("CCW");
    } else {
      Serial.print("CW");
    }
    Serial.print("\"}\n");
  }
  lastClockState = currentClockState;

  currentButtonState = digitalRead(BUTTON_PIN);
  if (currentButtonState != lastButtonState) {
    Serial.print("{\"button\":\"");
    if (currentButtonState == LOW) {
      Serial.print("pressed");
    } else {
      Serial.print("released");
    }
    Serial.print("\"}\n");
  }
  lastButtonState = currentButtonState;

  // Delay to debounce encoder data
  delay(1);
}
