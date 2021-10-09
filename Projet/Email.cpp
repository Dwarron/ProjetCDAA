#include "Email.h"

/*!
 * \file Email.cpp
 * \brief Stocke un email
 * \author Perion Maxence
 * \version 0.1
 */

#include <string>
#include <stdexcept>

using namespace std;

Email::Email() : Email("", "")
{

}

Email::Email(const string& id, const string& dom)
{
    if(id.size() == 0 || dom.size() == 0)
    {
        throw invalid_argument("identifiant ou domaine vide");
    }
    if(dom.find('.') == std::string::npos)
    {
        throw invalid_argument("domaine invalide");
    }

    identifiant = id;
    domaine = dom;
}

const string Email::toString() const
{
    return identifiant + "@" + domaine;
}
