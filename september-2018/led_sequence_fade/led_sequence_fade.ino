#define MAXIMUM_BRIGHTNESS 255

int pins[] = {3, 5, 11};

int fade_amt = 3;    // how fast the fading will be

const int no_of_pins = sizeof pins / sizeof pins[0];

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < no_of_pins; i++) {
    pinMode(pins[i], OUTPUT);
  }
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Is it working?");
}

void loop() {
  int delay_amt = 115;
  for (int i = 0; i < no_of_pins; i++) {
    int brightness = 0;
    
    int completed_times = 0;
    while (true) {
      analogWrite(pins[i], brightness);
      brightness += fade_amt;
      Serial.println(brightness);
      
      // when the light goes to maximum or minimum brightness, it lights up or down
      if (brightness <= 0 || brightness >= MAXIMUM_BRIGHTNESS) {
        fade_amt = -fade_amt;
        completed_times++;
      }

      if (completed_times == 2) break;
    }

    analogWrite(pins[i], 0);
    delay(delay_amt);
  }
}
