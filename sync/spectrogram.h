#pragma once

#include "fft_types.h"
#include "property.h"
#include "impl.h"

#include <string>


struct Spectrogram
{
    Spectrogram(const std::string& filename);

    ~Spectrogram();


    void add_chunk(const spectrum_t& in);

    void finish();


    Property<std::string> filename;

    Property<int> data_size;

    Property<double> fs;
    
    Property<double> freq_min;
    
    Property<double> freq_max;
    
    Property<double> ampl_min;
    
    Property<double> ampl_max;
    
    Property<bool> linear;


    IMPL;
};

struct SpectrogramEOF {};


void operator>>(const spectrum_t& in, Spectrogram& spectrogram);

void operator>>(const SpectrogramEOF&, Spectrogram& spectrogram);
