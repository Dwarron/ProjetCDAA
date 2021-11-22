QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AfficheInteractionsWindow.cpp \
    AjoutInteractionWindow.cpp \
    Contact.cpp \
    CreationFicheWindow.cpp \
    DatabaseManager.cpp \
    Date.cpp \
    FicheContactWindow.cpp \
    Interaction.cpp \
    RechercheContactWindow.cpp \
    RequeteWindow.cpp \
    Todo.cpp \
    GestionContact.cpp \
    GestionnaireQObject.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    AfficheInteractionsWindow.h \
    AjoutInteractionWindow.h \
    Contact.h \
    CreationFicheWindow.h \
    DatabaseManager.h \
    Date.h \
    FicheContactWindow.h \
    Interaction.h \
    RechercheContactWindow.h \
    RequeteWindow.h \
    Todo.h \
    GestionContact.h \
    GestionnaireQObject.h \
    MainWindow.h

FORMS += \
    AfficheInteractionsWindow.ui \
    AjoutInteractionWindow.ui \
    CreationFicheWindow.ui \
    FicheContactWindow.ui \
    RechercheContactWindow.ui \
    RequeteWindow.ui \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
