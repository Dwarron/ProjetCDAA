#ifndef INTERACTION_H
#define INTERACTION_H

/**
 * \file Interaction.h
 * \class Interaction Interaction.h
 * \brief Enregistre une interaction avec un contact
 * \author Pinon Alexandre, Perion Maxence
 * \version 0.1
 */

#include <string>
#include <Date.h>

using namespace std;

class Interaction
{
public:
    Interaction();
    Interaction(const string&);

    const Date getDate() const;
    void setDate(const Date&);

    const string &getResume() const;

    friend ostream& operator << (ostream&, const Interaction&);
    const string toString() const;

private:
    Date date;
    string resume;
};

#endif // INTERACTION_H
