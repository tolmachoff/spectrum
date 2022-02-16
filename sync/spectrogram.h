#pragma once

#include "fft_types.h"
#include "impl.h"

#include <string>


struct Spectrogram
{
    std::string     filename;
    int             data_size       = 880;
    double          fs              = 44100.0;
    double          freq_min        = 27.5;
    double          freq_max        = 4224.0;
    double          ampl_min        = -40.0;
    double          ampl_max        = 20.0;
    bool            linear          = true;


    Spectrogram(const std::string& filename);

    ~Spectrogram();


    void add_chunk(const spectrum_t& in);

    void finish();


    IMPL;
};

struct SpectrogramEOF {};


void operator>>(const spectrum_t& in, Spectrogram& spectrogram);

void operator>>(const SpectrogramEOF&, Spectrogram& spectrogram);
