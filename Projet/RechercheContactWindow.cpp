/**
 * \file RechercheContactWindow.cpp
 * \class RechercheContactWindow RechercheContactWindow.h
 * \brief Fenetre avec laquel on peut rechercher un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "RechercheContactWindow.h"
#include "ui_RechercheContactWindow.h"
#include "QDate"

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

   connect(ui->validButton, SIGNAL(clicked()), this, SLOT(rechercheContact()));
   connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
}

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

RechercheContactWindow::~RechercheContactWindow()
{
    delete ui;
}
