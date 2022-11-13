QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DrawLogic/DrawSymbols/S57DrawSymbols.cpp \
    ReadSupportFiles/OpenCPN/OpenCPNS57ColorCalibLibrary.cpp \
    ReadSupportFiles/OpenCPN/OpenCPNS57LookUpTableLibrary.cpp \
    ReadSupportFiles/OpenCPN/OpenCPNS57Objects.cpp \
    ReadSupportFiles/OpenCPN/OpenCPNS57SymbolLibrary.cpp \
    ReadSupportFiles/OpenCPN/ReadOpenCPNSupportFiles.cpp \
    ReadSupportFiles/OpenCPN/openCPNS57Attributes.cpp \
    ReadSupportFiles/S57Support/ReadS57SupportFiles.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    DrawLogic/DrawSymbols/S57DrawSymbols.h \
    MainWindow.h \
    ReadSupportFiles/OpenCPN/OpenCPNS57ColorCalibLibrary.h \
    ReadSupportFiles/OpenCPN/OpenCPNS57LookUpTableLibrary.h \
    ReadSupportFiles/OpenCPN/OpenCPNS57Objects.h \
    ReadSupportFiles/OpenCPN/OpenCPNS57SymbolLibrary.h \
    ReadSupportFiles/OpenCPN/ReadOpenCPNSupportFiles.h \
    ReadSupportFiles/OpenCPN/openCPNS57Attributes.h \
    ReadSupportFiles/S57Support/ReadS57SupportFiles.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
