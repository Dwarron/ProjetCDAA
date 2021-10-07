#include "Contact.h"

#include <string>

using namespace std;

Contact::Contact()
{

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
