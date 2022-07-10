#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "App.hh"
#include "Page.hh"

class MainMenuPage : public Page
{
private:
  int selectedIndex = 0;
  bool dirty = true;

  static const size_t cItems = 5;

  // see https://cse.engineering.nyu.edu/~mleung/CS1114/f04/ch10/cs_array.htm#:~:text=Since%20cstrings%20are%20stored%20in%20single%20dimensional%20character,of%20cstrings%3A%20charscientists%20%3D%20%7B%22Newton%22%2C%20%22Maxwell%22%2C%20%22Einstein%22%2C%20%22Feynman%22%7D%3B
  const char labels[5][10] = {
      "Clock\0",
      "Set time\0",
      "Stopwatch",
      "Timer\0",
      "Theme\0"};

  const PageType navTargets[5] = {
      PageType::Clock,
      PageType::SetTime,
      PageType::Stopwatch,
      PageType::Timer,
      PageType::SetTheme,
  };

public:
  MainMenuPage(App *app, TFT_eSPI *screen) : Page(app, screen, "Main menu", PageType::MainMenu){}
  ~MainMenuPage(){}

  void incr()
  {
    selectedIndex = (selectedIndex + 1) % cItems;
  }

  void onNavigate() override;
  void onTopButton(ButtonState state) override;
  void onBottomButton(ButtonState state) override;
  void render() override;

private:
  PageType selectedPageType()
  {
    return navTargets[selectedIndex];
  }
};

#endif