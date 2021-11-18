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
    file_name = "";

    connect(this, SIGNAL(imageSelected(QString)), this, SLOT(showImage(QString)));
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

    emit imageSelected(file_name);
}

void CreationFicheWindow::showImage(QString path)
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
  *  \brief Creation de la fiche d'un contact
  *
  *  Slot qui permet de creer la fiche d'un contact avec tous les informations recupere dans la fenetre.
  */
void CreationFicheWindow::CreationFiche()
{
    emit contactCreated(ui->nomLineEdit->text().toStdString(),
                                ui->prenomLineEdit->text().toStdString(),
                                ui->entrepriseLineEdit->text().toStdString(),
                                ui->telLineEdit->text().toStdString(),
                                ui->mailLineEdit->text().toStdString(),
                                file_name.toStdString()
                              );

    ui->nomLineEdit->setText("");
    ui->prenomLineEdit->setText("");
    ui->entrepriseLineEdit->setText("");
    ui->telLineEdit->setText("");
    ui->mailLineEdit->setText("");
    file_name = "";
    emit imageSelected(file_name);

    //apres avoir crée le contact avec les informations de la fenetre on la ferme
    this->close();
}

void CreationFicheWindow::resizeEvent(QResizeEvent*)
{
    emit imageSelected(file_name);
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
