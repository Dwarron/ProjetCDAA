QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AjoutEvenementWindow.cpp \
    Contact.cpp \
    CreationFicheWindow.cpp \
    Date.cpp \
    Interaction.cpp \
    ModificationContactWindow.cpp \
    ModificationEvenementWindow.cpp \
    RechercheContactWindow.cpp \
    RequeteWindow.cpp \
    Todo.cpp \
    GestionContact.cpp \
    GestionnaireQObject.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    AjoutEvenementWindow.h \
    Contact.h \
    CreationFicheWindow.h \
    Date.h \
    Interaction.h \
    ModificationContactWindow.h \
    ModificationEvenementWindow.h \
    RechercheContactWindow.h \
    RequeteWindow.h \
    Todo.h \
    GestionContact.h \
    GestionnaireQObject.h \
    mainwindow.h

FORMS += \
    AjoutEvenementWindow.ui \
    CreationFicheWindow.ui \
    ModificationContactWindow.ui \
    ModificationEvenementWindow.ui \
    RechercheContactWindow.ui \
    RequeteWindow.ui \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
