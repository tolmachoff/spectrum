#pragma once

#include "fft_types.h"
#include "i_processor.h"
#include "property.h"
#include "impl.h"

#include <string>


struct Spectrogram : IProcessor<spectrum_t, void>
{
    Spectrogram(const std::string& filename);

    ~Spectrogram();


    void process(const spectrum_t& in) override;

    void commit();


    Property<std::string>   filename;
    Property<int>           data_size;
    Property<double>        fs;
    Property<double>        freq_min;
    Property<double>        freq_max;
    Property<double>        ampl_min;
    Property<double>        ampl_max;
    Property<bool>          linear;


    IMPL;
};
