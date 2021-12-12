QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_PROJECT_DEPTH = 0

SOURCES += \
    arduinowindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    arduinowindow.h \
    mainwindow.h

FORMS += \
    arduinowindow.ui \
    mainwindow.ui

#LIBS += "C:/Program Files/Lucid Vision Labs/Arena SDK/lib64/Arena/Arena_v140.lib"
#LIBS += "C:/Program Files/Lucid Vision Labs/Arena SDK/lib64/Arena/ArenaUI_v140.lib"
#LIBS += "C:/Program Files/Lucid Vision Labs/Arena SDK/lib64/Arena/GenTL_LUCID_v140.lib"
#LIBS += "C:/Program Files/Lucid Vision Labs/Arena SDK/lib64/Arena/lucidlog_v140.lib"
#LIBS += "C:/Program Files/Lucid Vision Labs/Arena SDK/lib64/Arena/Save_v140.lib"
#LIBS += "C:/Program Files/Lucid Vision Labs/Arena SDK/GenICam/library/CPP/lib/Win64_x64/GCBase_MD_VC140_v3_3_LUCID.lib"
#LIBS += "C:/Program Files/Lucid Vision Labs/Arena SDK/GenICam/library/CPP/lib/Win64_x64/GenApi_MD_VC140_v3_3_LUCID.lib"
#LIBS += "C:/Program Files/Lucid Vision Labs/Arena SDK/GenICam/library/CPP/lib/Win64_x64/Log_MD_VC140_v3_3_LUCID.lib"
#LIBS += "C:/Program Files/Lucid Vision Labs/Arena SDK/GenICam/library/CPP/lib/Win64_x64/MathParser_MD_VC140_v3_3_LUCID.lib"
#LIBS += "C:/Program Files/Lucid Vision Labs/Arena SDK/GenICam/library/CPP/lib/Win64_x64/NodeMapData_MD_VC140_v3_3_LUCID.lib"
#LIBS += "C:/Program Files/Lucid Vision Labs/Arena SDK/GenICam/library/CPP/lib/Win64_x64/ResUsageStat_MD_VC140_v3_3_LUCID.lib"
#LIBS += "C:/Program Files/Lucid Vision Labs/Arena SDK/GenICam/library/CPP/lib/Win64_x64/XmlParser_MD_VC140_v3_3_LUCID.lib"



#INCLUDEPATH += "C:/Program Files/Lucid Vision Labs/Arena SDK/include/Arena"
#INCLUDEPATH += "C:/Program Files/Lucid Vision Labs/Arena SDK/include/ArenaUI"
#INCLUDEPATH += "C:/Program Files/Lucid Vision Labs/Arena SDK/include/GenTL"
#INCLUDEPATH += "C:/Program Files/Lucid Vision Labs/Arena SDK/include/Save"
#INCLUDEPATH += "C:/Program Files/Lucid Vision Labs/Arena SDK/include/Win32pp"

#INCLUDEPATH += "C:/Program Files/Lucid Vision Labs/Arena SDK/GenICam/library/CPP/include"



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    stylesheets.qrc
