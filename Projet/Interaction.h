#pragma once     //probleme d'include, vu avec Monsieur Raffin et pas de meilleur solution trouvee

/**
 * \file Interaction.h
 * \class Interaction Interaction.h
 * \brief Enregistre une interaction avec un contact
 * \author Pinon Alexandre, Perion Maxence
 * \version 0.1
 */

#include <string>
#include <list>
#include "Todo.h"
#include "Contact.h"
#include "Date.h"

class Contact;   //probleme d'include, vu avec Monsieur Raffin et pas de meilleur solution trouvee

class Interaction
{
public:
    Interaction(const std::string&);
    ~Interaction();

    const Date getDate() const;
    const std::string &getResume() const;
    void setResume(const std::string &newResume);

    friend std::ostream& operator << (std::ostream&, const Interaction&);
    const std::string toString() const;

    friend bool operator<(const Interaction&, const Interaction&);

    const std::list<Todo *> &getTodos() const;

private:
    Date date;
    std::string resume;

    std::list<Todo*> todos;

    void creerTodos();
    void viderTodos();
};
