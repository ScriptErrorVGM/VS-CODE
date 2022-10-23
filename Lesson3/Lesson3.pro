TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    phrase.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    phrase.h

