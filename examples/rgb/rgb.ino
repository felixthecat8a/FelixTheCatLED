#include <FelixTheCatLED.h>

#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11
FelixTheCatLED::RGB rgb(RED_PIN, GREEN_PIN, BLUE_PIN);

#define PUSHBUTTON_PIN 2
FelixTheCatLED::Button button(PUSHBUTTON_PIN);

const int COLOR_COUNT = 25;
int currentColor = 0;

void setup() {
  rgb.begin();
  rgb.setBrightness(77); // Set brightness to 30%

  button.begin();
  button.setHoldTime(900);
  button.setMultiClickTime(250);
}

void loop() {
  button.update();

  if (button.wasDoubleClicked()) {
    currentColor = (currentColor - 1 + COLOR_COUNT) % COLOR_COUNT;
    switchColor(currentColor);
  } else if (button.wasClicked()) {
    currentColor = (currentColor + 1) % COLOR_COUNT;
    switchColor(currentColor);
  }

}

void switchColor(int color) {
  switch (color) {
    case 0: rgb.setRed(); break;
    case 1: rgb.setVermilion(); break;
    case 2: rgb.setOrange(); break;
    case 3: rgb.setAmber(); break;
    case 4: rgb.setYellow(); break;
    case 5: rgb.setLime(); break;
    case 6: rgb.setChartreuse(); break;
    case 7: rgb.setHarlequin(); break;
    case 8: rgb.setGreen(); break;
    case 9: rgb.setMint(); break;
    case 10: rgb.setSpringGreen(); break;
    case 11: rgb.setTurquoise(); break;
    case 12: rgb.setCyan(); break;
    case 13: rgb.setSkyBlue(); break;
    case 14: rgb.setAzure(); break;
    case 15: rgb.setSapphire(); break;
    case 16: rgb.setBlue(); break;
    case 17: rgb.setIndigo(); break;
    case 18: rgb.setViolet(); break;
    case 19: rgb.setPurple(); break;
    case 20: rgb.setMagenta(); break;
    case 21: rgb.setPink(); break;
    case 22: rgb.setRose(); break;
    case 23: rgb.setCrimson(); break;
    case 24: rgb.setWhite(); break;
    default: rgb.off(); break;
  }
}
