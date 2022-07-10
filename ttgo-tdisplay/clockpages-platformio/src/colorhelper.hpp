#pragma once

#include <stdint.h>

/** converts a web hex rgb to rgb565 (16-bit color suitable for our LCD screen) */
uint16_t rgb888ToRgb565(uint32_t rgb888);