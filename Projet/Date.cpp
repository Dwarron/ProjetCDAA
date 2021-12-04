/**
 * \file Date.cpp
 * \class Date Date.h
 * \brief Stocke une date
 * \author Perion Maxence
 * \version 0.1
 */

#include <time.h>
#include <string>
#include <stdexcept>
#include <stdlib.h>
#include <ctype.h>
#include "Date.h"
#include "Verificator.h"

using namespace std;

/**
 *  \brief Constructeur standard de Date
 *
 *  Constructeur standard de la classe Date, represente la date courante lors de son initialisation
 */
Date::Date()
{
    time_t n = time(0);     //date courante
    struct tm d = *localtime(&n);
    jour = d.tm_mday;
    mois = d.tm_mon + 1;
    annee = d.tm_year + 1900;
}

/**
 *  \brief Constructeur de Date a partir d'une chaine de caracteres
 *
 *  Construit une instance de Date a partir des informations contenues dans une chaine de caracteres de la forme DD/MM/YY
 *
 *  \param text : la date en forme de chaine de caracteres
 */
Date::Date(const string &text)
{
    const string delimiter = "/";
    size_t position;
    size_t last = 0;
    string composition[3];

    for(int i = 0; i < 2; i++)
    {
        position = text.find(delimiter, last);

        if(position == string::npos || position - last == 0)    //manque de delimiteur ou pas de texte apres le delimiteur
            throw invalid_argument("Representation de date mal formee");

        composition[i] = text.substr(last, position - last);    //on decoupe la partie entre ce delimiteur et le precedent
        last = position + 1;

        Verificator::checkChiffres(composition[i]);  //on verifie qu'on a bien decoupe un nombre
    }

    if(text.length() - last == 0)   //pas de texte apres le dernier delimiteur
        throw invalid_argument("Representation de date mal formee");

    composition[2] = text.substr(last); //decoupe de la derniere partie
    Verificator::checkChiffres((composition[2]));

    *this = Date(stoi(composition[0]), stoi(composition[1]), stoi(composition[2])); //appel du constructeur standard de Date avec les informations recuperees et converties en entier
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
    if(j > 31 || j <= 0)
    {
        throw invalid_argument("jour j incorrect");
    }
    if(m > 12 || m <= 0)
    {
        throw invalid_argument("mois m incorrect");
    }
    if(y < 2020)
    {
        throw invalid_argument("annee y incorrecte");
    }

    jour = j;
    mois = m;
    annee = y;
}

/**
  *  \brief Accesseur du jour
  *
  *  Methode qui renvoie le jour de la date
  *
  *  \return jour
  */
int Date::getJour() const
{
    return jour;
}

/**
  *  \brief Accesseur du mois
  *
  *  Methode qui renvoie le mois de la date
  *
  *  \return mois
  */
int Date::getMois() const
{
    return mois;
}

/**
  *  \brief Accesseur de l'annee
  *
  *  Methode qui renvoie l'annee de la date
  *
  *  \return annee
  */
int Date::getAnnee() const
{
    return annee;
}

/**
  *  \brief Ajout d'un delai a une date
  *
  *  Methode qui permet de decaler la date selon un delai
  *
  *  \param jours : le nombre de jours a ajouter
  */
void Date::addDelay(const int jours)
{
    addDelay(jours, 0); //on ajoute des jours et 0 mois, evite le redondance
}

/**
  *  \brief Ajout d'un delai a une date
  *
  *  Methode qui permet de decaler la date selon un delai
  *
  *  \param jours : le nombre de jours a ajouter
  *  \param mois : le nombre de mois a ajouter
  */
void Date::addDelay(const int jours, const int mois)
{
    addDelay(jours, mois, 0);   //on ajoute des jours, des mois et 0 annees, evite le redondance
}

/**
  *  \brief Ajout d'un delai a une date
  *
  *  Methode qui permet de decaler la date selon un delai
  *
  *  \param j : le nombre de jours a ajouter
  *  \param m : le nombre de mois a ajouter
  *  \param a : le nombre d'annees a ajouter
  */
void Date::addDelay(const int j, const int m, const int a)
{
    int newDay = jour + j;
    jour = newDay % 31;                   //le nombre de jour ne doit pas depasser 31
    int additionalMonth = newDay / 31;          //si on a plus de 31j, on ajoute des mois

    int newMonth = mois + m + additionalMonth;
    mois = newMonth % 12;                  //le nombre de mois ne doit pas depasser 12
    int additionalYear = newMonth / 12;         //si on a plus de 12 mois, on ajoute des annees

    annee += a + additionalYear;
}

/**
  *  \brief Representation en string
  *
  *  Methode qui renvoie la representation textuel de la date
  *
  *  \return (J/M/A)
  */
