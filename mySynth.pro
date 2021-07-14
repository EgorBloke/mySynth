QT       += core gui
 QT       +=multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    audioRecord.cpp \
    key.cpp \
    keyboard.cpp \
    main.cpp \
    mygraphicsview.cpp \
    note.cpp \
    synth.cpp

HEADERS += \
    audioRecord.h \
    key.h \
    keyboard.h \
    mygraphicsview.h \
    note.h \
    synth.h

FORMS += \
    synth.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    sounds/piano-b_B_major.wav \
    sounds/piano-bb_A#_major.wav \
    sounds/piano-c_C_major.wav
