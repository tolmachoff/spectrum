#pragma once

#include "iwindow.h"
#include "impl.h"


class Hamming : public IWindow
{
public:
    Hamming();

    signal_t apply(const signal_t& v) const override;


    IMPL;
};
