QT += core gui
greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

CONFIG += sanitizer sanitize_adress

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Block.cpp \
    BlockUi.cpp \
    Board.cpp \
    Game.cpp \
    GameUi.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Block.h \
    BlockUi.h \
    Board.h \
    Game.h \
    GameUi.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += $$PWD/headers

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
