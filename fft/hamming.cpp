#include "hamming.h"


signal_t operator<<(const Hamming&, const signal_t& in)
{
    signal_t res(in);

    size_t N = res.size();
    for (size_t i = 0; i < N; ++i)
    {
        double curr = 0.53836 - 0.46164 * std::cos(2.0 * M_PI * i / N);
        res[i] = in[i] * curr;
    }

    return res;
}
