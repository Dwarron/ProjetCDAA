#ifndef EMAIL_H
#define EMAIL_H

/*!
 * \file Email.h
 * \brief Stocke un email
 * \author Perion Maxence
 * \version 0.1
 */

#include <string>

using namespace std;

class Email
{
public:
    Email();
    Email(const string&, const string&);

    const string toString() const;

private:
    string identifiant;
    string domaine;

};

#endif // EMAIL_H
