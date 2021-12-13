/**
 * \file DatabaseManager.cpp
 * \class DatabaseManager DatabaseManager.h
 * \brief Gestionnaire de la base de donnees: lis, modifie et insere des donnees persistentes
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QtSql/QSqlQuery>
#include <QDir>
#include <stdexcept>
#include <QSqlError>
#include <QtDebug>
#include "DatabaseManager.h"

using namespace std;

/**
 *  \brief Constructeur standard
 *
 *  Constructeur standard de la classe DatabaseManager
 *
 *  \param parent : classe parent
 *  \see init()
 */
DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{
    init();
}

/**
 *  \brief Initiation de la connexion a la base de donnees
 *
 *  Initie la connexion à la base de donnee et la cree si necessaire
 *
 *  \see createBDDModel()
 */
void DatabaseManager::init()
{
    contactsIds = map<Contact*, int>();

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QDir::currentPath()+ QDir::separator() + "base.sqlite");

    if(!db.open())
    {
        throw runtime_error("Unable to open database");
    }

    createBDDModel();
}

/**
 *  \brief Creation du model de la base de donnees
 *
 *  Cree le modele de la base de donnees, s'il a ete supprimee ou c'est la premiere fois qu'on utilise le logiciel
 *
 */
void DatabaseManager::createBDDModel()
{
    QFile model(QDir::currentPath()+ QDir::separator() + "model.sql");
    if(!model.open(QIODevice::ReadOnly))
    {
        throw runtime_error("Unable to open database file model");
    }

    QTextStream stream(&model);
    for (QString line = stream.readLine(); !line.isNull(); line = stream.readLine())
    {
        if(!line.startsWith("--") && line.length() > 3)
        {
            QSqlQuery query;
            if(!query.exec(line))
            {
                throw runtime_error("Unable to create bdd model : " + db.lastError().text().toStdString());
            }
        }
    }

    QSqlQuery query;

    if(!query.exec("SELECT Count(*) FROM Infos;"))
    {
        throw runtime_error("Unable to reading in created bdd model : " + db.lastError().text().toStdString());
    }
    else
    {
        query.next();
        QString count = query.value(0).toString();
        if(count == "0")
        {
            QSqlQuery queryDate;
            if(!queryDate.exec("INSERT INTO Infos VALUES('01/01/2021');"))  //insertion de la valeur par defaut de la date de derniere suppression
            {
                throw runtime_error("Unable to insert in created bdd model : " + db.lastError().text().toStdString());
            }
        }
    }
}


/**
 *  \brief Chargement des donnees
 *
 *  Lis tous les contacts stockes dans la base de donnees et demande leur creation dans le logiciel via des signaux
 *  Lis egalement les interactions
 *  Les todos seront lu pour chaque interaction lorsqu'elle aura ete creee
 */
void DatabaseManager::loadDatas()
{
    QSqlQuery queryContact;

    if(!queryContact.exec("SELECT * FROM Contact;"))
    {
       throw runtime_error("Unable to load contacts : " + db.lastError().text().toStdString());
    }
    else
    {
       while(queryContact.next())
       {
            const int id = queryContact.value(0).toInt();
            const string& nom = queryContact.value(1).toString().toStdString();
            const string& prenom = queryContact.value(2).toString().toStdString();
            const string& entreprise = queryContact.value(3).toString().toStdString();
            const string& telephone = queryContact.value(4).toString().toStdString();
            const string& mail = queryContact.value(5).toString().toStdString();
            const string& photo = queryContact.value(6).toString().toStdString();
            const string& dateCreation = queryContact.value(7).toString().toStdString();
            const string& dateModif = queryContact.value(8).toString().toStdString();

            emit loadContact(id, nom, prenom, entreprise, telephone, mail, photo, dateCreation, dateModif);
       }
    }

    map<int, Contact*> idsContacts;     //inversion de la correspondance contact->id pour obtenir les contacts a partir des id

    for(auto it = contactsIds.begin(); it != contactsIds.end(); it++)
         idsContacts[it->second] = it->first;

    QSqlQuery queryInteraction;
    if(!queryInteraction.exec("SELECT * FROM Interaction;"))
    {
       throw runtime_error("Unable to load interactions : " + db.lastError().text().toStdString());
    }
    else
    {
       while(queryInteraction.next())
       {
            const int interactionId = queryInteraction.value(0).toInt();
            const string date = queryInteraction.value(1).toString().toStdString();
            const string resume = queryInteraction.value(2).toString().toStdString();

            QSqlQuery queryContactsInteraction;
            queryContactsInteraction.prepare("SELECT ContactId FROM ContactsToInteractions WHERE InteractionId = :id;");
            queryContactsInteraction.bindValue(":id", interactionId);

            if(!queryContactsInteraction.exec())
            {
                throw runtime_error("Unable to load contacts from interaction : " + db.lastError().text().toStdString());
            }
            else
            {
                if(queryContactsInteraction.next())
                {
                    int contactId = queryContactsInteraction.value(0).toInt();
                    emit loadAndCreateInteraction(interactionId, idsContacts[contactId], date, resume);

                    while(queryContactsInteraction.next())
                    {
                        contactId = queryContactsInteraction.value(0).toInt();
                        emit loadInteraction(idsInteraction[interactionId], idsContacts[contactId]);
                    }
                }
            }
       }
    }
}

