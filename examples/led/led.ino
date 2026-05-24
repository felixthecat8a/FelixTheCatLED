#include <FelixTheCatLED.h>

#define LED_PIN 6
FelixTheCatLED::LED led(LED_PIN);

const unsigned long BLINK_INTERVAL = 1000;
FelixTheCatLED::Timer blinkTimer(BLINK_INTERVAL);

#define PWM_PIN 5
FelixTheCatLED::PWM pwm(PWM_PIN);

const unsigned long PWM_INTERVAL = 50;
FelixTheCatLED::Timer pwmTimer(PWM_INTERVAL);

int brightness = 0;
int fadeAmount = 5;

void setup() {
  led.begin();
  led.on();
  pwm.begin();
  pwm.setBrightness(128); // Set brightness to 50%

  pwmTimer.onTick([]() {
    pwm.setBrightness(brightness);
    brightness += fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount; // Reverse direction at limits
    }
  });
}

void loop() {
  if (blinkTimer.tick()) {
    led.toggle();
  }
  pwmTimer.tick();
}
