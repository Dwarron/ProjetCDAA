#ifndef CONTACT_H
#define CONTACT_H

/**
 * \file Contact.h
 * \class Contact Contact.h
 * \brief Contact representant une personne
 * \author Pinon Alexandre, Perion Maxence
 * \version 0.1
 */

#include "Interaction.h"
#include <string>
#include <list>

using namespace std;

class Contact
{
public:
    Contact();
    Contact(const string&, const string&, const string&, const string&, const string&, const string&);

    const string &getNom() const;
    void setNom(const string&);

    const string &getPrenom() const;
    void setPrenom(const string&);

    const string &getEntreprise() const;
    void setEntreprise(const string&);

    const string &getTelephone() const;
    void setTelephone(const string&);

    friend ostream& operator << (ostream&, const Contact&);
    const string toString() const;
    const string interactionsToString();

    void addInteraction(const Interaction&);

    string verifInfo(string);
    string verifMail(string);

private:
    string nom;
    string prenom;
    string entreprise;
    string telephone;
    string mail;
    string uriPhoto;
    Date dateCreation;

    list<Interaction> interactions;
};

#endif // CONTACT_H
