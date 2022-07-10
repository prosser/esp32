#pragma once

#include "ButtonState.hpp"
#include "ButtonHandler.hpp"

#define TOP_BUTTON_PIN 35
#define BOTTOM_BUTTON_PIN 0

class Button
{
public:
  Button(uint8_t gpioPin, long debounceDelayMilliseconds)
  {
    pinMode(gpioPin, INPUT);

    pin = gpioPin;
    debounceDelay = debounceDelayMilliseconds;
  }

private:
  ButtonState _state = ButtonState::Pressed;

  long lastDebounceTime = 0; // last time the output pin was toggled
  long debounceDelay = 50;   // the debounce time; increase if the output flickers

public:
  uint8_t pin;

  void update(ButtonHandler *handler)
  {
    ButtonState state = static_cast<ButtonState>(digitalRead(pin));
    if (_state != state)
    {
      long now = millis();
      if (now - lastDebounceTime > debounceDelay)
      {
        lastDebounceTime = now;
        tracef("button %d %s (%d). Handler: %x\n",
                      pin,
                      state == ButtonState::Pressed ? "pressed" : "released",
                      state,
                      handler);
        _state = state;

        if (handler != nullptr)
        {
          switch (pin)
          {
          case BOTTOM_BUTTON_PIN:
            handler->onBottomButton(state);
            break;
          case TOP_BUTTON_PIN:
            handler->onTopButton(state);
            break;
          }
        }
      }
    }
  }
};

// set up the buttons with a debounce time == 50ms
static Button bottomButton = Button(BOTTOM_BUTTON_PIN, 50L);
static Button topButton = Button(TOP_BUTTON_PIN, 50L);