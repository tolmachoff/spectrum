#include "fft.h"

#include <gtest/gtest.h>

#include "hamming.h"

using namespace std;

TEST(FFTTest, Test1)
{
    signal_t v{1, 0, 0, 0};

    auto V = v >> FFT();

    spectrum_t etalon_V{1, 1, 1, 1};

    EXPECT_EQ(V.size(), 4);
    EXPECT_EQ(V, etalon_V);
}

TEST(FFTTest, Test2)
{
    signal_t v{1, 1, 1, 1};

    auto V = v >> FFT();

    spectrum_t etalon_V{4, 0, 0, 0};

    EXPECT_EQ(V.size(), 4);
    EXPECT_EQ(V, etalon_V);
}

TEST(FFTTest, Test3)
{
    signal_t v{1, 0, -1, 0};

    auto V = v >> FFT();

    spectrum_t etalon_V{0, 2, 0, 2};

    EXPECT_EQ(V.size(), 4);
    EXPECT_EQ(V, etalon_V);
}

TEST(FFTTest, Test4)
{
    signal_t v{1, 0, 0, 0};

    auto V = v >> Hamming() >> FFT();

    EXPECT_EQ(V.size(), 4);
    for (int i = 0; i < 4; ++i)
    {
        EXPECT_NEAR(V[i].real(), 0.07672, 1e-5);
    }
}

TEST(FFTTest, Test5)
{
    signal_t v{1, 0, 0, 0};

    auto v_ = v >> FFT() >> IFFT();

    EXPECT_EQ(v, v_);
}
