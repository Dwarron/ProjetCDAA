#ifndef CONTACT_H
#define CONTACT_H

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

    friend std::ostream& operator << (std::ostream&, const Contact&);
    const std::string toString() const;
    const std::string interactionsToString();

    void addInteraction(const std::string&);

    std::string verifInfo(std::string);
    std::string verifMail(std::string);

    friend bool operator==(const Contact&, const Contact&);

    const std::list<Interaction*> &getInteractions() const;
    const std::list<Todo*> getTodos() const;

private:
    std::string nom;
    std::string prenom;
    std::string entreprise;
    std::string telephone;
    std::string mail;
    std::string uriPhoto;
    Date dateCreation;

    std::list<Interaction*> interactions;

    void addTodo(const Todo&);

};

#endif // CONTACT_H
