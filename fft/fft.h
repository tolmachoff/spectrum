#pragma once

#include "fft_types.h"
#include "i_processor.h"

struct FFT : IProcessor<signal_t, spectrum_t>
{
    spectrum_t process(const signal_t& in) override;
};

struct IFFT : IProcessor<spectrum_t, signal_t>
{
    signal_t process(const spectrum_t& in) override;
};
