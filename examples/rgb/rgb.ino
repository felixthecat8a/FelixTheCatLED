#include <FelixTheCatLED.h>

#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11
FelixTheCatLED::RGB rgb(RED_PIN, GREEN_PIN, BLUE_PIN);

const unsigned long RGB_INTERVAL = 1000;
FelixTheCatLED::Timer timer(RGB_INTERVAL);

void setup() {
  rgb.begin();
  rgb.setBrightness(128); // Set brightness to 50%
}

void loop() {
  if (timer.tick()) {
    switchColor();
  }
}

void switchColor() {
  static uint8_t state = 0;
  switch (state) {
    case 0: rgb.setRed(); break;
    case 1: rgb.setGreen(); break;
    case 2: rgb.setBlue(); break;
    case 3: rgb.setYellow(); break;
    case 4: rgb.setCyan(); break;
    case 5: rgb.setMagenta(); break;
    default: rgb.setWhite(); break;
  }
  state = (state + 1) % 7; // Cycle through colors
}
