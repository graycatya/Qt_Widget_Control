#-------------------------------------------------
#
# Project created by QtCreator 2019-11-27T08:49:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ControlTools
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Button/switchbutton.cpp \
        Encp/encpssl.cpp \
        IpLabel/iplabeledit.cpp \
        Marquee/marquee.cpp \
        ProgressBar/progressarc.cpp \
        main.cpp \
        widget.cpp

HEADERS += \
        Button/switchbutton.h \
        Encp/encpssl.h \
        IpLabel/iplabeledit.h \
        Marquee/marquee.h \
        ProgressBar/progressarc.h \
        ThreadPool/ThreadPool.h \
        openssl/aes.h \
        openssl/asn1.h \
        openssl/asn1_mac.h \
        openssl/asn1err.h \
        openssl/asn1t.h \
        openssl/async.h \
        openssl/asyncerr.h \
        openssl/bio.h \
        openssl/bioerr.h \
        openssl/blowfish.h \
        openssl/bn.h \
        openssl/bnerr.h \
        openssl/buffer.h \
        openssl/buffererr.h \
        openssl/camellia.h \
        openssl/cast.h \
        openssl/cmac.h \
        openssl/cms.h \
        openssl/cmserr.h \
        openssl/comp.h \
        openssl/comperr.h \
        openssl/conf.h \
        openssl/conf_api.h \
        openssl/conferr.h \
        openssl/crypto.h \
        openssl/cryptoerr.h \
        openssl/ct.h \
        openssl/cterr.h \
        openssl/des.h \
        openssl/dh.h \
        openssl/dherr.h \
        openssl/dsa.h \
        openssl/dsaerr.h \
        openssl/dtls1.h \
        openssl/e_os2.h \
        openssl/ebcdic.h \
        openssl/ec.h \
        openssl/ecdh.h \
        openssl/ecdsa.h \
        openssl/ecerr.h \
        openssl/engine.h \
        openssl/engineerr.h \
        openssl/err.h \
        openssl/evp.h \
        openssl/evperr.h \
        openssl/hmac.h \
        openssl/idea.h \
        openssl/kdf.h \
        openssl/kdferr.h \
        openssl/lhash.h \
        openssl/md2.h \
        openssl/md4.h \
        openssl/md5.h \
        openssl/mdc2.h \
        openssl/modes.h \
        openssl/obj_mac.h \
        openssl/objects.h \
        openssl/objectserr.h \
        openssl/ocsp.h \
        openssl/ocsperr.h \
        openssl/opensslconf.h \
        openssl/opensslv.h \
        openssl/ossl_typ.h \
        openssl/pem.h \
        openssl/pem2.h \
        openssl/pemerr.h \
        openssl/pkcs12.h \
        openssl/pkcs12err.h \
        openssl/pkcs7.h \
        openssl/pkcs7err.h \
        openssl/rand.h \
        openssl/rand_drbg.h \
        openssl/randerr.h \
        openssl/rc2.h \
        openssl/rc4.h \
        openssl/rc5.h \
        openssl/ripemd.h \
        openssl/rsa.h \
        openssl/rsaerr.h \
        openssl/safestack.h \
        openssl/seed.h \
        openssl/sha.h \
        openssl/srp.h \
        openssl/srtp.h \
        openssl/ssl.h \
        openssl/ssl2.h \
        openssl/ssl3.h \
        openssl/sslerr.h \
        openssl/stack.h \
        openssl/store.h \
        openssl/storeerr.h \
        openssl/symhacks.h \
        openssl/tls1.h \
        openssl/ts.h \
        openssl/tserr.h \
        openssl/txt_db.h \
        openssl/ui.h \
        openssl/uierr.h \
        openssl/whrlpool.h \
        openssl/x509.h \
        openssl/x509_vfy.h \
        openssl/x509err.h \
        openssl/x509v3.h \
        openssl/x509v3err.h \
        widget.h

FORMS += \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lcrypto-1_1-x64 -lssl-1_1-x64
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lcrypto-1_1-x64 -lssl-1_1-x64
else:unix: LIBS += -L$$PWD/lib/ -lcrypto -lssl

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
