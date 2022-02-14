#pragma once

#include <vector>
#include <complex>

#include "property.h"

using cmplx_t = std::complex<double>;
using cmplx_vec_t = std::vector<cmplx_t>;


class FFT
{
public:
    FFT();

    cmplx_vec_t process(const cmplx_vec_t& in) const;

    Property<RW, int> data_size;
    Property<RW, int> fft_size;

};
