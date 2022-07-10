#pragma once

// uncomment to send serial messages for debugging/troubleshooting
#define DEBUG

#include <SPI.h>
#include <TFT_eSPI.h> // Hardware-specific library
#include "Theme.hpp"
#include "Buttons.hpp"
#include <time.h>
#include "simpleSleep.hpp"
#include "pages/Page.hpp"
#include "LinkedList.hpp"

// since we rotate to have the buttons on the right, swap width and height
#define SCREEN_WIDTH TFT_HEIGHT
#define SCREEN_HEIGHT TFT_WIDTH
#define TFT_BACKLIGHT 4
#define LINE2_Y 85


class Page;

class App
{
public:
  App();
  ~App();

  void refresh();
  void nav(PageType pageType);
  void readInputs();

  tm getTime();
  void setTime(tm t);
  void applyThemeColors(bool inverted = false);
  TFT_eSPI *screen = nullptr;
  Theme *theme = nullptr;
  unsigned long loopStartMicros = 0;

private:
  Page *page = nullptr;
  LinkedList<Page *> pages;
  // Page **pages = nullptr;
  //  int numPages;

  unsigned long timeOffset = 0;
};