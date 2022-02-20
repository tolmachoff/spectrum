#pragma once

#include "fft_types.h"
#include "i_processor.h"

struct Normalizer : IProcessor<signal_t, signal_t>
{
    signal_t process(const signal_t& in) override;
};
