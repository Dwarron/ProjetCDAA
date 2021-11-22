/**
 * \file FicheContactWindow.cpp
 * \class FicheContactWindow FicheContactWindow.h
 * \brief Fenetre qui permet d'afficher et modifier la fiche d'un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */


#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QDate>
#include "FicheContactWindow.h"
#include "ui_FicheContactWindow.h"

using namespace std;

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
FicheContactWindow::FicheContactWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FicheContactWindow)
{
    ui->setupUi(this);

    afficheInteractionsWindow = new AfficheInteractionsWindow();
    afficheInteractionsWindow->setWindowTitle("Interactions de :");

    ajoutinter = new AjoutInteractionWindow();

    connect(this, SIGNAL(listContactsUpdated(std::list<Contact*>)), ajoutinter, SIGNAL(listContactsUpdated(std::list<Contact*>)));
    connect(this, SIGNAL(onEndModifContact()), ajoutinter, SIGNAL(onEndModifContact()));

    connect(ajoutinter, SIGNAL(ajoutInteraction(Contact*,QString)), this, SIGNAL(ajoutInteraction(Contact*,QString)));
    connect(ajoutinter, SIGNAL(ajoutInteraction(Contact*,Interaction*)), this, SIGNAL(ajoutInteraction(Contact*,Interaction*)));

    connect(this, SIGNAL(contactSelected(Contact*)), afficheInteractionsWindow, SLOT(selectContact(Contact*)));
    connect(this, SIGNAL(contactSelected(Contact*)), ajoutinter, SLOT(selectContact(Contact*)));

    connect(afficheInteractionsWindow, SIGNAL(interactionDateEdited(Interaction*,QDate)), this, SIGNAL(interactionDateEdited(Interaction*,QDate)));
    connect(afficheInteractionsWindow, SIGNAL(interactionResumeEdited(Interaction*,QString)), this, SIGNAL(interactionResumeEdited(Interaction*,QString)));
    connect(this, SIGNAL(onInteractionEdited()), afficheInteractionsWindow, SLOT(interactionEdited()));

    connect(ui->validButton, SIGNAL(clicked()), this, SLOT(modifFiche()));
    connect(ui->supprButton, SIGNAL(clicked()), this, SLOT(supprimerContact()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->changeFilePushButton, SIGNAL(clicked()), this, SLOT(changeFile()));
    connect(ui->interactionsButton, SIGNAL(clicked()), afficheInteractionsWindow, SLOT(show()));
    connect(ui->ButtonAjouterInteraction, SIGNAL(clicked()), ajoutinter, SLOT(show()));

    connect(this, SIGNAL(imageSelected(QString)), this, SLOT(showImage(QString)));
}

/**
  *  \brief Selection de fichier
  *
  *  Slot qui permet de selectionner la photo d'un contacts.
  *  La photo ne peut seulement etre en format jpg ou png.
  */
void FicheContactWindow::changeFile()
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
void FicheContactWindow::supprimerContact()
{
    QMessageBox::StandardButton confirmation = QMessageBox::question(this, QString::fromStdString("Suppression du contact : " + curContact->toString()), QString::fromStdString("êtes-vous sûr de vouloir supprimer ce contact ?"));
    if(confirmation == QMessageBox::Yes)
    {
        emit contactDeleted(curContact);
        this->close();
    }
}

void FicheContactWindow::showImage(QString path)
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
void FicheContactWindow::loadContact(Contact* c)
{
    curContact = c;
    bool contactExistant = curContact != nullptr;

    if(contactExistant)
    {
        ui->nomLineEdit->setText(QString::fromStdString(curContact->getNom()));
        ui->prenomLineEdit->setText(QString::fromStdString(curContact->getPrenom()));
        ui->entrepriseLineEdit->setText(QString::fromStdString(curContact->getEntreprise()));
        ui->telLineEdit->setText(QString::fromStdString(curContact->getTelephone()));
        ui->mailLineEdit->setText(QString::fromStdString(curContact->getMail()));
        file_name = QString::fromStdString(curContact->getUriPhoto());
        ui->photoLineEdit->setText(file_name);

        emit imageSelected(file_name);

        ui->labelDateCreation->setText(QString::fromStdString("<i>" + curContact->getDateCreation().toString() + "</i>"));
        ui->labelDateModif->setText(QString::fromStdString("<i>" + curContact->getDateDerniereModification().toString() + "</i>"));
    }
    else
    {
        ui->nomLineEdit->setText("");
        ui->prenomLineEdit->setText("");
        ui->entrepriseLineEdit->setText("");
        ui->telLineEdit->setText("");
        ui->mailLineEdit->setText("");
        file_name = QString::fromStdString("");
        ui->photoLineEdit->setText("");

        ui->labelDateCreation->setText("");
        ui->labelDateModif->setText("");
    }

    ui->nomLineEdit->setEnabled(contactExistant);
    ui->prenomLineEdit->setEnabled(contactExistant);
    ui->entrepriseLineEdit->setEnabled(contactExistant);
    ui->telLineEdit->setEnabled(contactExistant);
    ui->mailLineEdit->setEnabled(contactExistant);
    ui->photoLineEdit->setEnabled(contactExistant);

    emit contactSelected(c);

}

void FicheContactWindow::resizeEvent(QResizeEvent*)
{
    emit imageSelected(file_name);
}

/**
  *  \brief Modification de la fiche du contact
  *
  *  Slot qui va recuperer toutes les informations rentrer dans la fenetre par l'utilisateur pour modifier le contact selectionne.
  *  Si l'utilisateur ecrit son nom ou prenom avec un caractere special ou un chiffre l'application lui propose de le reecrire correctement.
  */
void FicheContactWindow::modifFiche()
{
    string nom = ui->nomLineEdit->text().toStdString();
    string nomTest = Contact::suggestionNom(nom);

    //on va regarder quel champ sont modifies pour utiliser les setters/mutateur
    if(curContact->getNom() != nom)
    {
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

            return;
        }
        else
        {
            emit nomModified(curContact, nom);
        }
    }

    string prenom = ui->prenomLineEdit->text().toStdString();
    string prenomTest = Contact::suggestionNom(prenom);

    if(curContact->getPrenom() != prenom)
    {
        if(prenom.length() == 0)
        {
            QMessageBox::warning(this, "Prenom vide", QString::fromStdString("Veuillez entrer un prenom"));
        }
        else if(prenomTest != prenom)
        {
            QMessageBox::StandardButton confirmation = QMessageBox::question(this, QString::fromStdString("Prenom invalide : " + prenom), QString::fromStdString("Vouliez-vous écrire : " + prenomTest + " ?"));
            if(confirmation == QMessageBox::Yes)
            {
                ui->prenomLineEdit->setText(QString::fromStdString(prenomTest));
            }
            return;
        }
        else
        {
            emit prenomModified(curContact, prenom);
        }
    }

    string entreprise = ui->entrepriseLineEdit->text().toStdString();
    if(curContact->getEntreprise() != entreprise)
        emit entrepriseModified(curContact, entreprise);

    string tel = ui->telLineEdit->text().toStdString();
    if(curContact->getTelephone() != tel)
    {
        bool badPhone = false;
        if(tel.length() > 0)
        {
            try {
               Contact::checkChiffres(tel);
            }
            catch (const invalid_argument& e) {
                badPhone = true;
            }
            if(tel.length() != 10)
            {
                badPhone = true;
            }
        }

        if(badPhone)
        {
            QMessageBox::warning(this, "Téléphone invalide", QString::fromStdString(tel + " n'est pas un numéro de téléphone valide"));
        }
        else
        {
            emit telephoneModified(curContact, tel);
        }
    }

    string mail = ui->mailLineEdit->text().toStdString();
    if(curContact->getMail() != mail)
    {
        bool badMail = false;
        try {
           Contact::checkMail(mail);
        }
        catch (const invalid_argument& e) {
            badMail = true;
        }

        if(badMail)
        {
            QMessageBox::warning(this, "Mail invalide", QString::fromStdString(mail + " n'est pas un mail valide"));
        }
        else
        {
            emit mailModified(curContact, mail);
        }
    }

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
FicheContactWindow::~FicheContactWindow()
{
    delete ui;
    delete afficheInteractionsWindow;
    delete ajoutinter;
}
