TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    car.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    car.h

