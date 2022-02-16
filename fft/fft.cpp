#include "fft.h"

#include <fftw3.h>


FFT::FFT() : data_size(1024) {}


spectrum_t FFT::forward(const signal_t& in) const
{
    spectrum_t res(data_size.get());
    std::copy(in.begin(), in.end(), res.begin());
    
    fftw_plan plan = fftw_plan_dft_1d(data_size.get(),
                                      reinterpret_cast<fftw_complex*>(res.data()),
                                      reinterpret_cast<fftw_complex*>(res.data()),
                                      FFTW_FORWARD,
                                      FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);

    return res;
}


signal_t FFT::backward(const spectrum_t& in) const
{
    spectrum_t tmp(in);

    fftw_plan plan = fftw_plan_dft_1d(data_size.get(),
                                      reinterpret_cast<fftw_complex*>(tmp.data()),
                                      reinterpret_cast<fftw_complex*>(tmp.data()),
                                      FFTW_BACKWARD,
                                      FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);

    signal_t res(data_size.get());
    std::transform(tmp.begin(), tmp.end(), res.begin(), [this](auto x) { return std::abs(x) / data_size.get(); });
    
    return res;
}
