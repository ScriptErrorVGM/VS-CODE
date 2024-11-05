TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bus.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    bus.h

