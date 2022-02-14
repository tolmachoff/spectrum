#include "hamming.h"


struct Hamming::Impl
{
    Hamming* q;


    std::vector<double> window;

    void update_window()
    {
        window.resize(q->data_size.get());

        for (int i = 0; i < q->data_size.get(); ++i) 
        {
            double curr = 0.53836 - 0.46164 * std::cos(2.0 * M_PI * i / q->data_size.get());
            window[i] = curr;
        }
    }
};


Hamming::Hamming()
    : d(new Hamming::Impl {this})
{
    d->update_window();
    
    data_size.set_set_clbk(std::bind(&Hamming::Impl::update_window, d.get()));
}


void Hamming::apply(cmplx_vec_t& v) const
{
    // TODO: Is it normal much time data_size.get() ?
    for (int i = 0; i < data_size.get(); ++i)
    {
        v[i] *= d->window[i];
    }
}
