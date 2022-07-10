#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "esp_system.h"
#include "driver/uart.h"

using namespace std;

class Log
{
public:
  Log(const int uart_num);
  // static void write(const char *message);
  // static void writeln(const char *message);
  void write(string &message);
  void writeln(string &message);

private:
  int uartNum = 0;
};