/**
 *  \brief Creation d'un nouveau contact
 *
 *  Slot pour l'insertion dans la base de donnees d'un nouveau contact
 *
 *  \param c : pointeur vers le nouveau contact
 *  \param dc : date de creation
 *  \param dm :  date de derniere modification
 */
void DatabaseManager::createContact(Contact* c, string dc, string dm)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Contact (nom, prenom, entreprise, telephone, mail, uriPhoto, dateCreation, dateModification) "
                  "VALUES (:nom, :prenom, :entreprise, :tel, :mail, :photo, :dateCreation, :dateModification);");
    query.bindValue(":nom", QVariant(QString::fromStdString(c->getNom())));
    query.bindValue(":prenom", QVariant(QString::fromStdString(c->getPrenom())));
    query.bindValue(":entreprise", QVariant(QString::fromStdString(c->getEntreprise())));
    query.bindValue(":tel", QVariant(QString::fromStdString(c->getTelephone())));
    query.bindValue(":mail", QVariant(QString::fromStdString(c->getMail())));
    query.bindValue(":photo", QVariant(QString::fromStdString(c->getUriPhoto())));
    query.bindValue(":dateCreation", QVariant(QString::fromStdString(dc)));
    query.bindValue(":dateModification", QVariant(QString::fromStdString(dm)));

    if(!query.exec())
    {
       throw runtime_error("Error inserting contact in bdd : " + db.lastError().text().toStdString());
    }
    else
    {
        QSqlQuery queryId;
        if(!queryId.exec("SELECT MAX(Id) FROM Contact;"))
        {
            throw runtime_error("Error reading inserted contact id in bdd : " + db.lastError().text().toStdString());
        }
        else
        {
            queryId.next();
            int createdId = queryId.value(0).toInt();
            contactsIds[c] = createdId;
        }
    }
}

/**
 *  \brief Slot appele lorsqu'un contact a effectivement ete charger comme une instance dans le logiciel
 *
 *  \param id : identifiant dans la base de donnees
 *  \param c : pointeur vers le contact
 */
void DatabaseManager::contactLoaded(int id, Contact* c)
{
    contactsIds[c] = id;
}

/**
 *  \brief Slot appele lorsqu'une interaction a effectivement ete charger comme une instance dans le logiciel
 *
 *  Provoque la lectue des todos correspondant a cette interaction
 *
 *  \param id : identifiant dans la base de donnees
 *  \param i : pointeur vers l'interaction
 */
void DatabaseManager::interactionLoaded(int id, Interaction* i)
{
    idsInteraction[id] = i;
    interactionsIds[i] = id;

    QSqlQuery query;
    query.prepare("SELECT * FROM Todo WHERE InteractionId = :id;");
    query.bindValue(":id", QVariant(id));

    if(!query.exec())
    {
       throw runtime_error("Error reading todos in bdd : " + db.lastError().text().toStdString());
    }
    else
    {
        while(query.next())
        {
            const int id = query.value(0).toInt();
            const string& date = query.value(2).toString().toStdString();
            const string& contenu = query.value(3).toString().toStdString();
            const bool effectue = query.value(4).toInt();

            emit loadTodo(id, i, date, contenu, effectue);
        }
    }
}

/**
 *  \brief Creation des todos pour une interaction
 *
 *  Slot pour l'insertion dans la base de donnees des todos d'une nouvelle interaction
 *
 *  \param i : pointeur vers l'interaction
 *  \param todos : les todos a inserer
 */
