#ifndef GESTIONNAIREQOBJECT_H
#define GESTIONNAIREQOBJECT_H

#include <QObject>
#include "MainWindow.h"

class GestionnaireQObject : public QObject
{
    Q_OBJECT
public:
    explicit GestionnaireQObject(QObject *parent = nullptr);
    ~GestionnaireQObject();

private:
    MainWindow* mainWin;
    GestionContact* gestionContact;

private slots:
    void deleteContact(Contact*);
    void modifPrenom(Contact*, std::string);
    void modifNom(Contact*, std::string);
    void modifEntreprise(Contact*,  std::string);
    void modifTelephone(Contact*, std::string);
    void modifMail(Contact*, std::string);
    void modifPhoto(Contact*, std::string);
    void createContact(std::string, std::string, std::string, std::string, std::string, std::string);

signals:
    void listContactsUpdated();
    void onContactCreated(Contact*);
};

#endif // GESTIONNAIREQOBJECT_H
