#pragma once

#include <memory>

#include <gst/gst.h>
#include <gst/sdp/gstsdpmessage.h>
#include <gst/gstpromise.h>
#include <gst/webrtc/rtcsessiondescription.h>


struct GstWebRtcUnref
{
    void operator() (GObject* object)
        { gst_object_unref(object); }

    void operator() (GstSDPMessage* sdp)
        { gst_sdp_message_free(sdp); }

    void operator() (GstSDPMedia* media)
        { gst_sdp_media_free(media); }

    void operator() (GstPromise* promise)
        { gst_promise_unref(promise); }

    void operator() (GstWebRTCSessionDescription* description)
        { gst_webrtc_session_description_free(description); }

    void operator() (GstWebRTCRTPTransceiver* transceiver)
        { (*this)(G_OBJECT(transceiver)); }
};

typedef
    std::unique_ptr<
        GstSDPMessage,
        GstWebRtcUnref> GstSDPMessagePtr;
typedef
    std::unique_ptr<
        GstSDPMedia,
        GstWebRtcUnref> GstSDPMediaPtr;
typedef
    std::unique_ptr<
        GstPromise,
        GstWebRtcUnref> GstPromisePtr;
typedef
    std::unique_ptr<
        GstWebRTCSessionDescription,
        GstWebRtcUnref> GstWebRTCSessionDescriptionPtr;
typedef
    std::unique_ptr<
        GstWebRTCRTPTransceiver,
        GstWebRtcUnref> GstWebRTCRTPTransceiverPtr;
