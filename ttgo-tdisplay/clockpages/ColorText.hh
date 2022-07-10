#ifndef COLORTEXT_HPP
#define COLORTEXT_HPP

#include "Theme.hh"
// #include "Debugging.h"

class ColorText
{
public:
  ThemeColor textColor;
  ThemeColor bgColor;
  const char *text;

  ColorText(const char *text, ThemeColor textColor, ThemeColor bgColor)
  {
    Serial.printf("Creating new ColorText: '%s' color=%x bgColor=%x", text, textColor.color(), bgColor.color());
    this->text = text;
    this->textColor = textColor;
    this->bgColor = bgColor;
  }

  bool operator == (ColorText& other)
  {
      return other.textColor == textColor &&
          other.bgColor == bgColor &&
          strcmp(other.text, text) == 0;
  }

  bool operator != (ColorText& other)
  {
      return other.textColor != textColor ||
          other.bgColor != bgColor ||
          strcmp(other.text, text) != 0;
  }
};

#endif