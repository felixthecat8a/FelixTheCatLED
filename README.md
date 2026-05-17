# FelixTheCatLED

[![License: MIT](https://img.shields.io/github/license/felixthecat8a/FelixTheCatLED)](https://opensource.org/licenses/MIT)
![GitHub repo size](https://img.shields.io/github/repo-size/felixthecat8a/FelixTheCatLED)
![GitHub repo file or directory count](https://img.shields.io/github/directory-file-count/felixthecat8a/FelixTheCatLED)
![GitHub top language](https://img.shields.io/github/languages/top/felixthecat8a/FelixTheCatLED)

An Arduino Library for LED Control

## Implementation

### `BlinkLED.ino`

```cpp
#include <FelixTheCatLED.h>

#define LED_PIN 6
FelixTheCatLED::LED led(LED_PIN);

void setup() {
  led.begin();
}

void loop() {
  led.on();
  delay(1000);
  led.off();
  delay(1000);
}
```

### `FadeLED.ino`

```cpp
#include <FelixTheCatLED.h>

#define LED_PIN 3
FelixTheCatLED::PWM led(LED_PIN);

int brightness = 0;
int step = 1;

void setup() {
  led.begin();
}

void loop() {
  led.setBrightness(brightness);
  brightness += step;
  if (brightness >= 255) {
    brightness = 255; step = -1;
  } else if (brightness <= 0) {
    brightness = 0; step = 1;
  }
  delay(10);
}
```

