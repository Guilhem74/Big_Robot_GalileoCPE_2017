QT += widgets core gui serialport

greaterThan(QT_MAJOR_VERSION,4): QT += widgets printsupport


SOURCES += \
    main.cpp \
    mainFenetre.cpp \
    qcustomplot.cpp \
    Customplot.cpp \
    SerialCustom.cpp

HEADERS += \
    mainFenetre.h \
    qcustomplot.h \
    Customplot.h \
    define.h \
    SerialCustom.h
