#pragma once

#include "fft_types.h"
#include "i_processor.h"
#include "property.h"

struct Rescaler : IProcessor<signal_t, signal_t>
{
    Rescaler(int data_size = 1024);

    signal_t process(const signal_t& in) override;

    Property<int> data_size;
};
