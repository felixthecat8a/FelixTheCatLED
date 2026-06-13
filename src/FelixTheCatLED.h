#ifndef FELIX_THE_CAT_8A_LED_H
#define FELIX_THE_CAT_8A_LED_H

#include <Arduino.h>
#include "util/ColorsRGB.h"
#include "FelixTheCatTimer.h"
#include "FelixTheCatButton.h"
#include "anim/Anim.h"

#ifdef ARDUINO_ARCH_AVR
  #include <avr/pgmspace.h>
  #define READ_GAMMA(x) pgm_read_byte(&_gammaTable[x])
#else
  #define READ_GAMMA(x) _gammaTable[x]
#endif

#ifndef PWM_MAX
  #define PWM_MAX 255
#endif

namespace FelixTheCatLED {

  class LED {
    public:
      explicit LED(uint8_t pin);

      void begin();
      void on();
      void off();
      void toggle();
      bool isOn() const { return _state; }
      void setPin(uint8_t pin);
      uint8_t getPin() const { return _pin; }
      void setActiveLow(bool activeLow);
      bool isActiveLow() const { return _activeLow; }

    private:
      uint8_t _pin;
      bool _state;
      bool _activeLow;
  };

  /* PWM LED */

  enum LED_type : uint8_t {
    AUTO_LED,
    GENERIC_LED,
    ESP32_LED
  };

  class PWM {
    public:
      explicit PWM(uint8_t pin, LED_type type = GENERIC_LED, int8_t channel = -1);
      ~PWM();

      void begin();
      void setBrightness(uint8_t brightness);
      uint8_t getBrightness() const { return _brightness; }
      void on();
      void off();
      void toggle();
      bool isOn() const { return _state; }
      void setPin(uint8_t pin);
      uint8_t getPin() const { return _pin; }
      void setActiveLow(bool activeLow);
      bool isActiveLow() const { return _activeLow; }

    private:
      void _writeRaw(uint8_t value);
      uint8_t _pin;
      uint8_t _brightness;
      bool _state;
      bool _activeLow;
      LED_type _type;
      int8_t _channel;
  };

  /* RGB LED */

  class RGB {
    public:
      RGB(uint8_t rPin, uint8_t gPin, uint8_t bPin, bool commonAnode = true,
        LED_type type = GENERIC_LED, int8_t rCh = -1, int8_t gCh = -1, int8_t bCh = -1);

      void begin();

      void setRGB(const uint8_t rgb[3]);
      void setRGB(uint8_t red, uint8_t green, uint8_t blue);
      void setHex(uint32_t hex);
      void setBrightness(uint8_t brightness);
      uint8_t* getRGB() { return _RGB; }
      const uint8_t* getRGB() const { return _RGB; }
      uint8_t getRed() const { return _RGB[0]; }
      uint8_t getGreen() const { return _RGB[1]; }
      uint8_t getBlue() const { return _RGB[2]; }
      uint32_t getHex() const;
      String getHexString() const;

      void off() { setRGB(RGB_COLOR::BLACK); }
      void setWhite() { setRGB(RGB_COLOR::WHITE); }
      void setRed() { setRGB(RGB_COLOR::RED); }
      void setVermilion() { setRGB(RGB_COLOR::VERMILION); }
      void setOrange() { setRGB(RGB_COLOR::ORANGE); }
      void setAmber() { setRGB(RGB_COLOR::AMBER); }
      void setYellow() { setRGB(RGB_COLOR::YELLOW); }
      void setLime() { setRGB(RGB_COLOR::LIME); }
      void setChartreuse() { setRGB(RGB_COLOR::CHARTREUSE); }
      void setHarlequin() { setRGB(RGB_COLOR::HARLEQUIN); }
      void setGreen() { setRGB(RGB_COLOR::GREEN); }
      void setMint() { setRGB(RGB_COLOR::MINT); }
      void setSpringGreen() { setRGB(RGB_COLOR::SPRING_GREEN); }
      void setTurquoise() { setRGB(RGB_COLOR::TURQUOISE); }
      void setCyan() { setRGB(RGB_COLOR::CYAN); }
      void setSkyBlue() { setRGB(RGB_COLOR::SKY_BLUE); }
      void setAzure() { setRGB(RGB_COLOR::AZURE); }
      void setCerulean() { setRGB(RGB_COLOR::CERULEAN); }
      void setBlue() { setRGB(RGB_COLOR::BLUE); }
      void setIndigo() { setRGB(RGB_COLOR::INDIGO); }
      void setViolet() { setRGB(RGB_COLOR::VIOLET); }
      void setPurple() { setRGB(RGB_COLOR::PURPLE); }
      void setMagenta() { setRGB(RGB_COLOR::MAGENTA); }
      void setPink() { setRGB(RGB_COLOR::HOT_PINK); }
      void setRose() { setRGB(RGB_COLOR::ROSE); }
      void setCrimson() { setRGB(RGB_COLOR::CRIMSON); }

      void setHSV(int hue, float sat, float val);
      void setCMYK(float cyan, float magenta, float yellow, float key);
      void setGammaCorrection(bool enabled);

    private:
      PWM _rPWM, _gPWM, _bPWM;

      uint8_t _RGB[3];
      uint8_t _brightness;
      bool _gammaEnabled;
      bool _isCommonAnode;

      inline uint8_t _applyBrightness(uint8_t c) const {
        return (uint16_t(c) * _brightness) / PWM_MAX;
      }

      inline uint8_t _applyGamma(uint8_t c) const {
        return _gammaEnabled ? READ_GAMMA(c) : c;
      }

      inline uint8_t _process(uint8_t c) const {
        c = _applyBrightness(c);
        c = _applyGamma(c);
        return c;
      }

      inline void _showRGB(uint8_t r, uint8_t g, uint8_t b) {
        _RGB[0] = r; _RGB[1] = g; _RGB[2] = b;

        _rPWM.setBrightness(_process(r));
        _gPWM.setBrightness(_process(g));
        _bPWM.setBrightness(_process(b));
      }

      static const uint8_t _gammaTable[256] PROGMEM;
  };

} // namespace FelixTheCatLED

#endif // FELIX_THE_CAT_8A_LED_H
