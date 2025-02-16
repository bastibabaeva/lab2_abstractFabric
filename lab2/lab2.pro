QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        unit.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    abstractFactory.h \
    classUnit.h \
    cplusClass.h \
    cplusFactory.h \
    cplusMethod.h \
    cplusPrintOperator.h \
    csharpClass.h \
    csharpFactory.h \
    csharpMethod.h \
    csharpPrintOperator.h \
    javaFactory.h \
    javaclass.h \
    javamethod.h \
    javaprintOperator.h \
    methodUnit.h \
    printOperatorUnit.h \
    unit.h
