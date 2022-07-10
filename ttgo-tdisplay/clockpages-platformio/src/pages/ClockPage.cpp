#include "App.hpp"
#include "ClockPage.hpp"
#include "simpleSleep.hpp"
#include "timeutil.hpp"
#include "colorhelper.hpp"

void ClockPage::onTopButton(ButtonState state)
{
  tracef("ClockPage::onTopButton(%d)\n", state);
  if (state == ButtonState::Pressed)
  {
    app->nav(PageType::MainMenu);
  }
}

void ClockPage::onBottomButton(ButtonState state)
{
  // don't have anything defined yet
}

void ClockPage::render()
{
  if (nextScreenRefresh < millis())
  {
    Theme *theme = app->theme;

    screen->setTextColor(theme->textColor->color(), theme->bgColor->color());

    char hourMinsStr[6];
    char secsStr[3];

    tm t = app->getTime();
    // see https://www.tutorialspoint.com/c_standard_library/c_function_strftime.htm
    strftime(hourMinsStr, 6, "%H:%M", &t);
    strftime(secsStr, 3, "%S", &t);
    screen->drawString(hourMinsStr, -4, 0, 8);
    screen->drawString(secsStr, SCREEN_WIDTH - 60, LINE2_Y, 7);
    nextScreenRefresh = millis() + MILLIS_PER_SECOND;

    screen->setTextColor(rgb888ToRgb565(0x666666), 0);
    screen->drawString("Hi Zach!", 0, LINE2_Y, 4);
  }
}
