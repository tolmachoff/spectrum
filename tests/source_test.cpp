#include <gtest/gtest.h>

#include "noise.h"

#include <numeric>

using namespace std;



TEST(SourceTest, Noise01)
{
    Noise noise(0.0, 1.0);

    auto v = 1000 >> noise;

    EXPECT_EQ(v.size(), 1000);

    double mean = accumulate(v.begin(), v.end(), 0.0) / v.size();

    EXPECT_NEAR(mean, 0.0, 0.1);
}
