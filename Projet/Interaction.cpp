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
