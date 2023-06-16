#pragma once

#include <memory>

#include <gio/gio.h>


struct GioUnref {
    void operator() (GObject* object)
        { g_object_unref(object); }
    void operator() (GFile* file)
        { (*this)(G_OBJECT(file)); }
    void operator() (GFileMonitor* fileMonitor)
        { (*this)(G_OBJECT(fileMonitor)); }
    void operator() (GTlsInteraction* interaction)
        { (*this)(interaction); }
    void operator() (GTlsCertificate* certificate)
        { (*this)(certificate); }
    void operator() (GCancellable* task)
        { (*this)(G_OBJECT(task)); }
    void operator() (GTask* task)
        { (*this)(G_OBJECT(task)); }
};

typedef std::unique_ptr<GFile, GioUnref> GFilePtr;
typedef std::unique_ptr<GFileMonitor, GioUnref> GFileMonitorPtr;
typedef std::unique_ptr<GTlsInteraction, GioUnref> GTlsInteractionPtr;
typedef std::unique_ptr<GTlsCertificate, GioUnref> GTlsCertificatePtr;
typedef std::unique_ptr<GCancellable, GioUnref> GCancellablePtr;
typedef std::unique_ptr<GTask, GioUnref> GTaskPtr;
