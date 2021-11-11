/**
 * \file ModificationEvenementWindow.cpp
 * \class ModificationEvenementWindow ModificationEvenementWindow.h
 * \brief Fenetre qui permet de modifier un evenement
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "ModificationEvenementWindow.h"
#include "ui_ModificationEvenementWindow.h"

ModificationEvenementWindow::ModificationEvenementWindow(GestionContact *g, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModificationEvenementWindow)
{
    ui->setupUi(this);

    gestCont = g;

    connect(ui->validButton, SIGNAL(clicked()), this, SLOT(ModifEvent()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->contactComboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(LoadContactSelectionner(QString)));
    connect(ui->eventComboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(LoadEvenementSelectionner(QString)));

    //on remplie la combo box des contacts
    for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
    {
        ui->contactComboBox->addItem(QString::fromStdString((*it)->toString()));
    }
}

void ModificationEvenementWindow::LoadContactSelectionner(QString contact)
{
    for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
    {
        if( (*it)->toString() == contact.toStdString() )
            c = *it;
    }

    emit FillEventComboBox();
}

void ModificationEvenementWindow::FillEventComboBox()
{
    ui->eventComboBox->clear();

    for(auto it = c->getInteractions().begin(); it != c->getInteractions().end(); it++)
    {
        ui->eventComboBox->addItem(QString::fromStdString((*it)->toString()));
    }
}

void ModificationEvenementWindow::LoadEvenementSelectionner(QString event)
{
    for(auto it = c->getInteractions().begin(); it != c->getInteractions().end(); it++)
    {
        if( (*it)->toString() == event.toStdString() )
            i = *it;
    }
}

void ModificationEvenementWindow::ModifEvent()
{
    interaction = ui->modifEventLineEdit->text().toStdString();
    temps = ui->addTimeLineEdit->text().toStdString();

    if( interaction != "" && temps != "")
    {
       i->setResume(interaction);
       //i->getDate().addDelay(std::stoi(temps));
    }
    else if( interaction != "" )
        i->setResume(interaction);
    else if( temps != "")
    {
        //i->getDate().addDelay(std::stoi(temps));
    }

    //apres avoir modifier l'événement avec les informations de la fentre on la ferme
    this->close();
}

ModificationEvenementWindow::~ModificationEvenementWindow()
{
    delete ui;
}
