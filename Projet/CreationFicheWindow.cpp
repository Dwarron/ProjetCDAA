#include "CreationFicheWindow.h"
#include <ui_CreationFicheWindow.h>
#include "Contact.h"
#include <QObject>
#include <iostream>

using namespace std;

CreationFicheWindow::CreationFicheWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreationFicheWindow)
{
    ui->setupUi(this);

    connect(ui->validButton, SIGNAL(clicked()), this, SLOT(CreationFiche()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(quit()));
}

CreationFicheWindow::~CreationFicheWindow()
{
    delete ui;
}

void CreationFicheWindow::CreationFiche()
{
    Contact c(  ui->nomLineEdit->text().toStdString(),
                ui->prenomLineEdit->text().toStdString(),
                ui->entrepriseLineEdit->text().toStdString(),
                ui->telLineEdit->text().toStdString(),
                ui->mailLineEdit->text().toStdString(),
                ui->photoLineEdit->text().toStdString()
             );

    //utiliser proposeNom pour le nom et le prénom

    cout << "Contact crée : " << c << endl;
}
