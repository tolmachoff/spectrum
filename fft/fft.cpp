#include "fft.h"

#include <fftw3.h>


FFT::FFT()
    : data_size(1024)
    , fft_size(1024 * 8) 
{

}


cmplx_vec_t FFT::process(const cmplx_vec_t& in) const
{
    cmplx_vec_t res(in);
    res.resize(fft_size.get());

    /// TODO: Add Hamming window

    fftw_plan plan = fftw_plan_dft_1d(fft_size.get(),
                                      reinterpret_cast<fftw_complex*>(res.data()),
                                      reinterpret_cast<fftw_complex*>(res.data()),
                                      FFTW_FORWARD,
                                      FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);

    return res;
}
