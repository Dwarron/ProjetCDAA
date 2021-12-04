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

/**
 *  \brief Constructeur standard
 *
 *  Constructeur standard de la classe GestionnaireQObject.
 *  Effectue les connexions signaux/slots
 *
 *  \param parent : fenetre parent
 */
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
    connect(dbManager, SIGNAL(loadTodo(int,Interaction*,std::string,std::string,bool)), this, SLOT(loadTodo(int,Interaction*,std::string,std::string,bool)));
    connect(this, SIGNAL(todoLoaded(int,Todo*)), dbManager, SLOT(todoLoaded(int,Todo*)));

    dbManager->loadDatas();

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
            this, SIGNAL(contactCreated(std::string,std::string,std::string,std::string,std::string,std::string)));
    connect(this, SIGNAL(contactCreated(std::string,std::string,std::string,std::string,std::string,std::string)),
            this, SLOT(createContact(std::string,std::string,std::string,std::string,std::string,std::string)));
    connect(this, SIGNAL(contactCreated(std::string,std::string,std::string,std::string,std::string,std::string,Date,Date)),
            this, SLOT(createContact(std::string,std::string,std::string,std::string,std::string,std::string,Date,Date)));
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

    connect(mainWin, SIGNAL(todoSetEffectue(Todo*,bool)), this, SLOT(setTodoEffectue(Todo*,bool)));
    connect(mainWin, SIGNAL(todoSetEffectue(Todo*,bool)), dbManager, SLOT(setTodoEffectue(Todo*,bool)));

    connect(this, SIGNAL(onTodoEdited()), mainWin, SIGNAL(onTodoEdited()));

    connect(mainWin, SIGNAL(exportJSON(QString)), this, SLOT(exportJSON(QString)));
    connect(mainWin, SIGNAL(importJSON(QString)), this, SLOT(importJSON(QString)));

    connect(this, SIGNAL(onLoadJSON()), this, SLOT(clearData()));
    connect(this, SIGNAL(onLoadJSON()), dbManager, SLOT(deleteAll()));

    mainWin->show();
}

/**
 *  \brief Suppression de la fiche d'un contact
 *
 *  Slot pour supprimer la fiche d'un contact
 *
 *  \param c : le contact
 */
void GestionnaireQObject::deleteContact(Contact* c)
{
    gestionContact->supprimeContact(c);
    emit listContactsUpdated(gestionContact->getContacts());
    emit contactDeleted(gestionContact->getDateDerniereSuppression().toString());
}

/**
 *  \brief Modification du prenom d'un contact
 *
 *  Slot pour modifier le prenom d'un contact
 *
 *  \param c : le contact
 *  \param prenom : le nouveau prenom
 */
void GestionnaireQObject::modifPrenom(Contact* c, string prenom)
{
    string oldPrenom = c->getPrenom();
    c->setPrenom(prenom);
    emit onEndModifContact(c, c->getDateDerniereModification().toString());

    ajoutInteraction(c, QString::fromStdString("modification du prenom (" + oldPrenom + " -> " + prenom + ")"));
}

/**
 *  \brief Modification du nom d'un contact
 *
 *  Slot pour modifier le nom d'un contact
 *
 *  \param c : le contact
 *  \param nom : le nouveau nom
 */
void GestionnaireQObject::modifNom(Contact* c, string nom)
{
    string oldNom = c->getNom();
    c->setNom(nom);
    emit onEndModifContact(c, c->getDateDerniereModification().toString());

    ajoutInteraction(c, QString::fromStdString("modification du nom (" + oldNom + " -> " + nom + ")"));
}

/**
 *  \brief Modification de l'entreprise d'un contact
 *
 *  Slot pour modifier l'entreprise d'un contact
 *
 *  \param c : le contact
 *  \param entreprise : la nouvelle entreprise
 */
void GestionnaireQObject::modifEntreprise(Contact* c, string entreprise)
{
    string oldEntreprise = c->getEntreprise();
    c->setEntreprise(entreprise);
    emit onEndModifContact(c, c->getDateDerniereModification().toString());

    ajoutInteraction(c, QString::fromStdString("modification de l'entreprise (" + oldEntreprise + " -> " + entreprise + ")"));
}

