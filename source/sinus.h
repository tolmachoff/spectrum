#pragma once

#include "fft_types.h"


struct Sinus
{
    double fs = 44100.0;
    double f0 = 100.0;
    double a = 1.0;
    double phi = 0.0;
};


signal_t operator>>(int samples, Sinus& sinus);
