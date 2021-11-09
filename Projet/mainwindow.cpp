#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_CreationFicheWindow.h"
#include "ui_ModificationContactWindow.h"

#include <QObject>

#include <QDebug>

MainWindow::MainWindow(GestionContact *g, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gestCont = g;

    connect(ui->ButtonCreerFiche, SIGNAL(clicked()), this, SLOT(openWindowCreeFiche()));
    connect(ui->ButtonModifContact, SIGNAL(clicked()), this, SLOT(openWindowModifFiche()));
    connect(ui->ButtonRechercherContact, SIGNAL(clicked()), this, SLOT(openWindowRechercheContact()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openWindowCreeFiche()
{
    creatfich = new CreationFicheWindow(gestCont);
    creatfich->show();
}

void MainWindow::openWindowModifFiche()
{
    modiffich = new ModificationContactWindow(gestCont);
    modiffich->show();
}

void MainWindow::openWindowRechercheContact()
{
    rechcontact = new RechercheContactWindow(gestCont);
    rechcontact->show();
}

