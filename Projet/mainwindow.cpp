#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_CreationFicheWindow.h"

#include <QObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->ButtonCreerFiche, SIGNAL(clicked()), this, SLOT(openWindow()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openWindow()
{
    creatfich = new CreationFicheWindow();
    creatfich->show();
}
