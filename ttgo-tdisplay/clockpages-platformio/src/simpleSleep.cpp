#include <esp_sleep.h>
#include <driver/gpio.h>
#include "simpleSleep.hpp"

/** enters light sleep, waking after a set time or any configured GPIO pins are set to low
 * @param micros Number of microseconds to sleep
 * @param argc Number of GPIO pins in the parameter list
 * @param argv Array of esp_sleep_arg values
 */
void simpleSleep(unsigned long micros, int argc, SimpleSleepArg *argv)
{
  if (micros != 0)
  {
    esp_sleep_enable_timer_wakeup(micros);
  }

  // enable wakup when either built-in button is pressed
  if (argc > 0 && argv != nullptr)
  {
    for (int i = 0; i < argc; i++)
    {
      gpio_wakeup_enable(argv[i].pin, argv[i].level);
    }

    esp_sleep_enable_gpio_wakeup();
  }

  // start light sleep
  esp_light_sleep_start();
}

// /** starts light sleep, waking after a set time or either built-in button is pressed
//  * @param micros Number of microseconds to sleep, or 0 if only a button should wake us up.
//  */
// void startLightSleep(unsigned long micros)
// {
//   esp_sleep_arg pin0 = {gpio_num_t::GPIO_NUM_0, gpio_int_type_t::GPIO_INTR_LOW_LEVEL};
//   esp_sleep_arg pin35 = {GPIO_NUM_35, GPIO_INTR_LOW_LEVEL};
//   esp_sleep_arg argv[2] = {pin0, pin35};
//   startLightSleep(micros, 2, argv);
// }
