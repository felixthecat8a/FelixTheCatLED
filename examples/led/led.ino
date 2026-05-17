#include <FelixTheCatLED.h>

#define LED_PIN 6
FelixTheCatLED::LED led(LED_PIN);

void setup() {
  led.begin();
  led.on();
  delay(1000);
}

void loop() {
  led.toggle();
  delay(1000);
}
