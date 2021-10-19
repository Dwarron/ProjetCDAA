#ifndef GESTIONCONTACT_H
#define GESTIONCONTACT_H

/**
 * \file gestioncontact.h
 * \class GestionContact GestionContact.h
 * \brief Class de gestion des contacts: ajout, suppressions, requetes, ...
 * \author Perion Maxence
 * \version 0.1
 */

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
    Date dateDerniereSuppression;
};

#endif // GESTIONCONTACT_H
