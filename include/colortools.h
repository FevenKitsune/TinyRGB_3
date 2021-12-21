/*
 * colortools.h
 *
 * Created: 12/21/2021 12:30:00 PM
 * Author : feven
 */

#ifndef COLORTOOLS_H
#define COLORTOOLS_H

#include <stdint.h>
#include <avr/pgmspace.h>
#include <math.h>

struct RGB
{
    uint8_t R;
    uint8_t G;
    uint8_t B;
};

struct HSL
{
    uint16_t H; // 0 - 360
    uint8_t S;  // 0 - 100
    uint8_t L;  // 0 - 100
};

RGB HSLToRGB(HSL hsl);

#endif