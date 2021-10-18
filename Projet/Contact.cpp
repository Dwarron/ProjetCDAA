/**
 * \file Contact.cpp
 * \class Contact Contact.h
 * \brief Contact representant une personne
 * \author Pinon Alexandre, Perion Maxence
 * \version 0.1
 */

#include "Contact.h"
#include "Interaction.h"
#include <string.h>
#include <Date.h>
#include <stdexcept>

using namespace std;

/**
 *  \brief Constructeur par defaut
 *
 *  Constructeur par defaut de la classe Contact
 */
Contact::Contact() : Contact("Jean", "Dupont", "Carrefour", "0123456789", "jean.dupont@mail.com", "")
{

}

/**
 *  \brief Constructeur standard
 *
 *  Constructeur standard de la classe Contact
 *
 *  \param n : nom du contact
 *  \param p : prenom
 *  \param e : entreprise
 *  \param tel : telephone
 *  \param m : mail
 *  \param uri : chemin vers la photo de profil
 */
Contact::Contact(const string& n, const string& p, const string& e, const string& tel, const string& m, const string& uri)
{   
    nom = verifInfo(n);
    prenom = verifInfo(p);
    entreprise = e;
    telephone = tel;
    mail = verifMail(m);
    uriPhoto = verifUri(uri);
    dateCreation = Date();
}

/**
  *  \brief Accesseur de nom
  *
  *  Methode qui permet d'acceder au nom du contact
  *
  *  \return nom
  */
const string &Contact::getNom() const
{
    return nom;
}

/**
  *  \brief Mutateur de nom
  *
  *  Methode qui permet de modifier le nom du contact et ajouter une nouvelle interaction horodate
  *
  *  \param newNom : le nouveau nom
  */
void Contact::setNom(const string &newNom)
{
    nom = verifInfo(newNom);
    Interaction i(Date(), "modification du nom");
    addInteraction(i);
}

/**
  *  \brief Accesseur de prenom
  *
  *  Methode qui permet d'acceder au prenom du contact
  *
  *  \return prenom
  */
const string &Contact::getPrenom() const
{
    return prenom;
}

/**
  *  \brief Mutateur de prenom
  *
  *  Methode qui permet de modifier le prenom du contactet ajouter une nouvelle interaction horodate
  *
  *  \param newPrenom : le nouveau prenom
  */
void Contact::setPrenom(const string &newPrenom)
{
    prenom = verifInfo(newPrenom);
    Interaction i(Date(), "modification du prenom");
    addInteraction(i);
}

/**
  *  \brief Accesseur d'entreprise
  *
  *  Methode qui permet d'acceder a l'entreprise du contact
  *
  *  \return entreprise
  */
const string &Contact::getEntreprise() const
{
    return entreprise;
}

/**
  *  \brief Mutateur d'entreprise
  *
  *  Methode qui permet de modifier l'entreprise du contact
  *
  *  \param newEntreprise : la nouvelle entreprise
  */
void Contact::setEntreprise(const string &newEntreprise)
{
    entreprise = newEntreprise;
    Interaction i(Date(), "modification de l'entreprise");
    addInteraction(i);
}

/**
  *  \brief Accesseur de telephone
  *
  *  Methode qui permet d'acceder au telephone du contact
  *
  *  \return telephone
  */
const string &Contact::getTelephone() const
{
    return telephone;
}

/**
  *  \brief Mutateur de telephone
  *
  *  Methode qui permet de modifier le telephone du contact
  *
  *  \param newTelephone : le nouveau telephone
  */
void Contact::setTelephone(const string &newTelephone)
{
    telephone = newTelephone;
    Interaction i(Date(), "modification du numero de telephone");
    addInteraction(i);
}

/**
  *  \brief Accesseur de mail
  *
  *  Methode qui permet d'acceder au telephone du contact
  *
  *  \return mail
  */
const string &Contact::getMail() const
{
    return mail;
}

/**
  *  \brief Mutateur de mail
  *
  *  Methode qui permet de modifier le mail du contact
  *
  *  \param newMail : le nouveau mail
  */
void Contact::setMail(const string &newMail)
{
    mail = newMail;
    Interaction i(Date(), "modification du mail");
    addInteraction(i);
}

/**
  *  \brief Methode addInteraction
  *
  *  Methode qui permet d'ajouter une interaction a la liste d'interaction d'un contact
  *
  *  \param Interaction &interr : l'interaction a ajouter a la liste
  */
void Contact::addInteraction(Interaction &inter)
{
    li.push_back(inter);
}

/**
  *  \brief Methode verifInfo
  *
  *  Methode qui permet de retirer tous les chiffres ainsi que caracteres speciaux
  *
  *  \param chaine : la chaine a verifier
  */
string Contact::verifInfo(string chaine)
{
    char delimitation[] = "1,2,3,4,5,6,7,8,9,0,&,#";

    char tabTest[chaine.length() + 1];
    string newChaine;
    char *result = NULL ;

    strcpy(tabTest, chaine.c_str()); //on copie le nom qui est un string, en tableau de char pour utiliser strtok()

    result = strtok (tabTest, delimitation); //pour que result soit != de NULL

    while( result != NULL )
    {
       newChaine += string(result);
       result = strtok( NULL , delimitation );
    }

    return newChaine;
    //garder le meme principe mais utiliser des interruption
}

/**
  *  \brief Methode verifMail
  *
  *  Methode qui permet de verifier si le mail est corectement inscrit
  *
  *  \param chaine : la chaine a verifier
  */
string Contact::verifMail(string chaine)
{
    int count = 0;

    for(int i = 0; i < chaine.size(); i++)
    {
        if(chaine[i] == '@')
            count++;
    }

    if(count > 1)
        throw invalid_argument("format mail incorrect");
    else
        return chaine;
}

/**
  *  \brief Methode verifUri
  *
  *  Methode qui permet de verifier si l'uri de la photo d'un contact est bien une photo png ou jpg
  *
  *  \param chaine : la chaine a verifier
  */
string Contact::verifUri(string chaine)
{
    string chainetmp;
    int i = chaine.size()-1;

    chainetmp = chaine[i-2];
    chainetmp += chaine[i-1];
    chainetmp += chaine[i];

    if(chainetmp != "jpg" && chainetmp != "png")
        throw invalid_argument("format photo incorrect");
    else
        return chaine;
}
