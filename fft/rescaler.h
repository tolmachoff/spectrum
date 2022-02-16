#pragma once

#include "fft_types.h"


struct Rescaler
{
    int data_size = 1024;
};


signal_t operator>>(const signal_t& in, const Rescaler& rescaler);
