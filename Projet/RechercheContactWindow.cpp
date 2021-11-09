#include "RechercheContactWindow.h"
#include "ui_RechercheContactWindow.h"
#include "QDate"

#include "QDebug"



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

   connect(ui->rechercheContactComboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(rechercheContact(QString)));
   connect(ui->dateEditDebut, SIGNAL(dateChanged(QDate)), this, SLOT(dateContact(QDate)));
   //connect(ui->dateEditFin, SIGNAL(dateChanged(QDate)), this, SLOT(dateContact(QDate)));
   connect(ui->rechercheContactComboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(trieContact(QString)));
   connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
}

RechercheContactWindow::~RechercheContactWindow()
{
    delete ui;
}

void RechercheContactWindow::rechercheContact(QString infos)
{
    if( infos == "Nom")
    {
        ui->listeContactsTextEdit->clear();

        // on affiche tous les nom des contacts
        for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
        {
            ui->listeContactsTextEdit->insertPlainText(QString::fromStdString((*it)->getNom()) + "\n");
        }
    }
    else
    {
        ui->listeContactsTextEdit->clear();

        // on affiche toutes les entreprises des contacts
        for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
        {
            ui->listeContactsTextEdit->insertPlainText(QString::fromStdString((*it)->getEntreprise()) + "\n");
        }
    }
}

void RechercheContactWindow::trieContact(QString trie)
{
    //to do
}

void RechercheContactWindow::dateContact(QDate &q)
{
    qDebug() << ui->dateEditDebut->dateTime().toString("dd/MM/yyyy");
    qDebug() << ui->dateEditFin->dateTime().toString("dd/MM/yyyy");
}
