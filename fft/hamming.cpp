#include "hamming.h"


struct Hamming::Impl
{
    Hamming* q;

    std::vector<double> window;


    Impl(Hamming* p) : q(p) {}

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
    : d(new Hamming::Impl(this))
{
    d->update_window();
    
    data_size.set_set_clbk(std::bind(&Hamming::Impl::update_window, d.get()));
}


signal_t Hamming::apply(const signal_t& v) const
{
    signal_t res(v);
    for (int i = 0; i < data_size.get(); ++i)
    {
        res[i] *= d->window[i];
    }
    return res;
}
