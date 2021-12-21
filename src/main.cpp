/*
 * TinyRGB_3
 * ATTiny RGB PWM controller.
 * main.cpp
 *
 * Created: 9/11/2021 9:36:38 PM
 * Author : feven
 */

#include "tinyrgb.h"
#include "loops.h"
#include <util/delay.h>
#include <avr/interrupt.h>

#define ANIMATION_COUNT 3
volatile uint8_t animation_mode = 2;

int main(void)
{
  SetPinOutputs();
  ConfigureTimers();
  SetRGBRegisters(0, 0, 0);
  DDRB &= ~_BV(DDB2);
  PORTB &= ~_BV(PORTB2);
  MCUCR &= ~_BV(ISC00);
  MCUCR |= _BV(ISC01);
  GIMSK |= _BV(INT0);
  sei();
  while (1)
  {
    switch (animation_mode) // TODO: Animation only switches once full animation has finished. Make it change instantly.
    {
    case 0:
      RGSweep();
      break;
    case 1:
      RGBlink();
      break;
    case 2:
      ColorBlend();
      break;
    }
  }
}

ISR(INT0_vect)
{
  _delay_ms(100); // Debounce delay
  SetRGBRegisters(0, 0, 0);
  animation_mode++;
  if (animation_mode >= ANIMATION_COUNT)
  {
    animation_mode = 0;
  }
}