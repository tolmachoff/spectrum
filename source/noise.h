#pragma once

#include "fft_types.h"
#include "impl.h"


class Noise
{
public:
    Noise(double m, double s);

    double get_sample() const;


    IMPL;
};


signal_t operator>>(int samples, const Noise& noise);
