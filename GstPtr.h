#pragma once

#include <memory>

#include <gst/gst.h>


struct GstUnref
{
    void operator() (GstObject* object)
        { gst_object_unref(object); }

    void operator() (GstBus* bus)
        { (*this)(GST_OBJECT(bus)); }

    void operator() (GstCaps* caps)
        { gst_caps_unref(caps); }

    void operator() (GstClock* clock)
        { (*this)(GST_OBJECT(clock)); }

    void operator() (GstElement* element)
        { (*this)(GST_OBJECT(element)); }

    void operator() (GstPad* pad)
        { (*this)(GST_OBJECT(pad)); }

    void operator() (GstSample* sample)
        { gst_sample_unref(sample); }

    void operator() (GstBuffer* buffer)
        { gst_buffer_unref(buffer); }
};

typedef
    std::unique_ptr<
        GstObject,
        GstUnref> GstObjectPtr;
typedef
    std::unique_ptr<
        GstBus,
        GstUnref> GstBusPtr;
typedef
    std::unique_ptr<
        GstCaps,
        GstUnref> GstCapsPtr;
typedef
    std::unique_ptr<
        GstClock,
        GstUnref> GstClockPtr;
typedef
    std::unique_ptr<
        GstElement,
        GstUnref> GstElementPtr;
typedef
    std::unique_ptr<
        GstPad,
        GstUnref> GstPadPtr;
typedef
    std::unique_ptr<
        GstSample,
        GstUnref> GstSamplePtr;
typedef
    std::unique_ptr<
        GstBuffer,
        GstUnref> GstBufferPtr;
