/*
 * loops.cpp
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
    _delay_ms(8); // Approx 120hz

    /*
     * Sweep R UP
     */
    while (GetRawR() < 255)
    {
        SetR(GetRawR() + 1);
        _delay_ms(8);
    }

    /*
     * Sweep R Down
     */
    while (GetRawR() > 0)
    {
        SetR(GetRawR() - 1);
        _delay_ms(8);
    }

    /*
     * Sweep G UP
     */
    while (GetRawG() < 255)
    {
        SetG(GetRawG() + 1);
        _delay_ms(8);
    }

    /*
     * Sweep G Down
     */
    while (GetRawG() > 0)
    {
        SetG(GetRawG() - 1);
        _delay_ms(8);
    }
}

/*
 * SWEEP_ID = 1
 * RGBlink
 */
void RGBlink()
{
    _delay_ms(2000);
    SetR(255);
    SetG(0);
    _delay_ms(2000);
    SetR(0);
    SetG(255);
}