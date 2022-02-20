#include "fft.h"

#include <fftw3.h>

#include <algorithm>

spectrum_t FFT::process(const signal_t& in)
{
    spectrum_t res(in.begin(), in.end());

    fftw_plan plan = fftw_plan_dft_1d(
        res.size(),
        reinterpret_cast<fftw_complex*>(res.data()),
        reinterpret_cast<fftw_complex*>(res.data()),
        FFTW_FORWARD,
        FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);

    return res;
}

signal_t IFFT::process(const spectrum_t& in)
{
    spectrum_t tmp(in);

    fftw_plan plan = fftw_plan_dft_1d(
        tmp.size(),
        reinterpret_cast<fftw_complex*>(tmp.data()),
        reinterpret_cast<fftw_complex*>(tmp.data()),
        FFTW_BACKWARD,
        FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);

    signal_t res(tmp.size());
    std::transform(tmp.begin(), tmp.end(), res.begin(), [&res](auto x) { return std::abs(x) / res.size(); });

    return res;
}
