/**
 * \file CreationFicheWindow.cpp
 * \class CreationFicheWindow CreationFicheWindow.h
 * \brief Fenetre qui permet de creer la fiche d'un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QObject>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include "CreationFicheWindow.h"
#include "ui_CreationFicheWindow.h"
#include "Contact.h"

using namespace std;

/**
 *  \brief Constructeur standard
 *
 *  Constructeur standard de la classe CreationFicheWindow
 *  Effectue les connexions signaux/slots
 *
 *  \param parent : fenetre parent
 */
CreationFicheWindow::CreationFicheWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreationFicheWindow)
{
    ui->setupUi(this);

    file_name = "";

    connect(this, SIGNAL(imageSelected(QString)), this, SLOT(showImage(QString)));
    connect(ui->validButton, SIGNAL(clicked()), this, SLOT(CreationFiche()));
    connect(ui->selectFilePushButton, SIGNAL(clicked()), this, SLOT(SelectFile()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
}

/**
  *  \brief Selection de fichier
  *
  *  Slot qui permet de selectionner la photo du contact (le chemin)
  *  La photo ne peut seulement etre en format jpg ou png
  */
void CreationFicheWindow::SelectFile()
{
    QString filter = "PNG File (*.png) ;; JPG File (*.jpg)";
    file_name = QFileDialog::getOpenFileName(this, "Open file", QDir::homePath(), filter);

    emit imageSelected(file_name);
}

/**
  *  \brief Affiche l'image
  *
  *  Slot qui permet d'afficher l'image situee dans path
  *  \param path : le chemin absolu jusqu'a l'image
  */
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
  *  Appele lors du click sur le bouton de creation
  */
void CreationFicheWindow::CreationFiche()
{
    string nom = ui->nomLineEdit->text().toStdString();
    string nomTest = Contact::suggestionNom(nom);

    if(nom.length() == 0)
    {
        QMessageBox::warning(this, "Nom vide", QString::fromStdString("Veuillez entrer un nom"));
    }
    else if(nomTest != nom)
    {
        QMessageBox::StandardButton confirmation = QMessageBox::question(this, QString::fromStdString("Nom invalide : " + nom), QString::fromStdString("Vouliez-vous écrire : " + nomTest + " ?"));
        if(confirmation == QMessageBox::Yes)
        {
            ui->nomLineEdit->setText(QString::fromStdString(nomTest));
        }
    }
    else
    {
        string prenom = ui->prenomLineEdit->text().toStdString();
        string prenomTest = Contact::suggestionNom(prenom);

        if(prenom.length() == 0)
        {
            QMessageBox::warning(this, "Prenom vide", QString::fromStdString("Veuillez entrer un prenom"));
        }
        else if(prenom != prenomTest)
        {
            QMessageBox::StandardButton confirmation = QMessageBox::question(this, QString::fromStdString("Prenom invalide : " + prenom), QString::fromStdString("Vouliez-vous écrire : " + prenomTest + " ?"));
            if(confirmation == QMessageBox::Yes)
            {
                ui->prenomLineEdit->setText(QString::fromStdString(prenomTest));
            }
        }
        else
        {
            string telephone = ui->telLineEdit->text().toStdString();

            bool badPhone = false;
            if(telephone.length() > 0)
            {
                try {
                   Contact::checkChiffres(telephone);
                }
                catch (const invalid_argument& e) {
                    badPhone = true;
                }
                if(telephone.length() != 10)
                {
                    badPhone = true;
                }
            }

            if(badPhone)
            {
                QMessageBox::warning(this, "Téléphone invalide", QString::fromStdString(telephone + " n'est pas un numéro de téléphone valide"));
            }
            else
            {
                string mail = ui->mailLineEdit->text().toStdString();
                bool badMail = false;

                if(mail.length() > 0)
                {
                    try {
                       Contact::checkMail(mail);
                    }
                    catch (const invalid_argument& e) {
                        badMail = true;
                    }
                }

                if(badMail)
                {
                    QMessageBox::warning(this, "Mail invalide", QString::fromStdString(mail + " n'est pas un mail valide"));
                }
                else
                {
                    emit contactCreated(nom, prenom, ui->entrepriseLineEdit->text().toStdString(), telephone, mail, file_name.toStdString());

                    ui->nomLineEdit->setText("");
                    ui->prenomLineEdit->setText("");
                    ui->entrepriseLineEdit->setText("");
                    ui->telLineEdit->setText("");
                    ui->mailLineEdit->setText("");
                    file_name = "";
                    emit imageSelected(file_name);

                    this->close();
                }
            }

        }
    }
}

/**
  *  \brief Evenement de modification de la taille de la fenetre
  *
  *  Surcharge de l'evenement de modification de la taille de la fenetre, reaffiche l'image (photo du contact)
  *  \param e : l'evenement
  */
void CreationFicheWindow::resizeEvent(QResizeEvent* e)
{
    QWidget::resizeEvent(e);        //evenement de la classe parente (QWidget)
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
