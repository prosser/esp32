#ifndef THEME_HPP
#define THEME_HPP

#include <TFT_eSPI.h>
//#include "Debugging.h"

#define NumThemeColors 24
#define NotAThemeColor 0xDEAD

static const int ThemeColors[] = {
    TFT_BLACK,
    TFT_NAVY,
    TFT_DARKGREEN,
    TFT_DARKCYAN,
    TFT_MAROON,
    TFT_PURPLE,
    TFT_OLIVE,
    TFT_LIGHTGREY,
    TFT_DARKGREY,
    TFT_BLUE,
    TFT_GREEN,
    TFT_CYAN,
    TFT_RED,
    TFT_MAGENTA,
    TFT_YELLOW,
    TFT_WHITE,
    TFT_ORANGE,
    TFT_GREENYELLOW,
    TFT_PINK,
    TFT_BROWN,
    TFT_GOLD,
    TFT_SILVER,
    TFT_SKYBLUE,
    TFT_VIOLET,
};

class ThemeColor
{
public:
  ThemeColor()
  {
    themeColor(0);
  }

  ThemeColor(uint16_t color)
  {
    value = color;
    themeColorIndex = NotAThemeColor;
  }

  uint16_t color()
  {
    return value;
  }

  void color(uint16_t newColor)
  {
    value = newColor;
    themeColorIndex = NotAThemeColor;
  }

  uint16_t themeColor(int index)
  {
    if (index < 0)
    {
      index = 0;
    }
    else if (index >= NumThemeColors)
    {
      index = NumThemeColors - 1;
    }
    themeColorIndex = index;
    value = ThemeColors[index];
    return value;
  }

  uint16_t reset()
  {
    return themeColor(0);
  }

  uint16_t next()
  {
    int index = themeColorIndex == NotAThemeColor
                    ? 0
                    : (themeColorIndex + 1) % NumThemeColors;
    return themeColor(index);
  }

  uint16_t prev()
  {
    int index = themeColorIndex == NotAThemeColor
                    ? 0
                    : (themeColorIndex - 1) % NumThemeColors;
    return themeColor(index);
  }

  bool operator ==(ThemeColor& other)
  {
      return other.value == value &&
          other.themeColorIndex == themeColorIndex;
  }

  bool operator !=(ThemeColor& other)
  {
      return other.value != value ||
          other.themeColorIndex != themeColorIndex;
  }

private:
  int themeColorIndex;
  uint16_t value;
};

class Theme
{
public:
  ThemeColor *bgColor;
  ThemeColor *textColor;

  Theme(
      uint16_t textColor,
      uint16_t backgroundColor)
  {
    this->bgColor = new ThemeColor(backgroundColor);
    this->textColor = new ThemeColor(textColor);
  }

  Theme(
      ThemeColor *textColor,
      ThemeColor *backgroundColor)
  {
    this->textColor = textColor;
    this->bgColor = backgroundColor;
  }
};

#endif