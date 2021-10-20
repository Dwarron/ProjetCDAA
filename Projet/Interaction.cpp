/**
 * \file Interaction.cpp
 * \class Interaction Interaction.h
 * \brief Enregistre une interaction avec un contact
 * \author Pinon Alexandre, Perion Maxence
 * \version 0.1
 */

#include "Interaction.h"
#include "Date.h"
#include <string>

using namespace std;

/**
 *  \brief Constructeur de la class Interaction
 *
 *  Constructeur avec parametre de la classe Interaction
 *
 *  \param r : le resume de l'interaction
 *  \param c : pointeur vers le contact avec qui s'est produit l'interaction
 */
Interaction::Interaction(const string& r, Contact* c)
{
    date = Date();
    resume = r;
    contact = c;
    todos = list<Todo*>();
}

/**
  *  \brief Ajout d'un Todo
  *
  *  Methode qui permet d'ajouter un todo a la liste des todos d'une interaction
  *
  *  \param Todo t : le todo a ajouter
  */
void Interaction::addTodo(Todo* t)
{
    todos.push_back(t);
}

/**
  *  \brief Accesseur de date
  *
  *  Methode qui permet d'acceder a la date de l'interaction
  *
  *  \return date
  */
const Date Interaction::getDate() const
{
    return date;
}

/**
  *  \brief Accesseur de resume
  *
  *  Methode qui permet d'acceder au resume de l'interaction
  *
  *  \return resume
  */
const string& Interaction::getResume() const
{
    return resume;
}

/**
  *  \brief Fonction amie d'affichage via cout
  *
  *  Fonction surchargeant l'operateur << pour afficher l'interaction avec un cout
  *
  *  \param o : le stream a surcharger
  *  \param i : l'interaction a afficher dans le stream
  *  \return operateur surchage
  */
ostream& operator<< (ostream &o, const Interaction& i)
{
    o << i.toString();
    return o;
}

/**
  *  \brief Representation en string
  *
  *  Methode qui renvoie la representation textuel de l'interaction
  *
  *  \return date : resume
  */
const string Interaction::toString() const
{
    return date.toString() + " : " + resume;
}

/**
  *  \brief Accesseur de contact
  *
  *  Methode qui permet d'acceder au contact aupres de qui l'interaction s'est produite
  *
  *  \return contact
  */
Contact *Interaction::getContact() const
{
    return contact;
}

/**
  *  \brief Accesseur de todos
  *
  *  Methode qui permet d'acceder a la liste des todos lies a l'interaction
  *
  *  \return contact
  */
const std::list<Todo *> &Interaction::getTodos() const
{
    return todos;
}

/**
  *  \brief Comparaison a < b
  *
  *  Surdefinition de l'operateur "<", renvoie vraie si semantiquement a < b
  *  Les interactions sont comparees selon leurs dates
  *  \param a : premiere operande
  *  \param b : deuxieme operande
  *
  *  \return a < b
  */
bool operator<(const Interaction& a, const Interaction& b)
{
    return (a.getDate() < b.getDate());
}

/**
 *  \brief Destructeur d'Interaction
 *
 *  Detruis en memoire tout ce qui etait utilise par une instance d'interactions qui va etre supprimee (les instances de todos pointees par la liste)
 */
Interaction::~Interaction()
{
    for(auto it = todos.begin(); it != todos.end(); it++)
    {
        delete *it;
    }
}
