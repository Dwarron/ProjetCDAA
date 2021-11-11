/**
 * \file ModificationContactWindow.cpp
 * \class ModificationContactWindow ModificationContactWindow.h
 * \brief Fenetre qui permet de modifier la fiche d'un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "ModificationContactWindow.h"
#include "ui_ModificationContactWindow.h"

ModificationContactWindow::ModificationContactWindow(GestionContact *g, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModificationContactWindow)
{
    ui->setupUi(this);

    gestCont = g;

    connect(ui->validButton, SIGNAL(clicked()), this, SLOT(ModifFiche()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->comboContacts, SIGNAL(currentTextChanged(QString)), this, SLOT(LoadContactSelectionner(QString)));

    //on remplie la combo box
    for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
    {
        ui->comboContacts->addItem(QString::fromStdString((*it)->toString()));
    }
}

void ModificationContactWindow::RemplieInfos(Contact *c)
{
    ui->nomLineEdit->setText(QString::fromStdString(c->getNom()));
    ui->prenomLineEdit->setText(QString::fromStdString(c->getPrenom()));
    ui->entrepriseLineEdit->setText(QString::fromStdString(c->getEntreprise()));
    ui->telLineEdit->setText(QString::fromStdString(c->getTelephone()));
    ui->mailLineEdit->setText(QString::fromStdString(c->getMail()));
    ui->photoLineEdit->setText(QString::fromStdString(c->getUriPhoto()));
}

void ModificationContactWindow::LoadContactSelectionner(QString contact)
{
    for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
    {
        if( (*it)->toString() == contact.toStdString() )
            c = *it;
    }

    emit RemplieInfos(c);
}

void ModificationContactWindow::ModifFiche()
{
    //on va regarder quelle champ sont modifier pour utiliser les setters/mutateur
    if(c->getNom() != ui->nomLineEdit->text().toStdString())
        c->setNom(ui->nomLineEdit->text().toStdString());

    if(c->getPrenom() != ui->prenomLineEdit->text().toStdString())
        c->setPrenom(ui->prenomLineEdit->text().toStdString());

    if(c->getEntreprise() != ui->entrepriseLineEdit->text().toStdString())
        c->setEntreprise(ui->entrepriseLineEdit->text().toStdString());

    if(c->getTelephone() != ui->telLineEdit->text().toStdString())
        c->setTelephone(ui->telLineEdit->text().toStdString());

    if(c->getMail() != ui->mailLineEdit->text().toStdString())
        c->setMail(ui->mailLineEdit->text().toStdString());

    if(c->getUriPhoto() != ui->photoLineEdit->text().toStdString())
        c->setUriPhoto(ui->photoLineEdit->text().toStdString());

    //utiliser proposeNom pour le nom et le prénom


    //apres avoir modifier le contact avec les informations de la fentre on la ferme
    this->close();
}

ModificationContactWindow::~ModificationContactWindow()
{
    delete ui;
}
