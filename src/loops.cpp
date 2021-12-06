/*
 * tinyrgb.h
 *
 * Created: 12/06/2021 1:54:00 AM
 * Author : feven
 */ 

#include "loops.h"

/*
 * SWEEP_ID = 0
 * Christmas!
 */
void RGSweep()
{
    // TODO: Logarithmic dimming curve function!
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

    /*
     * Sweep G UP
     */
    while (GetG() < 255)
    {
        SetG(GetG() + 1);
        _delay_ms(16);
    }

    /*
     * Sweep G Down
     */
    while (GetG() > 0)
    {
        SetG(GetG() - 1);
        _delay_ms(16);
    }
}