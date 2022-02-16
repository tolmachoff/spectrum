#include <gtest/gtest.h>

#include "sinus.h"
#include "fft.h"
#include "hamming.h"
#include "spectrogram.h"

using namespace std;



TEST(SyncTest, Spectrogram01)
{
    Sinus sinus{44100.0, 440.0, 0.1};
    Spectrogram spectr("spectrogram01.bmp");

    for (int i = 0; i < 880; ++i)
    {
        2205 >> sinus >> Hamming{} >> FFT{Direction::Forward} >> spectr;
        sinus.f0 += 1.0;
    }
    SpectrogramEOF{} >> spectr;

    EXPECT_TRUE(true); // :)
}