# FelixTheCatLED

![GitHub Release](https://img.shields.io/github/v/release/felixthecat8a/FelixTheCatLED?logo=arduino&color=00878F)
![GitHub License](https://img.shields.io/github/license/felixthecat8a/FelixTheCatLED)
![GitHub repo size](https://img.shields.io/github/repo-size/felixthecat8a/FelixTheCatLED)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/felixthecat8a/FelixTheCatLED)
![GitHub repo file or directory count](https://img.shields.io/github/directory-file-count/felixthecat8a/FelixTheCatLED)
![GitHub top language](https://img.shields.io/github/languages/top/felixthecat8a/FelixTheCatLED?color=%2300599C&logo=c%2B%2B)

An Arduino Library for LED Control

## Installation

### Install via ZIP file

1. Download the *.zip* file of the [latest release](https://github.com/felixthecat8a/FelixTheCatLED/releases/latest/).
2. In the **Arduino IDE**, go to ***Sketch*** > ***Include Library*** > ***Add .ZIP Library...***.
3. Select the downloaded *.zip* file.

### Updating the Library

To update the library:
1. Delete the existing ***FelixTheCatLED*** folder from your libraries directory: ***Documents*** > ***Arduino*** > ***libraries*** > ***FelixTheCatLED***
2. Follow the installation steps above to install the latest version.

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

#define LED_PIN 3 // Choose a PWM Pin denoted by ~
FelixTheCatLED::PWM led(LED_PIN);

int brightness = 0;
int step = 1;

void setup() {
  led.begin();
}

void loop() {
  led.setBrightness(brightness);
  brightness = brightness + step;
  if (brightness <= 0 || brightness >= 255) {
    step = -step;
  }
  delay(30);
}
```

