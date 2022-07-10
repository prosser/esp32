#ifndef TIMEUTIL_H
#define TIMEUTIL_H

#define MILLIS_PER_SECOND 1000
#define MILLIS_PER_MINUTE 60000
#define MILLIS_PER_HOUR 3600000

#define MICROS_PER_SECOND 1000000
#define MICROS_PER_MINUTE 60000000
#define MICROS_PER_HOUR 3600000000

tm millisToTm(unsigned long);
unsigned long tmToMillis(tm);
void serialPrintTm(tm);

#endif