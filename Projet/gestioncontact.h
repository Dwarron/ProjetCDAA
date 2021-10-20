#pragma once     //probleme d'include, vu avec Monsieur Raffin et pas de meilleur solution trouvee

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
    ~GestionContact();

    Contact* creeContact(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
    void supprimeContact(Contact*);

    void ajoutInteraction(Contact*, Interaction&);

    const Date &getDateDerniereSuppression() const;

private:
    std::list<Contact*> contacts;
    Date dateDerniereSuppression;
};
