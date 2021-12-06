/*
 * Tiny_RGB.cpp
 *
 * Created: 9/11/2021 9:36:38 PM
 * Author : feven
 */

#include "tinyrgb.h"
#include "loops.h"
#include <util/delay.h>

int main(void)
{
  uint8_t animation_mode;
  SetPinOutputs();
  ConfigureTimers();
  SetRGBRegisters(1, 1, 1);
  animation_mode = 0; // TODO: Animation mode switching.
  while (1)
  {
    switch (animation_mode) {
      case 0:
        RGSweep();
        break;
    }
  }
}