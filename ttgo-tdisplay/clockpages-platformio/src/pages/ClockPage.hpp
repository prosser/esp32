#ifndef CLOCKPAGE_H
#define CLOCKPAGE_H

#include "App.hpp"
#include "Page.hpp"

class ClockPage : public Page
{
public:
  ClockPage(App *app, TFT_eSPI *screen) : Page(app, screen, "Clock", PageType::Clock){}
  ~ClockPage() {}

  void render() override;
  void onTopButton(ButtonState state) override;
  void onBottomButton(ButtonState state) override;

private:
  App *pApp = nullptr;
  unsigned long nextScreenRefresh = 0;
};

#endif