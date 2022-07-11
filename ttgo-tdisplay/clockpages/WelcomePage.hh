#pragma once

#include "Page.hh"
//#include <PNGdec.h>

// struct PngDrawArg
// {
//   PNG *png;
//   TFT_eSPI *screen;
// };

class WelcomePage : public Page
{
  public:
  WelcomePage(App *app, TFT_eSPI *screen) : Page(app, screen, "Welcome", PageType::Welcome){}

  void render() override;

  // private:
  // void pngDrawCallback(PNGDRAW *);
};