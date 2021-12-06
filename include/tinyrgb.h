/*
 * tinyrgb.h
 *
 * Created: 12/06/2021 1:31:00 AM
 * Author : feven
 */ 

#ifndef TINYRGB_H
#define TINYRGB_H

#include <avr/io.h>
#include <avr/sfr_defs.h>

void ConfigureTimers();
void SetPinOutputs();
void SetRGBRegisters(uint8_t R, uint8_t G, uint8_t B);
void SetR(uint8_t R);
void SetG(uint8_t G);
void SetB(uint8_t B);
uint8_t GetR();
uint8_t GetG();
uint8_t GetB();

#endif