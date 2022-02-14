#pragma once

#include <memory>

using std::shared_ptr;


#define IMPL                    \
private:                        \
    struct Impl;                \
    shared_ptr<Impl> d

