#include <gtest/gtest.h>

#include "sinus.h"
#include "hamming.h"
#include "rescaler.h"
#include "fft.h"
#include "spectrogram.h"

using namespace std;



TEST(SyncTest, Spectrogram01)
{
    Sinus sinus{44100.0, 440.0, 1e-2};
    Spectrogram spectr("spectrogram01.bmp");

    for (int i = 0; i < 880; ++i)
    {
        882 >> sinus >> Hamming{} >> Rescaler{4096} >> FFT{Direction::Forward} >> spectr;
        sinus.f0 += 1.0;
    }
    SpectrogramEOF{} >> spectr;

    EXPECT_TRUE(true);
}
