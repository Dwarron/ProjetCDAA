/**
 * \file AjoutEvenementWindow.cpp
 * \class AjoutEvenementWindow AjoutEvenementWindow.h
 * \brief Fenetre qui permet de creer de nouvelle interactions ou d'en reutiliser des anciennes. Et de l'ajouter au contact.
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "AjoutEvenementWindow.h"
#include <ui_AjoutEvenementWindow.h>

/**
 *  \brief Constructeur standard
 *
 *  Constructeur standard de la classe AjoutEvenementWindow.
 *  Effectue les connexions entre les differents Widget et evenement a declencher.
 *  Permet de remplir l'ensemble de la comboBox des contacts.
 *
 *  \param g : gestion des contacts
 *  \param parent : fenetre parent
 */
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

/**
  *  \brief Charge le contact selectionne
  *
  *  Methode qui permet de recuperer le contact selectionne dans la comboBox.
  *
  *  \param contact : le contact selectionne
  */
void AjoutEvenementWindow::LoadContactSelectionner(QString contact)
{
    for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
    {
        if( (*it)->toString() == contact.toStdString() )
            c = *it;
    }
}

/**
  *  \brief Charge l'interaction selectionne
  *
  *  Methode qui permet de recuperer l'interaction selectionne dans la comboBox.
  *
  *  \param event : l'interaction selectionne
  */
void AjoutEvenementWindow::LoadEvenementSelectionner(QString event)
{
    for(auto it = c->getInteractions().begin(); it != c->getInteractions().end(); it++)
    {
        if( (*it)->toString() == event.toStdString() )
            i = *it;
    }
}

/**
  *  \brief Remplie la comboBox des interactions
  *
  *  Signal qui permet de remplir la comboBox des interactions deja existante dans la gestion des contacts.
  *  Permet egalement de redimensionner la comboBox si une interaction est de grande taille.
  */
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

/**
  *  \brief Prepare au choix de la nouvelle interaction
  *
  *  Slot qui cache le Widget lineEdit, et qui recupere une interaction deja existante.
  *  Et envoie un signal pour remplir la comboBox des interactions.
  */
void AjoutEvenementWindow::ChoixEvenement()
{
    ui->newEventlineEdit->setVisible(false);
    ui->eventComboBox->setVisible(true);

    emit FillEventComboBox();
}

/**
  *  \brief Recuperer nouvelle interaction
  *
  *  Slot qui permet de cacher la comboBox, et de recupere la chaine de caractere qui sera la nouvelle interaction.
  */
void AjoutEvenementWindow::NouvelleEvenement()
{
    ui->eventComboBox->setVisible(false);
    ui->newEventlineEdit->setVisible(true);
    interaction = ui->newEventlineEdit->text().toStdString();
}

/**
  *  \brief Ajoute l'interaction
  *
  *  Slot qui permet d'ajouter au contact l'interation selectionne ou cree.
  */
void AjoutEvenementWindow::AjoutEvenement()
{
    if( interaction != "")
        gestCont->ajoutInteraction(c, interaction);
    else
        gestCont->ajoutInteraction(c, i);

    //apres avoir ajouter l'événement avec les informations de la fentre on la ferme
    this->close();
}

/**
 *  \brief Destructeur de AjoutEvenementWindow
 *
 *  Detruis en memoire la fenetre
 */
AjoutEvenementWindow::~AjoutEvenementWindow()
{
    delete ui;
}
