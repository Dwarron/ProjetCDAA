/**
 * \file ModificationEvenementWindow.cpp
 * \class ModificationEvenementWindow ModificationEvenementWindow.h
 * \brief Fenetre qui permet de modifier un evenement/interaction
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "ModificationEvenementWindow.h"
#include "ui_ModificationEvenementWindow.h"

/**
 *  \brief Constructeur standard
 *
 *  Constructeur standard de la classe ModificationEvenementWindow.
 *  Effectue les connexions entre les differents Widget et evenement a declencher.
 *  Permet de remplir l'ensemble de la comboBox des contacts.
 *
 *  \param g : gestion des contacts
 *  \param parent : fenetre parent
 */
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

/**
  *  \brief Charge le contact selectionne
  *
  *  Slot qui permet de recuperer le contact selectionne dans la comboBox.
  *
  *  \param contact : le contact selectionne
  */
void ModificationEvenementWindow::LoadContactSelectionner(QString contact)
{
    for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
    {
        if( (*it)->toString() == contact.toStdString() )
            c = *it;
    }

    emit FillEventComboBox();
}

/**
  *  \brief Remplie la comboBox des interactions
  *
  *  Signal avec lequel on va remplir la comboBox des interactions.
  *  Permet egalement de redimensionner la comboBox si une interaction est de grande taille.
  */
void ModificationEvenementWindow::FillEventComboBox()
{
    ui->eventComboBox->clear();
    int size = 1;

    for(auto it = c->getInteractions().begin(); it != c->getInteractions().end(); it++)
    {
        ui->eventComboBox->addItem(QString::fromStdString((*it)->toString()));

        if( static_cast<int>(((*it)->toString().length())) > size)
            size = static_cast<int>(((*it)->toString().length()));
    }

    ui->eventComboBox->setMinimumHeight(size);
}

/**
  *  \brief Charge l'interaction selectionne
  *
  *  Slot qui permet de recuperer l'interaction selectionne dans la comboBox.
  *
  *  \param event : l'interaction selectionne
  */
void ModificationEvenementWindow::LoadEvenementSelectionner(QString event)
{
    for(auto it = c->getInteractions().begin(); it != c->getInteractions().end(); it++)
    {
        if( (*it)->toString() == event.toStdString() )
            i = *it;
    }
}

/**
  *  \brief Modifie l'interaction
  *
  *  Slot qui a pour effet de modifie l'interaction d'un contact.
  *  Il est possible de changer le contenue l'interaction et/ou la date des todos.
  *  Pour changer le contenue d'un todo il doit etre ecrit avec @todo pour creer un todo et @date pour lui associer une date.
  *
  */
void ModificationEvenementWindow::ModifEvent()
{
    interaction = ui->modifEventLineEdit->text().toStdString();
    temps = ui->addTimeLineEdit->text().toStdString();

    if( interaction != "" && temps != "")
    {
       i->setResume(interaction);

       //on parcours les todos de l'interaction pour ajouter le temps
       for(auto it = i->getTodos().begin(); it != i->getTodos().end(); it++)
       {
            (*it)->getEcheance().addDelay(std::stoi(temps));
       }
    }
    else if( interaction != "" )
        i->setResume(interaction);
    else if( temps != "")
    {
        //on parcours les todos de l'interaction pour ajouter le temps
        for(auto it = i->getTodos().begin(); it != i->getTodos().end(); it++)
        {
            (*it)->getEcheance().addDelay(std::stoi(temps));
            //petit soucis ici on a bien du temps qui s'ajoute aux todos mais dans le contenue du todo le temps ne se modifie pas
            //en effet il faudrais changer le contenue des todos pour etre parfaitement parfait
        }
    }

    //apres avoir modifier l'événement avec les informations de la fentre on la ferme
    this->close();
}

/**
 *  \brief Destructeur de ModificationEvenementWindow
 *
 *  Detruis en memoire la fenetre
 */
ModificationEvenementWindow::~ModificationEvenementWindow()
{
    delete ui;
}
