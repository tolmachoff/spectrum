#pragma once

#include "iwindow.h"
#include "impl.h"


class Hamming : public IWindow
{
public:
    Hamming();

    void apply(cmplx_vec_t& v) const override;


    IMPL;
};
