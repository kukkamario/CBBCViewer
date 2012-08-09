TEMPLATE = app
QT += core
CONFIG += console precompiled_header

SOURCES += main.cpp \
    main.cpp \
    bytecodereader.cpp \
    bytecode.cpp \
    stringpool.cpp \
    instruction.cpp

HEADERS += \
    instruction.h \
    bytecodereader.h \
    bytecode.h \
    precomp.h \
    stringpool.h

PRECOMPILED_HEADER = precomp.h
