/*
 * Tiny_RGB.cpp
 *
 * Created: 9/11/2021 9:36:38 PM
 * Author : feven
 */

#include "tinyrgb.h"
#include <util/delay.h>

int main(void)
{
  SetPinOutputs();
  ConfigureTimers();
  SetRGBRegisters(1, 1, 1);
  while (1)
  {
    _delay_ms(16); // Approx 60hz

    /*
     * Sweep R UP
     */
    while (GetR() < 255)
    {
      SetR(GetR() + 1);
      _delay_ms(16);
    }

    /*
     * Sweep R Down
     */
    while (GetR() > 0)
    {
      SetR(GetR() - 1);
      _delay_ms(16);
    }
  }
}