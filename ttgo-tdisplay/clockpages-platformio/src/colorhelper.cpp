#include "colorhelper.hpp"

uint16_t rgb888ToRgb565(uint32_t rgb888)
{
  uint8_t red = (rgb888 & 0x00FF0000) >> 16;
  uint8_t green = (rgb888 & 0x0000FF00) >> 8;
  uint8_t blue = rgb888 & 0x000000FF;

  uint16_t b = (blue >> 3) & 0x1f;
  uint16_t g = ((green >> 2) & 0x3f) << 5;
  uint16_t r = ((red >> 3) & 0x1f) << 11;

  return (uint16_t)(r | g | b);
}
