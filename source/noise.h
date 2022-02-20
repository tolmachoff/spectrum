#pragma once

#include "fft_types.h"
#include "i_processor.h"
#include "impl.h"

struct Noise : IProcessor<int, signal_t>
{
    Noise(double m, double sigma);

    signal_t process(const int& in) override;

    IMPL;
};
