/**
 * \file MainWindow.cpp
 * \class MainWindow MainWindow.h
 * \brief Fenetre qui permet de gerer l'ensemble des fenetres de cette application
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

/**
 *  \brief Constructeur standard
 *
 *  Constructeur standard de la classe MainWindow.
 *  Effectue les connexions entre les differents fenetres et evenement a declencher.
 *
 *  \param g : gestion des contacts
 *  \param parent : fenetre parent
 */
MainWindow::MainWindow(GestionContact *g, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gestCont = g;

    connect(ui->actionA_propos, SIGNAL(triggered(bool)), this, SLOT(slot_aPropos()));
    connect(ui->ButtonCreerFiche, SIGNAL(clicked()), this, SLOT(openWindowCreeFiche()));
    connect(ui->ButtonModifContact, SIGNAL(clicked()), this, SLOT(openWindowModifFiche()));
    connect(ui->ButtonRechercherContact, SIGNAL(clicked()), this, SLOT(openWindowRechercheContact()));
    connect(ui->ButtonAjouterEvenement, SIGNAL(clicked()), this, SLOT(openWindowAjoutInteraction()));
    connect(ui->ButtonModifEvent, SIGNAL(clicked()), this, SLOT(openWindowModifEvent()));
    connect(ui->ButtonRequete, SIGNAL(clicked()), this, SLOT(openWindowRequete()));
}

/**
  *  \brief Fenetre de creation de la fiche d'un contact
  *
  *  Slot qui permet l'ouverture de la fenetre de creation d'une fiche.
  */
void MainWindow::openWindowCreeFiche()
{
    creatfich = new CreationFicheWindow(gestCont);
    creatfich->show();
}

/**
  *  \brief Fenetre de modification de la fiche d'un contact
  *
  *  Slot qui permet l'ouverture de la fenetre de modification d'une fiche.
  */
void MainWindow::openWindowModifFiche()
{
    modiffich = new ModificationContactWindow(gestCont);
    modiffich->show();
}

/**
  *  \brief Fenetre de recherche d'un contact
  *
  *  Slot qui permet l'ouverture de la fenetre de recherche d'un contact.
  */
void MainWindow::openWindowRechercheContact()
{
    rechcontact = new RechercheContactWindow(gestCont);
    rechcontact->show();
}

/**
  *  \brief Fenetre d'ajout d'interaction a un contact
  *
  *  Slot qui permet l'ouverture de la fenetre d'ajout d'interaction a un contact.
  */
void MainWindow::openWindowAjoutInteraction()
{
    ajoutinter = new AjoutEvenementWindow(gestCont);
    ajoutinter->show();
}

/**
  *  \brief Fenetre de modification d'interaction d'un contact
  *
  *  Slot qui permet l'ouverture de la fenetre de modification d'interaction d'un contact.
  */
void MainWindow::openWindowModifEvent()
{
    modifevent = new ModificationEvenementWindow(gestCont);
    modifevent->show();
}

/**
  *  \brief Fenetre sur les requetes
  *
  *  Slot qui permet l'ouverture de la fenetre sur les requetes.
  */
void MainWindow::openWindowRequete()
{
    requete = new RequeteWindow(gestCont);
    requete->show();
}

/**
  *  \brief A propos de l'application
  *
  *  Affiche le fonctionnement globale de l'application dans un QMessageBox.
  */
void MainWindow::slot_aPropos()
{
    QMessageBox *messageAbout = new QMessageBox();
    messageAbout->about(this, "A propos",
    "Le but de cette applications est de produire un logiciel de gestion de relations clients "
    "prenant en compte des interactions et des taches à faire, extraites de ces interactions. "
    "Qui utilise également une base de données SQL afin de stocker les contacts et les interactions.");
}

/**
 *  \brief Destructeur de ModificationContactWindow
 *
 *  Detruis en memoire la fenetre
 */
MainWindow::~MainWindow()
{
    delete ui;
}