/**
 *  \brief Modification du telephone d'un contact
 *
 *  Slot pour modifier le telephone d'un contact
 *
 *  \param c : le contact
 *  \param telephone : le nouveau telephone
 */
void GestionnaireQObject::modifTelephone(Contact* c, string telephone)
{
    string oldTelephone = c->getTelephone();
    c->setTelephone(telephone);
    emit onEndModifContact(c, c->getDateDerniereModification().toString());

    ajoutInteraction(c, QString::fromStdString("modification du telephone (" + oldTelephone + " -> " + telephone + ")"));
}

/**
 *  \brief Modification du mail d'un contact
 *
 *  Slot pour modifier le mail d'un contact
 *
 *  \param c : le contact
 *  \param mail : le nouveau mail
 */
void GestionnaireQObject::modifMail(Contact* c, string mail)
{
    string oldMail = c->getMail();
    c->setMail(mail);
    emit onEndModifContact(c, c->getDateDerniereModification().toString());

    ajoutInteraction(c, QString::fromStdString("modification du mail (" + oldMail + " -> " + mail + ")"));
}

/**
 *  \brief Modification de la photo d'un contact
 *
 *  Slot pour modifier la photo d'un contact
 *
 *  \param c : le contact
 *  \param photo : le nouveau chemin vers la photo
 */
void GestionnaireQObject::modifPhoto(Contact* c, string photo)
{
    string oldPhoto = c->getUriPhoto();
    c->setUriPhoto(photo);
    emit onEndModifContact(c, c->getDateDerniereModification().toString());

    ajoutInteraction(c, QString::fromStdString("modification de la photo (" + oldPhoto + " -> " + photo + ")"));
}

/**
 *  \brief creation d'un contact
 *
 *  Slot pour creer la fiche d'un contact
 *
 *  \param nom : le nom du contact
 *  \param prenom : le prenom du contact
 *  \param entreprise : l'entreprise du contact
 *  \param tel : le telephone du contact
 *  \param mail : le mail du contact
 *  \param photo : le chemin vers la photo du contact
 */
void GestionnaireQObject::createContact(string nom, string prenom, string entreprise, string tel, string mail, string photo)
{
    createContact(nom, prenom, entreprise, tel, mail, photo, Date(), Date());
}

/**
 *  \brief creation d'un contact
 *
 *  Slot pour creer la fiche d'un contact
 *
 *  \param nom : le nom du contact
 *  \param prenom : le prenom du contact
 *  \param entreprise : l'entreprise du contact
 *  \param tel : le telephone du contact
 *  \param mail : le mail du contact
 *  \param photo : le chemin vers la photo du contact
 *  \param dc : la date de creation de la fiche
 *  \param dm : la date de derniere modification de la fiche
 */
void GestionnaireQObject::createContact(string nom, string prenom, string entreprise, string tel, string mail, string photo, Date dc, Date dm)
{
    Contact* c = gestionContact->creeContact(nom, prenom, entreprise, tel, mail, photo, dc, dm);
    emit listContactsUpdated(gestionContact->getContacts());
    emit onContactCreated(c, c->getDateCreation().toString(), c->getDateDerniereModification().toString());
}

/**
 *  \brief Chargement de la fiche d'un contact
 *
 *  Slot pour charger la fiche d'un contact
 *
 *  \param id : l'identifiant de la fiche dans la base de donnees
 *  \param nom : le nom du contact
 *  \param prenom : le prenom du contact
 *  \param entreprise : l'entreprise du contact
 *  \param tel : le telephone du contact
 *  \param mail : le mail du contact
 *  \param photo : le chemin vers la photo du contact
 *  \param dateCreation : la date de creation de la fiche
 *  \param dateModification : la date de derniere modification de la fiche
 */
void GestionnaireQObject::loadContact(int id, string nom, string prenom, string entreprise, string tel, string mail, string photo, string dateCreation, string dateModification)
{
    Contact* c = gestionContact->creeContact(nom, prenom, entreprise, tel, mail, photo, dateCreation, dateModification);
    emit contactLoaded(id, c);
}

/**
 *  \brief Chargement d'un interaction
 *
 *  Slot pour charger une interaction
 *
 *  \param id : l'identification de l'interaction dans la base de donnees
 *  \param c : le contact avec lequel s'est produit l'interaction
 *  \param date : la date de l'interaction
 *  \param resume : le resume de l'interaction
 */
