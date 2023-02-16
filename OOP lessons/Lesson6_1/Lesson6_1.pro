TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    book.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    book.h

