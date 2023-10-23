QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 qt debug

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    credit.cpp \
    graph.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    result_credit.cpp \
    ../controller/controller.cc \
    ../model/model.cc \
    ../model/credit_model.cc

HEADERS += \
    credit.h \
    graph.h \
    mainwindow.h \
    qcustomplot.h \
    result_credit.h \
    ../controller/controller.h \
    ../model/model.h \
    ../model/credit_model.h

FORMS += \
    credit.ui \
    graph.ui \
    mainwindow.ui \
    result_credit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
