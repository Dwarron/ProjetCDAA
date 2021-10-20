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

class Date
{
public:
    Date();
    Date(const int, const int, const int);
    Date(const std::string&);

    ~Date();

    int getJour() const;
    int getMois() const;
    int getAnnee() const;

    void addDelay(const int);
    void addDelay(const int, const int);
    void addDelay(const int, const int, const int);

    bool depassee() const;

    friend std::ostream& operator << (std::ostream&, const Date&);
    const std::string toString() const;

    friend bool operator<(const Date&, const Date&);
    friend std::string operator+(const std::string&, const Date&);
    friend int operator-(const Date&, const Date&);
    friend bool operator==(const Date&, const Date&);

private:
    struct tm *d;

};

#endif // DATE_H
