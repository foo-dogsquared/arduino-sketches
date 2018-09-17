int pins[] = {8, 10, 12};

const int no_of_pins = sizeof pins / sizeof pins[0];

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < no_of_pins; i++) {
    pinMode(pins[i], OUTPUT);
  }
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.print("Is it working?");
}

void loop() {
  // put your main code here, to run repeatedly:
  int delay_amt = 100;
  for (int i = 0; i < no_of_pins; i++) {
    digitalWrite(pins[i], HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delay_amt);
    digitalWrite(pins[i], LOW);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print("This is working, right?");
  }
}
