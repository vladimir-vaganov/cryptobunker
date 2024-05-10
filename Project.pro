QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game.cpp \
    kpk.cpp \
    levels.cpp \
    leveltemplate.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    randomlevels.cpp \
    randomleveltemplate.cpp \
    roundedbutton.cpp \
    spravochnik.cpp

HEADERS += \
    game.h \
    includes.h \
    kpk.h \
    levels.h \
    leveltemplate.h \
    mainwindow.h \
    menu.h \
    randomlevels.h \
    randomleveltemplate.h \
    roundedbutton.h \
    spravochnik.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
