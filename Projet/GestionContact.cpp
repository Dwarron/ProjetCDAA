/**
 * \file GestionContact.cpp
 * \class GestionContact GestionContact.h
 * \brief Class de gestion des Contact: ajout, suppressions, requetes, ...
 * \author Perion Maxence
 * \version 0.1
 */

#include "GestionContact.h"

using namespace std;

/**
 *  \brief Constructeur par defaut
 *
 *  Constructeur par defaut de la classe GestionContact, initialise a vide la liste des contacts
 */
GestionContact::GestionContact(Date derniereSuppression)
{
    contacts = list<Contact*>();
    dateDerniereSuppression = derniereSuppression;
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
    return creeContact(n, p, e, tel, m, uri, Date(), Date());
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
 *  \param dc : la date de creation du contact
 *  \param dm : la date de derniere modification du contact
 */
Contact* GestionContact::creeContact(const string& n, const string& p, const string& e, const string& tel, const string& m, const string& uri, const Date& dc, const Date& dm)
{
    Contact* c = new Contact(n, p, e, tel, m, uri, dc, dm);
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
 *  \param d : la date de l'interaction
 *  \param text : le text de l'interaction
 */
Interaction* GestionContact::ajoutInteraction(Contact* c, const Date& d, const string& text)
{
    Interaction* i = new Interaction(d, text);
    c->addInteraction(i);

    return i;
}

/**
 *  \brief Creation de la liste des Todo concernant cette Interaction
 *
 *  Analyse le resume/contenu de l'interaction pour creer tous les Todo correspondant et les stocker dans la liste
 *
 *  \param i : l'interaction
 */
void GestionContact::creerTodos(Interaction* i)
{
    const string delimiter = "@todo ";
    const int delimiterLength = delimiter.length();

    size_t position;
    size_t last = 0;

    string resume = i->getResume();
    position = resume.find(delimiter, last);
    while(position != string::npos) // on recherche tous les @ todo
    {
        size_t positionEndLine = resume.find("\n", position); // fin de ligne du todo
        if(positionEndLine == string::npos)
            positionEndLine = resume.length();  // fin du todo a la fin du texte si pas de nouvelle ligne

        size_t positionNextTodo = resume.find(delimiter, position + delimiterLength);   //@todo present sur la meme ligne
        if(positionNextTodo != string::npos && positionNextTodo < positionEndLine)
            positionEndLine = positionNextTodo;

        string todoText = resume.substr(position, positionEndLine - position); // on decoupe le texte correspondant au todo
        Date d = getDateFromLine(todoText);
        Todo* t = new Todo(todoText, d, false);
        resume = resume.substr(0, position) +  todoText + resume.substr(positionEndLine);   // correction de la ligne du todo avec celle analysee et retournee par l'instance
        i->ajoutTodo(t);

        last = position + delimiterLength;
        position = resume.find(delimiter, last);
    }
}

/**
  *  \brief Recupere la date d'une ligne de text de todo
  *
  *  Fonction qui recupere une date valide apres un @ date (ou la date du jour) a partir d'un text ayant debute par @ todo
  *
  *  \param text : le text du todo
  *  \return une date extraite du text, ou la date du jour le cas echeant
  */
const Date GestionContact::getDateFromLine(const string& text)
{
    Date d = Date();
    const string delimiter = "@date ";
    const int delimiterLength = delimiter.length();

    size_t position = text.find(delimiter);

    if(position != string::npos)    // recherche de @ date, sinon date du jour
    {
        position += delimiterLength;
        size_t last = position;
        string dateText = text.substr(position);

        size_t positionFinDate = 0;
        for(int i = 0; i < 2; i++)  // position du 'J/M/' pour le debut de la date
        {
            positionFinDate = dateText.find("/", positionFinDate);
            if(positionFinDate == string::npos)
            {
                throw invalid_argument("Date mal formee dans un todo");
            }
            positionFinDate++;
        }
        positionFinDate += 4; //YYYY
        if(positionFinDate > dateText.length())
        {
            throw invalid_argument("Date mal formee dans un todo");
        }
        dateText = dateText.substr(0, positionFinDate);    // on coupe la fin si @ date ne termine pas la ligne
        d = Date(dateText);

        position = text.find(delimiter, last);
        if(position != string::npos)
        {
            throw invalid_argument("Plusieurs @date dans une ligne de todo");
        }
    }

    return d;
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
 *  \brief Ajoute un todo a une interaction
 *
 *  Ajoute a l'interaction un nouveau todo cree
 *
 *  \param i : l'interaction
 *  \param date : la date du todo
 *  \param c : le contenu du todo
 *  \param e : todo deja effectue ou non
 *  \return le todo cree
 */
Todo* GestionContact::ajoutTodo(Interaction* i, const Date& date, const string& c, const bool e)
{
    Todo* t = new Todo(c, date, e);
    i->ajoutTodo(t);
    return t;
}


/**
 *  \brief Recupere toutes les interactions de tous les contacts
 *  Trie toutes les interactions et supprime les duplicatas
 *
 *  \return la liste de toutes les interactions existantes
 */
const list<Interaction*> GestionContact::getAllInteractions() const
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
const list<Contact*> &GestionContact::getContacts()
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
  *  \brief Mutateur de dateDerniereSuppression
  *
  *  Methode qui permet de modifier la date de la derniere suppression
  *
  */
void GestionContact::setDateDerniereSuppression(const Date& d)
{
    dateDerniereSuppression = d;
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
