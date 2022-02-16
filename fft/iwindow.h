#pragma once

#include "fft_types.h"
#include "property.h"


class IWindow
{
public:
    virtual signal_t apply(const signal_t& v) const = 0;

    Property<int> data_size;
    
};
