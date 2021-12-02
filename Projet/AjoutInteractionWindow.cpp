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
 *  Effectue les connexions signaux/slots
 *
 *  \param contacts : la liste des contacts lors de la creation de la fenetre
 *  \param parent : fenetre parent
 */
AjoutInteractionWindow::AjoutInteractionWindow(list<Contact*> contacts, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AjoutInteractionWindow)
{
    ui->setupUi(this);

    rechContactWindow = new RechercheContactWindow(contacts);
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
    connect(ui->newEventButton, SIGNAL(clicked()), this, SLOT(ajoutInteraction()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
}

/**
  *  \brief Charge le contact selectionne
  *
  *  Slot appele lors du changement du contact selectionne, le stocke dans le contact courant
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

/**
  *  \brief Charge l'interaction selectionne
  *
  *  Slot appele lors de la selection de l'interaction que l'on veut ajouter au contact courant
  *  \param i : l'interaction selectionne
  */
void AjoutInteractionWindow::selectInteraction(Interaction* i)
{
    emit ajoutInteraction(curContact, i);
}

/**
  *  \brief Ajoute l'interaction
  *
  *  Slot qui permet d'ajouter au contact l'interaction cree, appele lors du click sur le bouton
  */
void AjoutInteractionWindow::ajoutInteraction()
{
    if(curContact != nullptr && ui->newEventText->toPlainText().length() > 0)
    {
        emit ajoutInteraction(curContact, ui->newEventText->toPlainText());

        ui->newEventText->setText("");

        //apres avoir ajoute l'interaction avec les informations de la fenetre, on la referme
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
