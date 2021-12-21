/*
 * colortools.cpp
 *
 * Created: 12/21/2021 12:30:00 PM
 * Author : feven
 */

#include "colortools.h"

RGB HSLToRGB(HSL hsl)
{
    // https://en.wikipedia.org/wiki/HSL_and_HSV#To_RGB
    RGB conversion;
    float s_div = (float)hsl.S / 100.0;
    float l_div = (float)hsl.L / 100.0;
    float chroma = (1.0 - fabs(2.0 * l_div - 1.0)) * s_div;
    float h_prime = (float)hsl.H / 60.0;
    float intermediate_x = chroma * (1.0 - fabs(fmod(h_prime, 2.0) - 1.0));
    float modifier = l_div - (chroma / 2.0);
    switch ((uint8_t)floor(h_prime))
    {
    case 0:
        conversion.R = (chroma + modifier) * 255.0;
        conversion.G = (intermediate_x + modifier) * 255.0;
        conversion.B = (0.0 + modifier) * 255.0;
        break;
    case 1:
        conversion.R = (intermediate_x + modifier) * 255.0;
        conversion.G = (chroma + modifier) * 255.0;
        conversion.B = (0.0 + modifier) * 255.0;
        break;
    case 2:
        conversion.R = (0.0 + modifier) * 255.0;
        conversion.G = (chroma + modifier) * 255.0;
        conversion.B = (intermediate_x + modifier) * 255.0;
        break;
    case 3:
        conversion.R = (0.0 + modifier) * 255.0;
        conversion.G = (intermediate_x + modifier) * 255.0;
        conversion.B = (chroma + modifier) * 255.0;
        break;
    case 4:
        conversion.R = (intermediate_x + modifier) * 255.0;
        conversion.G = (0.0 + modifier) * 255.0;
        conversion.B = (chroma + modifier) * 255.0;
        break;
    case 5:
        conversion.R = (chroma + modifier) * 255.0;
        conversion.G = (0.0 + modifier) * 255.0;
        conversion.B = (intermediate_x + modifier) * 255.0;
        break;
    }
    return conversion;
}