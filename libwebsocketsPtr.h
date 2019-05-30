#pragma once

#include <memory>

#include <libwebsockets.h>


struct LibWebsocketsUnref
{
    void operator() (lws_context* context)
        { lws_context_destroy(context); }
};

typedef
    std::unique_ptr<
        lws_context,
        LibWebsocketsUnref> LwsContextPtr;
