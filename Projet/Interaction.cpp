/**
 * \file Interaction.cpp
 * \class Interaction Interaction.h
 * \brief Enregistre une interaction avec un contact
 * \author Pinon Alexandre
 * \version 0.1
 */

#include "Interaction.h"
#include "Date.h"
#include <string>

using namespace std;

/**
 *  \brief Constructeur par defaut
 *
 *  Constructeur par defaut de la classe Interaction
 */
Interaction::Interaction()
{
    dateInteraction = Date();
}

/**
 *  \brief Constructeur de la class Interaction
 *
 *  Constructeur avec parametre de la classe Interaction
 */
Interaction::Interaction(Date& date, string inter)
{
    dateInteraction = date;
    interaction = inter;
}

/**
  *  \brief Accesseur de date
  *
  *  Methode qui permet d'acceder a la date de l'interaction
  *
  *  \return dateInteraction
  */
const Date Interaction::getDateInteraction() const
{
    return dateInteraction;
}

/**
  *  \brief Mutateur de date
  *
  *  Methode qui permet de modifier la date de l'interaction
  *
  *  \param newDateinteraction : la nouvelle date d'interaction
  */
void Interaction::setDateInteraction(const Date &newDateinteraction)
{
    dateInteraction = newDateinteraction;
}
