#ifndef REQUETEWINDOW_H
#define REQUETEWINDOW_H

/**
 * \file RequeteWindow.h
 * \class RequeteWindow RequeteWindow.h
 * \brief Fenetre qui affiche differentes requetes selectionnables
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QWidget>
#include <QStandardItemModel>
#include <QStringListModel>
#include "Contact.h"

namespace Ui { class RequeteWindow; }

class RequeteWindow: public QWidget
{
    Q_OBJECT

public:
    RequeteWindow(std::list<Contact*>, QWidget* parent = nullptr);
    ~RequeteWindow();

private:
    Ui::RequeteWindow* ui;
    std::list<Contact*> contacts;
    Contact* curContact;
    QStandardItemModel* modelCheckableListViewContact;
    QStringListModel* modelStringListViewContact;
    QStandardItemModel* modelCheckableListViewAllContacts;
    QStringListModel* modelStringListViewAllContacts;
    std::list<Todo*> todosShownListViewContact;
    std::list<Todo*> todosShownListViewAllContacts;

private slots:
    void updateListContacts(std::list<Contact*>);
    void loadInfosInteractions2Dates();
    void loadInfosContact(Contact*);
    void loadInfosContact();
    void loadInfosAllContacts();
    void todoItemCheckedListViewContact(QStandardItem*);
    void todoItemCheckedListViewAllContacts(QStandardItem*);

signals:
    void todoSetEffectue(Todo*, bool);
};

#endif // REQUETEWINDOW_H
