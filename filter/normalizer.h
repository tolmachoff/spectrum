#pragma once

#include "fft_types.h"


struct Normalizer {}; 


signal_t operator>>(const signal_t& in, const Normalizer&);