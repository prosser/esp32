#include "Log.hpp"

#define BUF_SIZE (1024)

Log::Log(int uart_num)
{
  uartNum = uart_num;
  uart_config_t uart_config = {
      .baud_rate = 115200,
      .data_bits = UART_DATA_8_BITS,
      .parity = UART_PARITY_DISABLE,
      .stop_bits = UART_STOP_BITS_1,
      .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
      .rx_flow_ctrl_thresh = 122,
  };

  uart_set_pin(uart_num, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
  uart_param_config(uart_num, &uart_config);
  uart_driver_install(uart_num, BUF_SIZE * 2, 0, 0, nullptr, 0);
}

void Log::write(string &message)
{
  uart_write_bytes(UART_NUM_0, message.c_str(), message.length());
}

void Log::writeln(string &message)
{
  uart_write_bytes(uartNum, message.c_str(), message.length());
  uart_write_bytes(uartNum, "\n", 1);
}