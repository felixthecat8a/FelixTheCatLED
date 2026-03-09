#ifndef FELIX_THE_CAT_LED_H
#define FELIX_THE_CAT_LED_H

#include <Arduino.h>

namespace FelixTheCatLED {
  class LED {
    public:
      LED(uint8_t pin);
  
      void begin();
      void on();
      void off();
      void toggle();
      bool isOn() const { return _state; }
      void setPin(uint8_t pin);
      void setActiveLow(bool activeLow);
      bool isActiveLow() const { return _activeLow; }
  
    private:
      uint8_t _pin;
      bool _state;
      bool _activeLow;
  };

} // namespace FelixTheCatLED

#endif // FELIX_THE_CAT_LED_H
