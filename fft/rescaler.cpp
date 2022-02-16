#include "rescaler.h"


signal_t operator>>(const signal_t& in, const Rescaler& rescaler)
{
    signal_t res(in);
    res.resize(rescaler.data_size);
    return res;
}
