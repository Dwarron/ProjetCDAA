/**
 * \file GestionnaireQObject.cpp
 * \class GestionnaireQObject GestionnaireQObject.h
 * \brief QObject permettant le lien entre le cote affichage et le cote gestion interne
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QDate>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include "GestionnaireQObject.h"
#include "JSONSerializer.h"

using namespace std;

GestionnaireQObject::GestionnaireQObject(QObject *parent) : QObject(parent)
{
    dbManager = new DatabaseManager();
    string dateDerniereSuppression = dbManager->getDateDerniereSuppression();
    gestionContact = new GestionContact(Date(dateDerniereSuppression));

    connect(dbManager, SIGNAL(loadContact(int,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string)),
            this, SLOT(loadContact(int,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string)));
    connect(this, SIGNAL(contactLoaded(int,Contact*)), dbManager, SLOT(contactLoaded(int,Contact*)));
    connect(dbManager, SIGNAL(loadAndCreateInteraction(int,Contact*,std::string,std::string)), this, SLOT(loadAndCreateInteraction(int,Contact*,std::string,std::string)));
    connect(this, SIGNAL(interactionLoaded(int,Interaction*)), dbManager, SLOT(interactionLoaded(int,Interaction*)));
    connect(dbManager, SIGNAL(loadInteraction(Interaction*,Contact*)), this, SLOT(loadInteraction(Interaction*,Contact*)));
    connect(dbManager, SIGNAL(loadTodo(Interaction*,std::string,std::string,bool)), this, SLOT(loadTodo(Interaction*,std::string,std::string,bool)));

    dbManager->loadAllContacts();

    mainWin = new MainWindow(gestionContact->getDateDerniereSuppression().toString(), gestionContact->getContacts());

    connect(mainWin, SIGNAL(contactDeleted(Contact*)), this, SLOT(deleteContact(Contact*)));
    connect(mainWin, SIGNAL(contactDeleted(Contact*)), dbManager, SLOT(deleteContact(Contact*)));

    connect(mainWin, SIGNAL(prenomModified(Contact*,std::string)), this, SLOT(modifPrenom(Contact*,std::string)));
    connect(mainWin, SIGNAL(prenomModified(Contact*,std::string)), dbManager, SLOT(updateContactPrenom(Contact*,std::string)));

    connect(mainWin, SIGNAL(nomModified(Contact*,std::string)), this, SLOT(modifNom(Contact*,std::string)));
    connect(mainWin, SIGNAL(nomModified(Contact*,std::string)), dbManager, SLOT(updateContactNom(Contact*,std::string)));

    connect(mainWin, SIGNAL(entrepriseModified(Contact*,std::string)), this, SLOT(modifEntreprise(Contact*,std::string)));
    connect(mainWin, SIGNAL(entrepriseModified(Contact*,std::string)), dbManager, SLOT(updateContactEntreprise(Contact*,std::string)));

    connect(mainWin, SIGNAL(mailModified(Contact*,std::string)), this, SLOT(modifMail(Contact*,std::string)));
    connect(mainWin, SIGNAL(mailModified(Contact*,std::string)), dbManager, SLOT(updateContactMail(Contact*,std::string)));

    connect(mainWin, SIGNAL(telephoneModified(Contact*,std::string)), this, SLOT(modifTelephone(Contact*,std::string)));
    connect(mainWin, SIGNAL(telephoneModified(Contact*,std::string)), dbManager, SLOT(updateContactTelephone(Contact*,std::string)));

    connect(mainWin, SIGNAL(photoModified(Contact*,std::string)), this, SLOT(modifPhoto(Contact*,std::string)));
    connect(mainWin, SIGNAL(photoModified(Contact*,std::string)), dbManager, SLOT(updateContactPhoto(Contact*,std::string)));

    connect(mainWin, SIGNAL(contactCreated(std::string,std::string,std::string,std::string,std::string,std::string)),
            this, SLOT(createContact(std::string,std::string,std::string,std::string,std::string,std::string)));

    connect(mainWin, SIGNAL(interactionDateEdited(Interaction*,QDate)), this, SLOT(editInteractionDate(Interaction*,QDate)));

    connect(mainWin, SIGNAL(interactionResumeEdited(Interaction*,QString)), this, SLOT(editInteractionResume(Interaction*,QString)));

    connect(mainWin, SIGNAL(ajoutInteraction(Contact*,QString)), this, SLOT(ajoutInteraction(Contact*,QString)));
    connect(mainWin, SIGNAL(ajoutInteraction(Contact*,Interaction*)), this, SLOT(ajoutInteraction(Contact*,Interaction*)));

    connect(this, SIGNAL(listContactsUpdated(std::list<Contact*>)), mainWin, SIGNAL(listContactsUpdated(std::list<Contact*>)));

    connect(this, SIGNAL(contactDeleted(std::string)), mainWin, SLOT(updateDateDerniereSuppression(std::string)));
    connect(this, SIGNAL(contactDeleted(std::string)), dbManager, SLOT(updateDateDerniereSuppression(std::string)));
    connect(this, SIGNAL(contactDeleted(std::string)), mainWin, SLOT(selectContact()));

    connect(this, SIGNAL(onContactCreated(Contact*,std::string,std::string)), mainWin, SLOT(selectContact(Contact*)));
    connect(this, SIGNAL(onContactCreated(Contact*,std::string,std::string)), dbManager, SLOT(createContact(Contact*,std::string,std::string)));

    connect(this, SIGNAL(onInteractionModifResume(Interaction*,std::string)), this, SIGNAL(onInteractionEdited()));
    connect(this, SIGNAL(onInteractionModifResume(Interaction*,std::string)), dbManager, SLOT(updateInteractionResume(Interaction*,std::string)));

    connect(this, SIGNAL(onInteractionModifDate(Interaction*,std::string)), this, SIGNAL(onInteractionEdited()));
    connect(this, SIGNAL(onInteractionModifDate(Interaction*,std::string)), dbManager, SLOT(updateInteractionDate(Interaction*,std::string)));
    connect(this, SIGNAL(onInteractionEdited()), mainWin, SIGNAL(onInteractionEdited()));

    connect(this, SIGNAL(onEndModifContact(Contact*,std::string)), mainWin, SIGNAL(onEndModifContact()));
    connect(this, SIGNAL(onEndModifContact(Contact*,std::string)), dbManager, SLOT(updateContactDateModif(Contact*,std::string)));

    connect(this, SIGNAL(onCreateInteraction(Interaction*,Contact*,std::string)), this, SIGNAL(onInteractionEdited()));
    connect(this, SIGNAL(onCreateInteraction(Interaction*,Contact*,std::string)), dbManager, SLOT(createInteraction(Interaction*,Contact*,std::string)));

    connect(this, SIGNAL(onAddExistingInteraction(Interaction*,Contact*)), this, SIGNAL(onInteractionEdited()));
    connect(this, SIGNAL(onAddExistingInteraction(Interaction*,Contact*)), dbManager, SLOT(addExistingInteraction(Interaction*,Contact*)));

    connect(this, SIGNAL(onCreateTodos(Interaction*,std::list<Todo*>)), dbManager, SLOT(createTodos(Interaction*,std::list<Todo*>)));
    connect(this, SIGNAL(onDeleteTodos(Interaction*)), dbManager, SLOT(deleteTodos(Interaction*)));

    connect(mainWin, SIGNAL(exportJSON(QString)), this, SLOT(exportJSON(QString)));
    connect(mainWin, SIGNAL(importJSON(QString)), this, SLOT(importJSON(QString)));

    connect(this, SIGNAL(onLoadJSON()), this, SLOT(clearData()));
    connect(this, SIGNAL(onLoadJSON()), dbManager, SLOT(deleteAll()));

    mainWin->show();
}

void GestionnaireQObject::deleteContact(Contact* c)
{
    gestionContact->supprimeContact(c);
    emit listContactsUpdated(gestionContact->getContacts());
    emit contactDeleted(gestionContact->getDateDerniereSuppression().toString());
}

void GestionnaireQObject::modifPrenom(Contact* c, string prenom)
{
    string oldPrenom = c->getPrenom();
    c->setPrenom(prenom);
    emit onEndModifContact(c, c->getDateDerniereModification().toString());

    ajoutInteraction(c, QString::fromStdString("modification du prenom (" + oldPrenom + " -> " + prenom + ")"));
}

void GestionnaireQObject::modifNom(Contact* c, string nom)
{
    string oldNom = c->getNom();
    c->setNom(nom);
    emit onEndModifContact(c, c->getDateDerniereModification().toString());

    ajoutInteraction(c, QString::fromStdString("modification du nom (" + oldNom + " -> " + nom + ")"));
}

void GestionnaireQObject::modifEntreprise(Contact* c, string entreprise)
{
    string oldEntreprise = c->getEntreprise();
    c->setEntreprise(entreprise);
    emit onEndModifContact(c, c->getDateDerniereModification().toString());

    ajoutInteraction(c, QString::fromStdString("modification de l'entreprise (" + oldEntreprise + " -> " + entreprise + ")"));
}

void GestionnaireQObject::modifTelephone(Contact* c, string telephone)
{
    string oldTelephone = c->getTelephone();
    c->setTelephone(telephone);
    emit onEndModifContact(c, c->getDateDerniereModification().toString());

    ajoutInteraction(c, QString::fromStdString("modification du telephone (" + oldTelephone + " -> " + telephone + ")"));
}

void GestionnaireQObject::modifMail(Contact* c, string mail)
{
    string oldMail = c->getMail();
    c->setMail(mail);
    emit onEndModifContact(c, c->getDateDerniereModification().toString());

    ajoutInteraction(c, QString::fromStdString("modification du mail (" + oldMail + " -> " + mail + ")"));
}

void GestionnaireQObject::modifPhoto(Contact* c, string photo)
{
    string oldPhoto = c->getUriPhoto();
    c->setUriPhoto(photo);
    emit onEndModifContact(c, c->getDateDerniereModification().toString());

    ajoutInteraction(c, QString::fromStdString("modification de la photo (" + oldPhoto + " -> " + photo + ")"));
}

void GestionnaireQObject::createContact(string nom, string prenom, string entreprise, string tel, string mail, string photo)
{
    Contact* c = gestionContact->creeContact(nom, prenom, entreprise, tel, mail, photo);
    emit listContactsUpdated(gestionContact->getContacts());
    emit onContactCreated(c, c->getDateCreation().toString(), c->getDateDerniereModification().toString());
}

void GestionnaireQObject::loadContact(int id, string nom, string prenom, string entreprise, string tel, string mail, string photo, string dateCreation, string dateModification)
{
    Contact* c = gestionContact->creeContact(nom, prenom, entreprise, tel, mail, photo, dateCreation, dateModification);
    emit contactLoaded(id, c);
}

void GestionnaireQObject::loadAndCreateInteraction(int id, Contact* c, std::string date, std::string resume)
{
    Interaction* i = gestionContact->ajoutInteraction(c, Date(date), resume);
    emit interactionLoaded(id, i);
}

void GestionnaireQObject::loadInteraction(Interaction* i, Contact* c)
{
    gestionContact->ajoutInteraction(c, i);
}

void GestionnaireQObject::loadTodo(Interaction* i, std::string date, std::string contenue, bool effectue)
{
    gestionContact->ajoutTodo(i, Date(date), contenue, effectue);
}

void GestionnaireQObject::editInteractionDate(Interaction* i, QDate d)
{
    string dateString = d.toString("dd/MM/yyyy").toStdString();
    if(dateString != i->getDate().toString())
    {
        i->setDate(Date(dateString));
        emit onInteractionModifDate(i, d.toString("dd/MM/yyyy").toStdString());
    }
}

void GestionnaireQObject::editInteractionResume(Interaction* i, QString s)
{
    i->setResume(s.toStdString());
    i->viderTodos();
    emit onDeleteTodos(i);

    i->creerTodos();

    emit onInteractionModifResume(i, s.toStdString());
    emit onCreateTodos(i, i->getTodos());
}

void GestionnaireQObject::ajoutInteraction(Contact* c, QString s)
{
    Date d = Date();
    Interaction* i = gestionContact->ajoutInteraction(c, d, s.toStdString());
    i->creerTodos();

    emit onCreateInteraction(i, c, d.toString());
    emit onCreateTodos(i, i->getTodos());
}

void GestionnaireQObject::ajoutInteraction(Contact* c, Interaction* i)
{
    gestionContact->ajoutInteraction(c, i);
    emit onAddExistingInteraction(i, c);
}

void GestionnaireQObject::exportJSON(QString filePath)
{
    QFile file(filePath);
    if(file.open(QIODevice::WriteOnly))
    {
        QJsonDocument doc;
        QJsonArray baseArray;
        QJsonArray contactsArray;
        QJsonArray interactionsArray;
        list<Interaction*> interactions = gestionContact->getAllInteractions();
        map<Interaction*, int> interactionsIds;

        int id = 0;
        for(auto it = interactions.begin(); it != interactions.end(); it++)
        {
            interactionsIds[*it] = id;
            QJsonObject interactionJson = JSONSerializer::serialize(*it);
            interactionJson.insert("id", id);
            interactionsArray.append(interactionJson);
            id++;
        }

        for(auto c = gestionContact->getContacts().begin(); c != gestionContact->getContacts().end(); c++)
        {
            QJsonObject contactJson = JSONSerializer::serialize(*c);

            QJsonArray contactInteractionArray;
            for(auto i = (*c)->getInteractions().begin(); i != (*c)->getInteractions().end(); i++)
            {
                contactInteractionArray.append(QJsonValue::fromVariant(QVariant(interactionsIds[*i])));
            }

            contactJson.insert("interactionsIds", contactInteractionArray);
            contactsArray.append(contactJson);
        }

        baseArray.append(contactsArray);
        baseArray.append(interactionsArray);
        doc.setArray(baseArray);

        file.write(doc.toJson());
        file.close();
    }
    else
    {
        throw runtime_error("Unable to open JSON file");
    }
}

void GestionnaireQObject::importJSON(QString filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(bytes);
        QJsonArray baseArray = doc.array();
        QJsonArray contactsArray = baseArray.takeAt(0).toArray();
        QJsonArray interactionsArray = baseArray.takeAt(1).toArray();

        emit onLoadJSON();

        //TODO READ DATAS
    }
    else
    {
        throw runtime_error("Unable to open JSON file");
    }
}

void GestionnaireQObject::clearData()
{
    delete gestionContact;
    gestionContact = new GestionContact(Date());
}

GestionnaireQObject::~GestionnaireQObject()
{
    delete gestionContact;
    delete dbManager;
    delete mainWin;
}
