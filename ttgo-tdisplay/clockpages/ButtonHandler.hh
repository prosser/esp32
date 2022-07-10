#ifndef BUTTONHANDLER_H
#define BUTTONHANDLER_H

#include <HardwareSerial.h>
#include "ButtonState.hh"
class ButtonHandler
{
public:
  virtual ~ButtonHandler() {}

  /** handle the bottom button being pressed or released */
  virtual void onBottomButton(ButtonState state)
  {
    Serial.printf("ButtonHandler::onBottomButton(%d)\n", state);
  }
  
  /** handle the top button being pressed or released */
  virtual void onTopButton(ButtonState state)
  {
    Serial.printf("ButtonHandler::onTopButton(%d)\n", state);
  }
};

#endif