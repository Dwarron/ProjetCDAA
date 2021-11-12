/**
 * \file CreationFicheWindow.cpp
 * \class CreationFicheWindow CreationFicheWindow.h
 * \brief Fenetre qui permet de creer la fiche d'un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "CreationFicheWindow.h"
#include <ui_CreationFicheWindow.h>
#include <QObject>
#include <QFileDialog>
#include <QDir>

/**
 *  \brief Constructeur standard
 *
 *  Constructeur standard de la classe CreationFicheWindow.
 *  Effectue les connexions entre les differents Widget et evenement a declencher.
 *
 *  \param g : gestion des contacts
 *  \param parent : fenetre parent
 */
CreationFicheWindow::CreationFicheWindow(GestionContact *g, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreationFicheWindow)
{
    ui->setupUi(this);

    gestCont = g;

    connect(ui->validButton, SIGNAL(clicked()), this, SLOT(CreationFiche()));
    connect(ui->selectFilePushButton, SIGNAL(clicked()), this, SLOT(SelectFile()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
}

/**
  *  \brief Selection de fichier
  *
  *  Slot qui permet de selectionner la photo d'un contacts.
  *  La photo ne peut seulement etre en format jpg ou png.
  */
void CreationFicheWindow::SelectFile()
{
    QString filter = "PNG File (*.png) ;; JPG File (*.jpg)";
    file_name = QFileDialog::getOpenFileName(this, "Open file", QDir::homePath(), filter);
}

/**
  *  \brief Creation de la fiche d'un contact
  *
  *  Slot qui permet de creer la fiche d'un contact avec tous les informations recupere dans la fenetre.
  */
void CreationFicheWindow::CreationFiche()
{
    //ici on ajoute ce contact a la gestion des contact
    emit gestCont->creeContact( ui->nomLineEdit->text().toStdString(),
                                ui->prenomLineEdit->text().toStdString(),
                                ui->entrepriseLineEdit->text().toStdString(),
                                ui->telLineEdit->text().toStdString(),
                                ui->mailLineEdit->text().toStdString(),
                                file_name.toStdString()
                              );

    //apres avoir crée le contact avec les informations de la fentre on la ferme
    this->close();
}

/**
 *  \brief Destructeur de CreationFicheWindow
 *
 *  Detruis en memoire la fenetre
 */
CreationFicheWindow::~CreationFicheWindow()
{
    delete ui;
}
