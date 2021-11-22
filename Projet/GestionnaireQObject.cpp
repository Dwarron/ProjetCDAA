/**
 * \file GestionnaireQObject.cpp
 * \class GestionnaireQObject GestionnaireQObject.h
 * \brief QObject permettant le lien entre le cote affichage et le cote gestion interne
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QDate>
#include "GestionnaireQObject.h"

using namespace std;

GestionnaireQObject::GestionnaireQObject(QObject *parent) : QObject(parent)
{
    gestionContact = new GestionContact();
    dbManager = new DatabaseManager();

    connect(dbManager, SIGNAL(loadContact(std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string)),
            this, SLOT(createContact(std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string)));

    dbManager->loadAllContacts();

 /*   Contact* contact1 = gestionContact->creeContact("Duportail", "Damien", "Unirex compagnie", "0673332557", "damien.duportail@btc.fr", "/home/Directory/Document/Image/duportail.jpg");
    Contact* contact2 = gestionContact->creeContact("Delafenetre", "Jean-Pierre", "Btc compagnie", "0607487537", "", "/home/Directory/Document/Photo/dlf.jpg");
    contact1->setEntreprise("Pancakesquad NFT");

    Interaction* i = gestionContact->ajoutInteraction(contact1, "rdv tel ras\n@todo rappeler 1 le @date 10/11/2021\n@todo rappeler 2 le @date 22/10/2021");

    i->setResume("en fait RAS, @todo rappeler seulement @date 25/10/2021"); //modification d'une interaction

    gestionContact->ajoutInteraction(contact2, i);        //possibilite d'ajouter une meme interaction a deux contacts differents
    gestionContact->ajoutInteraction(contact1, "Investir en bourse\n @todo acheter btc le @date 25/12/2021\n @todo acheter eth le @date 28/12/2021");
*/
    mainWin = new MainWindow(nullptr);

    connect(mainWin, SIGNAL(contactDeleted(Contact*)), this, SLOT(deleteContact(Contact*)));

    connect(mainWin, SIGNAL(prenomModified(Contact*,std::string)), this, SLOT(modifPrenom(Contact*,std::string)));
    connect(mainWin, SIGNAL(nomModified(Contact*,std::string)), this, SLOT(modifNom(Contact*,std::string)));
    connect(mainWin, SIGNAL(entrepriseModified(Contact*,std::string)), this, SLOT(modifEntreprise(Contact*,std::string)));
    connect(mainWin, SIGNAL(mailModified(Contact*,std::string)), this, SLOT(modifMail(Contact*,std::string)));
    connect(mainWin, SIGNAL(telephoneModified(Contact*,std::string)), this, SLOT(modifTelephone(Contact*,std::string)));
    connect(mainWin, SIGNAL(photoModified(Contact*,std::string)), this, SLOT(modifPhoto(Contact*,std::string)));

    connect(mainWin, SIGNAL(contactCreated(std::string,std::string,std::string,std::string,std::string,std::string)),
            this, SLOT(createContact(std::string,std::string,std::string,std::string,std::string,std::string)));
    connect(this, SIGNAL(contactCreated(std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string)),
            dbManager, SLOT(createContact(std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string)));

    connect(mainWin, SIGNAL(interactionDateEdited(Interaction*,QDate)), this, SLOT(editInteractionDate(Interaction*,QDate)));
    connect(mainWin, SIGNAL(interactionResumeEdited(Interaction*,QString)), this, SLOT(editInteractionResume(Interaction*,QString)));

    connect(mainWin, SIGNAL(ajoutInteraction(Contact*,QString)), this, SLOT(ajoutInteraction(Contact*,QString)));
    connect(mainWin, SIGNAL(ajoutInteraction(Contact*,Interaction*)), this, SLOT(ajoutInteraction(Contact*,Interaction*)));

    connect(this, SIGNAL(listContactsUpdated(std::list<Contact*>)), mainWin, SIGNAL(listContactsUpdated(std::list<Contact*>)));
    connect(this, SIGNAL(contactDeleted()), mainWin, SLOT(selectContact()));
    connect(this, SIGNAL(onContactCreated(Contact*)), mainWin, SLOT(selectContact(Contact*)));
    connect(this, SIGNAL(onInteractionEdited()), mainWin, SIGNAL(onInteractionEdited()));
    connect(this, SIGNAL(onEndModifContact()), mainWin, SIGNAL(onEndModifContact()));

    emit listContactsUpdated(gestionContact->getContacts());

    mainWin->show();
}

void GestionnaireQObject::deleteContact(Contact* c)
{
    gestionContact->supprimeContact(c);
    emit listContactsUpdated(gestionContact->getContacts());
    emit contactDeleted();
}

void GestionnaireQObject::modifPrenom(Contact* c, string prenom)
{
    c->setPrenom(prenom);
    emit onEndModifContact();
}

void GestionnaireQObject::modifNom(Contact* c, string nom)
{
    c->setNom(nom);
    emit onEndModifContact();
}

void GestionnaireQObject::modifEntreprise(Contact* c, string entreprise)
{
    c->setEntreprise(entreprise);
    emit onEndModifContact();
}

void GestionnaireQObject::modifTelephone(Contact* c, string telephone)
{
    c->setTelephone(telephone);
    emit onEndModifContact();
}

void GestionnaireQObject::modifMail(Contact* c, string mail)
{
    c->setMail(mail);
    emit onEndModifContact();
}

void GestionnaireQObject::modifPhoto(Contact* c, string photo)
{
    c->setUriPhoto(photo);
    emit onEndModifContact();
}

void GestionnaireQObject::createContact(string nom, string prenom, string entreprise, string tel, string mail, string photo)
{
    Contact* c = gestionContact->creeContact(nom, prenom, entreprise, tel, mail, photo);
    emit contactCreated(nom, prenom, entreprise, tel, mail, photo, c->getDateCreation().toString(), c->getDateDerniereModification().toString());
    emit listContactsUpdated(gestionContact->getContacts());
    emit onContactCreated(c);
}

void GestionnaireQObject::createContact(string nom, string prenom, string entreprise, string tel, string mail, string photo, string dateCreation, string dateModification)
{
    Contact* c = gestionContact->creeContact(nom, prenom, entreprise, tel, mail, photo, dateCreation, dateModification);
    emit listContactsUpdated(gestionContact->getContacts());
    emit onContactCreated(c);
}

void GestionnaireQObject::editInteractionDate(Interaction* i, QDate d)
{
    string dateString = d.toString("dd/MM/yyyy").toStdString();
    if(dateString != i->getDate().toString())
    {
        i->setDate(Date(dateString));
        emit onInteractionEdited();
    }
}

void GestionnaireQObject::editInteractionResume(Interaction* i, QString s)
{
    i->setResume(s.toStdString());
    emit onInteractionEdited();
}

void GestionnaireQObject::ajoutInteraction(Contact* c, QString s)
{
    gestionContact->ajoutInteraction(c, s.toStdString());
    emit onInteractionEdited();
}

void GestionnaireQObject::ajoutInteraction(Contact* c, Interaction* i)
{
    gestionContact->ajoutInteraction(c, i);
    emit onInteractionEdited();
}

GestionnaireQObject::~GestionnaireQObject()
{
    delete gestionContact;
    delete dbManager;
    delete mainWin;
}
