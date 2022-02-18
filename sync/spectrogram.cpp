#include "spectrogram.h"

#include "BMP.h"


enum class State
{
    WAITING_FIRST,
    COLLECTING
};


struct Spectrogram::Impl
{
    State state;

    std::vector<std::vector<uint8_t>> chunks;


    Impl() : state(State::WAITING_FIRST) {} 
};


Spectrogram::Spectrogram(const std::string& filename)
    : filename(filename)
    , data_size(880)
    , fs(44100.0)
    , freq_min(27.5)
    , freq_max(4224.0)
    , ampl_min(-40.0)
    , ampl_max(20.0)
    , linear(true)
    , d(new Impl)
{

}


Spectrogram::~Spectrogram()
{
    commit();
}


void Spectrogram::process(const spectrum_t& in)
{
    std::vector<uint8_t> chunk(data_size.get());
    for (int i = 0; i < data_size.get(); ++i)
    {
        double freq = freq_min.get();
        if (linear.get()) 
        {
            freq += (freq_max.get() - freq_min.get()) * i / (data_size.get() - 1);
        }
        else 
        {
            freq *= std::pow(freq_max.get() / freq_min.get(), 1.0 * i / data_size.get());
        }
        double freq_res = 1.0 * fs.get() / in.size();
        int freq_num = static_cast<int>(std::round(freq / freq_res));
        double ampl = 20.0 * std::log10(std::abs(in[freq_num]));
        if (ampl < ampl_min.get()) 
        {
            chunk[i] = 0;
        }
        else if (ampl > ampl_max.get()) 
        {
            chunk[i] = 255;
        }
        else 
        {
            chunk[i] = static_cast<uint8_t>(255.0 * (ampl - ampl_min.get()) / (ampl_max.get() - ampl_min.get()));
        }
    }
    d->chunks.emplace_back(std::move(chunk));

    if (d->state == State::WAITING_FIRST)
    {
        d->state = State::COLLECTING;
    }
}


void Spectrogram::commit()
{
    if (d->state == State::COLLECTING)
    {
        BMP out(d->chunks.size(), data_size.get());
        for (int x = 0; x < d->chunks.size(); ++x)
        {
            for (int y = 0; y < data_size.get(); ++y)
            {
                auto pix = d->chunks[x][y];
                out.set_pixel(x, y, pix, pix, pix, 255);
            }
        }
        out.write(filename.get().c_str());

        d->state = State::WAITING_FIRST;
    }
}
