#pragma once

#include <memory>

#include <glib-object.h>
#include <glib.h>

#if GLIB_CHECK_VERSION(2, 66, 0)
    #include <glib/guri.h>
#endif

#include <gio/gio.h>


struct GlibUnref
{
    void operator() (GError* error)
        { g_error_free(error); }

    void operator() (GObject* object)
        { g_object_unref(object); }

    void operator() (GMainContext* context)
        { g_main_context_unref(context); }

    void operator() (GMainLoop* loop)
        { g_main_loop_unref(loop); }

    void operator() (GSource* source)
        { g_source_unref(source); }

    void operator() (GList* list)
        { g_list_free(list); }

    void operator() (gchar* str)
        { g_free(str); }

    void operator() (GTlsInteraction* interaction)
        { g_object_unref(interaction); }

    void operator() (GTlsCertificate* certificate)
        { g_object_unref(certificate); }

    void operator() (GTimer* timer)
        { g_timer_destroy(timer); }

#if GLIB_CHECK_VERSION(2, 66, 0)
    void operator() (GUri* uri)
        { g_uri_unref(uri); }
#endif

    void operator() (GCancellable* task)
        { (*this)(G_OBJECT(task)); }

    void operator() (GTask* task)
        { (*this)(G_OBJECT(task)); }
};

typedef
    std::unique_ptr<
        GError,
        GlibUnref> GErrorPtr;
typedef
    std::unique_ptr<
        GObject,
        GlibUnref> GObjectPtr;
typedef
    std::unique_ptr<
        GMainContext,
        GlibUnref> GMainContextPtr;
typedef
    std::unique_ptr<
        GMainLoop,
        GlibUnref> GMainLoopPtr;
typedef
    std::unique_ptr<
        GSource,
        GlibUnref> GSourcePtr;
typedef
    std::unique_ptr<
        GList,
        GlibUnref> GListPtr;
typedef
    std::unique_ptr<
        gchar,
        GlibUnref> GCharPtr;
typedef
    std::unique_ptr<
        GTlsInteraction,
        GlibUnref> GTlsInteractionPtr;
typedef
    std::unique_ptr<
        GTlsCertificate,
        GlibUnref> GTlsCertificatePtr;
typedef
    std::unique_ptr<
        GTimer,
        GlibUnref> GTimerPtr;

#if GLIB_CHECK_VERSION(2, 66, 0)
typedef
    std::unique_ptr<
        GUri,
        GlibUnref> GUriPtr;
#endif

typedef
    std::unique_ptr<
        GCancellable,
        GlibUnref> GCancellablePtr;
typedef
    std::unique_ptr<
        GTask,
        GlibUnref> GTaskPtr;


struct GObjectWeakRef
{
    GObjectWeakRef(GObject* object = nullptr)
        { g_weak_ref_init(&ref, object); }

    ~GObjectWeakRef()
        { g_weak_ref_clear(&ref); }

    GObjectPtr get()
        { return GObjectPtr(G_OBJECT(g_weak_ref_get(&ref))); }

    void reset(GObject* object)
        { g_weak_ref_set(&ref, object); }

    GWeakRef ref;
};
