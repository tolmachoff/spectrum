#include <gtest/gtest.h>

#include "normalizer.h"

using namespace std;

TEST(FilterTest, Normalizer01)
{
    signal_t v{2, 0, -8, 4};

    auto v_norm = v >> Normalizer();

    signal_t v_etalon = {0.25, 0, -1, 0.5};

    EXPECT_EQ(v_norm, v_etalon);
}
