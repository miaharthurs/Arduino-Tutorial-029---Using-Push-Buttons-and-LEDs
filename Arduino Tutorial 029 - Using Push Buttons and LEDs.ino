// assign Pins and constants and global variables
const unsigned LEDPin = 8;
const unsigned buttonPin1 = 12;
const unsigned buttonPin2 = 11;
const unsigned buzzPin = 13;
const unsigned delayTime = 100;
const int maxBrightness = 255;
const int minBrightness = 0;
int brightness = minBrightness;
int step = 10;

// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(LEDPin, OUTPUT);
    digitalWrite(LEDPin, LOW);
    pinMode(buttonPin1, INPUT);
    pinMode(buttonPin2, INPUT);
    pinMode(buzzPin, OUTPUT);
}

// the loop function runs over and over again until power down or reset

// check which button is being pressed then either increase or decrease the brightness of the LEDs

void loop() {
    const unsigned buttonNew1 = digitalRead(buttonPin1);
    const unsigned buttonNew2 = digitalRead(buttonPin2);

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