const string Date::toString() const
{
    string d = to_string(getJour());
    if(d.length() == 1)
        d = "0" + d;

    string m = to_string(getMois());
    if(m.length() == 1)
        m = "0" + m;

    string y = to_string(getAnnee());
    if(y.length() > 4)
        y = y[0] + y[1] + y[2] + y[3];

    return d + "/" + m + "/" + y;
}

/**
  *  \brief Fonction amie d'affichage via cout
  *
  *  Fonction surchargeant l'operateur << pour afficher la date avec un cout
  *
  *  \param o : le stream a surcharger
  *  \param d : la date a afficher dans le stream
  *  \return operateur surchage
  */
ostream& operator<< (ostream &o, const Date& d)
{
    o << d.toString();
    return o;
}

/**
  *  \brief Comparaison a < b
  *
  *  Surdefinition de l'operateur "<", renvoie vraie si semantiquement a < b
  *  \param a : premiere operande
  *  \param b : deuxieme operande
  *
  *  \return a < b
  */
bool operator<(const Date& a, const Date& b)
{
    if(a.getAnnee() < b.getAnnee())
        return true;
    if(b.getAnnee() < a.getAnnee())
        return false;
    if(a.getMois() < b.getMois())
        return true;
    if(b.getMois() < a.getMois())
        return false;
    if(a.getJour() < b.getJour())
        return true;
    if(b.getJour() < a.getJour())
        return false;

    return false;
}

/**
  *  \brief Comparaison a > b
  *
  *  Surdefinition de l'operateur ">", renvoie vraie si semantiquement a > b
  *  \param a : premiere operande
  *  \param b : deuxieme operande
  *
  *  \return a < b
  */
bool operator>(const Date& a, const Date& b)
{
    if(a.getAnnee() > b.getAnnee())
        return true;
    if(b.getAnnee() > a.getAnnee())
        return false;
    if(a.getMois() > b.getMois())
        return true;
    if(b.getMois() > a.getMois())
        return false;
    if(a.getJour() > b.getJour())
        return true;
    if(b.getJour() > a.getJour())
        return false;

    return false;
}

/**
  *  \brief Comparaison a <= b
  *
  *  Surdefinition de l'operateur "<=", renvoie vraie si semantiquement a <= b
  *  \param a : premiere operande
  *  \param b : deuxieme operande
  *
  *  \return a < b
  */
bool operator<=(const Date& a, const Date& b)
{
    return a < b || a == b;
}

/**
  *  \brief Surcharge de l'operateur +
  *
  *  Surdefinition de l'operateur + de concatenation avec un string
  *  \param a : premiere operande
  *  \param b : deuxieme operande
  *
  *  \return s + d.toString()
  */
string operator+(const string& s, const Date& d)
{
    return s + d.toString();
}

/**
  *  \brief Surcharge de l'operateur -
  *
  *  Surdefinition de l'operateur - de difference, renvoie le nombre de jours dans l'intervalle entre a et b
  *  Positif si a > b (a est plus loin dans le futur que b), negatif si a < b et 0 si a = b (a et b representent la meme date)
  *  \param a : premiere operande
  *  \param b : deuxieme operande
  *
  *  \return s + d.toString()
  */
int operator-(const Date& a, const Date& b)
{
    return (a.getAnnee() - b.getAnnee()) * 365 + (a.getMois() - b.getMois()) * 31 + (a.getJour() - b.getJour());
}

/**
  *  \brief Surcharge de l'operateur de test d'egalite
  *
  *  Methode qui surcharge l'operateur ==, compare semantiquement deux dates
  *
  *  \param a : operande de gauche
  *  \param b : operande de droite
  *  \return vrai si les dates sont semantiquement egales, faux sinon
  */
bool operator==(const Date& a, const Date& b)
{
    return a.getAnnee() == b.getAnnee() && a.getMois() == b.getMois() && a.getJour() == b.getJour();
}

/**
  *  \brief Surcharge de l'operateur de test de difference
  *
  *  Methode qui surcharge l'operateur !=, compare semantiquement deux dates
  *
  *  \param a : operande de gauche
  *  \param b : operande de droite
  *  \return vrai si les dates sont semantiquement egales, faux sinon
  */
bool operator!=(const Date& a, const Date& b)
{
    return !(a == b);
}

/**
  *  \brief L'instance de date est-elle dans le passe ?
  *
  *  Utilise une comparaison avec la date actuelle: renvoie vrai si la date est plus ancienne que la date courante, sinon faux
  *
  *  \return instance de Date < date actuelle
  */
bool Date::depassee() const
{
    Date now = Date();
    return (*this) < now;
}
