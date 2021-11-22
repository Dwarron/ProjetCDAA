#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QtSql/QSqlDatabase>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    void loadAllContacts();

private:
    QSqlDatabase db;

signals:
     void loadContact(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string);

private slots:
    void createContact(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string);
};

#endif // DATABASEMANAGER_H
