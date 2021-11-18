/**
 * \file AjoutEvenementWindow.cpp
 * \class AjoutEvenementWindow AjoutEvenementWindow.h
 * \brief Fenetre qui permet de creer de nouvelle interactions ou d'en reutiliser des anciennes. Et de l'ajouter au contact.
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "AjoutEvenementWindow.h"
#include <ui_AjoutEvenementWindow.h>

using namespace std;

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
    connect(ui->newEventRadionButton, SIGNAL(clicked()), this, SLOT(NouvelEvenement()));
    connect(ui->eventComboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(LoadEvenement(QString)));
    connect(ui->validButton, SIGNAL(clicked()), this, SLOT(AjoutEvenement()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
}

/**
  *  \brief Charge le contact selectionne
  *
  *  \param c : le contact selectionne
  */
void AjoutEvenementWindow::selectContact(Contact* c)
{
    curContact = c;
}

/**
  *  \brief Charge l'interaction selectionne
  *
  *  Methode qui permet de recuperer l'interaction selectionne dans la comboBox.
  *
  *  \param event : l'interaction selectionne
  */
void AjoutEvenementWindow::LoadEvenement(QString event)
{
    for(auto it = curContact->getInteractions().begin(); it != curContact->getInteractions().end(); it++)
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

    int maxNbLignes = 1;

    list<Interaction*> interactions = gestCont->getAllInteractions();
    for(auto it = interactions.begin(); it != interactions.end(); it++)
    {
        string newElement = (*it)->toString();
        size_t position = 0;
        int nbLignes = 1;
        while((position = newElement.find("\n", position + 1)) != string::npos)
        {
            nbLignes++;
        }

        if(nbLignes > maxNbLignes)
        {
            maxNbLignes = nbLignes;
        }

        ui->eventComboBox->addItem(QString::fromStdString(newElement));
    }

   ui->eventComboBox->setMinimumHeight(interactions.size() * maxNbLignes * 4);     // 4 pixels par ligne
}

/**
  *  \brief Prepare au choix de la nouvelle interaction
  *
  *  Slot qui cache le Widget lineEdit, et qui recupere une interaction deja existante.
  *  Et envoie un signal pour remplir la comboBox des interactions.
  */
void AjoutEvenementWindow::ChoixEvenement()
{
    ui->newEventText->setVisible(false);
    ui->eventComboBox->setVisible(true);
FillEventComboBox();
   // emit FillEventComboBox();
}

/**
  *  \brief Recuperer nouvelle interaction
  *
  *  Slot qui permet de cacher la comboBox, et de recupere la chaine de caractere qui sera la nouvelle interaction.
  */
void AjoutEvenementWindow::NouvelEvenement()
{
    ui->eventComboBox->setVisible(false);
    ui->newEventText->setVisible(true);
    interaction = ui->newEventText->toPlainText().toStdString();
}

/**
  *  \brief Ajoute l'interaction
  *
  *  Slot qui permet d'ajouter au contact l'interation selectionne ou cree.
  */
void AjoutEvenementWindow::AjoutEvenement()
{
    if( interaction != "")
        gestCont->ajoutInteraction(curContact, interaction);
    else
        gestCont->ajoutInteraction(curContact, i);

    //apres avoir ajouter l'événement avec les informations de la fenetre on la ferme
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
