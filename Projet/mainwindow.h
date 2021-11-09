#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <CreationFicheWindow.h>
#include <ModificationContactWindow.h>
#include <RechercheContactWindow.h>
#include <gestioncontact.h>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(GestionContact *g, QWidget *parent = nullptr); // Les arguments avec une valeur par défaut doivent figurer à la fin de la liste des arguments.
    ~MainWindow();

private:
    GestionContact *gestCont;
    Ui::MainWindow *ui;
    CreationFicheWindow *creatfich;
    ModificationContactWindow *modiffich;
    RechercheContactWindow *rechcontact;

private slots:
    void openWindowCreeFiche();
    void openWindowModifFiche();
    void openWindowRechercheContact();

};
#endif // MAINWINDOW_H
