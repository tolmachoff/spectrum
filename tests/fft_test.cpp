#include <gtest/gtest.h>

#include "../fft/fft.h"

using namespace std;



TEST(StupidTest, Test1)
{
    cmplx_vec_t v {1, 0, 0, 0};

    FFT fft;
    fft.set_data_size(4);
    fft.set_fft_size(4);
    auto V = fft.process(v);

    cmplx_vec_t etalon_V {1, 1, 1, 1};

    EXPECT_EQ(V.size(), 4);
    EXPECT_EQ(V, etalon_V);
}


TEST(StupidTest, Test2)
{
    cmplx_vec_t v {1, 1, 1, 1};

    FFT fft;
    fft.set_data_size(4);
    fft.set_fft_size(4);
    auto V = fft.process(v);

    cmplx_vec_t etalon_V {4, 0, 0, 0};

    EXPECT_EQ(V.size(), 4);
    EXPECT_EQ(V, etalon_V);
}


TEST(StupidTest, Test3)
{
    cmplx_vec_t v {1, 0, -1, 0};

    FFT fft;
    fft.set_data_size(4);
    fft.set_fft_size(4);
    auto V = fft.process(v);

    cmplx_vec_t etalon_V {0, 2, 0, 2};

    EXPECT_EQ(V.size(), 4);
    EXPECT_EQ(V, etalon_V);
}