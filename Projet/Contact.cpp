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
    interactions = list<Interaction>();
    todos = list<Todo>();

    Date dateBienvenue = Date();
    dateBienvenue.addDelay(3);
    Interaction i = Interaction("Creation de la fiche\n@todo Souhaiter la bienvenue @date " + dateBienvenue);
    addInteraction(i);
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
    Interaction i("modification du nom (" + nom + " -> " + newNom + ")");
    nom = newNom;
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
    Interaction i("modification du prenom (" + prenom + " -> " + newPrenom + ")");
    prenom = newPrenom;
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
    Interaction i("modification de l'entreprise (" + entreprise + " -> " + newEntreprise + ")");
    entreprise = newEntreprise;
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
    Interaction i("modification du telephone (" + telephone + " -> " + newTelephone + ")");
    telephone = newTelephone;
    addInteraction(i);
}

/**
  *  \brief Ajout d'une interaction
  *
  *  Methode qui permet d'ajouter une interaction a la liste d'interaction d'un contact
  *
  *  \param Interaction i : l'interaction a ajouter
  */
void Contact::addInteraction(const Interaction &i)
{
    interactions.push_back(i);
}

/**
  *  \brief Ajout d'un Todo
  *
  *  Methode qui permet d'ajouter un todo a la liste des todos d'un contact
  *
  *  \param Todo t : le todo a ajouter
  */
void Contact::addTodo(const Todo &t)
{
    todos.push_back(t);
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
    return chaine;
}

/**
  *  \brief Fonction amie d'affichage via cout
  *
  *  Fonction surchargeant l'operateur << pour afficher le contact avec un cout
  *
  *  \param o : le stream a surcharger
  *  \param c : le contact a afficher dans le stream
  *  \return operateur surchage
  */
ostream& operator<< (ostream &o, const Contact& c)
{
    o << c.toString();
    return o;
}

/**
  *  \brief Representation en string
  *
  *  Methode qui renvoie la representation textuel du contact
  *
  *  \return prenom nom de (entreprise) telephone ou mail
  */
const string Contact::toString() const
{
    string result = prenom + " " + nom;

    if(entreprise != "")
    {
        result += " de " + entreprise;
    }

    result += " tel: " + telephone + " ou mail: " + mail;

    return result;
}

/**
  *  \brief Representation en string de la liste des interactions
  *
  *  Methode qui renvoie la representation textuel de la liste des interactions, triee par ordre de date
  *
  *  \return concatenation de representations textuelles de chaque interaction
  */
const string Contact::interactionsToString()
{
    interactions.sort();
    string res = "Interactions de " + prenom + " " + nom + " : ";

    for(auto it = interactions.begin(); it != interactions.end(); it++)
    {
        if(it != interactions.begin())
            res += ", ";

        res += (*it).toString();
    }

    return res;
}

/**
  *  \brief Surcharge de l'operateur de test d'egalite
  *
  *  Methode qui surcharge l'operateur ==, compare semantiquement deux contacts, utilise par exemple pour supprimer des instances
  *  de la liste des contacts
  *
  *  \param a : operande de gauche
  *  \param b : operande de droite
  *  \return vrai si les contacts sont semantiquement egales, faux sinon
  */
bool operator==(const Contact& a, const Contact& b)
{
    return a.getPrenom() == b.getPrenom()
            && a.getNom() == b.getNom()
            && a.getEntreprise() == b.getEntreprise()
            ;
}