void DatabaseManager::createTodos(Interaction* i, std::list<Todo*> todos)
{
    int interactionId = interactionsIds[i];
    for(auto it = todos.begin(); it != todos.end(); it++)
    {
        QSqlQuery query;
        query.prepare("INSERT INTO Todo (InteractionId, echeance, contenu, effectue) "
                      "VALUES (:id, :date, :contenu, :effectue);");
        query.bindValue(":id", QVariant(interactionId));
        query.bindValue(":date", QVariant(QString::fromStdString((*it)->getEcheance().toString())));
        query.bindValue(":contenu", QVariant(QString::fromStdString((*it)->getContenu())));
        query.bindValue(":effectue", QVariant((*it)->getEffectue()));

        if(!query.exec())
        {
            throw runtime_error("Error inserting todos in bdd : " + db.lastError().text().toStdString());
        }
        else
        {
            QSqlQuery queryId;
            if(!queryId.exec("SELECT MAX(Id) FROM Todo;"))
            {
                throw runtime_error("Error reading inserted todo id in bdd : " + db.lastError().text().toStdString());
            }
            else
            {
                queryId.next();
                int createdId = queryId.value(0).toInt();
                todosIds[*it] = createdId;
            }
        }
    }
}

/**
 *  \brief Slot appele lorsqu'un todo a effectivement ete charger comme une instance dans le logiciel
 *
 *  \param id : identifiant dans la base de donnees
 *  \param t : pointeur vers le todo
 */
void DatabaseManager::todoLoaded(int id, Todo* t)
{
    todosIds[t] = id;
}

/**
 *  \brief Suppression des todos pour une interaction
 *
 *  Slot pour la suppression dans la base de donnees des todos d'une interaction
 *
 *  \param i : pointeur vers l'interaction
 */
void DatabaseManager::deleteTodos(Interaction* i)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Todo WHERE InteractionId = :id;");
    query.bindValue(":id", interactionsIds[i]);

    if(!query.exec())
    {
        throw runtime_error("Error deleting todos in bdd : " + db.lastError().text().toStdString());
    }
}

/**
 *  \brief Lecture de la date de derniere suppression
 *
 *  Slot pour consulter la date de derniere suppression inscrite dans la base de donnees
 *
 *  \return la date de derniere suppression lue
 */
string DatabaseManager::getDateDerniereSuppression()
{
    QSqlQuery query;

    if(!query.exec("SELECT * FROM Infos;"))
    {
       throw runtime_error("Error reading infos in bdd : " + db.lastError().text().toStdString());
    }

    query.next();
    return query.value(0).toString().toStdString();
}

/**
 *  \brief Modification de la date de derniere suppression
 *
 *  Slot pour modifier la date de derniere suppression inscrite dans la base de donnees
 *
 *  \param d : la nouvelle date
 */
void DatabaseManager::updateDateDerniereSuppression(string d)
{
    QSqlQuery query;
    query.prepare("UPDATE Infos SET dateDerniereSuppression = :date;");
    query.bindValue(":date", QVariant(QString::fromStdString(d)));

    if(!query.exec())
    {
       throw runtime_error("Error updating infos in bdd : " + db.lastError().text().toStdString());
    }
}

/**
 *  \brief Modification du nom d'un contact
 *
 *  Slot pour modifier le nom d'un contact inscris dans la base de donnees
 *
 *  \param c : le contact
 *  \param nom : le nouveau nom
 */
void DatabaseManager::updateContactNom(Contact* c, string nom)
{
    QSqlQuery query;
    query.prepare("UPDATE Contact SET nom = :nom WHERE Id = :id;");
    query.bindValue(":nom", QVariant(QString::fromStdString(nom)));
    query.bindValue(":id", QVariant(contactsIds[c]));

    if(!query.exec())
    {
       throw runtime_error("Error updating contact in bdd : " + db.lastError().text().toStdString());
    }
}

/**
 *  \brief Modification du prenom d'un contact
 *
 *  Slot pour modifier le prenom d'un contact inscris dans la base de donnees
 *
 *  \param c : le contact
 *  \param nom : le nouveau prenom
 */
void DatabaseManager::updateContactPrenom(Contact* c, string prenom)
{
    QSqlQuery query;
    query.prepare("UPDATE Contact SET prenom = :prenom WHERE Id = :id;");
    query.bindValue(":prenom", QVariant(QString::fromStdString(prenom)));
    query.bindValue(":id", QVariant(contactsIds[c]));

    if(!query.exec())
    {
       throw runtime_error("Error updating contact in bdd : " + db.lastError().text().toStdString());
    }
}

