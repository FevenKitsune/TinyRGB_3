/*
 * logmapper.cpp
 *
 * Created: 12/07/2021 9:47:00 PM
 * Author : feven
 */

#include "logmapper.h"

uint8_t MapToLogarithmic(uint8_t input)
{
    return pgm_read_byte(&log_lut[input]);
}