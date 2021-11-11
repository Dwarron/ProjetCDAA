/**
 * \file CreationFicheWindow.cpp
 * \class CreationFicheWindow CreationFicheWindow.h
 * \brief Fenetre qui permet de creer la fiche d'un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "CreationFicheWindow.h"
#include <ui_CreationFicheWindow.h>
#include <QObject>

CreationFicheWindow::CreationFicheWindow(GestionContact *g, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreationFicheWindow)
{
    ui->setupUi(this);

    gestCont = g;

    connect(ui->validButton, SIGNAL(clicked()), this, SLOT(CreationFiche()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
}

void CreationFicheWindow::CreationFiche()
{
    //ici on ajoute ce contact a la gestion des contact
    emit gestCont->creeContact( ui->nomLineEdit->text().toStdString(),
                                ui->prenomLineEdit->text().toStdString(),
                                ui->entrepriseLineEdit->text().toStdString(),
                                ui->telLineEdit->text().toStdString(),
                                ui->mailLineEdit->text().toStdString(),
                                ui->photoLineEdit->text().toStdString()
                              );
    //A voir
    //QFile file("fichier.txt");
    //if (!file.open(QIODevice::ReadOnly | QIODevice::Text))

    //utiliser proposeNom pour le nom et le prénom

    //apres avoir crée le contact avec les informations de la fentre on la ferme
    this->close();
}

CreationFicheWindow::~CreationFicheWindow()
{
    delete ui;
}
