#ifndef REQUETEWINDOW_H
#define REQUETEWINDOW_H

/**
 * \file RequeteWindow.h
 * \class RequeteWindow RequeteWindow.h
 * \brief Fenetre avec laquel on peut rechercher un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QWidget>
#include "gestioncontact.h"

namespace Ui { class RequeteWindow; }

class RequeteWindow: public QWidget
{
    Q_OBJECT

public:
    RequeteWindow(GestionContact *g, QWidget *parent = nullptr);
    ~RequeteWindow();

private:
    Ui::RequeteWindow *ui;
    GestionContact *gestCont;

private slots:
    void NombreContacts();
    void EvenementEntre2Dates();
    void ListeTodoDateContact();
    void ListeTodoDateContacts();
    void LoadInfosEvent2Dates();

};

#endif // REQUETEWINDOW_H
