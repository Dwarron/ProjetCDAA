#include "CreationFicheWindow.h"
#include <ui_CreationFicheWindow.h>
#include "Contact.h"
#include "contact.h"
#include <QObject>
#include <iostream>

using namespace std;

CreationFicheWindow::CreationFicheWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreationFicheWindow)
{
    ui->setupUi(this);

    connect(ui->validButton, SIGNAL(clicked()), this, SLOT(CreationFiche()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
}

CreationFicheWindow::~CreationFicheWindow()
{
    delete ui;
}

void CreationFicheWindow::CreationFiche()
{
    //ici on ajoute ce contact a la gestion des contact
    g->creeContact( ui->nomLineEdit->text().toStdString(),
                    ui->prenomLineEdit->text().toStdString(),
                    ui->entrepriseLineEdit->text().toStdString(),
                    ui->telLineEdit->text().toStdString(),
                    ui->mailLineEdit->text().toStdString(),
                    ui->photoLineEdit->text().toStdString()
                  );

    //utiliser proposeNom pour le nom et le prénom

    for(auto it = g->getContacts().begin(); it != g->getContacts().end(); it++)
    {
        cout << "Contact cree : " << (*it)->getNom() << endl;
    }

    //apres avoir crée le contact avec les informations de la fentre on la ferme
    this->close();
}
