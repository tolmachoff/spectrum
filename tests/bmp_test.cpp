#include <gtest/gtest.h>

#include "BMP.h"
#include "color.h"



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
