/**
 * \file Contact.cpp
 * \class Contact Contact.h
 * \brief Contact representant une personne
 * \author Pinon Alexandre, Perion Maxence
 * \version 0.1
 */

#include <string>
#include <stdexcept>
#include "Contact.h"

using namespace std;

/**
 *  \brief Constructeur par defaut
 *
 *  Constructeur par defaut de la classe Contact
 */
Contact::Contact() : Contact("Jean", "Dupont", "Carrefour", "0123456789", "jean.dupont@mail.com", "", Date(), Date())
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
 *  \param dc : la date de creation du contact
 *  \param dm : la date de derniere modification du contact
 */
Contact::Contact(const string& n, const string& p, const string& e, const string& tel, const string& m, const string& uri, const Date& dc, const Date& dm)
{   
    checkLettres(n);    // nom et prenom doivent uniquement contenir des lettres
    nom = n;
    checkLettres(p);
    prenom = p;

    entreprise = e;

    if(tel != "")
    {
        checkChiffres(tel);     // telephone doit etre compose uniquement de chiffres
        if(tel.length() != 10)
        {
            throw invalid_argument("Telephone errone (doit avoir 10 chiffres)");
        }
    }
    telephone = tel;

    if(m != "")
    {
        checkMail(m);
    }
    mail = m;

    uriPhoto = uri;

    dateCreation = dc;
    dateModification = dm;
    interactions = list<Interaction*>();
}

/**
  *  \brief Test si la chaine entree est conforme
  *
  *  Methode qui renvoie une exception si la chaine contient autre chose que des lettres, un espace ou un tiret
  *
  *  \param chaine : la chaine a tester
  */
void Contact::checkLettres(const std::string& chaine)
{
    size_t position = chaine.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ -");
    if(position != string::npos)
    {
        throw invalid_argument("Chaine mal formee (doit contenir uniquement des lettres)");
    }
}

/**
  *  \brief Test si la chaine entree est conforme
  *
  *  Methode qui renvoie une exception si la chaine contient autre chose que des chiffres
  *
  *  \param chaine : la chaine a tester
  */
void Contact::checkChiffres(const std::string& chaine)
{
    size_t position = chaine.find_first_not_of("0123456789");
    if(position != string::npos)
    {
        throw invalid_argument("Chaine mal formee (doit contenir uniquement des chiffres)");
    }
}

/**
  *  \brief Test si la chaine entree est conforme
  *
  *  Methode qui renvoie une exception si la chaine ne decrit pas un mail
  *
  *  \param chaine : la chaine a tester
  */
void Contact::checkMail(const std::string& chaine)
{
    size_t positionArobase = chaine.find("@");

    if(positionArobase == string::npos)
    {
        throw invalid_argument("Mail mal forme : doit contenir exactement 1 @");
    }
    else
    {
        size_t positionArobase2 = chaine.find("@", positionArobase + 1);
        if(positionArobase2 != string::npos)
        {
            throw invalid_argument("Mail mal forme : doit contenir exactement 1 @");
        }
    }

    size_t positionPoint = chaine.find(".", positionArobase);
    if(positionPoint == string::npos)
    {
        throw invalid_argument("Mail mal forme : doit contenir au moins un point apres @");
    }
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
    checkLettres(newNom);    // le nom doit uniquement contenir des lettres
    nom = newNom;
    dateModification = Date();
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
    checkLettres(newPrenom);    // le prenom doit uniquement contenir des lettres
    prenom = newPrenom;
    dateModification = Date();
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
    dateModification = Date();
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
    checkChiffres(newTelephone);     // le telephone doit etre compose uniquement de chiffres
    if(newTelephone.length() != 10)
    {
        throw invalid_argument("Telephone errone (doit avoir 10 chiffres)");
    }
    telephone = newTelephone;
    dateModification = Date();
}

/**
  *  \brief Accesseur de mail
  *
  *  Methode qui permet d'acceder au mail du contact
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
    checkMail(newMail);     // format mail

    mail = newMail;
    dateModification = Date();
}


/**
  *  \brief Accesseur de uriPhoto
  *
  *  Methode qui permet d'acceder a l'emplacement de la photo du contact
  *
  *  \return uriPhoto
  */
const std::string &Contact::getUriPhoto() const
{
    return uriPhoto;
}

