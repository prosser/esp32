#include "MainMenuPage.hpp"

void MainMenuPage::onTopButton(ButtonState state)
{
  if (state == ButtonState::Pressed)
  {
    app->nav(selectedPageType());
  }
}

void MainMenuPage::onBottomButton(ButtonState state)
{
  if (state == ButtonState::Pressed)
  {
    incr();
    dirty = true;
  }
}

void MainMenuPage::onNavigate()
{
  Page::onNavigate();
  dirty = true;
  selectedIndex = 0;
}

void MainMenuPage::render()
{
  if (dirty)
  {
    traceln("MainMenuPage::render()");

    for (int i = 0; i < cItems; i++)
    {
      app->applyThemeColors(i == selectedIndex);
      tracef("%s%s\n", i == selectedIndex ? "*" : "", labels[i]);

      // font heights:
      // 1=8px, 2=16px, 4=26px, 6=48px, 7=48px (7-segment digits only), 8=75px (7-segment digits only)
      // see User_Setup.h!
      screen->drawString(labels[i], 0, i * 28, 4);
    }

    dirty = false;
    traceln("MainMenuPage::render() done");
  }
}