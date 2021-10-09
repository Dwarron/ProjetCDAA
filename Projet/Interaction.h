#ifndef INTERACTION_H
#define INTERACTION_H

/*!
 * \file Interaction.h
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

    const string &getDateinteraction() const;
    void setDateinteraction(const string &newDateinteraction);

private:
    Date dateInteraction;
};

#endif // INTERACTION_H
