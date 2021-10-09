/*!
 * \file Interaction.cpp
 * \brief Enregistre une interaction avec un contact
 * \author Pinon Alexandre
 * \version 0.1
 */
#include "Interaction.h"
#include <string>

using namespace std;

Interaction::Interaction()
{

}

const string &Interaction::getDateinteraction() const
{
    return dateinteraction;
}

void Interaction::setDateinteraction(const string &newDateinteraction)
{
    dateinteraction = newDateinteraction;
}
