#ifndef JSONSERIALIZER_H
#define JSONSERIALIZER_H

/**
 * \file JSONSerializer.h
 * \class JSONSerializer JSONSerializer.h
 * \brief Classe utilitaire pour serialiser en JSON différentes classes
 * \author Pinon Alexandre, Perion Maxence
 * \version 0.1
 */

#include <QJsonObject>
#include "Contact.h"

class JSONSerializer
{
public:
    static QJsonObject serialize(Contact*);
    static QJsonObject serialize(Interaction*);
    static QJsonObject serialize(Todo*);
};

#endif // JSONSERIALIZER_H