void GestionnaireQObject::loadAndCreateInteraction(int id, Contact* c, string date, string resume)
{
    Interaction* i = gestionContact->ajoutInteraction(c, Date(date), resume);
    emit interactionLoaded(id, i);
}

/**
 *  \brief Chargement d'un interaction
 *
 *  Slot pour charger une interaction
 *
 *  \param i : l'interaction
 *  \param c : le contact (supplementaire) avec lequel s'est produit l'interaction
 */
void GestionnaireQObject::loadInteraction(Interaction* i, Contact* c)
{
    gestionContact->ajoutInteraction(c, i);
}

/**
 *  \brief Chargement d'un todo
 *
 *  Slot pour charger un todo dans une interaction
 *
 *  \param id : l'id du todo
 *  \param i : l'interaction dans laquelle se situe le contact
 *  \param date : la date du todo
 *  \param contenu : le contenu du todo
 *  \param effectue : si le todo a deja ete effectue ou non
 */
void GestionnaireQObject::loadTodo(int id, Interaction* i, string date, string contenu, bool effectue)
{
    Todo* t = gestionContact->ajoutTodo(i, Date(date), contenu, effectue);
    emit todoLoaded(id, t);
}

/**
 *  \brief Modification de la date d'une interaction
 *
 *  Slot pour modifier la date d'une interaction
 *
 *  \param i : l'interaction
 *  \param d : la nouvelle date
 */
void GestionnaireQObject::editInteractionDate(Interaction* i, QDate d)
{
    string dateString = d.toString("dd/MM/yyyy").toStdString();
    if(dateString != i->getDate().toString())
    {
        i->setDate(Date(dateString));
        emit onInteractionModifDate(i, d.toString("dd/MM/yyyy").toStdString());
    }
}

/**
 *  \brief Modification du resume d'une interaction
 *
 *  Slot pour modifier le resume d'une interaction
 *
 *  \param i : l'interaction
 *  \param s : le nouveau resume
 */
void GestionnaireQObject::editInteractionResume(Interaction* i, QString s)
{
    i->setResume(s.toStdString());
    i->viderTodos();
    emit onDeleteTodos(i);

    gestionContact->creerTodos(i);

    emit onInteractionModifResume(i, s.toStdString());
    emit onCreateTodos(i, i->getTodos());
}

/**
 *  \brief Ajout d' une interaction
 *
 *  Slot pour ajouter une nouvelle interaction
 *
 *  \param c : le contact avec lequel s'est produit l'interaction
 *  \param s : le resume de l'interaction
 */
void GestionnaireQObject::ajoutInteraction(Contact* c, QString s)
{
    ajoutInteraction(c, Date(), s);
}

/**
 *  \brief Ajout d'une interaction
 *
 *  Slot pour ajouter une nouvelle interaction
 *
 *  \param c : le contact avec lequel s'est produit l'interaction
 *  \param d : la date de l'interaction
 *  \param s : le resume de l'interaction
 *  \param createTodo : les todos doivent-ils etre generes ?
 */
Interaction* GestionnaireQObject::ajoutInteraction(Contact* c, Date d, QString s, bool createTodo)
{
    Interaction* i = gestionContact->ajoutInteraction(c, d, s.toStdString());

    if(createTodo)
        gestionContact->creerTodos(i);

    emit onCreateInteraction(i, c, d.toString());

    if(createTodo)
        emit onCreateTodos(i, i->getTodos());

    return i;
}

/**
 *  \brief Ajout d'une interaction
 *
 *  Slot pour ajouter une interaction existante a un nouveau contact
 *
 *  \param c : le contact (supplementaire) avec lequel s'est produit l'interaction
 *  \param i : l'interaction
 */
void GestionnaireQObject::ajoutInteraction(Contact* c, Interaction* i)
{
    gestionContact->ajoutInteraction(c, i);
    emit onAddExistingInteraction(i, c);
}

/**
 *  \brief Modification de l'etat effectue d'un todo
 *
 *  Slot pour changer l'etat effectue ou non d'un todo
 *
 *  \param t : le todo
 *  \param e : l'etat
 */
void GestionnaireQObject::setTodoEffectue(Todo* t, bool e)
{
    t->setEffectue(e);

    emit onTodoEdited();
}

