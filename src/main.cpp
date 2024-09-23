#include <Arduino.h>
#define PIN_SW 6
volatile int nCount = 0;

IRAM_ATTR void onResetCounter()
{
  nCount++;
}

void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
  pinMode(PIN_SW, INPUT_PULLUP);
  attachInterrupt(PIN_SW, onResetCounter, FALLING);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // Turn on the LED
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
  // Print "Hello World" to the serial monitor
  Serial.printf("Hello World: %d\r\n", nCount);
  // Wait for 1 second (1000 milliseconds)

  digitalWrite(5, HIGH);
  delay(100);
  digitalWrite(5, LOW);
  delay(5000);
  // if (digitalRead(PIN_SW) == LOW) {
  //   nCount++;
  //   Serial.printf("Button pressed: %d\n", nCount);
  // }
}