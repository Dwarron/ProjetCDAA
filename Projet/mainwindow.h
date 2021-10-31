#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <CreationFicheWindow.h>
#include <ModificationContactWindow.h>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CreationFicheWindow *creatfich;
    ModificationContactWindow *modiffich;

private slots:
    void openWindowCreeFiche();
    void openWindowModifFiche();

};
#endif // MAINWINDOW_H
