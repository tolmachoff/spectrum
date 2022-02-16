#pragma once

#include "fft_types.h"
#include "property.h"


class FFT
{
public:
    FFT();

    spectrum_t forward(const signal_t& in) const;
    signal_t backward(const spectrum_t& in) const;


    Property<int> data_size;


};
