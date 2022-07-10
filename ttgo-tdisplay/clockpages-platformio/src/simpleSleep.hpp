#ifndef SIMPLESLEEP_HPP
#define SIMPLESLEEP_HPP

struct SimpleSleepArg
{
  gpio_num_t pin;
  gpio_int_type_t level;
};

/** enters light sleep, waking after a set time or any configured GPIO pins are set to low
 * @param micros Number of microseconds to sleep
 * @param argc Number of GPIO pins in the parameter list
 * @param argv Array of esp_sleep_arg values
 */
void simpleSleep(unsigned long micros = 1000000, int argc = 0, SimpleSleepArg *argv = nullptr);

#endif