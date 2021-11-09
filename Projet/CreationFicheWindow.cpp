#include "CreationFicheWindow.h"
#include <ui_CreationFicheWindow.h>
#include "Contact.h"
#include <QObject>
#include <iostream>

#include <QDebug>

using namespace std;

CreationFicheWindow::CreationFicheWindow(GestionContact *g, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreationFicheWindow)
{
    ui->setupUi(this);

    qDebug() << "On est dans le constructeur avec GestionContact de creationFicheWindow ";
    gestCont = g;

    connect(ui->validButton, SIGNAL(clicked()), this, SLOT(CreationFiche()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
    qDebug() << "On a effectuer toutes les connexion ";
}

CreationFicheWindow::~CreationFicheWindow()
{
    delete ui;
}

void CreationFicheWindow::CreationFiche()
{
    //ici on ajoute ce contact a la gestion des contact
    emit gestCont->AjoutFicheContacts(   ui->nomLineEdit->text().toStdString(),
                                        ui->prenomLineEdit->text().toStdString(),
                                        ui->entrepriseLineEdit->text().toStdString(),
                                        ui->telLineEdit->text().toStdString(),
                                        ui->mailLineEdit->text().toStdString(),
                                        ui->photoLineEdit->text().toStdString()
                                      );
    //A voir
    //QFile file("Enregistrer.txt");
    //if (!file.open(QIODevice::ReadOnly | QIODevice::Text))

    //utiliser proposeNom pour le nom et le prénom

    //apres avoir crée le contact avec les informations de la fentre on la ferme
    this->close();
}
