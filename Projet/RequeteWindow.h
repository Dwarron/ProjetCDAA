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
#include "GestionContact.h"

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
    Contact* c;

private slots:
    void NombreContacts();
    void EvenementEntre2Dates();
    void ListeTodoDateContact();
    void ListeTodoDateContacts();
    void LoadInfosEvent2Dates();
    void LoadInfosSelectContact();
    void LoadInfosContacts();

};

#endif // REQUETEWINDOW_H
