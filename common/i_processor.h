#pragma once


template <typename TIn, typename TOut>
struct IProcessor 
{
    virtual TOut process(const TIn& in) = 0;
};


template<typename TIn, typename TOut>
TOut operator>>(const TIn& in, IProcessor<TIn, TOut>& processor)
{
    return processor.process(in);
}

template<typename TIn, typename TOut>
TOut operator>>(const TIn& in, IProcessor<TIn, TOut>&& processor)
{
    return processor.process(in);
}
