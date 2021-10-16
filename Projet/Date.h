#ifndef DATE_H
#define DATE_H

/**
 * \file Date.h
 * \class Date Date.h
 * \brief Stocke une date
 * \author Perion Maxence
 * \version 0.1
 */

#include <string>

using namespace std;

class Date
{
public:
    Date();
    Date(const int, const int, const int);

    int getJour() const;
    int getMois() const;
    int getAnnee() const;

    const string toString() const;

private:
    const struct tm *d;

};

#endif // DATE_H
