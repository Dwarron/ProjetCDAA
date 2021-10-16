/**
 * \file Date.cpp
 * \class Date Date.h
 * \brief Stocke une date
 * \author Perion Maxence
 * \version 0.1
 */

#include "Date.h"
#include <time.h>
#include <string>
#include <stdexcept>

using namespace std;

/**
 *  \brief Constructeur standard de Date
 *
 *  Constructeur standard de la classe Date, represente la date courante lors de son initialisation
 */
Date::Date()
{
    time_t n = time(0);     //date courante
    d = localtime(&n);
}

/**
 *  \brief Constructeur de Date
 *
 *  Constructeur standard de la classe Date, represente la date correspondante a un jour, un mois et une annee donnees
 *  \param j : jour
 *  \param m : mois
 *  \param y : annee
 */
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

/**
  *  \brief Accesseur virtuel du jour
  *
  *  Methode qui renvoie le jour de la date
  *
  *  \return jour
  */
int Date::getJour() const
{
    return d->tm_mday;
}

/**
  *  \brief Accesseur virtuel du mois
  *
  *  Methode qui renvoie le mois de la date
  *
  *  \return mois
  */
int Date::getMois() const
{
    return d->tm_mon + 1;
}

/**
  *  \brief Accesseur virtuel de l'annee
  *
  *  Methode qui renvoie l'annee de la date
  *
  *  \return annee
  */
int Date::getAnnee() const
{
    return d->tm_year + 1900;
}

/**
  *  \brief Accesseur virtuel de l'annee
  *
  *  Methode qui renvoie la representation textuel de la date
  *
  *  \return (J/M/A)
  */
const string Date::toString() const
{
    return to_string(getJour()) + "/" + to_string(getMois()) + "/" + to_string(getAnnee());
}
