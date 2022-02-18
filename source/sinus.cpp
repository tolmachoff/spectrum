#include "sinus.h"


Sinus::Sinus(double f0, double a)
    : f0(f0)
    , a(a)
    , phi(0.0)
    , fs(44100.0)
{

}


signal_t Sinus::process(const int& in)
{
    signal_t res(in);
    for (auto& x : res)
    {
        x = a.get() * sin(phi.get());
        phi.set(phi.get() + 2 * M_PI * f0.get() / fs.get());
    }
    return res;
}
