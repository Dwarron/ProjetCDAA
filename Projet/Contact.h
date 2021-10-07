#ifndef CONTACT_H
#define CONTACT_H
#include "Interaction.h"
#include <string>
#include <list>


using namespace std;

class Contact
{
public:
    Contact();

    const string &getNom() const;

    const string &getPrenom() const;

    const string &getEntreprise() const;
    void setEntreprise(const string &newEntreprise);

    const string &getTelephone() const;
    void setTelephone(const string &newTelephone);

    list<Interaction>li;
    addInteraction(Interaction&);

    friend ostream operator << (ostream &o, const Contact&);

private:
    string nom;
    string prenom;
    string entreprise;
    string telephone;
    string mail;
    string urlphoto;
    Date dateCreation;

};

#endif // CONTACT_H
