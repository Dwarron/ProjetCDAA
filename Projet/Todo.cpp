/**
 * \file Todo.cpp
 * \class Todo Todo.h
 * \brief Permets de décrire les choses à faire (todo), des Interaction pour un Contact.
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <stdexcept>
#include "Todo.h"

using namespace std;

/**
 *  \brief Constructeur
 *
 *  Constructeur de la classe Todo
 *
 *  \param txt : le contenu du todo
 *  \param date : la date d'echeance
 *  \param i : pointeur vers l'interaction initiale
 *  \param e : booleen effectue ou non
 */
Todo::Todo(const string& txt, const Date& date, const bool e)
{
    contenu = txt;
    echeance = date;
    effectue = e;
}

/**
  *  \brief Accesseur d'echeance
  *
  *  Methode qui permet d'acceder a la date d'echeance du todo
  *
  *  \return echeance
  */
Date &Todo::getEcheance()
{
    return echeance;
}

/**
  *  \brief Accesseur du contenu
  *
  *  Methode qui permet d'acceder au contenu du todo
  *
  *  \return contenu
  */
const string& Todo::getContenu() const
{
    return contenu;
}

/**
  *  \brief Representation en string
  *
  *  Methode qui renvoie la representation textuelle du todo
  *
  *  \return Todo pour le (J/M/A) : contenue
  */
const string Todo::toString() const
{
    return "TODO pour le " + echeance.toString() + " : " + contenu;
}

/**
  *  \brief Fonction amie d'affichage via cout
  *
  *  Fonction surchargeant l'operateur << pour afficher le todo avec un cout
  *
  *  \param o : le stream a surcharger
  *  \param t : le todo a afficher dans le stream
  *  \return operateur surchage
  */
ostream& operator<< (ostream &o, const Todo& t)
{
    o << t.toString();
    return o;
}

/**
  *  \brief Accesseur d'effectue
  *
  *  Methode qui permet d'acceder au booleen indiquant si un todo a ete realise ou non
  *
  *  \return effectue
  */
bool Todo::getEffectue() const
{
    return effectue;
}

/**
  *  \brief Mutateur d'effectue
  *
  *  Methode qui permet d'indiquant si le todo a ete realise ou non
  *
  *  \return effectue
  */
void Todo::setEffectue(bool e)
{
    effectue = e;
}

/**
  *  \brief Comparaison a < b
  *
  *  Surdefinition de l'operateur "<", renvoie vraie si semantiquement a < b
  *  Les todos sont compares selon leur echeance
  *  \param a : premiere operande
  *  \param b : deuxieme operande
  *
  *  \return a < b
  */
bool operator<(Todo& a, Todo& b)
{
    return (a.getEcheance() < b.getEcheance());
}
