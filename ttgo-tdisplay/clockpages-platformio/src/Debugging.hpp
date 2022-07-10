#ifndef DEBUGGING_H
#define DEBUGGING_H


#ifndef _TFT_eSPIH_
#define TFT_BLACK       0x0000      /*   0,   0,   0 */
#define TFT_NAVY        0x000F      /*   0,   0, 128 */
#define TFT_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define TFT_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define TFT_MAROON      0x7800      /* 128,   0,   0 */
#define TFT_PURPLE      0x780F      /* 128,   0, 128 */
#define TFT_OLIVE       0x7BE0      /* 128, 128,   0 */
#define TFT_LIGHTGREY   0xD69A      /* 211, 211, 211 */
#define TFT_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define TFT_BLUE        0x001F      /*   0,   0, 255 */
#define TFT_GREEN       0x07E0      /*   0, 255,   0 */
#define TFT_CYAN        0x07FF      /*   0, 255, 255 */
#define TFT_RED         0xF800      /* 255,   0,   0 */
#define TFT_MAGENTA     0xF81F      /* 255,   0, 255 */
#define TFT_YELLOW      0xFFE0      /* 255, 255,   0 */
#define TFT_WHITE       0xFFFF      /* 255, 255, 255 */
#define TFT_ORANGE      0xFDA0      /* 255, 180,   0 */
#define TFT_GREENYELLOW 0xB7E0      /* 180, 255,   0 */
#define TFT_PINK        0xFE19      /* 255, 192, 203 */ //Lighter pink, was 0xFC9F      
#define TFT_BROWN       0x9A60      /* 150,  75,   0 */
#define TFT_GOLD        0xFEA0      /* 255, 215,   0 */
#define TFT_SILVER      0xC618      /* 192, 192, 192 */
#define TFT_SKYBLUE     0x867D      /* 135, 206, 235 */
#define TFT_VIOLET      0x915C      /* 180,  46, 226 */
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _INT8_T_DECLARED
    typedef signed char __int8_t;
    typedef signed char int8_t;
#define _INT8_T_DECLARED
#endif
#ifndef _UINT8_T_DECLARED
    typedef unsigned char __uint8_t;
    typedef unsigned char uint8_t;
#define _UINT8_T_DECLARED
#endif
#define __int8_t_defined 1

#ifndef _INT16_T_DECLARED
    typedef signed short __int16_t;
    typedef signed short int16_t;
#define _INT16_T_DECLARED
#endif
#ifndef _UINT16_T_DECLARED
    typedef unsigned short __uint16_t;
    typedef unsigned short uint16_t;
#define _UINT16_T_DECLARED
#endif
#define __int16_t_defined 1

#ifdef ___int32_t_defined
#ifndef _INT32_T_DECLARED
    typedef __int32_t int32_t;
#define _INT32_T_DECLARED
#endif
#ifndef _UINT32_T_DECLARED
    typedef __uint32_t uint32_t;
#define _UINT32_T_DECLARED
#endif
#define __int32_t_defined 1
#endif /* ___int32_t_defined */

#ifdef ___int64_t_defined
#ifndef _INT64_T_DECLARED
    typedef __int64_t int64_t;
#define _INT64_T_DECLARED
#endif
#ifndef _UINT64_T_DECLARED
    typedef __uint64_t uint64_t;
#define _UINT64_T_DECLARED
#endif
#define __int64_t_defined 1
#endif /* ___int64_t_defined */


#ifdef __cplusplus
}
#endif

int strcmp(const char* src1, const char* src2)
{
    int i = 0;
    while ((src1[i] != '\0') || (src2[i] != '\0'))
    {
        if (src1[i] > src2[i])
            return 1;
        if (src1[i] < src2[i])
            return -1;
        i++;
    }

    return 0;
}

unsigned long m = 0;
unsigned long micros()
{
    m += 500;
    return m;
}

unsigned int millis()
{
    return micros() / 1000;
}

int r = 0;
int digitalRead(int pin)
{
    r = r ? 0 : 1;
    return r;
}

#define HIGH 1
#define LOW 0
#endif /* DEBUGGING_H */