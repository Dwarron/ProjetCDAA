/*!
 * \file Date.cpp
 * \brief Stocke une date
 * \author Perion Maxence
 * \version 0.1
 */

#include "Date.h"
#include <time.h>
#include <string>
#include <stdexcept>

using namespace std;

Date::Date()
{
    time_t n = time(0);
    d = localtime(&n);
}

Date::Date(const int j, const int m, const int y)
{
    if(j > 31 || j < 0)
    {
        throw invalid_argument("jour j incorrect");
    }
    if(m > 12 || m < 0)
    {
        throw invalid_argument("mois m incorrect");
    }
    if(y < 2020)
    {
        throw invalid_argument("annee y incorrecte");
    }

    struct tm nd;
    nd.tm_mday = j;
    nd.tm_mon = m - 1;
    nd.tm_year = y - 1900;

    time_t nt = mktime(&nd);
    d = localtime(&nt);
}

int Date::getJour() const
{
    return d->tm_mday;
}

int Date::getMois() const
{
    return d->tm_mon + 1;
}

int Date::getAnnee() const
{
    return d->tm_year + 1900;
}

const string Date::toString() const
{
    return to_string(getJour()) + "/" + to_string(getMois()) + "/" + to_string(getAnnee());
}
