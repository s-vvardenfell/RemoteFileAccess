TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        client.cpp \
        filemanager.cpp \
        main.cpp

HEADERS += \
    client.hpp \
    filemanager.hpp

LIBS+= \
       -lpthread \