/**
 *  \brief Export des donnees en format JSON
 *
 *  Slot pour exporter toutes les donnees en format JSON
 *
 *  \param filePath : la chemin ou enregistrer le fichier avec les donnees
 */
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

        QJsonArray infosArray;
        QJsonObject infosObj;
        infosObj.insert("dernierSuppression", QString::fromStdString(gestionContact->getDateDerniereSuppression().toString()));
        infosArray.append(infosObj);

        baseArray.append(contactsArray);
        baseArray.append(interactionsArray);
        baseArray.append(infosArray);
        doc.setArray(baseArray);

        file.write(doc.toJson());
        file.close();
    }
    else
    {
        throw runtime_error("Unable to open JSON file");
    }
}

/**
 *  \brief Importation de donnees sous format JSON
 *
 *  Slot pour importer des donnees en format JSON
 *
 *  \param filePath : la chemin du fichier ou lire les donnees
 */
void GestionnaireQObject::importJSON(QString filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(bytes);
        QJsonArray baseArray = doc.array();
        QJsonArray contactsArray = baseArray.takeAt(0).toArray();
        QJsonArray interactionsArray = baseArray.takeAt(0).toArray();
        QJsonArray infosArray = baseArray.takeAt(0).toArray();

        emit onLoadJSON();


        for(auto it = contactsArray.begin(); it != contactsArray.end(); it++)
        {
            QJsonObject contactObj = (*it).toObject();
            emit contactCreated(contactObj["nom"].toString().toStdString(), contactObj["prenom"].toString().toStdString(),
                    contactObj["entreprise"].toString().toStdString(), contactObj["tel"].toString().toStdString(),
                    contactObj["mail"].toString().toStdString(), contactObj["photo"].toString().toStdString(),
                    Date(contactObj["dateCreation"].toString().toStdString()), Date(contactObj["dateModification"].toString().toStdString()));
        }

        map<int, list<Contact*>> interactionsToContacts;

        list<Contact*> contacts = gestionContact->getContacts();
        auto cJson = contactsArray.begin();
        for(auto c = contacts.begin(); c != contacts.end(); c++, cJson++)
        {
            QJsonArray interactionsContactToArray = (*cJson).toObject()["interactionsIds"].toArray();
            for(auto i = interactionsContactToArray.begin(); i != interactionsContactToArray.end(); i++)
            {
                int interactionId = (*i).toInt();
                interactionsToContacts[interactionId].push_back(*c);
            }
        }

        for(auto it = interactionsArray.begin(); it != interactionsArray.end(); it++)
        {
            QJsonObject interactionObj = (*it).toObject();
            int indice = interactionObj["id"].toInt();
            Interaction* i = ajoutInteraction(*interactionsToContacts[indice].begin(), Date(interactionObj["date"].toString().toStdString()),
                    interactionObj["resume"].toString(), false);

            QJsonArray todosArray = interactionObj["todos"].toArray();
            for(auto t = todosArray.begin(); t != todosArray.end(); t++)
            {
                QJsonObject todoObj = (*t).toObject();
                i->ajoutTodo(new Todo(todoObj["contenu"].toString().toStdString(), Date(todoObj["echeance"].toString().toStdString()),
                        todoObj["effectue"].toBool()));
            }
            emit onCreateTodos(i, i->getTodos());

            auto c = interactionsToContacts[indice].begin();
            c++;
            for(; c != interactionsToContacts[indice].end(); c++)
            {
                ajoutInteraction(*c, i);
            }
        }

        string date = infosArray.begin()->toObject()["dernierSuppression"].toString().toStdString();
        gestionContact->setDateDerniereSuppression(Date(date));
        emit contactDeleted(date);
    }
    else
    {
        throw runtime_error("Unable to open JSON file");
    }
}

/**
 *  \brief Suppression des donnees
 *
 *  Slot pour supprimer les donnees stockees
 */
void GestionnaireQObject::clearData()
{
    delete gestionContact;
    gestionContact = new GestionContact(Date());
}

/**
 *  \brief Destructeur de GestionnaireQObject
 *
 *  Supprime les donnees en memoire (gestionContact et le manager de la base de donnees) et les fenetres
 */
GestionnaireQObject::~GestionnaireQObject()
{
    delete gestionContact;
    delete dbManager;
    delete mainWin;
}
