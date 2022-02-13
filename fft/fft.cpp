#include "fft.h"

#include <fftw3.h>


FFT::FFT()
    : m_data_size(1024)
    , m_fft_size(1024 * 8) 
{

}

int FFT::get_data_size() const
{
    return m_data_size;
}

int FFT::get_fft_size() const
{
    return m_fft_size;
}

void FFT::set_data_size(int val)
{
    m_data_size = val;
}

void FFT::set_fft_size(int val)
{
    m_fft_size = val;
}

cmplx_vec_t FFT::process(const cmplx_vec_t& in) const
{
    cmplx_vec_t res(in);
    res.resize(m_fft_size);

    /// TODO: Add Hamming window

    fftw_plan plan = fftw_plan_dft_1d(m_fft_size,
                                      reinterpret_cast<fftw_complex*>(res.data()),
                                      reinterpret_cast<fftw_complex*>(res.data()),
                                      FFTW_FORWARD,
                                      FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);

    return res;
}
