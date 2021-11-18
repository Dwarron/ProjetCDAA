/**
 * \file MainWindow.cpp
 * \class MainWindow MainWindow.h
 * \brief Fenetre qui permet de gerer l'ensemble des fenetres de cette application
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QCloseEvent>

using namespace std;

/**
 *  \brief Constructeur standard
 *
 *  Constructeur standard de la classe MainWindow.
 *  Effectue les connections entre les differentes fenetres et evenements a declencher.
 *
 *  \param g : gestion des contacts
 *  \param parent : fenetre parent
 */
MainWindow::MainWindow(GestionContact* g, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gestCont = g;
    creatfich = new CreationFicheWindow(gestCont);
    rechcontact = new RechercheContactWindow(gestCont);
    ajoutinter = new AjoutEvenementWindow(gestCont);
    modifevent = new ModificationEvenementWindow(gestCont);
    requete = new RequeteWindow(gestCont);
    modiffich = new ModificationContactWindow(gestCont);

    connect(this, SIGNAL(listContactsUpdated()), rechcontact, SLOT(updateListContacts()));

    connect(rechcontact, SIGNAL(contactSelected(Contact*)), this, SLOT(selectContact(Contact*)));
    connect(this, SIGNAL(contactSelected(Contact*)), modiffich, SLOT(loadContact(Contact*)));
    connect(this, SIGNAL(contactSelected(Contact*)), ajoutinter, SLOT(selectContact(Contact*)));

    connect(modiffich, SIGNAL(contactDeleted(Contact*)), this, SLOT(deleteContact(Contact*)));
    connect(modiffich, SIGNAL(prenomModified(Contact*,std::string)), this, SLOT(modifPrenom(Contact*,std::string)));
    connect(modiffich, SIGNAL(nomModified(Contact*,std::string)), this, SLOT(modifNom(Contact*,std::string)));
    connect(modiffich, SIGNAL(entrepriseModified(Contact*,std::string)), this, SLOT(modifEntreprise(Contact*,std::string)));
    connect(modiffich, SIGNAL(mailModified(Contact*,std::string)), this, SLOT(modifMail(Contact*,std::string)));
    connect(modiffich, SIGNAL(telephoneModified(Contact*,std::string)), this, SLOT(modifTelephone(Contact*,std::string)));
    connect(modiffich, SIGNAL(photoModified(Contact*,std::string)), this, SLOT(modifPhoto(Contact*,std::string)));

    connect(creatfich, SIGNAL(contactCreated(std::string,std::string,std::string,std::string,std::string,std::string)),
            this, SLOT(createContact(std::string,std::string,std::string,std::string,std::string,std::string)));

    connect(ui->actionA_propos, SIGNAL(triggered(bool)), this, SLOT(slot_aPropos()));
    connect(ui->ButtonCreerFiche, SIGNAL(clicked()), this, SLOT(openWindowCreeFiche()));
    connect(ui->ButtonModifContact, SIGNAL(clicked()), this, SLOT(openWindowModifFiche()));
    connect(ui->ButtonRechercherContact, SIGNAL(clicked()), this, SLOT(openWindowRechercheContact()));
    connect(ui->ButtonAjouterEvenement, SIGNAL(clicked()), this, SLOT(openWindowAjoutInteraction()));
    connect(ui->ButtonModifEvent, SIGNAL(clicked()), this, SLOT(openWindowModifEvent()));
    connect(ui->ButtonRequete, SIGNAL(clicked()), this, SLOT(openWindowRequete()));
}

void MainWindow::updateListContacts()
{
    emit listContactsUpdated();
}

void MainWindow::onContactCreated(Contact* c)
{
    selectContact(c);
}


/**
  *  \brief Fenetre de creation de la fiche d'un contact
  *
  *  Slot qui permet l'ouverture de la fenetre de creation d'une fiche.
  */
void MainWindow::openWindowCreeFiche()
{
    creatfich->show();
}

/**
  *  \brief Fenetre de modification de la fiche d'un contact
  *
  *  Slot qui permet l'ouverture de la fenetre de modification d'une fiche.
  */
void MainWindow::openWindowModifFiche()
{
    modiffich->show();
}

void MainWindow::deleteContact(Contact* c)
{
    emit contactDeleted(c);
}

void MainWindow::modifPrenom(Contact* c, string prenom)
{
    emit prenomModified(c, prenom);
}

void MainWindow::modifNom(Contact* c, string nom)
{
    emit nomModified(c, nom);
}

void MainWindow::modifEntreprise(Contact* c, string entreprise)
{
    emit prenomModified(c, entreprise);
}

void MainWindow::modifTelephone(Contact* c, string telephone)
{
    emit prenomModified(c, telephone);
}

void MainWindow::modifMail(Contact* c, string mail)
{
    emit prenomModified(c, mail);
}

void MainWindow::modifPhoto(Contact* c, string photo)
{
    emit prenomModified(c, photo);
}

/**
  *  \brief Fenetre de recherche d'un contact
  *
  *  Slot qui permet l'ouverture de la fenetre de recherche d'un contact.
  */
void MainWindow::openWindowRechercheContact()
{
    rechcontact->show();
}

void MainWindow::selectContact(Contact* c)
{
    curContact = c;

    bool contactExistant = curContact != nullptr;
    ui->ButtonModifContact->setEnabled(contactExistant);

    if(contactExistant)
    {
        ui->contactSelectionneLabel->setText(QString::fromStdString(c->toString()));
        ui->ButtonRechercherContact->setText(QString::fromStdString("Chercher un autre contact"));
    }
    else
    {
        ui->contactSelectionneLabel->setText(QString::fromStdString("Aucun"));
        ui->ButtonRechercherContact->setText(QString::fromStdString("Chercher un contact"));
    }

    emit contactSelected(c);
}

void MainWindow::createContact(string nom, string prenom, string entreprise, string tel, string mail, string photo)
{
    emit contactCreated(nom, prenom, entreprise, tel, mail, photo);
}

/**
  *  \brief Fenetre d'ajout d'interaction a un contact
  *
  *  Slot qui permet l'ouverture de la fenetre d'ajout d'interaction a un contact.
  */
void MainWindow::openWindowAjoutInteraction()
{
    ajoutinter->show();
}

/**
  *  \brief Fenetre de modification d'interaction d'un contact
  *
  *  Slot qui permet l'ouverture de la fenetre de modification d'interaction d'un contact.
  */
void MainWindow::openWindowModifEvent()
{
    modifevent->show();
}

/**
  *  \brief Fenetre sur les requetes
  *
  *  Slot qui permet l'ouverture de la fenetre sur les requetes.
  */
void MainWindow::openWindowRequete()
{
    requete->show();
}

/**
  *  \brief A propos de l'application
  *
  *  Affiche le fonctionnement globale de l'application dans un QMessageBox.
  */
void MainWindow::slot_aPropos()
{
    QMessageBox messageAbout;
    messageAbout.about(this, "À-propos",
    "Le but de cette application est la gestion de relations clients "
    "prenant en compte des interactions et des tâches à faire, extraites automatiquement de ces interactions. "
    "L'application tilise également une base de données SQLite afin de stocker les contacts et les interactions; et les données sont exportables en JSON.");
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
    QApplication::quit();
}

/**
 *  \brie>f Destructeur de ModificationContactWindow
 *
 *  Detruis en memoire la fenetre
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete creatfich;
    delete modiffich;
    delete rechcontact;
    delete ajoutinter;
    delete modifevent;
    delete requete;
}
