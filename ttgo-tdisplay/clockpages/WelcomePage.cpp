#include "WelcomePage.hh"
#include "colorhelper.hh"
#include "App.hh"

// welcome-background.h was generated from a 240x135 image (a PNG file) using ImageConverter565.exe.
// See WelcomePage-ImageConverterScreenshot.png for a screenshot of how to configure it, or follow these instructions:
// * Size must be 240x135. Resize if it's not!
// * the array name must be "welcome" (without the quotes).
// * Choose the [Save as ".c"] option, but when you save it, either save it as welcome-background.h or rename it to that afterwards.
// * Choose the [ARM / PIC32] option for [Board type]
#include "welcome-background.h"

void WelcomePage::render()
{
  screen->setSwapBytes(true);
  screen->pushImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, welcome);

  // show the welcome screen for 5 seconds
  if (millis() > 5000)
  {
    app->nav(PageType::Clock);
  }
}
