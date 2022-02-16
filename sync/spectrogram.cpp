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
};


Spectrogram::Spectrogram(const std::string& filename)
    : filename(filename)
    , d(new Impl)
{
    d->state = State::WAITING_FIRST;
}


Spectrogram::~Spectrogram()
{
    finish();
}


void Spectrogram::add_chunk(const spectrum_t& in)
{
    std::vector<uint8_t> chunk(data_size);
    for (int i = 0; i < data_size; ++i)
    {
        double freq = freq_min;
        if (linear) 
        {
            freq += (freq_max - freq_min) * i / (data_size - 1);
        }
        else 
        {
            freq *= std::pow(freq_max / freq_min, 1.0 * i / data_size);
        }
        double freq_res = 1.0 * fs / in.size();
        int freq_num = static_cast<int>(std::round(freq / freq_res));
        double ampl = 20.0 * std::log10(std::abs(in[freq_num]));
        if (ampl < ampl_min) 
        {
            chunk[i] = 0;
        }
        else if (ampl > ampl_max) 
        {
            chunk[i] = 255;
        }
        else 
        {
            chunk[i] = static_cast<uint8_t>(255.0 * (ampl - ampl_min) / (ampl_max - ampl_min));
        }
    }
    d->chunks.emplace_back(std::move(chunk));

    if (d->state == State::WAITING_FIRST)
    {
        d->state = State::COLLECTING;
    }
}


void Spectrogram::finish()
{
    if (d->state == State::COLLECTING)
    {
        BMP out(d->chunks.size(), data_size);
        for (int x = 0; x < d->chunks.size(); ++x)
        {
            for (int y = 0; y < data_size; ++y)
            {
                auto pix = d->chunks[x][y];
                out.set_pixel(x, y, pix, pix, pix, 255);
            }
        }
        out.write(filename.c_str());

        d->state = State::WAITING_FIRST;
    }
}


void operator>>(const spectrum_t& in, Spectrogram& spectrogram)
{
    spectrogram.add_chunk(in);
}


void operator>>(const SpectrogramEOF&, Spectrogram& spectrogram)
{
    spectrogram.finish();
}
