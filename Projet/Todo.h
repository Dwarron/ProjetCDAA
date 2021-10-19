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

using namespace std;

class Todo
{
public:
    Todo(Interaction*);
   // ~Todo();

    const Date &getEcheance() const;

    const string &getContenue() const;

    const string toString() const;

    static const Date getDateFromTodoLine(const string&);

private:
    Date echeance;
    string contenue;
    bool effectue;

   /* Interaction* interaction;
    Contact* contact;*/
};

#endif // TODO_H
