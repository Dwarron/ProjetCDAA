#pragma once    //probleme d'include, vu avec Monsieur Raffin et pas de meilleur solution trouvee

/**
 * \file Contact.h
 * \class Contact Contact.h
 * \brief Contact representant une personne
 * \author Pinon Alexandre, Perion Maxence
 * \version 0.1
 */

#include <string>
#include <list>
#include "Interaction.h"
#include "Date.h"
#include "Todo.h"

class Interaction;   //probleme d'include, vu avec Monsieur Raffin et pas de meilleur solution trouvee
class Todo;

class Contact
{
public:
    Contact();
    Contact(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const Date&, const Date&);
    ~Contact();

    const std::string &getNom() const;
    void setNom(const std::string&);

    const std::string &getPrenom() const;
    void setPrenom(const std::string&);

    const std::string &getEntreprise() const;
    void setEntreprise(const std::string&);

    const std::string &getTelephone() const;
    void setTelephone(const std::string&);

    const std::string &getMail() const;
    void setMail(const std::string&);

    const std::string &getUriPhoto() const;
    void setUriPhoto(const std::string&);

    Date &getDateCreation();
    const Date &getDateDerniereModification() const;

    const std::list<Interaction*> &getInteractions();
    const std::list<Todo*> getTodos() const;

    friend std::ostream& operator << (std::ostream&, const Contact&);
    friend bool operator<(const Contact&, const Contact&);
    const std::string toString() const;
    const std::string interactionsToString();
    const std::string todosToString();

    void addInteraction(Interaction*);
    void clearInteractions();

    static const std::string suggestionNom(std::string);

    friend bool operator==(const Contact&, const Contact&);

private:
    std::string nom;
    std::string prenom;
    std::string entreprise;
    std::string telephone;
    std::string mail;
    std::string uriPhoto;
    Date dateCreation;
    Date dateModification;

    std::list<Interaction*> interactions;
};
