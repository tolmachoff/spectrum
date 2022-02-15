#pragma once

#include "fft_types.h"
#include "property.h"


class IWindow
{
public:
    virtual void apply(cmplx_vec_t& v) const = 0;

    Property<int> data_size;
    
};
