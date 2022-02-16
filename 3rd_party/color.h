#pragma once

#include <cstdint>
#include <tuple>

using std::tie;


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
