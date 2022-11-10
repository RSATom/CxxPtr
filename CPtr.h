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

struct FDAutoClose
{
    FDAutoClose(int fd) : fd(fd) {}
    ~FDAutoClose() { if(fd != -1) close(fd); }

    int get() const { return fd; }

    void cancel() { fd = -1; }

private:
    int fd;
};
