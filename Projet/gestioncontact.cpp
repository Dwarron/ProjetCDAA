#include "gestioncontact.h"

GestionContact::GestionContact()
{
    contacts = list<Contact>();
    todos = list<Todo>();
}

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
        string todoText = text.substr(last, position);
//TODO creer le todo selon le text todoText
        last = position + delimiterLength;
        position = text.find(delimiter, last);
    }
}

void GestionContact::supprimeContact(const Contact& c)
{
    contacts.remove(c);
    dateDerniereSuppression = Date();
}

const Date &GestionContact::getDateDerniereSuppression() const
{
    return dateDerniereSuppression;
}
