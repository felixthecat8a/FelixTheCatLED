#ifndef ANIM_H
#define ANIM_H

#include <Arduino.h>
#include "PhaseTimer.h"

namespace FelixTheCatLED {

  template <typename BlinkTarget>
  class AnimBlinkLED {
  public:
    AnimBlinkLED(BlinkTarget& target, uint32_t period)
      : _target(target), _timer(period) {}

    void update() {
      float t = _timer.normalized();
      if (t < 0.5f) {
        _target.on();
      } else {
        _target.off();
      }
    }

  private:
    BlinkTarget& _target;
    PhaseTimer _timer;
  };

  template <typename FadeTarget>
  class AnimFadeLED {
  public:
    AnimFadeLED(FadeTarget& target, uint32_t period, uint8_t minB = 0, uint8_t maxB = 255.0f)
      : _target(target), _timer(period), _min(minB), _max(maxB) {}

    void update() {
      float t = _timer.normalized();
      float v = (1.0f - cosf(t * TWO_PI)) * 0.5f;
      uint8_t brightness = _min + (uint8_t)(v * (_max - _min));
      _target.setBrightness(brightness);
    }

    void setMin(uint8_t minBrightness) {
      _min = constrain(minBrightness, 0, 255.0f);
      if (_min > _max) _max = _min;
    }

    void setMax(uint8_t maxBrightness) {
      _max = constrain(maxBrightness, 0, 255.0f);
      if (_max < _min) _min = _max;
    }

  private:
    FadeTarget& _target;
    PhaseTimer _timer;
    uint8_t _min, _max;
  };

  template <typename RGBType>
  class AnimColorwheel {
  public:
    AnimColorwheel(RGBType& rgb, uint32_t period)
      : _rgb(rgb), _timer(period) {}

    void update() {
      float t = _timer.normalized();
      int hue = (int)(t * 360.0f);
      _rgb.setHSV(hue, 1.0f, 1.0f);
    }

  private:
    RGBType& _rgb;
    PhaseTimer _timer;
  };

} // namespace FelixTheCatLED

#endif // ANIM_H
