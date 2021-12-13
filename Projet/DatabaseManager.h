/**
 * \file DatabaseManager.h
 * \class DatabaseManager DatabaseManager.h
 * \brief Gestionnaire de la base de donnees: lis, modifie et insere des donnees persistentes
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include "Contact.h"
#include "Interaction.h"

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    std::string getDateDerniereSuppression();
    void loadDatas();

private:
    QSqlDatabase db;
    std::map<Contact*, int> contactsIds;            //lien entre les instances de contacts et leur identifiant dans la base de donnees
    std::map<Interaction*, int> interactionsIds;    //lien entre les instances d'interactions et leur identifiant dans la base de donnees
    std::map<int, Interaction*> idsInteraction;     //lien entre les identifiants d'interactions dans la base de donnees et l'instance dans le logiciel
    std::map<Todo*, int> todosIds;                  //lien entre les instances de todos et leurs identifants dans la base de donnees

    void createBDDModel();
    void init();

signals:
     void loadContact(int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string);
     void loadAndCreateInteraction(int, Contact*, std::string, std::string);
     void loadInteraction(Interaction*, Contact*);
     void loadTodo(int, Interaction*, std::string, std::string, bool);

private slots:
    void createContact(Contact*, std::string, std::string);
    void contactLoaded(int, Contact*);
    void updateContactNom(Contact*, std::string);
    void updateContactPrenom(Contact*, std::string);
    void updateContactEntreprise(Contact*, std::string);
    void updateContactTelephone(Contact*, std::string);
    void updateContactMail(Contact*, std::string);
    void updateContactPhoto(Contact*, std::string);
    void updateContactDateModif(Contact*, std::string);
    void updateDateDerniereSuppression(std::string);
    void deleteContact(Contact*);
    void interactionLoaded(int, Interaction*);
    void todoLoaded(int, Todo*);
    void updateInteractionDate(Interaction*, std::string);
    void updateInteractionResume(Interaction*, std::string);
    void createInteraction(Interaction*, Contact*, std::string);
    void addExistingInteraction(Interaction*, Contact*);
    void createTodos(Interaction*, std::list<Todo*>);
    void deleteTodos(Interaction*);
    void deleteAll();
    void setTodoEffectue(Todo*,bool);
};

#endif // DATABASEMANAGER_H
