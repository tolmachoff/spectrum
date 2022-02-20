#include <gtest/gtest.h>

#include <numeric>

#include "noise.h"
#include "sinus.h"

using namespace std;

TEST(SourceTest, Noise01)
{
    Noise noise(0.0, 1.0);

    auto v = 1000 >> noise;
    EXPECT_EQ(v.size(), 1000);

    double mean = accumulate(v.begin(), v.end(), 0.0) / v.size();
    EXPECT_NEAR(mean, 0.0, 0.1);
}

TEST(SourceTest, Sinus01)
{
    Sinus sinus(1.0, 1.0);
    sinus.fs.set(4);

    auto v = 16 >> sinus;

    signal_t v_etalon{0.0, 1.0, 0.0, -1.0};

    for (size_t i = 0; i < 16; ++i)
    {
        EXPECT_NEAR(v[i], v_etalon[i % 4], 1e-6);
    }
}
