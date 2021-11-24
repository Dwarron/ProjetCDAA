#ifndef JSONSERIALIZER_H
#define JSONSERIALIZER_H

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
