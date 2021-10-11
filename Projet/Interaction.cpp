/*!
 * \file Interaction.cpp
 * \brief Enregistre une interaction avec un contact
 * \author Pinon Alexandre
 * \version 0.1
 */

#include "Interaction.h"
#include "Date.h"
#include <string>

using namespace std;

Interaction::Interaction()
{

}

const Date Interaction::getDateInteraction() const
{
    return dateInteraction;
}

void Interaction::setDateInteraction(const Date &newDateinteraction)
{
    dateInteraction = newDateinteraction;
}
