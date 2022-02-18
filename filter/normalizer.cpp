#include "normalizer.h"

#include <algorithm>


signal_t Normalizer::process(const signal_t& in)
{
    auto max_it = std::max_element(in.begin(),
                                   in.end(),
                                    [](auto x, auto y)
                                    {
                                        return std::abs(x) < std::abs(y);
                                    });
    double k = std::abs(*max_it);

    signal_t res(in);
    for (auto& x : res)
    {
        x /= k;
    }

    return res;
}
