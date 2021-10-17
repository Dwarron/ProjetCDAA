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
    void setNom(const string &newNom);

    const string &getPrenom() const;
    void setPrenom(const string &newPrenom);

    const string &getEntreprise() const;
    void setEntreprise(const string &newEntreprise);

    const string &getTelephone() const;
    void setTelephone(const string &newTelephone);

    list<Interaction>li; /**< Liste des interactions*/

    friend ostream operator << (ostream &o, const Contact&);

    void addInteraction(Interaction &);

    string verifInfo(string chaine);
    string verifMail(string chaine);

private:
    string nom;
    string prenom;
    string entreprise;
    string telephone;
    string mail;
    string uriPhoto;
    Date dateCreation;

};

#endif // CONTACT_H
