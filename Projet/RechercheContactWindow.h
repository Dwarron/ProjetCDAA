#ifndef RECHERCHECONTACTWINDOW_H
#define RECHERCHECONTACTWINDOW_H

/**
 * \file RechercheContactWindow.h
 * \class RechercheContactWindow RechercheContactWindow.h
 * \brief Fenetre avec laquel on peut rechercher un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QWidget>
#include "gestioncontact.h"

namespace Ui { class RechercheContactWindow; }

class RechercheContactWindow : public QWidget
{
    Q_OBJECT

public:
    RechercheContactWindow(GestionContact *g, QWidget *parent = nullptr);
    ~RechercheContactWindow();

private:
    Ui::RechercheContactWindow *ui;
    GestionContact *gestCont;

private slots:
    void rechercheContact();

};

#endif // RECHERCHECONTACTWINDOW_H
