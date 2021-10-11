#include "Todo.h"

/*!
 * \file Todo.h
 * \brief Permets de décrire les choses à faire (todo), des interactions pour un contact.
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

Todo::Todo()
{

}

const string &Todo::getContenueTodo() const
{
    return contenueTodo;
}

void Todo::setContenueTodo(const string &newContenueTodo)
{
    contenueTodo = newContenueTodo;
}

const Date &Todo::getDateTodo() const
{
    return dateTodo;
}

void Todo::setDateTodo(const Date &newDateTodo)
{
    dateTodo = newDateTodo;
}
