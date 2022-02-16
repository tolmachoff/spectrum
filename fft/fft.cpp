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


spectrum_t FFT::process(const signal_t& in) const
{
    spectrum_t res(fft_size.get());

    if (d->window)
    {
        auto in_wnd = d->window->apply(in);
        std::copy(in_wnd.begin(), in_wnd.end(), res.begin());
    }
    else
    {
        std::copy(in.begin(), in.end(), res.begin());
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
