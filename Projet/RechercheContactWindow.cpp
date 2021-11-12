/**
 * \file RechercheContactWindow.cpp
 * \class RechercheContactWindow RechercheContactWindow.h
 * \brief Fenetre avec laquel on peut rechercher un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "RechercheContactWindow.h"
#include "ui_RechercheContactWindow.h"

/**
 *  \brief Constructeur standard
 *
 *  Constructeur standard de la classe RechercheContactWindow.
 *  Effectue les connexions entre les differents Widget et evenement a declencher.
 *  Permet de remplir les comboBox pour le trie et pour la recherche d'un contact.
 *
 *  \param g : gestion des contacts
 *  \param parent : fenetre parent
 */
RechercheContactWindow::RechercheContactWindow(GestionContact *g, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RechercheContactWindow)
{
   ui->setupUi(this);

   gestCont = g;

   //on remplie les combo box
   ui->rechercheContactComboBox->addItem("Nom");
   ui->rechercheContactComboBox->addItem("Entreprise");

   ui->trieListeComboBox->addItem("Ordre alphabétique");
   ui->trieListeComboBox->addItem("Date de création");

   ui->listeContactsTextEdit->setReadOnly(true);

   connect(ui->validButton, SIGNAL(clicked()), this, SLOT(rechercheContact()));
   connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
}

/**
  *  \brief Recherche le contact
  *
  *  Slot qui recherche le contact selectionne dans la comboBox.
  *  Permet de recherche ce contact entre 2 date et de trier le resultat par date de creation ou par ordre alphabetique.
  *
  */
void RechercheContactWindow::rechercheContact()
{
    ui->listeContactsTextEdit->clear(); //on nettoie la zone de text

    QString recherche = ui->rechercheContactComboBox->currentText();
    QString trie = ui->trieListeComboBox->currentText();

    Date dateDebut(ui->dateEditDebut->dateTime().toString("dd/MM/yyyy").toStdString());
    Date dateFin(ui->dateEditFin->dateTime().toString("dd/MM/yyyy").toStdString());

    std::list<Contact*> contactstemp;

    if( trie == "Ordre alphabétique")
    {
        gestCont->getContacts().sort([](Contact* a, Contact* b) {return a->getNom() < b->getNom();}); // on trie dans l'ordre alphabetique
    }
    else
    {
        gestCont->getContacts().sort([](Contact* a, Contact* b) {return a->getDateCreation() < b->getDateCreation();}); // on trie dans l'ordre de dates de création
    }

    for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
    {
        if( dateDebut < (*it)->getDateCreation() && (*it)->getDateCreation()< dateFin )
             contactstemp.push_back(*it);
    }

    if( recherche == "Nom")
    {
        // on affiche tous les nom des contacts de la liste temporaire
        for(auto it = contactstemp.begin(); it != contactstemp.end(); it++)
        {
            ui->listeContactsTextEdit->insertPlainText(QString::fromStdString((*it)->getNom()) + "\n");
        }
    }
    else
    {
        // on affiche toutes les entreprises des contacts de la liste temporaire
        for(auto it = contactstemp.begin(); it != contactstemp.end(); it++)
        {
            ui->listeContactsTextEdit->insertPlainText(QString::fromStdString((*it)->getEntreprise()) + "\n");
        }
    }
}

/**
 *  \brief Destructeur de RechercheContactWindow
 *
 *  Detruis en memoire la fenetre
 */
RechercheContactWindow::~RechercheContactWindow()
{
    delete ui;
}
