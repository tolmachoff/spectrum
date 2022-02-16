#include "noise.h"

#include <random>
#include <algorithm>


struct Noise::Impl
{
    std::default_random_engine dre;
    std::normal_distribution<double> dist;


    Impl(double m, double sigma) : dist(m, sigma) {}
};


Noise::Noise(double m, double sigma) : d(new Impl(m, sigma)) {}


double Noise::get_sample() const
{
    return d->dist(d->dre);
}


signal_t operator>>(int samples, const Noise& noise)
{
    signal_t res(samples);
    std::generate(res.begin(),
                  res.end(),
                    [&noise]()
                    {
                        return noise.get_sample();
                    });
    return res;
}