/**
 *  \brief Modification de l'entreprise d'un contact
 *
 *  Slot pour modifier l'entreprise d'un contact inscrite dans la base de donnees
 *
 *  \param c : le contact
 *  \param entreprise : la nouvelle entreprise
 */
void DatabaseManager::updateContactEntreprise(Contact* c, string entreprise)
{
    QSqlQuery query;
    query.prepare("UPDATE Contact SET entreprise = :entreprise WHERE Id = :id;");
    query.bindValue(":entreprise", QVariant(QString::fromStdString(entreprise)));
    query.bindValue(":id", QVariant(contactsIds[c]));

    if(!query.exec())
    {
       throw runtime_error("Error updating contact in bdd : " + db.lastError().text().toStdString());
    }
}

/**
 *  \brief Modification du telephone d'un contact
 *
 *  Slot pour modifier le telephone d'un contact inscris dans la base de donnees
 *
 *  \param c : le contact
 *  \param tel : le nouveau telephone
 */
void DatabaseManager::updateContactTelephone(Contact* c, string tel)
{
    QSqlQuery query;
    query.prepare("UPDATE Contact SET telephone = :tel WHERE Id = :id;");
    query.bindValue(":tel", QVariant(QString::fromStdString(tel)));
    query.bindValue(":id", QVariant(contactsIds[c]));

    if(!query.exec())
    {
       throw runtime_error("Error updating contact in bdd : " + db.lastError().text().toStdString());
    }
}

/**
 *  \brief Modification du mail d'un contact
 *
 *  Slot pour modifier le mail d'un contact inscris dans la base de donnees
 *
 *  \param c : le contact
 *  \param mail : le nouveau mail
 */
void DatabaseManager::updateContactMail(Contact* c, string mail)
{
    QSqlQuery query;
    query.prepare("UPDATE Contact SET mail = :mail WHERE Id = :id;");
    query.bindValue(":mail", QVariant(QString::fromStdString(mail)));
    query.bindValue(":id", QVariant(contactsIds[c]));

    if(!query.exec())
    {
       throw runtime_error("Error updating contact in bdd : " + db.lastError().text().toStdString());
    }
}

/**
 *  \brief Modification de la photo d'un contact
 *
 *  Slot pour modifier la photo d'un contact inscrite dans la base de donnees
 *
 *  \param c : le contact
 *  \param photo : le nouveau chemin vers la photo
 */
void DatabaseManager::updateContactPhoto(Contact* c, string photo)
{
    QSqlQuery query;
    query.prepare("UPDATE Contact SET uriPhoto = :photo WHERE Id = :id;");
    query.bindValue(":photo", QVariant(QString::fromStdString(photo)));
    query.bindValue(":id", QVariant(contactsIds[c]));

    if(!query.exec())
    {
       throw runtime_error("Error updating contact in bdd : " + db.lastError().text().toStdString());
    }
}

/**
 *  \brief Modification de la date de derniere modification d'un contact
 *
 *  Slot pour modifier la date de derniere modification d'un contact inscrite dans la base de donnees
 *
 *  \param c : le contact
 *  \param date : la nouvelle date
 */
void DatabaseManager::updateContactDateModif(Contact* c, string date)
{
    QSqlQuery query;
    query.prepare("UPDATE Contact SET dateModification = :d WHERE Id = :id;");
    query.bindValue(":d", QVariant(QString::fromStdString(date)));
    query.bindValue(":id", QVariant(contactsIds[c]));

    if(!query.exec())
    {
       throw runtime_error("Error updating contact in bdd : " + db.lastError().text().toStdString());
    }
}

/**
 *  \brief Suppression de la fiche d'un contact
 *
 *  Slot pour supprimer la fiche d'un contact dans la base de donnees
 *
 *  \param c : le contact
 */
void DatabaseManager::deleteContact(Contact* c)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Contact WHERE Id = :id;");
    query.bindValue(":id", QVariant(contactsIds[c]));

    if(!query.exec())
    {
       throw runtime_error("Error deleting contact in bdd : " + db.lastError().text().toStdString());
    }
}

/**
 *  \brief Modification de la date d'une interaction
 *
 *  Slot pour modifier la date d'une interaction inscrite dans la base de donnees
 *
 *  \param c : le contact
 *  \param d : la nouvelle date
 */
