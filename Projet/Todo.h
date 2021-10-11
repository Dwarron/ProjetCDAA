#ifndef TODO_H
#define TODO_H

/*!
 * \file Todo.h
 * \brief Permets de décrire les choses à faire (todo), des interactions pour un contact.
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "Date.h"
#include <string>

using namespace std;

class Todo
{
public:
    Todo();

    const string &getContenueTodo() const;
    void setContenueTodo(const string &newContenueTodo);

    const Date &getDateTodo() const;
    void setDateTodo(const Date &newDateTodo);

private:
    Date dateTodo;
    string contenueTodo; /*!< Liste des morceaux*/

};

#endif // TODO_H
