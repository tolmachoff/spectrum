#include <gtest/gtest.h>

#include "../BMP/BMP.h"

#include <cstdint>

using namespace std;


struct Color
{
    uint8_t b;
    uint8_t g;
    uint8_t r;
    uint8_t a;


    bool operator==(const Color& rhs) const
    {
        return tie(b, g, r, a) == tie(rhs.b, rhs.g, rhs.r, rhs.a);
    }
};


TEST(BMPTest, Test1)
{
    BMP out(16, 16);
    out.set_pixel(0, 0, 0, 0, 255, 255);
    out.set_pixel(15, 0, 0, 255, 0, 255);
    out.set_pixel(15, 15, 255, 0, 0, 255);
    out.write("test.bmp");
    
    BMP in("test.bmp");
    EXPECT_EQ(in.data.size(), 4 * 256);

    Color* data = reinterpret_cast<Color*>(in.data.data());
    Color red {0, 0, 255, 255};
    EXPECT_EQ(data[0], red);

    Color green {0, 255, 0, 255};
    EXPECT_EQ(data[15], green);

    Color blue {255, 0, 0, 255};
    EXPECT_EQ(data[255], blue);
}
