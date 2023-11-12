#include <ESP32Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // Include the LCD library

const int trigPin1 = 27;
const int echoPin1 = 26;

const int trigPin2 = 2;
const int echoPin2 = 15;

const int trigPin3 = 18;
const int echoPin3 = 5;

const int ledPin1 = 13;
const int ledPin2 = 12;
const int ledPin3 = 14;

const int switchPin = 32;
Servo servo;

long duration;
int distance;

bool isSwitchOn = false;

// LCD initialization (replace the address with the actual I2C address of your LCD)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  pinMode(switchPin, INPUT_PULLUP);
  servo.attach(25); // Attach servo to pin D25
  servo.write(0);   // Initialize the servo position

  // LCD setup
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");

  Serial.begin(9600); // Initialize Serial Monitor
}

void loop() {
  isSwitchOn = digitalRead(switchPin) == LOW;

  if (isSwitchOn) {
    servo.write(90); // Open the servo
  } else {
    servo.write(0); // Close the servo
  }

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  distance = duration * 0.034 / 2;

  lcd.clear(); // Clear the previous display content
  if (distance < 200) {
    digitalWrite(ledPin1, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Space 1: Occupied");
    Serial.println("Space 1: Occupied");
  } else {
    digitalWrite(ledPin1, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Space 1: Vacant");
    Serial.println("Space 1: Vacant");
  }
  delay(1000);

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  distance = duration * 0.034 / 2;

  lcd.clear(); // Clear the previous display content
  if (distance < 200) {
    digitalWrite(ledPin2, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Space 2: Occupied");
    Serial.println("Space 2: Occupied");
  } else {
    digitalWrite(ledPin2, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Space 2: Vacant");
    Serial.println("Space 2: Vacant");
  }
  delay(1000);

  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration = pulseIn(echoPin3, HIGH);
  distance = duration * 0.034 / 2;

  lcd.clear(); // Clear the previous display content
  if (distance < 200) {
    digitalWrite(ledPin3, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Space 3: Occupied");
    Serial.println("Space 3: Occupied");
  } else {
    digitalWrite(ledPin3, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Space 3: Vacant");
    Serial.println("Space 3: Vacant");
  }
  delay(1000);
}
