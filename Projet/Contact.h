#pragma once    //probleme d'include, vu avec Monsieur Raffin et pas de meilleur solution trouvee

/**
 * \file Contact.h
 * \class Contact Contact.h
 * \brief Contact representant une personne
 * \author Pinon Alexandre, Perion Maxence
 * \version 0.1
 */

#include <string>
#include "Interaction.h"
#include <list>
#include "Date.h"
#include "Todo.h"

class Interaction;   //probleme d'include, vu avec Monsieur Raffin et pas de meilleur solution trouvee
class Todo;

class Contact
{
public:
    Contact();
    Contact(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
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
    void setMail(const std::string &newMail);

    const std::string &getUriPhoto() const;
    void setUriPhoto(const std::string &newUriPhoto);

    const Date &getDateCreation() const;
    const Date &getDateDerniereModification() const;

    const std::list<Interaction*> &getInteractions() const;
    const std::list<Todo*> getTodos() const;

    friend std::ostream& operator << (std::ostream&, const Contact&);
    const std::string toString() const;
    const std::string interactionsToString();
    const std::string todosToString();

    void addInteraction(Interaction*);
    void clearInteractions();

    static void checkLettres(const std::string&);
    static void checkChiffres(const std::string&);
    static void checkMail(const std::string&);

    static const std::string suggestionNom(std::string&);

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
