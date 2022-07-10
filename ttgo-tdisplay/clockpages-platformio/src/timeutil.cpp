#include "time.h"
#include "timeutil.hpp"
#include "esp_system.h"
#include "driver/uart.h"

tm millisToTm(unsigned long milliseconds)
{
  tm t = {0};
  t.tm_sec = (milliseconds / MILLIS_PER_SECOND) % 60;
  t.tm_min = (milliseconds / MILLIS_PER_MINUTE) % 60;
  t.tm_hour = (milliseconds / MILLIS_PER_HOUR) % 24;

  return t;
}

unsigned long tmToMillis(tm t)
{
  return t.tm_sec * MILLIS_PER_SECOND +
         t.tm_min * MILLIS_PER_MINUTE +
         t.tm_hour * MILLIS_PER_HOUR;
}

void serialPrintTm(tm t)
{
  char str[6];
  strftime(str, 6, "%H:%M", &t);
  uart_write_bytes(UART_NUM_0, str, sizeof(str));
}
