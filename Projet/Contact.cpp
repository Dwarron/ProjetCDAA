/*!
 * \file Contact.cpp
 * \brief Contact representant une personne
 * \author Pinon Alexandre, Perion Maxence
 * \version 0.1
 */

#include "Contact.h"
#include <string>

using namespace std;

Contact::Contact() : Contact("Jean", "Dupont", "Carrefour", "0123456789", "jean.dupont@mail.com", "", Date())
{

}

Contact::Contact(const string& n, const string& p, const string& e, const string& tel, const string& m, const string& uri, const Date& date)
{
    nom = n;
    prenom = p;
    entreprise = e;
    telephone = tel;
    mail = m;
    uriPhoto = uri;
    dateCreation = date;
}

const string &Contact::getNom() const
{
    return nom;
}

const string &Contact::getPrenom() const
{
    return prenom;
}

const string &Contact::getEntreprise() const
{
    return entreprise;
}

void Contact::setEntreprise(const string &newEntreprise)
{
    entreprise = newEntreprise;
}

const string &Contact::getTelephone() const
{
    return telephone;
}

void Contact::setTelephone(const string &newTelephone)
{
    telephone = newTelephone;
}
