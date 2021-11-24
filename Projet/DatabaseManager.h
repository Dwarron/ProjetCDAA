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
    void loadAllContacts();

private:
    QSqlDatabase db;
    std::map<Contact*, int> contactsIds;
    std::map<Interaction*, int> interactionsIds;
    std::map<int, Interaction*> idsInteraction;

    void createBDDModel();
    void init();

signals:
     void loadContact(int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string);
     void loadAndCreateInteraction(int, Contact*, std::string, std::string);
     void loadInteraction(Interaction*, Contact*);
     void loadTodo(Interaction*, std::string, std::string, bool);

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
    void updateInteractionDate(Interaction*, std::string);
    void updateInteractionResume(Interaction*, std::string);
    void createInteraction(Interaction*, Contact*, std::string);
    void addExistingInteraction(Interaction*, Contact*);
    void createTodos(Interaction*, std::list<Todo*>);
    void deleteTodos(Interaction*);
    void deleteAll();
};

#endif // DATABASEMANAGER_H
