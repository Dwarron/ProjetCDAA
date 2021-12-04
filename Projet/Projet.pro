QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    AfficheInteractionsWindow.cpp \
    AjoutInteractionWindow.cpp \
    Contact.cpp \
    CreationFicheWindow.cpp \
    DatabaseManager.cpp \
    Date.cpp \
    FicheContactWindow.cpp \
    Interaction.cpp \
    JSONSerializer.cpp \
    RechercheContactWindow.cpp \
    RequeteWindow.cpp \
    Todo.cpp \
    GestionContact.cpp \
    GestionnaireQObject.cpp \
    Verificator.cpp \
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
    JSONSerializer.h \
    RechercheContactWindow.h \
    RequeteWindow.h \
    Todo.h \
    GestionContact.h \
    GestionnaireQObject.h \
    MainWindow.h \
    Verificator.h

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
