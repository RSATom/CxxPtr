#pragma once

#include <stdlib.h>

#include <memory>


struct CFree
{
    void operator() (char* str)
        { free(str); }
};

typedef
    std::unique_ptr<
        char,
        CFree> CharPtr;
