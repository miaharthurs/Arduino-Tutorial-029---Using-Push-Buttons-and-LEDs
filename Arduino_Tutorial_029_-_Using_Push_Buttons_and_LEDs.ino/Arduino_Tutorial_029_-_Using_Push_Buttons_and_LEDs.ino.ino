
const unsigned LEDPin = 8;
const unsigned buttonPin1 = 12;
const unsigned buttonPin2 = 11;
const unsigned buzzPin = 13;
const unsigned delayTime = 100;
const int maxBrightness = 255;
const int minBrightness = 0;
int brightness = minBrightness;
int step = 10;

bool ON = false;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LEDPin, OUTPUT);
  digitalWrite(LEDPin, LOW);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buzzPin, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
  const unsigned buttonNew1 = digitalRead(buttonPin1);
  if (buttonNew1 == 1)
  {
    brightness += step;
    if (brightness > maxBrightness)
    {
      brightness = maxBrightness;
      digitalWrite(buzzPin, HIGH);
      delay(500);
      digitalWrite(buzzPin, LOW);
    }
  }

  const unsigned buttonNew2 = digitalRead(buttonPin2);
  if (buttonNew2 == 1)
  {
    brightness -= step;
    if (brightness < minBrightness)
    {
      brightness = minBrightness;
      digitalWrite(buzzPin, HIGH);
      delay(500);
      digitalWrite(buzzPin, LOW);
    }
  }
  analogWrite(LEDPin, brightness);

  delay(delayTime);
}
