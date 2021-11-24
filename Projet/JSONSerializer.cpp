#include <QVariant>
#include <QJsonArray>
#include "JSONSerializer.h"

QJsonObject JSONSerializer::serialize(Contact* c)
{
    QJsonObject object;
    object.insert("nom", QJsonValue(QString::fromStdString(c->getNom())));
    object.insert("prenom", QJsonValue(QString::fromStdString(c->getPrenom())));
    object.insert("entreprise", QJsonValue(QString::fromStdString(c->getEntreprise())));
    object.insert("tel", QJsonValue(QString::fromStdString(c->getTelephone())));
    object.insert("mail", QJsonValue(QString::fromStdString(c->getMail())));
    object.insert("photo", QJsonValue(QString::fromStdString(c->getUriPhoto())));
    return object;
}

QJsonObject JSONSerializer::serialize(Interaction* i)
{
    QJsonObject object;
    object.insert("date", QJsonValue(QString::fromStdString(i->getDate().toString())));
    object.insert("resume", QJsonValue(QString::fromStdString(i->getResume())));

    QJsonArray todos;
    for(auto it = i->getTodos().begin(); it != i->getTodos().end(); it++)
    {
        todos.append(serialize(*it));
    }

    object.insert("todos", todos);
    return object;
}

QJsonObject JSONSerializer::serialize(Todo* t)
{
    QJsonObject object;
    object.insert("echeance", QJsonValue(QString::fromStdString(t->getEcheance().toString())));
    object.insert("contenu", QJsonValue(QString::fromStdString(t->getContenu())));
    object.insert("effectue", QJsonValue::fromVariant(QVariant(t->getEffectue())));
    return object;
}
