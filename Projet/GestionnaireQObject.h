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
#include "GestionContact.h"

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
    void createContact(std::string, std::string, std::string, std::string, std::string, std::string, Date, Date);
    void loadContact(int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string);
    void editInteractionDate(Interaction*, QDate);
    void editInteractionResume(Interaction*, QString);
    void ajoutInteraction(Contact*, QString);
    Interaction* ajoutInteraction(Contact*, Date, QString, bool createTodo = true);
    void ajoutInteraction(Contact*, Interaction*);
    void loadAndCreateInteraction(int, Contact*, std::string, std::string);
    void loadInteraction(Interaction*, Contact*);
    void loadTodo(int, Interaction*, std::string, std::string, bool);
    void exportJSON(QString);
    void importJSON(QString);
    void clearData();
    void setTodoEffectue(Todo*,bool);

signals:
    void listContactsUpdated(std::list<Contact*>);
    void onContactCreated(Contact*, std::string, std::string);
    void onInteractionEdited();
    void onEndModifContact(Contact*,std::string);
    void contactDeleted(std::string);
    void contactLoaded(int, Contact*);
    void contactCreated(std::string, std::string, std::string, std::string, std::string, std::string);
    void contactCreated(std::string, std::string, std::string, std::string, std::string, std::string, Date, Date);
    void interactionLoaded(int, Interaction*);
    void todoLoaded(int, Todo*);
    void onTodoEdited();
    void onInteractionModifDate(Interaction*, std::string);
    void onInteractionModifResume(Interaction*, std::string);
    void onCreateInteraction(Interaction*, Contact*, std::string);
    void onAddExistingInteraction(Interaction*, Contact*);
    void onCreateTodos(Interaction*, std::list<Todo*>);
    void onDeleteTodos(Interaction*);
    void onLoadJSON();
};

#endif // GESTIONNAIREQOBJECT_H