/**
  *  \brief Mutateur de uriPhoto
  *
  *  Methode qui permet de modifier l'adresse de la photo du contact
  *
  *  \param newUriPhoto : le nouveau chemin
  */
void Contact::setUriPhoto(const string &newUriPhoto)
{
    uriPhoto = newUriPhoto;
    dateModification = Date();
}


/**
  *  \brief Accesseur de dateCreation
  *
  *  Methode qui permet d'acceder a la date de creation de la fiche du contact
  *
  *  \return dateCreation
  */
Date &Contact::getDateCreation()
{
    return dateCreation;
}

/**
  *  \brief Accesseur de dateModification
  *
  *  Methode qui permet d'acceder a la date de la derniere modification de la fiche du contact
  *
  *  \return telephone
  */
const Date& Contact::getDateDerniereModification() const
{
    return dateModification;
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
  *  \brief Propose une suggestion de nom pour une chaine entree ne correspondant pas a ce qui est attendu
  *
  *  Methode qui retire tous les chiffres et caracteres speciaux
  *
  *  \param chaine : la chaine a verifier
  */
const std::string Contact::suggestionNom(std::string chaine)
{
    size_t position = chaine.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZéèùà -");
    while(position != string::npos)
    {
        chaine = chaine.substr(0, position) + chaine.substr(position + 1);
        position = chaine.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZéèùà -");
    }

    return chaine;
}

/**
  *  \brief Accesseur d'interactions
  *
  *  Methode qui permet d'acceder a la liste des interactions avec le contact
  *
  *  \return interactions
  */
const list<Interaction*> &Contact::getInteractions()
{
    interactions.sort([](Interaction* a, Interaction* b) {return *a < *b;});
    return interactions;
}

/**
  *  \brief Accesseur virtuel de todos
  *
  *  Methode qui permet d'acceder a la liste des todos vis a vis du contact (la liste de tous les todos de toutes les interactions)
  *
  *  \return liste de tous les todos
  */
const list<Todo*> Contact::getTodos() const
{
    list<Todo*> todos = list<Todo*>();
    for(auto i = interactions.begin(); i != interactions.end(); i++)
    {
        list<Todo*> todosInteraction = (*i)->getTodos();
        for(auto t = todosInteraction.begin(); t != todosInteraction.end(); t++)
            todos.push_back(*t);
    }

    todos.sort([](Todo* a, Todo* b) {return *a < *b;});     // lambda pour trier selon la valeur de l'instance et non le pointeur

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
  *  \brief Comparaison a < b
  *
  *  Surdefinition de l'operateur "<", renvoie vraie si semantiquement a < b
  *  \param a : premiere operande
  *  \param b : deuxieme operande
  *
  *  \return a < b
  */
bool operator<(const Contact& a, const Contact& b)
{
    if(a.getNom() == b.getNom())
        return a.getPrenom() < b.getPrenom();

    return a.getNom() < b.getNom();
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
    return prenom + " " + nom;
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
    interactions.sort([](Interaction* a, Interaction* b) {return *a < *b;});   // lambda pour trier selon la valeur de l'instance et non le pointeur

    string res = "Interactions de " + prenom + " " + nom + " :\n";

    for(auto it = interactions.begin(); it != interactions.end(); it++)
    {
        if(it != interactions.begin())
            res += ",\n";

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
    string res = "Todos de " + prenom + " " + nom + " :\n";

    for(auto it = todos.begin(); it != todos.end(); it++)
    {
        if(it != todos.begin())
            res += "\n";

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
 *  \brief vide la liste des interactions
 *  /!\ ne detruis pas les instances pointees, utilise par le destructeur de gestioncontact qui detruis lui meme les instances d'interactions
 *  pour ne pas avoir de probleme de duplicata et supprimer plusieurs fois une meme instance d'interaction
 */
void Contact::clearInteractions()
{
    interactions.clear();
}

/**
 *  \brief Destructeur de Contact
 *
 *  Detruis en memoire tout ce qui etait utilise par une instance de contact qui va etre supprimee (les instances d'interactions pointees par la liste)
 */
Contact::~Contact()
{
    // detruis les interactions referencees (si ca a deja ete fais par le destructeur de gestionContact, la liste aura ete videe via clearInteractions)
    // dans le cas ou une instance n'aurait pas ete cree via gestionContact
    for(auto it = interactions.begin(); it != interactions.end(); it++)
    {
        delete *it;
    }
}
