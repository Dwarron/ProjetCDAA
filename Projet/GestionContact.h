#pragma once     //probleme d'include, vu avec Monsieur Raffin et pas de meilleur solution trouvee

/**
 * \file GestionContact.h
 * \class GestionContact GestionContact.h
 * \brief Class de gestion des contacts: ajout, suppressions, requetes, ...
 * \author Perion Maxence
 * \version 0.1
 */

#include <list>
#include <QObject>
#include "Contact.h"
#include "Date.h"
#include "Todo.h"

class GestionContact
{
public:
    GestionContact(Date);
    ~GestionContact();

    Contact* creeContact(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
    Contact* creeContact(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const Date&, const Date&);

    static Interaction* ajoutInteraction(Contact*, const Date&, const std::string&);
    static void ajoutInteraction(Contact*, Interaction*);
    static Todo* ajoutTodo(Interaction*, const Date&, const std::string&, const bool);

    void setDateDerniereSuppression(const Date&);
    const Date &getDateDerniereSuppression() const;

    const std::list<Interaction*> getAllInteractions() const;

    const std::list<Contact*> &getContacts();

    static void creerTodos(Interaction*);
    static const Date getDateFromLine(const std::string&);

public slots:
    void supprimeContact(Contact*);

private:
    Date dateDerniereSuppression;
    std::list<Contact*> contacts;
};
