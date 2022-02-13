#pragma once

#include <vector>
#include <complex>


using cmplx_t = std::complex<double>;
using cmplx_vec_t = std::vector<cmplx_t>;


class FFT
{
public:
    FFT();


    int get_data_size() const;
    int get_fft_size() const;

    void set_data_size(int val);
    void set_fft_size(int val);

    cmplx_vec_t process(const cmplx_vec_t& in) const;


private:
    int m_data_size;
    int m_fft_size;

};
