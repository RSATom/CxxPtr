#pragma once

#include <memory>

#include <gst/gst.h>
#include <gst/sdp/gstsdpmessage.h>
#include <gst/gstpromise.h>
#include <gst/webrtc/rtcsessiondescription.h>


struct GstUnref
{
    void operator() (GObject* object)
        { gst_object_unref(object); }

    void operator() (GstBus* bus)
        { (*this)(G_OBJECT(bus)); }

    void operator() (GstCaps* caps)
        { gst_caps_unref(caps); }

    void operator() (GstClock* clock)
        { (*this)(G_OBJECT(clock)); }

    void operator() (GstElement* element)
        { (*this)(G_OBJECT(element)); }

    void operator() (GstPad* pad)
        { (*this)(G_OBJECT(pad)); }

    void operator() (GstSample* sample)
        { gst_sample_unref(sample); }

    void operator() (GstBuffer* buffer)
        { gst_buffer_unref(buffer); }

    void operator() (GstSDPMessage* sdp)
        { gst_sdp_message_free(sdp); }

    void operator() (GstSDPMedia* media)
        { gst_sdp_media_free(media); }

    void operator() (GstPromise* promise)
        { gst_promise_unref(promise); }

    void operator() (GstWebRTCSessionDescription* description)
        { gst_webrtc_session_description_free(description); }
};

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
typedef
    std::unique_ptr<
        GstSDPMessage,
        GstUnref> GstSDPMessagePtr;
typedef
    std::unique_ptr<
        GstSDPMedia,
        GstUnref> GstSDPMediaPtr;
typedef
    std::unique_ptr<
        GstPromise,
        GstUnref> GstPromisePtr;
typedef
    std::unique_ptr<
        GstWebRTCSessionDescription,
        GstUnref> GstWebRTCSessionDescriptionPtr;
