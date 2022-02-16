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


spectrum_t operator<<(const FFT& fft, const signal_t& in);

signal_t operator<<(const FFT& fft, const spectrum_t& in);
