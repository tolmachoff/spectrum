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


signal_t Noise::process(const int& in)
{
    signal_t res(in);
    std::generate(res.begin(),
                  res.end(),
                    [this]()
                    {
                        return d->dist(d->dre);
                    });
    return res;
}
