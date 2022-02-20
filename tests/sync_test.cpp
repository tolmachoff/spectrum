#include <gtest/gtest.h>

#include "fft.h"
#include "hamming.h"
#include "rescaler.h"
#include "sinus.h"
#include "spectrogram.h"

using namespace std;

TEST(SyncTest, Spectrogram01)
{
    Sinus sinus(440.0, 1e-2);
    Spectrogram spectr("spectrogram01.bmp");

    for (int i = 0; i < 880; ++i)
    {
        882 >> sinus >> Hamming() >> Rescaler(4096) >> FFT() >> spectr;
        sinus.f0.set(sinus.f0.get() + 1.0);
    }
    spectr.commit();

    EXPECT_TRUE(true);
}
