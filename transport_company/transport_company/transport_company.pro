QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Car.cpp \
    Company.cpp \
    CompanyStateWindow.cpp \
    EventWindow.cpp \
    MainWindow.cpp \
    Mechanic.cpp \
    ModelParametersWindow.cpp \
    main.cpp \

HEADERS += \
    Car.hpp \
    Company.hpp \
    CompanyStateWindow.hpp \
    EventWindow.hpp \
    MainWindow.hpp \
    Mechanic.hpp \
    ModelParametersWindow.hpp

FORMS += \
    CompanyStateWindow.ui \
    EventWindow.ui \
    MainWindow.ui \
    ModelParametersWindow.ui

