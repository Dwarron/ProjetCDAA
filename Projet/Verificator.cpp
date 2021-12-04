#include <stdexcept>
#include "Verificator.h"

using namespace std;

/**
  *  \brief Test si la chaine entree est conforme
  *
  *  Fonction utilitaire qui renvoie une exception si la chaine contient autre chose que des lettres, un espace ou un tiret
  *
  *  \param chaine : la chaine a tester
  */
void Verificator::checkLettres(const string& chaine)
{
    size_t position = chaine.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ -");
    if(position != string::npos)
    {
        throw invalid_argument("Chaine mal formee (doit contenir uniquement des lettres)");
    }
}

/**
  *  \brief Test si la chaine entree est conforme
  *
  *  Methode qui renvoie une exception si la chaine contient autre chose que des chiffres
  *
  *  \param chaine : la chaine a tester
  */
void Verificator::checkChiffres(const string& chaine)
{
    size_t position = chaine.find_first_not_of("0123456789");
    if(position != string::npos)
    {
        throw invalid_argument("Chaine mal formee (doit contenir uniquement des chiffres)");
    }
}

/**
  *  \brief Test si la chaine entree est conforme
  *
  *  Methode qui renvoie une exception si la chaine ne decrit pas un mail
  *
  *  \param chaine : la chaine a tester
  */
void Verificator::checkMail(const string& chaine)
{
    size_t positionArobase = chaine.find("@");

    if(positionArobase == string::npos)
    {
        throw invalid_argument("Mail mal forme : doit contenir exactement 1 @");
    }
    else
    {
        size_t positionArobase2 = chaine.find("@", positionArobase + 1);
        if(positionArobase2 != string::npos)
        {
            throw invalid_argument("Mail mal forme : doit contenir exactement 1 @");
        }
    }

    size_t positionPoint = chaine.find(".", positionArobase);
    if(positionPoint == string::npos)
    {
        throw invalid_argument("Mail mal forme : doit contenir au moins un point apres @");
    }
}

/**
  *  \brief Test si la chaine entree est conforme
  *
  *  Methode qui renvoie une exception si la chaine ne decrit pas un mail
  *
  *  \param chaine : la chaine a tester
  */
void Verificator::checkTelephone(const string& chaine)
{
    if(chaine.length() != 10)
    {
        throw invalid_argument("Telephone mal forme : doit avoir une longueur de 10 chiffres");
    }
    checkChiffres(chaine);
}

/**
  *  \brief Propose une suggestion de nom pour une chaine entree ne correspondant pas a ce qui est attendu
  *
  *  Methode qui retire tous les chiffres et caracteres speciaux
  *
  *  \param chaine : la chaine a verifier
  */
const string Verificator::onlyLetters(string chaine)
{
    size_t position = chaine.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZéèùà -");
    while(position != string::npos)
    {
        chaine = chaine.substr(0, position) + chaine.substr(position + 1);
        position = chaine.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZéèùà -");
    }

    return chaine;
}
