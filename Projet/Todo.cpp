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
Todo::Todo(Interaction* i)
{

}

/**
  *  \brief Accesseur d'echeance
  *
  *  Methode qui permet d'acceder a la date d'echeance du todo
  *
  *  \return echeance
  */
const Date &Todo::getEcheance() const
{
    return echeance;
}

/**
  *  \brief Accesseur du contenu
  *
  *  Methode qui permet d'acceder au contenu du todo
  *
  *  \return contenue
  */
const string &Todo::getContenue() const
{
    return contenue;
}
