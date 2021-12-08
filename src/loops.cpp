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
    while (GetRawR() < 255)
    {
        SetR(GetRawR() + 1);
        _delay_ms(16);
    }

    /*
     * Sweep R Down
     */
    while (GetRawR() > 0)
    {
        SetR(GetRawR() - 1);
        _delay_ms(16);
    }

    /*
     * Sweep G UP
     */
    while (GetRawG() < 255)
    {
        SetG(GetRawG() + 1);
        _delay_ms(16);
    }

    /*
     * Sweep G Down
     */
    while (GetRawG() > 0)
    {
        SetG(GetRawG() - 1);
        _delay_ms(16);
    }
}