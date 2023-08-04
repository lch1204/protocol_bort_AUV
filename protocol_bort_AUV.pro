QT += core network

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        kx_pult/qpiconfig.cpp \
        main.cpp \
        protocol_bort.cpp \
        protocol_pc.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    kx_pult/qpiconfig.h \
    protocol_pc.h \
    udp_protocol.h\
    pc_protocol.h \
    protocol.h \
    protocol_bort.h

