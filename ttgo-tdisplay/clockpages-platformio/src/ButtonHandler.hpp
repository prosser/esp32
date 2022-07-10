#pragma once

#include "ButtonState.hpp"
#include "Log.hpp"

class ButtonHandler
{
public:
  ButtonHandler(Log *log)
  {
    this->log = log;
  }
  virtual ~ButtonHandler() {}

  /** handle the bottom button being pressed or released */
  virtual void onBottomButton(ButtonState state)
  {
    log->writeln(basic_string("ButtonHandler::onBottomButton(") + to_string(state) + ")");
  }

  /** handle the top button being pressed or released */
  virtual void onTopButton(ButtonState state)
  {
    log->writeln(basic_string("ButtonHandler::onTopButton(") + to_string(state) + ")");
  }

private:
  Log *log;
};
