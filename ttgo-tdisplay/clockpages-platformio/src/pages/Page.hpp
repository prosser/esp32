#pragma once

#include "PageType.hpp"
#include "ButtonHandler.hpp"
#include "TFT_eSPI.h" // Hardware-specific library

class App;

class Page : public ButtonHandler
{
public:
  App *app;
  TFT_eSPI *screen;
  const char *name;
  PageType type;

  Page(App *app, TFT_eSPI *screen, const char *name, PageType type);
  virtual ~Page();

  virtual void render();
  virtual void onNavigate();
  virtual void onBottomButton(ButtonState state) override;
  virtual void onTopButton(ButtonState state) override;
};