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

#include <iostream>

/**
 *  \brief Constructeur standard
 *
 *  Constructeur standard de la classe ModificationContactWindow.
 *  Effectue les connexions entre les differents Widget et evenement a declencher.
 *  Permet de remplir l'ensemble de la comboBox des contacts.
 *
 *  \param g : gestion des contacts
 *  \param c : le contact a modifier/afficher
 *  \param parent : fenetre parent
 */
ModificationContactWindow::ModificationContactWindow(GestionContact *g, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModificationContactWindow)
{
    ui->setupUi(this);

    gestCont = g;

    connect(ui->validButton, SIGNAL(clicked()), this, SLOT(ModifFiche()));
    connect(ui->supprButton, SIGNAL(clicked()), this, SLOT(supprimerContact()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->changeFilePushButton, SIGNAL(clicked()), this, SLOT(ChangeFile()));
    connect(this, SIGNAL(imageSelected(QString)), this, SLOT(showImage(QString)));
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
    ui->photoLineEdit->setText(file_name);

    emit imageSelected(file_name);
}

/**
  *  \brief Suppression du contact
  *
  *  Slot qui permet de supprimer la fiche du contact
  */
void ModificationContactWindow::supprimerContact()
{
    QMessageBox::StandardButton confirmation = QMessageBox::question(this, QString::fromStdString("Suppression du contact : " + curContact->toString()), QString::fromStdString("êtes-vous sûr de vouloir supprimer ce contact ?"));
    if(confirmation == QMessageBox::Yes)
    {
        emit contactDeleted(curContact);
        this->close();
    }
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
    file_name = QString::fromStdString(c->getUriPhoto());
    ui->photoLineEdit->setText(file_name);

    emit imageSelected(file_name);
}

void ModificationContactWindow::showImage(QString path)
{
    if(path != "")
    {
        QImage photo = QImage(path);
        if(!photo.isNull())
        {
            QImage photoScaled = photo.scaled(ui->photoView->rect().width(), ui->photoView->rect().height());
            QGraphicsScene* scene = new QGraphicsScene(this);
            scene->addPixmap(QPixmap::fromImage(photoScaled));
            delete ui->photoView->scene();
            ui->photoView->setScene(scene);
        }
        else
        {
            ui->photoView->setScene(nullptr);
        }
    }
    else
    {
        ui->photoView->setScene(nullptr);
    }
}

/**
  *  \brief Charge le contact selectionne
  *
  *  Recupere le contact selectionne dans la comboBox.
  *
  *  \param c : le contact selectionne
  */
void ModificationContactWindow::loadContact(Contact* c)
{
    curContact = c;
    RemplieInfos(curContact);
  //  emit RemplieInfos(c);
}

void ModificationContactWindow::resizeEvent(QResizeEvent*)
{
    emit imageSelected(file_name);
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
    QPushButton* yesButton = messageErreur.addButton(QMessageBox::Yes);
    messageErreur.addButton(QMessageBox::No);

    std::string nom = ui->nomLineEdit->text().toStdString();
    std::string nomtester = nom;
    curContact->suggestionNom(nomtester);

    //on va regarder quel champ sont modifies pour utiliser les setters/mutateur
    if(curContact->getNom() != nom)
    {
        if(nomtester != nom)
        {
            messageErreur.setWindowTitle("Nom invalide");
            messageErreur.setText(QString::fromStdString("Nom invalide, vouliez-vous écrire : " + nomtester));
            messageErreur.setInformativeText(QString::fromStdString(nom));
            messageErreur.exec();
            if(messageErreur.clickedButton() == yesButton)
            {
                ui->nomLineEdit->setText(QString::fromStdString(nomtester));
                return;
            }
            else
            {
                emit nomModified(curContact, nom);
            }
        }
        else
        {
            emit nomModified(curContact, nom);
        }
    }

    std::string prenom = ui->prenomLineEdit->text().toStdString();
    std::string prenomtester = prenom;
    curContact->suggestionNom(prenomtester);

    if(curContact->getPrenom() != prenom)
    {
        if(prenomtester != prenom)
        {
            messageErreur.setWindowTitle("Prenom invalide");
            messageErreur.setText(QString::fromStdString("Prenom invalide, vouliez-vous écrire : " + prenomtester));
            messageErreur.setInformativeText(QString::fromStdString(prenom));
            messageErreur.exec();
            if(messageErreur.clickedButton() == yesButton)
            {
                ui->prenomLineEdit->setText(QString::fromStdString(prenomtester));
                return;
            }
            else
            {
                emit prenomModified(curContact, prenom);
            }
        }
        else
        {
            emit prenomModified(curContact, prenom);
        }
    }

    if(curContact->getEntreprise() != ui->entrepriseLineEdit->text().toStdString())
        emit entrepriseModified(curContact, ui->entrepriseLineEdit->text().toStdString());

    if(curContact->getTelephone() != ui->telLineEdit->text().toStdString())
        emit telephoneModified(curContact, ui->telLineEdit->text().toStdString());

    if(curContact->getMail() != ui->mailLineEdit->text().toStdString())
        emit mailModified(curContact, ui->mailLineEdit->text().toStdString());

    if(curContact->getUriPhoto() != file_name.toStdString())
        emit photoModified(curContact, file_name.toStdString());

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
