#ifndef TODO_H
#define TODO_H

/**
 * \file Todo.h
 * \class Todo Todo.h
 * \brief Permets de décrire les choses à faire (todo), des interactions pour un contact.
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "Date.h"
#include <string>
#include "Interaction.h"
#include "Contact.h"

using namespace std;

class Todo
{
public:
    Todo(Interaction*);
    ~Todo();

    const Date &getEcheance() const;

    const string &getContenue() const;

private:
    Date echeance;
    string contenue;
    Interaction* interaction;
    Contact* contact;
};

#endif // TODO_H
