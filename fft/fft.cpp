#include "fft.h"

#include <fftw3.h>


struct FFT::Impl
{
    FFT* q;

    IWindow* window;


    Impl(FFT* p) 
        : q(p)
        , window(nullptr) {} 

    void update_window()
    {
        if (window)
        {
            window->data_size.set(q->data_size.get());
        }
    }

};


FFT::FFT()
    : data_size(1024)
    , fft_size(1024 * 8)
    , d(new Impl(this))
{
    data_size.set_set_clbk(std::bind(&FFT::Impl::update_window, d.get()));
}


cmplx_vec_t FFT::process(const cmplx_vec_t& in) const
{
    cmplx_vec_t res(in);
    res.resize(fft_size.get());

    if (d->window)
    {
        d->window->apply(res);
    }

    fftw_plan plan = fftw_plan_dft_1d(fft_size.get(),
                                      reinterpret_cast<fftw_complex*>(res.data()),
                                      reinterpret_cast<fftw_complex*>(res.data()),
                                      FFTW_FORWARD,
                                      FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);

    return res;
}


void FFT::set_window(IWindow* wnd)
{
    d->window = wnd;
    d->window->data_size.set(data_size.get());
}
