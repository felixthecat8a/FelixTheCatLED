#include "FelixTheCatLED.h"

namespace FelixTheCatLED {

  LED::LED(uint8_t pin) : _pin(pin), _state(false), _activeLow(false) {}

  void LED::begin() {
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, _activeLow ? HIGH : LOW);
  }

  void LED::on() {
    digitalWrite(_pin, _activeLow ? LOW : HIGH);
    _state = true;
  }

  void LED::off() {
    digitalWrite(_pin, _activeLow ? HIGH : LOW);
    _state = false;
  }

  void LED::toggle() {
    _state = !_state;
    digitalWrite(_pin, (_state ^ _activeLow) ? HIGH : LOW);
  }

  void LED::setPin(uint8_t pin) {
    _pin = pin;
    begin();
  }

  void LED::setActiveLow(bool activeLow) {
    _activeLow = activeLow;
    digitalWrite(_pin, (_state ^ _activeLow) ? HIGH : LOW);
  }

} // namespace FelixTheCatLED
