#include "GestionnaireQObject.h"

using namespace std;

GestionnaireQObject::GestionnaireQObject(QObject *parent) : QObject(parent)
{
    gestionContact = new GestionContact();
    Contact* contact1 = gestionContact->creeContact("Duportail", "Damien", "Unirex compagnie", "0673332557", "damien.duportail@btc.fr", "/home/Directory/Document/Image/duportail.jpg");
    Contact* contact2 = gestionContact->creeContact("Delafenetre", "Jean-Pierre", "Btc compagnie", "0607487537", "", "/home/Directory/Document/Photo/dlf.jpg");
    contact1->setEntreprise("Pancakesquad NFT");

    Interaction* i = gestionContact->ajoutInteraction(contact1, "rdv tel ras\n@todo rappeler 1 le @date 10/11/2021\n@todo rappeler 2 le @date 22/10/2021");

    i->setResume("en fait RAS, @todo rappeler seulement @date 25/10/2021"); //modification d'une interaction

    gestionContact->ajoutInteraction(contact2, i);        //possibilite d'ajouter une meme interaction a deux contacts differents
    gestionContact->ajoutInteraction(contact1, "Investir en bourse\n @todo acheter btc le @date 25/12/2021\n @todo acheter eth le @date 28/12/2021");

    mainWin = new MainWindow(gestionContact, nullptr);

    connect(mainWin, SIGNAL(contactDeleted(Contact*)), this, SLOT(deleteContact(Contact*)));
    connect(mainWin, SIGNAL(prenomModified(Contact*,std::string)), this, SLOT(modifPrenom(Contact*,std::string)));
    connect(mainWin, SIGNAL(nomModified(Contact*,std::string)), this, SLOT(modifNom(Contact*,std::string)));
    connect(mainWin, SIGNAL(entrepriseModified(Contact*,std::string)), this, SLOT(modifEntreprise(Contact*,std::string)));
    connect(mainWin, SIGNAL(mailModified(Contact*,std::string)), this, SLOT(modifMail(Contact*,std::string)));
    connect(mainWin, SIGNAL(telephoneModified(Contact*,std::string)), this, SLOT(modifTelephone(Contact*,std::string)));
    connect(mainWin, SIGNAL(photoModified(Contact*,std::string)), this, SLOT(modifPhoto(Contact*,std::string)));
    connect(mainWin, SIGNAL(contactCreated(std::string,std::string,std::string,std::string,std::string,std::string)),
            this, SLOT(createContact(std::string,std::string,std::string,std::string,std::string,std::string)));

    connect(this, SIGNAL(listContactsUpdated()), mainWin, SLOT(updateListContacts()));
    connect(this, SIGNAL(onContactCreated(Contact*)), mainWin, SLOT(onContactCreated(Contact*)));

    mainWin->show();
}

void GestionnaireQObject::deleteContact(Contact* c)
{
    gestionContact->supprimeContact(c);
    emit listContactsUpdated();
}

void GestionnaireQObject::modifPrenom(Contact* c, string prenom)
{
    c->setPrenom(prenom);
}

void GestionnaireQObject::modifNom(Contact* c, string nom)
{
    c->setNom(nom);
}

void GestionnaireQObject::modifEntreprise(Contact* c, string entreprise)
{
    c->setEntreprise(entreprise);
}

void GestionnaireQObject::modifTelephone(Contact* c, string telephone)
{
    c->setTelephone(telephone);
}

void GestionnaireQObject::modifMail(Contact* c, string mail)
{
    c->setMail(mail);
}

void GestionnaireQObject::modifPhoto(Contact* c, string photo)
{
    c->setUriPhoto(photo);
}

void GestionnaireQObject::createContact(string nom, string prenom, string entreprise, string tel, string mail, string photo)
{
    Contact* c = gestionContact->creeContact(nom, prenom, entreprise, tel, mail, photo);
    emit listContactsUpdated();
    emit onContactCreated(c);
}


GestionnaireQObject::~GestionnaireQObject()
{
    delete gestionContact;
    delete mainWin;
}
