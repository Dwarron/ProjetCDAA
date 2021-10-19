#ifndef GESTIONCONTACT_H
#define GESTIONCONTACT_H

#include <list>
#include "Contact.h"
#include "Date.h"
#include "Todo.h"

class GestionContact
{
public:
    GestionContact();

    void ajoutContact(const Contact&);
    void supprimeContact(const Contact&);

    void ajoutInteraction(Contact*, Interaction&);

    const Date &getDateDerniereSuppression() const;

private:
    list<Contact> contacts;
    list<Todo> todos;
    Date dateDerniereSuppression;
};

#endif // GESTIONCONTACT_H
