#pragma once

#include "fft_types.h"
#include "i_processor.h"
#include "property.h"

struct Sinus : IProcessor<int, signal_t>
{
    Sinus(double f0 = 100.0, double a = 1.0);

    signal_t process(const int& in) override;

    Property<double> f0;
    Property<double> a;
    Property<double> phi;
    Property<double> fs;
};
