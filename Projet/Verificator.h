#ifndef VERIFICATOR_H
#define VERIFICATOR_H

#include <string>

class Verificator
{
public:
    static void checkLettres(const std::string&);
    static void checkChiffres(const std::string&);
    static void checkMail(const std::string&);
    static void checkTelephone(const std::string&);

    static const std::string onlyLetters(std::string);
};

#endif // VERIFICATOR_H
