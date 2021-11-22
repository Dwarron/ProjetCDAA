#include <QtSql/QSqlQuery>
#include <QDir>
#include <stdexcept>
#include <QSqlError>
#include <QtDebug>
#include "DatabaseManager.h"

using namespace std;

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QDir::currentPath()+ QDir::separator() + "base.sqlite");

    if(!db.open())
    {
        throw runtime_error("Unable to open database");
    }
}

void DatabaseManager::loadAllContacts()
{
    QSqlQuery query("Select * from Contact;");

    if(!query.exec())
    {
       throw runtime_error("Unable to load contacts : " + db.lastError().text().toStdString());
    }
    else
    {
       while(query.next())
       {
            const string& nom = query.value(1).toString().toStdString();
            const string& prenom = query.value(2).toString().toStdString();
            const string& entreprise = query.value(3).toString().toStdString();
            const string& telephone = query.value(4).toString().toStdString();
            const string& mail = query.value(5).toString().toStdString();
            const string& photo = query.value(6).toString().toStdString();
            const string& dateCreation = query.value(7).toString().toStdString();
            const string& dateModif = query.value(8).toString().toStdString();

            emit loadContact(nom, prenom, entreprise, telephone, mail, photo, dateCreation, dateModif);
       }
    }
}

void DatabaseManager::createContact(string n, string p, string e, string tel, string m, string uri, string dc, string dm)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Contact (nom, prenom, entreprise, telephone, mail, uriPhoto, dateCreation, dateModification) "
                  "VALUES (:nom, :prenom, :entreprise, :tel, :mail, :photo, :dateCreation, :dateModification)");
    query.bindValue(":nom", QVariant(QString::fromStdString(n)));
    query.bindValue(":prenom", QVariant(QString::fromStdString(p)));
    query.bindValue(":entreprise", QVariant(QString::fromStdString(e)));
    query.bindValue(":tel", QVariant(QString::fromStdString(tel)));
    query.bindValue(":mail", QVariant(QString::fromStdString(m)));
    query.bindValue(":photo", QVariant(QString::fromStdString(uri)));
    query.bindValue(":dateCreation", QVariant(QString::fromStdString(dc)));
    query.bindValue(":dateModification", QVariant(QString::fromStdString(dm)));
    if(!query.exec())
    {
       throw runtime_error("Error inserting contact in bdd : " + db.lastError().text().toStdString());
    }
}
