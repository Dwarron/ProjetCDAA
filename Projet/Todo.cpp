#include "Todo.h"

/**
 * \file Todo.h
 * \class Todo Todo.h
 * \brief Permets de décrire les choses à faire (todo), des interactions pour un contact.
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

/**
 *  \brief Constructeur par defaut
 *
 *  Constructeur par defaut de la classe Todo
 */
Todo::Todo()
{

}

/**
  *  \brief Accesseur du contenu
  *
  *  Methode qui permet d'acceder au contenu du todo
  *
  *  \return contenueTodo
  */
const string &Todo::getContenueTodo() const
{
    return contenueTodo;
}

/**
  *  \brief Mutateur de contenu
  *
  *  Methode qui permet de modifier le contenu du todo
  *
  *  \param newContenueTodo : le nouveau contenu
  */
void Todo::setContenueTodo(const string &newContenueTodo)
{
    contenueTodo = newContenueTodo;
}

/**
  *  \brief Accesseur de date
  *
  *  Methode qui permet d'acceder a la date du todo
  *
  *  \return dateTodo
  */
const Date &Todo::getDateTodo() const
{
    return dateTodo;
}

/**
  *  \brief Mutateur de date
  *
  *  Methode qui permet de modifier la date du todo
  *
  *  \param newDateTodo : la nouvelle date
  */
void Todo::setDateTodo(const Date &newDateTodo)
{
    dateTodo = newDateTodo;
}
