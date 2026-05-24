#ifndef FELIX_THE_CAT_8A_BUTTON_H
#define FELIX_THE_CAT_8A_BUTTON_H

#include <Arduino.h>

namespace FelixTheCatLED {

  class Button {
  public:
    enum class Event : uint8_t {
      None,
      Press,
      Release,
      Click,
      DoubleClick,
      TripleClick,
      Hold
    };

    explicit Button(
      uint8_t pin,
      bool activeLow = true,
      uint16_t debounceTime = 50
    )
      : _pin(pin),
        _activeLow(activeLow),
        _debounceTime(debounceTime),
        _holdTime(1000),
        _multiClickTime(300),
        _state(State::Idle),
        _event(Event::None),
        _lastDebounceTime(0),
        _pressedTime(0),
        _lastReleaseTime(0),
        _stableState(false),
        _lastReading(false),
        _holdFired(false),
        _clickCount(0) {}

    /* Lifecycle */
    void begin() {
      pinMode(_pin, _activeLow ? INPUT_PULLUP : INPUT);

      bool raw = digitalRead(_pin);
      _stableState = _activeLow ? !raw : raw;
      _lastReading = _stableState;

      _state = State::Idle;
      _event = Event::None;
      _clickCount = 0;
      _holdFired = false;
    }

    void update() {
      uint32_t now = millis();

      bool raw = digitalRead(_pin);
      bool reading = _activeLow ? !raw : raw;

      if (reading != _lastReading) {
        _lastDebounceTime = now;
        _lastReading = reading;
      }

      if ((now - _lastDebounceTime) < _debounceTime) {
        return;
      }

      if (reading != _stableState) {
        _stableState = reading;
        handleStableChange(now);
      }

      handleHold(now);
      handleClickTimeout(now);
    }

    /* Queries */
    bool isDown() const { return _stableState; }
    bool isHeld() const { return _state == State::Held; }

    /* Event Polling */
    Event poll() {
      Event e = _event;
      _event = Event::None;
      return e;
    }

    bool wasPressed()       { return consume(Event::Press); }
    bool wasReleased()      { return consume(Event::Release); }
    bool wasClicked()       { return consume(Event::Click); }
    bool wasDoubleClicked() { return consume(Event::DoubleClick); }
    bool wasTripleClicked() { return consume(Event::TripleClick); }
    bool wasHeld()          { return consume(Event::Hold); }

    /* Configuration */
    void setHoldTime(uint16_t ms) { _holdTime = ms; }
    void setMultiClickTime(uint16_t ms) { _multiClickTime = ms; }

  private:
    enum class State : uint8_t {
      Idle,
      Pressed,
      Held,
      WaitingMulti
    };

    void handleStableChange(uint32_t now) {
      if (_stableState) {
        // PRESS
        _pressedTime = now;
        _holdFired = false;

        if (_state == State::WaitingMulti && (now - _lastReleaseTime) <= _multiClickTime) {
          _clickCount++;
        } else {
          _clickCount = 1;
        }

        _event = Event::Press;
        _state = State::Pressed;

      } else {
        // RELEASE
        _event = Event::Release;

        if (_state == State::Held) {
          resetClicks();
          _state = State::Idle;
          return;
        }

        _lastReleaseTime = now;
        _state = State::WaitingMulti;
      }
    }

    void handleHold(uint32_t now) {
      if (_state == State::Pressed && !_holdFired && (now - _pressedTime) >= _holdTime) {
        _event = Event::Hold;
        _holdFired = true;
        resetClicks();
        _state = State::Held;
      }
    }

    void handleClickTimeout(uint32_t now) {
      if (_state == State::WaitingMulti && (now - _lastReleaseTime) > _multiClickTime) {

        if (_clickCount == 1)      _event = Event::Click;
        else if (_clickCount == 2) _event = Event::DoubleClick;
        else if (_clickCount >= 3) _event = Event::TripleClick;

        resetClicks();
        _state = State::Idle;
      }
    }

    void resetClicks() {
      _clickCount = 0;
    }

    bool consume(Event e) {
      if (_event == e) {
        _event = Event::None;
        return true;
      }
      return false;
    }

    /* Data */
    uint8_t  _pin;
    bool     _activeLow;

    uint16_t _debounceTime;
    uint16_t _holdTime;
    uint16_t _multiClickTime;

    State    _state;
    Event    _event;

    uint32_t _lastDebounceTime;
    uint32_t _pressedTime;
    uint32_t _lastReleaseTime;

    bool     _stableState;
    bool     _lastReading;
    bool     _holdFired;

    uint8_t  _clickCount;
  };

} // namespace FelixTheCatLED

#endif // FELIX_THE_CAT_8A_BUTTON_H
