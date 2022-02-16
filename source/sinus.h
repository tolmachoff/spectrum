#pragma once

#include "fft_types.h"


struct Sinus
{
    double fs;
    double f0;
    double a;
    double phi;


    Sinus(double fs, double f0, double a = 1.0, double phi = 0.0);
};


signal_t operator>>(int samples, Sinus& sinus);