void DatabaseManager::updateInteractionDate(Interaction* i, string d)
{
    QSqlQuery query;
    query.prepare("UPDATE Interaction SET date = :d WHERE Id = :id;");
    query.bindValue(":d", QVariant(QString::fromStdString(d)));
    query.bindValue(":id", QVariant(interactionsIds[i]));

    if(!query.exec())
    {
       throw runtime_error("Error updating interaction in bdd : " + db.lastError().text().toStdString());
    }
}

/**
 *  \brief Modification du resume d'une interaction
 *
 *  Slot pour modifier le resume d'une interaction inscrite dans la base de donnees
 *
 *  \param c : le contact
 *  \param r : le nouveau resume
 */
void DatabaseManager::updateInteractionResume(Interaction* i, string r)
{
    QSqlQuery query;
    query.prepare("UPDATE Interaction SET resume = :r WHERE Id = :id;");
    query.bindValue(":r", QVariant(QString::fromStdString(r)));
    query.bindValue(":id", QVariant(interactionsIds[i]));

    if(!query.exec())
    {
       throw runtime_error("Error updating interaction in bdd : " + db.lastError().text().toStdString());
    }
}

/**
 *  \brief Creation d'une nouvelle interaction
 *
 *  Slot pour la creation dans la base de donnees d'une nouvelle interaction
 *
 *  \param i : pointeur vers la nouvelle interaction
 *  \param c : pointeur vers le contact avec lequel a ete fais l'interaction
 *  \param date : date de l'interaction
 */
void DatabaseManager::createInteraction(Interaction* i, Contact* c, string date)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Interaction (date, resume) "
                  "VALUES (:date, :resume);");
    query.bindValue(":date", QVariant(QString::fromStdString(date)));
    query.bindValue(":resume", QVariant(QString::fromStdString(i->getResume())));

    if(!query.exec())
    {
       throw runtime_error("Error inserting interaction in bdd : " + db.lastError().text().toStdString());
    }
    else
    {
        QSqlQuery queryId;
        if(!queryId.exec("SELECT MAX(Id) FROM Interaction;"))
        {
            throw runtime_error("Error reading inserted interaction id in bdd : " + db.lastError().text().toStdString());
        }
        else
        {
            queryId.next();
            int createdId = queryId.value(0).toInt();
            interactionsIds[i] = createdId;
            idsInteraction[createdId] = i;

            addExistingInteraction(i, c);
        }
    }
}

/**
 *  \brief Ajout d'une interaction existante a un nouveau contact
 *
 *  Slot pour l'ajout d'une interaction existante a un nouveau contact
 *
 *  \param i : pointeur vers l'interaction
 *  \param c : pointeur vers le nouveau contact
 */
void DatabaseManager::addExistingInteraction(Interaction* i, Contact* c)
{
    QSqlQuery queryLinkContactInteraction;
    queryLinkContactInteraction.prepare("INSERT INTO ContactsToInteractions (ContactId, InteractionId) VALUES(:c, :i);");
    queryLinkContactInteraction.bindValue(":c", contactsIds[c]);
    queryLinkContactInteraction.bindValue(":i", interactionsIds[i]);

    if(!queryLinkContactInteraction.exec())
    {
        throw runtime_error("Error inserting contactsToInteractions in bdd : " + db.lastError().text().toStdString());
    }
}

/**
 *  \brief Modification de l'etat effectue d'un todo
 *
 *  Slot pour changer l'etat effectue ou non d'un todo dans la base de donnees
 *
 *  \param t : le todo
 *  \param e : l'etat
 */
void DatabaseManager::setTodoEffectue(Todo* t, bool e)
{
    QSqlQuery query;
    query.prepare("UPDATE Todo SET effectue = :etat WHERE Id = :id");
    query.bindValue(":etat", QVariant(e ? 1 : 0));
    query.bindValue(":id", todosIds[t]);

    if(!query.exec())
    {
        throw runtime_error("Error updating todos in bdd : " + db.lastError().text().toStdString());
    }
}

/**
 *  \brief Suppression de toute la base de donnees
 *
 *  Slot pour la suppression de toute la base de donnees
 */
void DatabaseManager::deleteAll()
{
    db.close();

    QFile file(QDir::currentPath()+ QDir::separator() + "base.sqlite");
    if(!file.remove())
    {
        throw runtime_error("Error deleting bdd file");
    }

    init();
}
