#include "Todo.h"
#include <stdexcept>

/**
 * \file Todo.h
 * \class Todo Todo.h
 * \brief Permets de décrire les choses à faire (todo), des interactions pour un contact.
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

/**
 *  \brief Constructeur par defaut
 *
 *  Constructeur par defaut de la classe Todo
 */
Todo::Todo(Interaction* i)
{

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
  *  \brief Recupere la date d'une ligne de text de todo
  *
  *  Methode statique qui recupere une date valide apres un @ date (ou la date du jour) a partir d'un text ayant debute par @ todo
  *
  *  \param text : le text du todo
  *  \return une date extraite du text, ou la date du jour le cas echeant
  */
const Date Todo::getDateFromTodoLine(const string& text)
{
    Date d = Date();
    const string delimiter = "@date ";
    const int delimiterLength = delimiter.length();

    size_t position = text.find(delimiter);

    if(position != string::npos)    // recherche de @ date, sinon date du jour
    {
        position += delimiterLength;
        size_t last = position;
        string dateText = text.substr(position);

        size_t positionFinDate = 0;
        for(int i = 0; i < 2; i++)  // positions du 'J/M/' pour le debut de la date
        {
            positionFinDate = dateText.find("/");
            if(positionFinDate == string::npos)
            {
                throw invalid_argument("Date mal formee dans un todo");
            }
        }
        positionFinDate += 4; //YYYY
        if(positionFinDate >= dateText.length())
        {
            throw invalid_argument("Date mal formee dans un todo");
        }
        dateText = dateText.substr(positionFinDate);    // on coupe la fin si @ date ne termine pas la ligne

        d = Date(dateText);

        position = text.find(delimiter, last);
        if(position != string::npos)
        {
            throw invalid_argument("Plusieurs @date dans une ligne de todo");
        }
    }

    return d;
}
