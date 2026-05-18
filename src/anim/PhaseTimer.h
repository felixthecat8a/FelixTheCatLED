#ifndef PHASE_TIMER_H
#define PHASE_TIMER_H

#include <Arduino.h>

namespace FelixTheCatLED {

  class PhaseTimer {
  public:
    explicit PhaseTimer(uint32_t period, uint32_t offset = 0)
      : _period(period), _offset(offset) {}

    void setPeriod(uint32_t period) { _period = period; }
    uint32_t period() const { return _period; }

    void setOffset(uint32_t offset) { _offset = offset; }

    float normalized() const {
      if (_period == 0) return 0.0f;
      uint32_t now = millis();
      return ((now + _offset) % _period) / (float)_period;
    }

  private:
    uint32_t _period;
    uint32_t _offset;
  };

} // namespace FelixTheCatLED

#endif // PHASE_TIMER_H
