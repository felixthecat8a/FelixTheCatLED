#include <FelixTheCatLED.h>

#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11
FelixTheCatLED::RGB rgb(RED_PIN, GREEN_PIN, BLUE_PIN);

void setup() {
    rgb.begin();
    rgb.setBrightness(128); // Set brightness to 50%
}

void loop() {
    rgb.setRed();
    delay(1000);
    rgb.setGreen();
    delay(1000);
    rgb.setChartreuse();
    delay(1000);
}