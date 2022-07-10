#ifndef SETTIMESTATE_HPP
#define SETTIMESTATE_HPP

#include "Page.hpp"
class App;

class SetTimePage : public Page
{
private:
  uint8_t selectedIndex = 0;
  uint8_t digits[4] = {0, 0, 0, 0};
  bool dirty = true;

public:
  SetTimePage(App *app, TFT_eSPI *screen) : Page(app, screen, "Set time", PageType::SetTime) {}
  ~SetTimePage() {}

  void selectNextDigit();

  /** increment the digit being set */
  void incrementDigit();

  void onNavigate() override;
  void onTopButton(ButtonState state) override;
  void onBottomButton(ButtonState state) override;
  void render() override;
};

#endif