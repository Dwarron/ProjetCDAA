#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_CreationFicheWindow.h"
#include "ui_ModificationContactWindow.h"

#include <QObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->ButtonCreerFiche, SIGNAL(clicked()), this, SLOT(openWindowCreeFiche()));
    connect(ui->ButtonModifContact, SIGNAL(clicked()), this, SLOT(openWindowModifFiche()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openWindowCreeFiche()
{
    creatfich = new CreationFicheWindow();
    creatfich->show();
}

void MainWindow::openWindowModifFiche()
{
    modiffich = new ModificationContactWindow();
    modiffich->show();
}
