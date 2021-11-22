/**
 * \file Interaction.cpp
 * \class Interaction Interaction.h
 * \brief Enregistre une interaction avec un Contact
 * \author Pinon Alexandre, Perion Maxence
 * \version 0.1
 */

#include <string>
#include "Interaction.h"
#include "Date.h"

using namespace std;

/**
 *  \brief Constructeur de la class Interaction
 *
 *  Constructeur avec parametre de la classe Interaction
 *
 *  \param r : le resume de l'interaction
 */
Interaction::Interaction(const string& r)
{
    date = Date();
    resume = r;
    todos = list<Todo*>();

    creerTodos();
}

/**
 *  \brief Creation de la liste des Todo concernant cette Interaction
 *
 *  Analyse le resume/contenu de l'interaction pour creer tous les Todo correspondant et les stocker dans la liste
 */
void Interaction::creerTodos()
{
    const string delimiter = "@todo ";
    const int delimiterLength = delimiter.length();

    size_t position;
    size_t last = 0;

    position = resume.find(delimiter, last);
    while(position != string::npos) // on recherche tous les @ todo
    {
        resume = resume.substr(0, position) + resume.substr(position + delimiterLength);    // suppression du @todo dans le texte

        size_t positionEndLine = resume.find("\n", position); // fin de ligne du todo
        if(positionEndLine == string::npos)
            positionEndLine = resume.length();  // fin du todo a la fin du texte si pas de nouvelle ligne

        string todoText = resume.substr(position, positionEndLine - position); // on decoupe le texte correspondant au todo
        Date d = Todo::getDateFromTodoLine(&todoText);
        Todo* t = new Todo(todoText, d, this);
        resume = resume.substr(0, position) +  todoText + resume.substr(positionEndLine);   // correction de la ligne du todo avec celle analysee et retournee par l'instance
        todos.push_back(t);

        last = position;
        position = resume.find(delimiter, last);
    }
}

/**
  *  \brief Accesseur de date
  *
  *  Methode qui permet d'acceder a la date de l'interaction
  *
  *  \return date
  */
Date Interaction::getDate() const
{
    return date;
}


/**
  *  \brief Mutateur de date
  *
  *  Methode qui permet de modifier la date de l'interaction
  *
  *  \param d : la nouvelle date
  */
void Interaction::setDate(const Date& d)
{
    date = d;
}

/**
  *  \brief Accesseur de resume
  *
  *  Methode qui permet d'acceder au resume de l'Interaction
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
  *  Fonction surchargeant l'operateur << pour afficher l'Interaction avec un cout
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
  *  \brief Mutateur de resume
  *
  *  Methode qui permet de modifier le resume de l'interaction (en cas d'erreur)
  *  Regenere egalement les todos associes.
  *
  */
void Interaction::setResume(const std::string &newResume)
{
    resume = newResume;
    viderTodos();
    creerTodos();
}

/**
  *  \brief Vide la liste des todos stockes dans cette interaction
  *
  *   Desalloue les instances de todos references
  */
void Interaction::viderTodos()
{
    for(auto it = todos.begin(); it != todos.end(); it++)
    {
        delete *it;
    }
    todos.clear();
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
bool operator<(Interaction& a, Interaction& b)
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
    viderTodos();
}
