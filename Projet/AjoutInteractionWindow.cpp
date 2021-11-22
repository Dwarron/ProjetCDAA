/**
 * \file AjoutEvenementWindow.cpp
 * \class AjoutEvenementWindow AjoutEvenementWindow.h
 * \brief Fenetre qui permet de creer de nouvelle interactions ou d'en reutiliser des anciennes. Et de l'ajouter au contact.
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "AjoutInteractionWindow.h"
#include <ui_AjoutInteractionWindow.h>

using namespace std;

/**
 *  \brief Constructeur standard
 *
 *  Constructeur standard de la classe AjoutEvenementWindow.
 *  Effectue les connexions entre les differents Widget et evenement a declencher.
 *  Permet de remplir l'ensemble de la comboBox des contacts.
 *
 *  \param parent : fenetre parent
 */
AjoutInteractionWindow::AjoutInteractionWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AjoutInteractionWindow)
{
    ui->setupUi(this);

    rechContactWindow = new RechercheContactWindow();
    rechContactWindow->setWindowTitle("Recherche du contact sur lequel se trouve l'évènement à ajouter");
    rechContactWindow->setWindowModality(Qt::ApplicationModal);
    afficheInteractionsWindow = new AfficheInteractionsWindow();
    afficheInteractionsWindow->setWindowModality(Qt::ApplicationModal);

    connect(this, SIGNAL(listContactsUpdated(std::list<Contact*>)), rechContactWindow, SLOT(updateListContacts(std::list<Contact*>)));
    connect(this, SIGNAL(onEndModifContact()), rechContactWindow, SLOT(rechercheContact()));

    connect(rechContactWindow, SIGNAL(contactSelected(Contact*)), rechContactWindow, SLOT(hide()));
    connect(rechContactWindow, SIGNAL(contactSelected(Contact*)), afficheInteractionsWindow, SLOT(show()));
    connect(rechContactWindow, SIGNAL(contactSelected(Contact*)), afficheInteractionsWindow, SLOT(selectContact(Contact*)));
    connect(afficheInteractionsWindow, SIGNAL(interactionSelected(Interaction*)), this, SLOT(selectInteraction(Interaction*)));
    connect(afficheInteractionsWindow, SIGNAL(interactionSelected(Interaction*)), afficheInteractionsWindow, SLOT(hide()));
    connect(afficheInteractionsWindow, SIGNAL(interactionSelected(Interaction*)), this, SLOT(hide()));

    connect(ui->existingEventButton, SIGNAL(clicked()), rechContactWindow, SLOT(show()));
    connect(ui->newEventButton, SIGNAL(clicked()), this, SLOT(ajoutEvenement()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
}

/**
  *  \brief Charge le contact selectionne
  *
  *  \param c : le contact selectionne
  */
void AjoutInteractionWindow::selectContact(Contact* c)
{
    curContact = c;

    if(curContact == nullptr)
    {
        this->hide();
    }
}

void AjoutInteractionWindow::selectInteraction(Interaction* i)
{
    emit ajoutInteraction(curContact, i);
}

/**
  *  \brief Ajoute l'interaction
  *
  *  Slot qui permet d'ajouter au contact l'interation selectionne ou cree.
  */
void AjoutInteractionWindow::ajoutEvenement()
{
    if(curContact != nullptr && ui->newEventText->toPlainText().length() > 0)
    {
        emit ajoutInteraction(curContact, ui->newEventText->toPlainText());

        ui->newEventText->setText("");

        //apres avoir ajouter l'événement avec les informations de la fenetre on la ferme
        this->hide();
    }
}

/**
 *  \brief Destructeur de AjoutEvenementWindow
 *
 *  Detruis en memoire la fenetre et ses sous-fenêtres
 */
AjoutInteractionWindow::~AjoutInteractionWindow()
{
    delete ui;
    delete rechContactWindow;
    delete afficheInteractionsWindow;
}
