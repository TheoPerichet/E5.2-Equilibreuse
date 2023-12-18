QT       += core gui
LIBS += /usr/local/lib/libuldaq.a
LIBS += -lusb-1.0
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mcculdaq.cpp \
    reglagesm18.cpp

HEADERS += \
    constantes.h \
    mcculdaq.h \
    reglagesm18.h

FORMS += \
    reglagesm18.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target