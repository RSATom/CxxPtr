#pragma once

#include <memory>

#include <libconfig.h>


struct LibconfigDestroy
{
    void operator() (config_t* object)
        { config_destroy(object); }
};

typedef
    std::unique_ptr<
        config_t,
        LibconfigDestroy> ConfigDestroy;
