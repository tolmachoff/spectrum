#include "rescaler.h"


Rescaler::Rescaler(int data_size)
    : data_size(data_size) 
{
    
}


signal_t Rescaler::process(const signal_t& in)
{
    signal_t res(in);
    res.resize(data_size.get());
    return res;
}
