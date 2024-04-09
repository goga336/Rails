QT       += core gui charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_element.cpp \
    graphic.cpp \
    list.cpp \
    main.cpp \
    pictureinhall.cpp \
    picturetimeperiod.cpp \
    window.cpp \
    zapas.cpp

HEADERS += \
    add_element.h \
    graphic.h \
    list.h \
    pictureinhall.h \
    picturetimeperiod.h \
    window.h \
    zapas.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
