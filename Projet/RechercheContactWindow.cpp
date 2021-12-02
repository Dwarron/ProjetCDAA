/**
 * \file RechercheContactWindow.cpp
 * \class RechercheContactWindow RechercheContactWindow.h
 * \brief Fenetre permettant la recherche et la selection d'un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QStringListModel>
#include "RechercheContactWindow.h"
#include "ui_RechercheContactWindow.h"

using namespace std;

/**
 *  \brief Constructeur standard
 *
 *  Constructeur standard de la classe RechercheContactWindow.
 *  Effectue les connexions signaux/slots
 *
 *  \param contacts : la liste des contacts lors de la creation de la fenetre
 *  \param parent : fenetre parent
 */
RechercheContactWindow::RechercheContactWindow(list<Contact*> c, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RechercheContactWindow)
{
   ui->setupUi(this);

   //on rempli les combo box
   ui->rechercheContactComboBox->addItem("Nom");
   ui->rechercheContactComboBox->addItem("Entreprise");

   ui->triListeComboBox->addItem("Ordre alphabétique");
   ui->triListeComboBox->addItem("Date de création");

   contacts = c;
   contactsAffiches = list<Contact*>();

   listeContactsModel = new QStringListModel();
   ui->listeContacts->setModel(listeContactsModel);

   connect(this, SIGNAL(listContactsUpdated(std::list<Contact*>)), this, SLOT(updateListContacts(std::list<Contact*>)));

   connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
   connect(ui->rechercheLineEdit, SIGNAL(textEdited(QString)), this, SLOT(rechercheContact(QString)));
   connect(ui->rechercheContactComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(rechercheContact()));
   connect(ui->triListeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(rechercheContact()));
   connect(ui->dateEditDebut, SIGNAL(dateChanged(QDate)), this, SLOT(rechercheContact()));
   connect(ui->dateEditFin, SIGNAL(dateChanged(QDate)), this, SLOT(rechercheContact()));
   connect(ui->listeContacts->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), this, SLOT(selectContact(QModelIndex)));

   rechercheContact();
}

/**
 *  \brief Mis a jour de la liste des contacts
 *
 *  Slot pour mettre a jour la liste des contacts
 *
 *  \param c : la nouvelle liste
 */
void RechercheContactWindow::updateListContacts(list<Contact*> c)
{
    contacts = c;
    rechercheContact();
}

/**
  *  \brief slot appele lors de la selection d'un contact
  *
  *  Selection d'un contact apres click dans la liste
  *
  *  \param newItem : l'item de selection
  */
void RechercheContactWindow::selectContact(QModelIndex q)
{
    auto it = contactsAffiches.begin();
    for(int i = 0; i < q.row(); i++)
    {
        it++;
    }

    emit contactSelected(*it);
}

/**
  *  \brief Recherche le contact
  *  \see rechercheContact(QString text)
  */
void RechercheContactWindow::rechercheContact()
{
    rechercheContact(ui->rechercheLineEdit->text());
}

/**
  *  \brief Recherche le contact
  *
  *  Slot qui recherche le contact selectionne dans la liste des contacts
  *  Permet de recherche ce contact entre 2 date et de trier le resultat par date de creation ou par ordre alphabetique.
  *
  *  \param text : le text avec lequel effectue la recherche (nom/prenom ou entreprise)
  */
void RechercheContactWindow::rechercheContact(QString text)
{
    QString recherche = ui->rechercheContactComboBox->currentText();
    QString tri = ui->triListeComboBox->currentText();

    Date dateDebut(ui->dateEditDebut->dateTime().toString("dd/MM/yyyy").toStdString());
    Date dateFin(ui->dateEditFin->dateTime().toString("dd/MM/yyyy").toStdString());

    contactsAffiches.clear();

    list<Contact*> contactstemp;

    if(tri == "Ordre alphabétique")
    {
        contacts.sort([](Contact* a, Contact* b) {return *a < *b;}); // on tri dans l'ordre alphabetique
    }
    else
    {   // date de creation
        contacts.sort([](Contact* a, Contact* b) {return a->getDateCreation() < b->getDateCreation();}); // on tri dans l'ordre de dates de création
    }

    bool triDates = dateDebut != dateFin && dateDebut < dateFin;

    for(auto it = contacts.begin(); it != contacts.end(); it++)
    {
        if((triDates && dateDebut < (*it)->getDateCreation() && (*it)->getDateCreation() < dateFin) || !triDates)
             contactstemp.push_back(*it);
    }

    QStringList list;

    if(recherche == "Nom")
    {
        // on affiche tous les noms des contacts de la liste temporaire
        for(auto it = contactstemp.begin(); it != contactstemp.end(); it++)
        {
            if((*it)->getNom().find(text.toStdString()) != string::npos || (*it)->getPrenom().find(text.toStdString()) != string::npos)
            {
                contactsAffiches.push_back(*it);
                list << QString::fromStdString((*it)->toString());
            }
        }
    }
    else    // recherche par entreprise
    {
        // on affiche toutes les entreprises des contacts de la liste temporaire
        for(auto it = contactstemp.begin(); it != contactstemp.end(); it++)
        {
            if((*it)->getEntreprise().find(text.toStdString()) != string::npos)
            {
                contactsAffiches.push_back(*it);
                string nom = (*it)->toString();
                if((*it)->getEntreprise().length() > 0)
                    nom += " (" + (*it)->getEntreprise() + ")";
                list << QString::fromStdString(nom);
            }
        }
    }

    listeContactsModel->setStringList(list);
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
