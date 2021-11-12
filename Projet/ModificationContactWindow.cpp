/**
 * \file ModificationContactWindow.cpp
 * \class ModificationContactWindow ModificationContactWindow.h
 * \brief Fenetre qui permet de modifier la fiche d'un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "ModificationContactWindow.h"
#include "ui_ModificationContactWindow.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

/**
 *  \brief Constructeur standard
 *
 *  Constructeur standard de la classe ModificationContactWindow.
 *  Effectue les connexions entre les differents Widget et evenement a declencher.
 *  Permet de remplir l'ensemble de la comboBox des contacts.
 *
 *  \param g : gestion des contacts
 *  \param parent : fenetre parent
 */
ModificationContactWindow::ModificationContactWindow(GestionContact *g, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModificationContactWindow)
{
    ui->setupUi(this);

    gestCont = g;

    connect(ui->validButton, SIGNAL(clicked()), this, SLOT(ModifFiche()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->comboContacts, SIGNAL(currentTextChanged(QString)), this, SLOT(LoadContactSelectionner(QString)));
    connect(ui->changeFilePushButton, SIGNAL(clicked()), this, SLOT(ChangeFile()));

    //on remplie la combo box
    for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
    {
        ui->comboContacts->addItem(QString::fromStdString((*it)->toString()));
    }
}

/**
  *  \brief Selection de fichier
  *
  *  Slot qui permet de selectionner la photo d'un contacts.
  *  La photo ne peut seulement etre en format jpg ou png.
  */
void ModificationContactWindow::ChangeFile()
{
    QString filter = "PNG File (*.png) ;; JPG File (*.jpg)";
    file_name = QFileDialog::getOpenFileName(this, "Open file", QDir::homePath(), filter);
}

/**
  *  \brief Remplir les informations d'un contact
  *
  *  Slot qui va remplir tous les champs de la fenetre pour un contact.
  *
  *  \param contact : le contact selectionne
  */
void ModificationContactWindow::RemplieInfos(Contact *c)
{
    ui->nomLineEdit->setText(QString::fromStdString(c->getNom()));
    ui->prenomLineEdit->setText(QString::fromStdString(c->getPrenom()));
    ui->entrepriseLineEdit->setText(QString::fromStdString(c->getEntreprise()));
    ui->telLineEdit->setText(QString::fromStdString(c->getTelephone()));
    ui->mailLineEdit->setText(QString::fromStdString(c->getMail()));
    ui->photoLineEdit->setText(QString::fromStdString(c->getUriPhoto()));
    file_name = QString::fromStdString(c->getUriPhoto());
}

/**
  *  \brief Charge le contact selectionne
  *
  *  Recupere le contact selectionne dans la comboBox.
  *
  *  \param contact : le contact selectionne
  */
void ModificationContactWindow::LoadContactSelectionner(QString contact)
{
    for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
    {
        if( (*it)->toString() == contact.toStdString() )
            c = *it;
    }

    emit RemplieInfos(c);
}

/**
  *  \brief Modification de la fiche du contact
  *
  *  Slot qui va recuperer toutes les informations rentrer dans la fenetre par l'utilisateur pour modifier le contact selectionne.
  *  Si l'utilisateur ecrit son nom ou prenom avec un caractere special ou un chiffre l'application lui propose de le reecrire correctement.
  */
void ModificationContactWindow::ModifFiche()
{  
    QMessageBox messageErreur;
    QPushButton *yesButton = messageErreur.addButton(QMessageBox::Yes);
    messageErreur.addButton(QMessageBox::No);

    std::string nom = ui->nomLineEdit->text().toStdString();
    std::string nomtester = nom;
    c->suggestionNom(nomtester);

    //on va regarder quelle champ sont modifier pour utiliser les setters/mutateur
    if(c->getNom() != nom)
    {
        if(nomtester != nom)
        {
            messageErreur.setWindowTitle("Nom invalide");
            messageErreur.setText("Nom invalide vouliez vous écrire : ");
            messageErreur.setInformativeText(QString::fromStdString(nomtester));
            messageErreur.exec();
            if(messageErreur.clickedButton() == yesButton)
                c->setNom(nomtester);
            else
                c->setNom(nom);

        }
        else
            c->setNom(nom);
    }

    std::string prenom = ui->prenomLineEdit->text().toStdString();
    std::string prenomtester = prenom;
    c->suggestionNom(prenomtester);

    if(c->getPrenom() != prenom)
    {
        if(prenomtester != prenom)
        {
            messageErreur.setWindowTitle("Prenom invalide");
            messageErreur.setText("Prenom invalide vouliez vous écrire : ");
            messageErreur.setInformativeText(QString::fromStdString(prenomtester));
            messageErreur.exec();
            if(messageErreur.clickedButton() == yesButton)
                c->setPrenom(prenomtester);
            else
                c->setPrenom(prenom);

        }
        else
            c->setPrenom(prenom);
    }

    if(c->getEntreprise() != ui->entrepriseLineEdit->text().toStdString())
        c->setEntreprise(ui->entrepriseLineEdit->text().toStdString());

    if(c->getTelephone() != ui->telLineEdit->text().toStdString())
        c->setTelephone(ui->telLineEdit->text().toStdString());

    if(c->getMail() != ui->mailLineEdit->text().toStdString())
        c->setMail(ui->mailLineEdit->text().toStdString());

    if(c->getUriPhoto() != file_name.toStdString())
        c->setUriPhoto(file_name.toStdString());

    //apres avoir modifier le contact avec les informations de la fentre on la ferme
    this->close();
}

/**
 *  \brief Destructeur de ModificationContactWindow
 *
 *  Detruis en memoire la fenetre
 */
ModificationContactWindow::~ModificationContactWindow()
{
    delete ui;
}
