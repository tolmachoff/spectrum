#pragma once

#include "window.h"
#include "fft_types.h"
#include "property.h"
#include "impl.h"


class FFT
{
public:
    FFT();

    cmplx_vec_t process(const cmplx_vec_t& in) const;

    void set_window(IWindow* wnd);


    Property<int> data_size;
    Property<int> fft_size;


    IMPL;

};
