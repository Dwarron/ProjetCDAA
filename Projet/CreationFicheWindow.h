#ifndef CREATIONFICHEWINDOW_H
#define CREATIONFICHEWINDOW_H

/**
 * \file CreationFicheWindow.h
 * \class CreationFicheWindow CreationFicheWindow.h
 * \brief Fenetre qui permet de creer la fiche d'un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QWidget>
#include "gestioncontact.h"

namespace Ui { class CreationFicheWindow; }

class CreationFicheWindow : public QWidget
{
    Q_OBJECT

public:
    CreationFicheWindow(GestionContact *g, QWidget *parent = nullptr);
    ~CreationFicheWindow();

private:
    Ui::CreationFicheWindow *ui;
    GestionContact *gestCont;
    QString file_name;

private slots:
    void CreationFiche();
    void SelectFile();
};

#endif // CREATIONFICHEWINDOW_H
