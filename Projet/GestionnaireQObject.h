#ifndef GESTIONNAIREQOBJECT_H
#define GESTIONNAIREQOBJECT_H

/**
 * \file GestionnaireQObject.h
 * \class GestionnaireQObject GestionnaireQObject.h
 * \brief QObject permettant le lien entre le cote affichage et le cote gestion interne
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QObject>
#include "MainWindow.h"
#include "DatabaseManager.h"

class GestionnaireQObject : public QObject
{
    Q_OBJECT
public:
    explicit GestionnaireQObject(QObject *parent = nullptr);
    ~GestionnaireQObject();

private:
    MainWindow* mainWin;
    GestionContact* gestionContact;
    DatabaseManager* dbManager;

private slots:
    void deleteContact(Contact*);
    void modifPrenom(Contact*, std::string);
    void modifNom(Contact*, std::string);
    void modifEntreprise(Contact*,  std::string);
    void modifTelephone(Contact*, std::string);
    void modifMail(Contact*, std::string);
    void modifPhoto(Contact*, std::string);
    void createContact(std::string, std::string, std::string, std::string, std::string, std::string);
    void createContact(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string);
    void editInteractionDate(Interaction*, QDate);
    void editInteractionResume(Interaction*, QString);
    void ajoutInteraction(Contact*, QString);
    void ajoutInteraction(Contact*, Interaction*);

signals:
    void listContactsUpdated(std::list<Contact*>);
    void onContactCreated(Contact*);
    void onInteractionEdited();
    void onEndModifContact();
    void contactDeleted();
    void contactCreated(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string);
};

#endif // GESTIONNAIREQOBJECT_H
