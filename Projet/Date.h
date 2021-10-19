#ifndef DATE_H
#define DATE_H

/**
 * \file Date.h
 * \class Date Date.h
 * \brief Stocke une date
 * \author Perion Maxence
 * \version 0.1
 */

#include <string>

using namespace std;

class Date
{
public:
    Date();
    Date(const int, const int, const int);
    Date(const string&);

    ~Date();

    int getJour() const;
    int getMois() const;
    int getAnnee() const;

    void addDelay(const int);
    void addDelay(const int, const int);
    void addDelay(const int, const int, const int);

    bool depassee() const;

    friend ostream& operator << (ostream&, const Date&);
    const string toString() const;

    friend bool operator<(const Date&, const Date&);

private:
    struct tm *d;

};

#endif // DATE_H
