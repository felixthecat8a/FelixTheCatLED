#include <FelixTheCatLED.h>

/* Blink Setup */
#define LED_PIN 8
FelixTheCatLED::LED blinkLED(LED_PIN);
FelixTheCatLED::AnimBlinkLED<FelixTheCatLED::LED> animBlink(blinkLED, 2000);

/* Fade Setup: Use PWM pins denoted by a ~ symbol. */
#define PWM_PIN 6
FelixTheCatLED::PWM pwmLED(PWM_PIN);
FelixTheCatLED::AnimFadeLED<FelixTheCatLED::PWM> animFade(pwmLED, 2000);

/* RGB LED Setup: Use PWM pins denoted by a ~ symbol. */
#define RGB_RED 9
#define RGB_GREEN 10
#define RGB_BLUE 11
FelixTheCatLED::RGB rgbLED(RGB_RED, RGB_GREEN, RGB_BLUE);

/* RGB LED colorwheel & fade setup */
FelixTheCatLED::AnimColorwheel<FelixTheCatLED::RGB> colorwheel(rgbLED, 5000);
FelixTheCatLED::AnimFadeLED<FelixTheCatLED::RGB> rgbFade(rgbLED, 2000, 5, 51);

void setup() {
  blinkLED.begin();
  pwmLED.begin();
  rgbLED.begin();
  rgbLED.setBrightness(75);
}

void loop() {
  /* Handle LED Blink */
  animBlink.update();

  /* Handle LED Fade */
  animFade.update();

  /* Handle RGB LED Colorwheel & Fade*/
  colorwheel.update();
  rgbFade.update();
}
