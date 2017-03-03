QT       += core gui widgets

TARGET = SimpleDragableTree
TEMPLATE = app
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        MainWindow.cpp \
    TreeModel.cpp

HEADERS  += MainWindow.h \
    TreeModel.h

FORMS    += MainWindow.ui
