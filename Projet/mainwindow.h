#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * \file MainWindow.h
 * \class MainWindow MainWindow.h
 * \brief Fenetre qui permet de gerer l'ensemble des fenetres de cette application
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QMainWindow>
#include <CreationFicheWindow.h>
#include <ModificationContactWindow.h>
#include <RechercheContactWindow.h>
#include <AjoutEvenementWindow.h>
#include <ModificationEvenementWindow.h>
#include <RequeteWindow.h>
#include <gestioncontact.h>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(GestionContact *g, QWidget *parent = nullptr);
    ~MainWindow();

private:
    GestionContact *gestCont;
    Ui::MainWindow *ui;
    CreationFicheWindow *creatfich;
    ModificationContactWindow *modiffich;
    RechercheContactWindow *rechcontact;
    AjoutEvenementWindow *ajoutinter;
    ModificationEvenementWindow *modifevent;
    RequeteWindow *requete;

private slots:
    void openWindowCreeFiche();
    void openWindowModifFiche();
    void openWindowRechercheContact();
    void openWindowAjoutInteraction();
    void openWindowModifEvent();
    void openWindowRequete();
    void slot_aPropos();

};
#endif // MAINWINDOW_H
