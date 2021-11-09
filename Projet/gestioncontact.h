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
    GestionContact();
    ~GestionContact();

    Contact* creeContact(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
    void supprimeContact(Contact*);

    Interaction* ajoutInteraction(Contact*, const std::string&);
    void ajoutInteraction(Contact*, Interaction*);

    const Date &getDateDerniereSuppression() const;

    std::list<Interaction*> getAllInteractions() const;

    const std::list<Contact *> &getContacts() const;

private:
    Date dateDerniereSuppression;
    std::list<Contact*> contacts;

signals:
    void AjoutFicheContacts(const std::string& nom, const std::string& prenom, const std::string& entreprise, const std::string& tel, const std::string& mail, const std::string& uri);
};
