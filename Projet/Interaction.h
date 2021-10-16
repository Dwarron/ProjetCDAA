#ifndef INTERACTION_H
#define INTERACTION_H

/**
 * \file Interaction.h
 * \class Interaction Interaction.h
 * \brief Enregistre une interaction avec un contact
 * \author Pinon Alexandre
 * \version 0.1
 */

#include <string>
#include <Date.h>

using namespace std;

class Interaction
{
public:
    Interaction();

    const Date getDateInteraction() const;
    void setDateInteraction(const Date &newDateinteraction);

private:
    Date dateInteraction;
};

#endif // INTERACTION_H
