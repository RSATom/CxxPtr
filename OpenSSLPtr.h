#pragma once

#include <memory>

#include <openssl/bio.h>
#include <openssl/x509.h>


struct OpenSSLUnref
{
    void operator() (BIO* bio)
        { BIO_free(bio); }
    void operator() (X509* x509)
        { X509_free(x509); }
    void operator() (X509_STORE* store)
        { X509_STORE_free(store); }
    void operator() (X509_STORE_CTX* ctx)
        { X509_STORE_CTX_free(ctx); }

    void operator() (STACK_OF(X509)* st)
        { sk_X509_free(st); }
};

typedef
    std::unique_ptr<
        BIO,
        OpenSSLUnref> BIOPtr;
typedef
    std::unique_ptr<
        X509,
        OpenSSLUnref> X509Ptr;
typedef
    std::unique_ptr<
        X509_STORE,
        OpenSSLUnref> X509_STOREPtr;
typedef
    std::unique_ptr<
        X509_STORE_CTX,
        OpenSSLUnref> X509_STORE_CTXPtr;
typedef
    std::unique_ptr<
        STACK_OF(X509),
        OpenSSLUnref> X509_STACKPtr;
