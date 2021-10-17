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
    uriPhoto = uri;
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
  *  Methode qui permet de modifier le nom du contact
  *
  *  \param newNom : le nouveau nom
  */
void Contact::setNom(const string &newNom)
{
    nom = newNom;
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
  *  Methode qui permet de modifier le prenom du contact
  *
  *  \param newPrenom : le nouveau prenom
  */
void Contact::setPrenom(const string &newPrenom)
{
    prenom = newPrenom;
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
}

/**
  *  \brief Methode addInteraction
  *
  *  Methode qui permet d'ajouter une interaction a la liste d'interaction d'un contact
  *
  *  \param Interaction & : la liste d'interaction du contact
  */
void Contact::addInteraction(Interaction &)
{
    //to do...
    //ajouter une interaction d'un contact avec push_back(const T& x); qui ajoute un element en fin de liste
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
    //garder le meme principe mais plutot utiliser des interruption
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
    //to do...
    //avec des interruption
}
