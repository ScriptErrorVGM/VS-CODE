QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ellipse.cpp \
    evolute.cpp \
    main.cpp \
    mainwindow.cpp \
    pwin.cpp \
    qcustomplot.cpp

HEADERS += \
    ellipse.h \
    evolute.h \
    mainwindow.h \
    pwin.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui \
    pwin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target