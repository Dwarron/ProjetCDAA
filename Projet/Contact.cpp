/**
 * \file Contact.cpp
 * \class Contact Contact.h
 * \brief Contact representant une personne
 * \author Pinon Alexandre, Perion Maxence
 * \version 0.1
 */

#include "Contact.h"
#include <string.h>

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
    interactions = list<Interaction*>();

    Date dateBienvenue = Date();
    dateBienvenue.addDelay(3);
    addInteraction(new Interaction("Creation de la fiche\n@todo Souhaiter la bienvenue avant le @date " + dateBienvenue));
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
    addInteraction(new Interaction("modification du nom (" + nom + " -> " + newNom + ")"));
    nom = newNom;
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
    addInteraction(new Interaction("modification du prenom (" + prenom + " -> " + newPrenom + ")"));
    prenom = newPrenom;
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
    addInteraction(new Interaction("modification de l'entreprise (" + entreprise + " -> " + newEntreprise + ")"));
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
    addInteraction(new Interaction("modification du telephone (" + telephone + " -> " + newTelephone + ")"));
    telephone = newTelephone;
}

/**
  *  \brief Ajout d'une interaction
  *
  *  Methode qui permet d'ajouter une interaction a la liste d'interaction d'un contact
  *
  *  \param Interaction i : l'interaction a ajouter
  */
void Contact::addInteraction(Interaction* i)
{
    interactions.push_back(i);
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
  *  \brief Accesseur d'interactions
  *
  *  Methode qui permet d'acceder a la liste des interactions avec le contact
  *
  *  \return interactions
  */
const std::list<Interaction*> &Contact::getInteractions() const
{
    return interactions;
}

/**
  *  \brief Accesseur virtuel de todos
  *
  *  Methode qui permet d'acceder a la liste des todos vis a vis du contact (la liste de tous les todos de toutes les interactions)
  *
  *  \return liste de tous les todos
  */
const std::list<Todo*> Contact::getTodos() const
{
    list<Todo*> todos = list<Todo*>();
    for(auto i = interactions.begin(); i != interactions.end(); i++)
    {
        list<Todo*> todosInteraction = (*i)->getTodos();
        for(auto t = todosInteraction.begin(); t != todosInteraction.end(); t++)
            todos.push_back(*t);
    }

    todos.sort();

    return todos;
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

        res += (*it)->toString();
    }

    return res;
}

/**
  *  \brief Representation en string de la liste des todos
  *
  *  Methode qui renvoie la representation textuel de la liste des todos, triee par ordre d'echeance
  *
  *  \return concatenation de representations textuelles de chaque todo
  */
const string Contact::todosToString()
{
    list<Todo*> todos = getTodos();
    string res = "Todos de " + prenom + " " + nom + " : ";

    for(auto it = todos.begin(); it != todos.end(); it++)
    {
        if(it != todos.begin())
            res += ", ";

        res += (*it)->toString();
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

/**
 *  \brief Destructeur de Contact
 *
 *  Detruis en memoire tout ce qui etait utilise par une instance de contact qui va etre supprimee (les instances d'interactions pointees par la liste)
 */
Contact::~Contact()
{
    for(auto it = interactions.begin(); it != interactions.end(); it++)
    {
        delete *it;
    }
}
