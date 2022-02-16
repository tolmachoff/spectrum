#pragma once

#include "fft_types.h"


struct Hamming {};


signal_t operator>>(const signal_t& in, const Hamming&);
