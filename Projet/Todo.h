#pragma once     //probleme d'include, vu avec Monsieur Raffin et pas de meilleur solution trouvee

/**
 * \file Todo.h
 * \class Todo Todo.h
 * \brief Permets de décrire les choses à faire (todo), des interactions pour un contact.
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <string>
#include "Interaction.h"
#include "Date.h"

class Interaction;   //probleme d'include, vu avec Monsieur Raffin et pas de meilleur solution trouvee

class Todo
{
public:
    Todo(const std::string&, const Date&, Interaction*);

    Date &getEcheance();

    const std::string &getContenue() const;

    const std::string toString() const;
    friend std::ostream& operator << (std::ostream&, const Todo&);

    static const Date getDateFromTodoLine(std::string*);

    bool getEffectue() const;
    void setEffectue(bool newEffectue);

    Interaction *getInteraction() const;

    friend bool operator<(Todo&, Todo&);

private:
    Date echeance;
    std::string contenue;
    bool effectue;
    size_t positionDate;

    Interaction* interaction;
};
