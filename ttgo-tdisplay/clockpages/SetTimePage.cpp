#include "SetTimePage.hh"
#include "App.hh"
#include "timeutil.h"

void SetTimePage::onNavigate()
{
  Page::onNavigate();
  dirty = true;

  tm now = app->getTime();
  Serial.print("now=");
  serialPrintTm(now);

  selectedIndex = 0;
  digits[0] = now.tm_hour / 10;
  digits[1] = now.tm_hour - digits[0] * 10;
  digits[2] = now.tm_min / 10;
  digits[3] = now.tm_min - digits[2] * 10;

  Serial.printf(", %d-%d-%d-%d\n", digits[0], digits[1], digits[2], digits[3]);
}

void SetTimePage::incrementDigit()
{
  dirty = true;
  int mod;
  switch (selectedIndex)
  {
  case 0:
    // the first digit can only be 0, 1, or 2, so use mod 3
    mod = 3;
    break;

  case 2:
    // the third digit can only be 0-5, so use mod 6
    mod = 6;
    break;
  default:
    // 2nd and 4th digits can be 0-9, so use mod 10
    mod = 10;
    break;
  }
  digits[selectedIndex] = (digits[selectedIndex] + 1) % mod;
}

void SetTimePage::selectNextDigit()
{
  dirty = true;
  selectedIndex = (selectedIndex + 1) % 4;
}

void SetTimePage::onTopButton(ButtonState state)
{
  Serial.printf("SetTimePage::onTopButton(%d)\n", state);
  if (state == ButtonState::Pressed)
  {
    if (selectedIndex == 3)
    {
      tm now = {0};

      now.tm_hour = digits[0] * 10 + digits[1];
      now.tm_min = digits[2] * 10 + digits[3];

      app->setTime(now);
      app->nav(PageType::Clock);
    }
    else
    {
      selectNextDigit();
    }
  }
}

void SetTimePage::onBottomButton(ButtonState state)
{
  Serial.printf("SetTimePage::onBottomButton(%d)\n", state);
  if (state == ButtonState::Pressed)
  {
    incrementDigit();
  }
}

void SetTimePage::render()
{
  if (dirty)
  {
    screen->setCursor(0, 0);

    app->applyThemeColors();
    screen->setTextFont(4);
    screen->println("Set time");

    screen->setTextFont(7);

    for (int i = 0; i < 4; i++)
    {
      if (i == 2)
      {
        app->applyThemeColors();
        screen->print(':');
      }
      app->applyThemeColors(i == selectedIndex);
      screen->print(digits[i]);
    }

    dirty = false;
  }
}