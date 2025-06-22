#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int button1 = 12;
const int button2 = 13;
const int button3 = 14;

const int ledRed = 2;
const int ledYellow = 4;
const int ledGreen = 5;

void blinkLED(int led, int count);
void alternateBlink(int led1, int led2, int count);
void alternateBlinkThree(int led1, int led2, int led3, int count);

void setup() {
    pinMode(button1, INPUT_PULLUP);
    pinMode(button2, INPUT_PULLUP);
    pinMode(button3, INPUT_PULLUP);
    pinMode(ledRed, OUTPUT);
    pinMode(ledYellow, OUTPUT);
    pinMode(ledGreen, OUTPUT);

    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("System Ready");
}

void loop() {
    static bool lastButtonState = false;
    bool buttonPressed = false;

    if (digitalRead(button1) == LOW) {
        delay(50);
        if (digitalRead(button1) == LOW) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Red LED Blinking");
            blinkLED(ledRed, 5);
            buttonPressed = true;
        }
    }

    if (digitalRead(button2) == LOW) {
        delay(50);
        if (digitalRead(button2) == LOW) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Red & Green Blink");
            alternateBlink(ledRed, ledGreen, 5);
            buttonPressed = true;
        }
    }

    if (digitalRead(button3) == LOW) {
        delay(50);
        if (digitalRead(button3) == LOW) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("All LEDs Blink");
            alternateBlinkThree(ledRed, ledYellow, ledGreen, 5);
            buttonPressed = true;
        }
    }

    // Update LCD hanya jika status tombol berubah
    if (!buttonPressed && lastButtonState) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("System Ready");
    }

    lastButtonState = buttonPressed;
}

// Implementasi fungsi di bawah
void blinkLED(int led, int count) {
    for (int i = 0; i < count; i++) {
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
    }
}

void alternateBlink(int led1, int led2, int count) {
    for (int i = 0; i < count; i++) {
        digitalWrite(led1, HIGH);
        delay(500);
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        delay(500);
        digitalWrite(led2, LOW);
    }
}

void alternateBlinkThree(int led1, int led2, int led3, int count) {
    for (int i = 0; i < count; i++) {
        digitalWrite(led1, HIGH);
        delay(500);
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        delay(500);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        delay(500);
        digitalWrite(led3, LOW);
    }
}
