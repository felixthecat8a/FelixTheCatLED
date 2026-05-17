#ifndef FELIX_THE_CAT_8A_TIMER_H
#define FELIX_THE_CAT_8A_TIMER_H

#include <Arduino.h>

namespace FelixTheCatLED {
  typedef void (*TimerCallback)();
  //using TimerCallback = void (*)();

  class Timer {
  public:
    explicit Timer(unsigned long interval)
      : _interval(interval),
        _startMillis(millis()),
        _paused(false),
        _pauseStart(0),
        _callback(nullptr) {}

    inline bool tick() {
      if (_paused) return false;

      // if (_repeatCount >= 0 && _runCount >= _repeatCount) {
      //   return false;
      // }

      if (_oneShot && _fired) return false;

      unsigned long now = millis();

      if (now - _startMillis >= _interval) {
        // _startMillis += _interval;

        // _runCount++;

        if (_oneShot) {
          _fired = true;
        } else {
          _startMillis += _interval;
        }

        if (_callback) _callback();
        return true;
      }

      return false;
    }

    inline void restart() { _startMillis = millis(); }

    inline void pause() {
      if (!_paused) {
        _paused = true;
        _pauseStart = millis();
      }
    }

    inline void resume() {
      if (_paused) {
        unsigned long pausedDuration = millis() - _pauseStart;
        _startMillis += pausedDuration;
        _paused = false;
      }
    }

    inline bool isExpired() const {
      if (_paused) return false;
      return millis() - _startMillis >= _interval;
    }

    inline bool isPaused() const { return _paused; }

    inline void setInterval(unsigned long interval) {_interval = interval; }

    inline unsigned long getInterval() const { return _interval; }

    inline void onTick(TimerCallback callback) { _callback = callback; }

    // inline void repeat(int count) {
    //   _repeatCount = count;
    //   _runCount = 0;
    // }

    // inline void resetRepeat() {
    //   _runCount = 0;
    //   _startMillis = millis();
    // }

    // inline int remaining() const {
    //   if (_repeatCount < 0) return -1; // infinite
    //   return _repeatCount - _runCount;
    // }

    // inline bool isFinished() const {
    //   return (_repeatCount >= 0 && _runCount >= _repeatCount);
    // }

    inline void setOneShot(bool enable = true) {
      _oneShot = enable;
    }

    inline void resetOneShot() {
      _fired = false;
      _startMillis = millis();
    }

  private:
    unsigned long _interval;
    unsigned long _startMillis;
    bool _paused;
    unsigned long _pauseStart;
    TimerCallback _callback;
    // int _repeatCount = -1; // -1 = infinite (default behavior)
    // int _runCount = 0;
    bool _oneShot = false;
    bool _fired = false;
  };

} // namespace FelixTheCatLED

#endif // FELIX_THE_CAT_8A_TIMER_H
