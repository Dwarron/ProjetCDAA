/**
 * \file gestioncontact.cpp
 * \class GestionContact GestionContact.h
 * \brief Class de gestion des contacts: ajout, suppressions, requetes, ...
 * \author Perion Maxence
 * \version 0.1
 */

#include "gestioncontact.h"

/**
 *  \brief Constructeur par defaut
 *
 *  Constructeur par defaut de la classe GestionContact, initialise a vide la liste des contacts
 */
GestionContact::GestionContact()
{
    contacts = list<Contact>();
}

/**
 *  \brief Ajoute un contact
 *
 *  Ajoute un contact a la liste des contacts
 *
 *  \param c : le contact a ajouter
 */
void GestionContact::ajoutContact(const Contact& c)
{
    contacts.push_back(c);
}

void GestionContact::ajoutInteraction(Contact* c, Interaction& i)
{
    const string delimiter = "@todo ";
    const int delimiterLength = delimiter.length();

    list<Todo> nouveauxTodos = list<Todo>();
    size_t position;
    size_t last = 0;
    string text = i.getResume();

    position = text.find(delimiter, last);
    while(position != string::npos)
    {
        size_t positionEndLine = text.find("\n");
        if(positionEndLine == string::npos)
            positionEndLine = text.length();

        string todoText = text.substr(position, positionEndLine);
        Date d = Todo::getDateFromTodoLine(todoText);

        last = position + delimiterLength;
        position = text.find(delimiter, last);
    }
}

/**
 *  \brief Supprime un contact
 *
 *  Supprime un contact de la liste des contacts
 *
 *  \param c : le contact a supprimer
 */
void GestionContact::supprimeContact(const Contact& c)
{
    contacts.remove(c);
    dateDerniereSuppression = Date();   //date de la derniere suppression aujourdhui
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
