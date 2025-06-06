#include <LiquidCrystal.h>

// Define pins for the LCD
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Define sensor and buzzer pins
const int trigPin = 2;
const int echoPin = 3;
const int buzzer = 4;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzer, OUTPUT);
    lcd.begin(16, 2);
}

void loop() {
    // Send a pulse to trigger the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure the echo time
    long duration = pulseIn(echoPin, HIGH);
    int distance = duration * 0.034 / 2; // Convert to cm

    // Display distance on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Water Level: ");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    lcd.print(" cm");

    // Trigger buzzer if water level is less than 30 cm
    if (distance < 30) {  
        digitalWrite(buzzer, HIGH);
        delay(500);  // Buzzer stays on for 500ms
        digitalWrite(buzzer, LOW);
        delay(500);  // Buzzer off for 500ms (blinking effect)
    } else {
        digitalWrite(buzzer, LOW);
    }

    delay(1000); // Update every second
}
