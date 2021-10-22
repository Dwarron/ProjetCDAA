#include "Todo.h"
#include <stdexcept>
#include <iostream>
using namespace std;

/**
 * \file Todo.h
 * \class Todo Todo.h
 * \brief Permets de décrire les choses à faire (todo), des interactions pour un contact.
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

/**
 *  \brief Constructeur
 *
 *  Constructeur de la classe Todo
 *
 *  \param txt : le contenu du todo
 *  \param date : la date d'echeance
 *  \param i : pointeur vers l'interaction initiale
 */
Todo::Todo(const string& txt, const Date& date, Interaction* i)
{
    contenue = txt;
    echeance = date;
    interaction = i;
    effectue = false;
}

/**
  *  \brief Accesseur d'echeance
  *
  *  Methode qui permet d'acceder a la date d'echeance du todo
  *
  *  \return echeance
  */
const Date &Todo::getEcheance() const
{
    return echeance;
}

/**
  *  \brief Accesseur du contenu
  *
  *  Methode qui permet d'acceder au contenu du todo
  *
  *  \return contenue
  */
const string& Todo::getContenue() const
{
    return contenue;
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
    return "TODO pour le " + echeance.toString() + " : " + contenue;
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
  *  \brief Recupere la date d'une ligne de text de todo
  *
  *  Methode statique qui recupere une date valide apres un @ date (ou la date du jour) a partir d'un text ayant debute par @ todo
  *
  *  \param text : le text du todo
  *  \return une date extraite du text, ou la date du jour le cas echeant
  */
const Date Todo::getDateFromTodoLine(string* text)
{
    Date d = Date();
    const string delimiter = "@date ";
    const int delimiterLength = delimiter.length();

    size_t position = text->find(delimiter);

    if(position != string::npos)    // recherche de @ date, sinon date du jour
    {
        position += delimiterLength;
        size_t last = position;
        string dateText = text->substr(position);

        *text = text->substr(0, position - delimiterLength) + text->substr(position);
        size_t positionFinDate = 0;
        for(int i = 0; i < 2; i++)  // positions du 'J/M/' pour le debut de la date
        {
            positionFinDate = dateText.find("/", positionFinDate);
            if(positionFinDate == string::npos)
            {
                throw invalid_argument("Date mal formee dans un todo");
            }
            positionFinDate++;
        }
        positionFinDate += 4; //YYYY
        if(positionFinDate > dateText.length())
        {
            throw invalid_argument("Date mal formee dans un todo");
        }
        dateText = dateText.substr(0, positionFinDate);    // on coupe la fin si @ date ne termine pas la ligne
        d = Date(dateText);

        position = text->find(delimiter, last);
        if(position != string::npos)
        {
            throw invalid_argument("Plusieurs @date dans une ligne de todo");
        }
    }

    return d;
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
  *  \brief Accesseur d'interaction
  *
  *  Methode qui permet d'acceder a l'interaction dans laquelle le todo a ete trouve
  *
  *  \return effectue
  */
Interaction *Todo::getInteraction() const
{
    return interaction;
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
bool operator<(const Todo& a, const Todo& b)
{
    return (a.getEcheance() < b.getEcheance());
}
