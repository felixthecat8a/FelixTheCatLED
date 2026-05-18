#include <FelixTheCatLED.h>
using namespace FelixTheCatLED;

/* Blink Setup */
#define LED_PIN 8
LED blinkLED(LED_PIN);
AnimBlinkLED<LED> animBlink(blinkLED, 2000);

/* Fade Setup: Use PWM pins denoted by a ~ symbol. */
#define PWM_PIN 6
PWM pwmLED(PWM_PIN);
AnimFadeLED<PWM> animFade(pwmLED, 2000);

/* RGB LED Setup: Use PWM pins denoted by a ~ symbol. */
#define RGB_RED 9
#define RGB_GREEN 10
#define RGB_BLUE 11
RGB rgbLED(RGB_RED, RGB_GREEN, RGB_BLUE);

/* RGB LED colorwheel & fade setup */
AnimColorwheel<RGB> colorwheel(rgbLED, 5000);
AnimFadeLED<RGB> rgbFade(rgbLED, 2000, 5, 51);

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
