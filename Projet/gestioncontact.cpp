/**
 * \file GestionContact.cpp
 * \class GestionContact GestionContact.h
 * \brief Class de gestion des Contact: ajout, suppressions, requetes, ...
 * \author Perion Maxence
 * \version 0.1
 */

#include "GestionContact.h"
#include <iostream>
using namespace std;

/**
 *  \brief Constructeur par defaut
 *
 *  Constructeur par defaut de la classe GestionContact, initialise a vide la liste des contacts
 */
GestionContact::GestionContact()
{
    contacts = list<Contact*>();
}

/**
 *  \brief Cree et ajoute un contact
 *
 *  Ajoute un nouveau contact a la liste des contacts
 *
 *  \param n : nom du contact
 *  \param p : prenom
 *  \param e : entreprise
 *  \param tel : telephone
 *  \param m : mail
 *  \param uri : chemin vers la photo de profil
 */
Contact* GestionContact::creeContact(const string& n, const string& p, const string& e, const string& tel, const string& m, const string& uri)
{
    Contact* c = new Contact(n, p, e, tel, m, uri);
    contacts.push_back(c);
    return c;
}

/**
 *  \brief Supprime un contact
 *
 *  Supprime un contact de la liste des contacts
 *
 *  \param c : le contact a supprimer
 */
void GestionContact::supprimeContact(Contact* c)
{
    contacts.remove(c);
    dateDerniereSuppression = Date();   //date de la derniere suppression = aujourdhui
}

/**
 *  \brief Ajoute une interaction non existante dans un contact
 *
 *  Cree une nouvelle interaction avec le text correspondant et l'ajoute au contact
 *
 *  \param c : le contact
 *  \param text : le text de l'interaction
 */
Interaction* GestionContact::ajoutInteraction(Contact* c, const string& text)
{
    Interaction* i = new Interaction(text);
    c->addInteraction(i);

    return i;
}

/**
 *  \brief Ajoute une interaction existante dans un contact
 *
 *  Ajoute au contact une interaction deja existante.
 *  Utile si on decide d'ajouter une meme interaction a plusieurs contacts differents (un groupe de clients par exemple)
 *
 *  \param c : le contact
 *  \param text : le text de l'interaction
 */
void GestionContact::ajoutInteraction(Contact* c, Interaction* i)
{
    c->addInteraction(i);
}

/**
 *  \brief Recupere toutes les interactions de tous les contacts
 *  Trie toutes les interactions et supprime les duplicatas
 *
 *  \return la liste de toutes les interactions existantes
 */
list<Interaction*> GestionContact::getAllInteractions() const
{
    list<Interaction*> li = list<Interaction*>();
    for(auto it = contacts.begin(); it != contacts.end(); it++)
    {
        list<Interaction*> licontact = (*it)->getInteractions();
        li.insert(li.end(), licontact.begin(), licontact.end());
    }

    li.sort();
    li.unique();
    return li;
}

/**
  *  \brief Accesseur de Contacts
  *
  *  Methode qui permet d'acceder a liste des contacts
  *
  *  \return contacts
  */
const std::list<Contact *> &GestionContact::getContacts() const
{
    return contacts;
}

/**
  *  \brief Accesseur de dateDerniereSuppression
  *
  *  Methode qui permet d'acceder a la date de la derniere suppression
  *
  *  \return dateDerniereSuppression
  */
const Date &GestionContact::getDateDerniereSuppression() const
{
    return dateDerniereSuppression;
}


/**
  *  \brief Destructeur de GestionContact
  *
  *  Detruis une instance de GestionContact precedemment construite et detruits egalement tous les contacts references dans la liste
  */
GestionContact::~GestionContact()
{
    list<Interaction*> interactions = getAllInteractions();     // detruis toutes les interactions depuis ici pour ne pas supprime plusieurs fois
                                                                // une meme instance references par deux contacts differents (aucun moyen de le savoir depuis contact)
    for(auto it = interactions.begin(); it != interactions.end(); it++)
    {
        delete *it;
    }

    for(auto it = contacts.begin(); it != contacts.end(); it++)
    {
        (*it)->clearInteractions();
        delete *it;
    }
}


void GestionContact::AjoutFicheContacts(const std::string& nom, const std::string& prenom, const std::string& entreprise, const std::string& tel, const std::string& mail, const std::string& uri)
{
    creeContact(nom, prenom, entreprise, tel, mail, uri);

    for(auto it = getContacts().begin(); it != getContacts().end(); it++)
    {
        cout << "Contact cree : " << (*it)->getNom() << endl;
    }

}
