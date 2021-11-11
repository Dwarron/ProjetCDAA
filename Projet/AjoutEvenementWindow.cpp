/**
 * \file AjoutEvenementWindow.cpp
 * \class AjoutEvenementWindow AjoutEvenementWindow.h
 * \brief Fenetre qui permet de creer de nouvelle interactions ou d'en reutiliser des anciennes
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "AjoutEvenementWindow.h"
#include <ui_AjoutEvenementWindow.h>

AjoutEvenementWindow::AjoutEvenementWindow(GestionContact *g, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AjoutEvenementWindow)
{
    ui->setupUi(this);

    gestCont = g;

    connect(ui->eventRadionButton, SIGNAL(clicked()), this, SLOT(ChoixEvenement()));
    connect(ui->newEventRadionButton, SIGNAL(clicked()), this, SLOT(NouvelleEvenement()));
    connect(ui->contactComboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(LoadContactSelectionner(QString)));
    connect(ui->eventComboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(LoadEvenementSelectionner(QString)));
    connect(ui->validButton, SIGNAL(clicked()), this, SLOT(AjoutEvenement()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));

    //on remplie la combo box des contacts
    for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
    {
        ui->contactComboBox->addItem(QString::fromStdString((*it)->toString()));
    }
}

void AjoutEvenementWindow::LoadContactSelectionner(QString contact)
{
    for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
    {
        if( (*it)->toString() == contact.toStdString() )
            c = *it;
    }
}

void AjoutEvenementWindow::LoadEvenementSelectionner(QString event)
{
    for(auto it = c->getInteractions().begin(); it != c->getInteractions().end(); it++)
    {
        if( (*it)->toString() == event.toStdString() )
            i = *it;
    }
}

void AjoutEvenementWindow::FillEventComboBox()
{
    ui->eventComboBox->clear();
    int size = 1;

    for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
    {
        for(auto it2 = (*it)->getInteractions().begin(); it2 != (*it)->getInteractions().end(); it2++)
        {
            ui->eventComboBox->addItem(QString::fromStdString((*it2)->toString()));

            //ici la taille de la comboBox est adapté quand une interactions est longue
            if( static_cast<int>(((*it2)->toString().length())) > size)
                size = static_cast<int>(((*it2)->toString().length()));
        }
    }

    ui->eventComboBox->setMinimumHeight(size);
}

void AjoutEvenementWindow::ChoixEvenement()
{
    ui->newEventlineEdit->setVisible(false);
    ui->eventComboBox->setVisible(true);

    emit FillEventComboBox();
}

void AjoutEvenementWindow::NouvelleEvenement()
{
    ui->eventComboBox->setVisible(false);
    ui->newEventlineEdit->setVisible(true);
}

void AjoutEvenementWindow::AjoutEvenement()
{
    interaction = ui->newEventlineEdit->text().toStdString();

    if( interaction != "")
        gestCont->ajoutInteraction(c, interaction);
    else
        gestCont->ajoutInteraction(c, i);

    //apres avoir ajouter l'événement avec les informations de la fentre on la ferme
    this->close();
}

AjoutEvenementWindow::~AjoutEvenementWindow()
{
    delete ui;
}
