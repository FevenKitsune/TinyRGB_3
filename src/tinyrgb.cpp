/*
 * tinyrgb.cpp
 *
 * Created: 12/06/2021 1:31:00 AM
 * Author : feven
 */

#include "tinyrgb.h"

void ConfigureTimers()
{
    TCCR0A |= _BV(COM0A1);             // Connect OC0A
    TCCR0A |= _BV(COM0B1);             // Connect OC0B
    GTCCR |= _BV(COM1B1);              // Connect OC1B
    TCCR0A |= _BV(WGM01) | _BV(WGM00); // Enable Mode 3 (Fast PWM) on Timer 0
    GTCCR |= _BV(PWM1B);               // Enable PWM mode on Timer1 B
    TCCR0B |= _BV(CS00);               // Enable clock(io) no prescale on Timer 0
    TCCR1 |= _BV(CS10);                // Enable clock(CK) on prescale on Timer 1
    return;
}

void SetPinOutputs()
{
    DDRB |= _BV(PORTB0) | _BV(PORTB1) | _BV(PORTB4);
    return;
}

void SetRGBRegisters(uint8_t R, uint8_t G, uint8_t B)
{
    SetR(R);
    SetG(G);
    SetB(B);
    return;
}

void SetR(uint8_t R)
{
    raw_R = R;
    OCR0A = MapToLogarithmic(R);
    return;
}

void SetG(uint8_t G)
{
    raw_G = G;
    OCR0B = MapToLogarithmic(G);
    return;
}

void SetB(uint8_t B)
{
    raw_B = B;
    OCR1B = MapToLogarithmic(B);
    return;
}

uint8_t GetR()
{
    return OCR0A;
}

uint8_t GetG()
{
    return OCR0B;
}

uint8_t GetB()
{
    return OCR1B;
}

uint8_t GetRawR()
{
    return raw_R;
}

uint8_t GetRawG()
{
    return raw_G;
}

uint8_t GetRawB()
{
    return raw_B;
}