/*
 * logmapper.h
 *
 * Created: 12/07/2021 9:47:00 PM
 * Author : feven
 */

#ifndef LOGMAPPER_H
#define LOGMAPPER_H

#include <stdint.h>
#include <avr/pgmspace.h>

const uint8_t log_lut[] PROGMEM = {0, 0}; // TODO: Populate with calculated LUT.
uint8_t MapToLogarithmic(uint8_t input);

#endif