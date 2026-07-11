#include <FelixTheCatLED.h>

/* RGB LED Setup: Use PWM pins denoted by a ~ symbol. */
#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11
FelixTheCatLED::RGB rgb(RED_PIN, GREEN_PIN, BLUE_PIN);

/* Pushbutton Setup */
#define PUSHBUTTON_PIN 2
FelixTheCatLED::Button bttn(PUSHBUTTON_PIN);
const int maxIndex = 13;
int currentIndex = 0;

void setup() {
  rgb.begin();
  rgb.setBrightness(100);
  bttn.begin();
  bttn.setHoldTime(900);
  bttn.setMultiClickTime(250);
}

void loop() {
  bttn.update();

  if (bttn.wasClicked()) {
    currentIndex++;
    if (currentIndex > maxIndex) currentIndex = 0;
  }

  if (bttn.wasDoubleClicked()) {
    currentIndex--;
    if (currentIndex < 0) currentIndex = maxIndex;
  }

  if (bttn.wasHeld()) {
    currentIndex = 0;
  }

  switch (currentIndex) {
    case 0: rgb.off(); break;
    case 1: rgb.setRed(); break;
    case 2: rgb.setOrange(); break;
    case 3: rgb.setYellow(); break;
    case 4: rgb.setLime(); break;
    case 5: rgb.setGreen(); break;
    case 6: rgb.setSpring(); break;
    case 7: rgb.setCyan(); break;
    case 8: rgb.setAzure(); break;
    case 9: rgb.setBlue(); break;
    case 10: rgb.setViolet(); break;
    case 11: rgb.setMagenta(); break;
    case 12: rgb.setRose(); break;
    case 13: rgb.setWhite(); break;
    default: rgb.off(); break;
  }
}
