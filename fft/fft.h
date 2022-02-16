#pragma once

#include "fft_types.h"
#include "iwindow.h"
#include "property.h"
#include "impl.h"


class FFT
{
public:
    FFT();

    spectrum_t process(const signal_t& in) const;

    void set_window(IWindow* wnd);


    Property<int> data_size;
    Property<int> fft_size;


    IMPL;

};
