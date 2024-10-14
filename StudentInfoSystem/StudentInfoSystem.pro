QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    courseui_std.cpp \
    databaseconnectionsingleton.cpp \
    globals.cpp \
    main.cpp \
    studentinfosystem.cpp \
    studentui.cpp \
    systemui.cpp

HEADERS += \
    courseui_std.h \
    databaseconnectionsingleton.h \
    globals.h \
    studentinfosystem.h \
    studentui.h \
    systemui.h

FORMS += \
    courseui_std.ui \
    studentinfosystem.ui \
    studentui.ui \
    systemui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
