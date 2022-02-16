#pragma once

#include "fft_types.h"


enum class Direction
{
    Forward,
    Backward
};


struct FFT
{
    Direction dir;
};


spectrum_t operator>>(const signal_t& in, const FFT& fft);

signal_t operator>>(const spectrum_t& in, const FFT& fft);
