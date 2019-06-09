#pragma once

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
