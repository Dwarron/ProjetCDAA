#pragma once     //probleme d'include, vu avec Monsieur Raffin et pas de meilleur solution trouve

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

class Contact;   //probleme d'include, vu avec Monsieur Raffin et pas de meilleur solution trouve

class Interaction
{
public:
    Interaction(const std::string&, Contact*);
    ~Interaction();

    const Date getDate() const;
    const std::string &getResume() const;

    friend std::ostream& operator << (std::ostream&, const Interaction&);
    const std::string toString() const;

    friend bool operator<(const Interaction&, const Interaction&);

    void addTodo(Todo*);
    Contact *getContact() const;

    const std::list<Todo *> &getTodos() const;

private:
    Date date;
    std::string resume;
    Contact* contact;

    std::list<Todo*> todos;
};
