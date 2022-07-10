#include "App.hh"
#include "Page.hh"
#include "ClockPage.hh"
#include "MainMenuPage.hh"
#include "SetTimePage.hh"
#include "timeutil.h"

App::App()
{
  screen = new TFT_eSPI(); // Invoke custom library

  // white text with a black background... at first
  theme = new Theme(TFT_WHITE, TFT_BLACK);

  // set up the pages. Each one is a screen with its own behavior!
  ClockPage *clockPage = new ClockPage(this, screen);
  MainMenuPage *mainMenuPage = new MainMenuPage(this, screen);
  SetTimePage *setTimePage = new SetTimePage(this, screen);

  pages.append(clockPage);
  pages.append(mainMenuPage);
  pages.append(setTimePage);

  if (pages.moveToStart())
  {
    int iPage = 0;
    do
    {
      Page *p = pages.getCurrent();
      Serial.printf("page [%d] name=\"%s\", type=%d, address=%x\n", iPage++, p->name, p->type, p);
    } while (pages.next());
  }

  screen->init();
  screen->setRotation(1);

  pinMode(TFT_BACKLIGHT, OUTPUT);
  digitalWrite(TFT_BACKLIGHT, HIGH); // Backlight on

  screen->fillScreen(theme->bgColor->color());

  pages.moveToStart();
  page = pages.getCurrent();
}

App::~App()
{
  // free the memory from all pages
  while (pages.moveToStart())
  {
    delete pages.getCurrent();
  }
  pages.clear();

  // free other things we created
  delete theme;
  delete screen;
}

void App::readInputs()
{
  // handle any button presses
  bottomButton.update(page);
  topButton.update(page);
}

void App::refresh()
{
  page->render();
}

void App::nav(PageType pageType)
{
  Serial.printf("App::nav(pageType=%d): ", pageType);
  bool match = false;
  if (pages.moveToStart())
  {
    do
    {
      Page *cur = pages.getCurrent();
      if (cur->type == pageType)
      {
        Serial.println("found a match!");
        page = cur;
        match = true;
        Serial.printf("calling onNavigate on page %d\n", page);
        page->onNavigate();
        break;
      }
    } while (pages.next());
  }

  if (!match)
  {
    Serial.println("no match :(");
  }
}

void App::applyThemeColors(bool inverted)
{
  // Serial.printf("App::applyThemeColors(%d) bgColor=%x, textColor=%x\n", inverted, theme->bgColor->color(), theme->textColor->color());
  if (inverted)
  {
    screen->setTextColor(theme->bgColor->color(), theme->textColor->color());
  }
  else
  {
    screen->setTextColor(theme->textColor->color(), theme->bgColor->color());
  }
  // Serial.println("App:applyThemeColors done");
}

tm App::getTime()
{
  unsigned long now = millis() + timeOffset;
  return millisToTm(now);
}

void App::setTime(tm t)
{
  unsigned long newTimeInMillis = tmToMillis(t);
  unsigned long elapsed = millis();
  timeOffset = newTimeInMillis - elapsed;

#ifdef DEBUG
  Serial.print("setTime(");
  serialPrintTm(t);
  Serial.printf("): newTimeInMillis=%d, elapsed=%d, timeOffset=%d, millisToTm(timeOffset)=",
                newTimeInMillis,
                elapsed,
                timeOffset);
  serialPrintTm(millisToTm(timeOffset));
  Serial.println();
#endif
}
