#include "sinus.h"


signal_t operator>>(int samples, Sinus& sinus)
{
    signal_t res(samples);
    for (auto& x : res)
    {
        x = sinus.a * sin(sinus.phi);
        sinus.phi += 2 * M_PI * sinus.f0 / sinus.fs;
    }
    return res;
}
