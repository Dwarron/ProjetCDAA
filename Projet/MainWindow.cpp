/**
 * \file MainWindow.cpp
 * \class MainWindow MainWindow.h
 * \brief Fenetre principale qui permet de gerer l'ensemble des fenetres
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QMessageBox>
#include <QCloseEvent>
#include <QDate>
#include <QDir>
#include <QFileDialog>
#include "MainWindow.h"
#include "ui_MainWindow.h"

using namespace std;

/**
 *  \brief Constructeur standard
 *
 *  Constructeur standard de la classe MainWindow.
 *  Effectue les connexions signaux/slots
 *
 *  \param dateDerniereSuppression : la date de la derniere suppression
 *  \param contacts : la liste des contacts lors de la creation de la fenetre
 *  \param parent : fenetre parent
 */
MainWindow::MainWindow(string dateDerniereSuppression, list<Contact*> contacts, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateDateDerniereSuppression(dateDerniereSuppression);

    creatfich = new CreationFicheWindow();
    rechcontact = new RechercheContactWindow(contacts);
    requete = new RequeteWindow(contacts);
    afficheFich = new FicheContactWindow(contacts);

    connect(this, SIGNAL(listContactsUpdated(std::list<Contact*>)), rechcontact, SLOT(updateListContacts(std::list<Contact*>)));
    connect(this, SIGNAL(listContactsUpdated(std::list<Contact*>)), afficheFich, SIGNAL(listContactsUpdated(std::list<Contact*>)));
    connect(this, SIGNAL(listContactsUpdated(std::list<Contact*>)), requete, SLOT(updateListContacts(std::list<Contact*>)));

    connect(rechcontact, SIGNAL(contactSelected(Contact*)), this, SLOT(selectContact(Contact*)));
    connect(rechcontact, SIGNAL(contactSelected(Contact*)), afficheFich, SLOT(loadContact(Contact*)));
    connect(rechcontact, SIGNAL(contactSelected(Contact*)), this, SLOT(updateContactValues()));
    connect(rechcontact, SIGNAL(contactSelected(Contact*)), requete, SLOT(loadInfosContact(Contact*)));

    connect(this, SIGNAL(onEndModifContact()), this, SLOT(updateContactValues()));
    connect(this, SIGNAL(onEndModifContact()), rechcontact, SLOT(rechercheContact()));
    connect(this, SIGNAL(onEndModifContact()), afficheFich, SIGNAL(onEndModifContact()));
    connect(this, SIGNAL(onEndModifContact()), requete, SLOT(loadInfosContact()));
    connect(this, SIGNAL(onEndModifContact()), requete, SLOT(loadInfosAllContacts()));

    connect(this, SIGNAL(onInteractionEdited()), afficheFich, SIGNAL(onInteractionEdited()));
    connect(this, SIGNAL(onInteractionEdited()), requete, SLOT(loadInfosContact()));
    connect(this, SIGNAL(onInteractionEdited()), requete, SLOT(loadInfosAllContacts()));

    connect(this, SIGNAL(onTodoEdited()), requete, SLOT(loadInfosAllContacts()));
    connect(this, SIGNAL(onTodoEdited()), requete, SLOT(loadInfosContact()));

    connect(afficheFich, SIGNAL(contactDeleted(Contact*)), this, SIGNAL(contactDeleted(Contact*)));
    connect(afficheFich, SIGNAL(prenomModified(Contact*,std::string)), this, SIGNAL(prenomModified(Contact*,std::string)));
    connect(afficheFich, SIGNAL(nomModified(Contact*,std::string)), this, SIGNAL(nomModified(Contact*,std::string)));
    connect(afficheFich, SIGNAL(entrepriseModified(Contact*,std::string)), this, SIGNAL(entrepriseModified(Contact*,std::string)));
    connect(afficheFich, SIGNAL(mailModified(Contact*,std::string)), this, SIGNAL(mailModified(Contact*,std::string)));
    connect(afficheFich, SIGNAL(telephoneModified(Contact*,std::string)), this, SIGNAL(telephoneModified(Contact*,std::string)));
    connect(afficheFich, SIGNAL(photoModified(Contact*,std::string)), this, SIGNAL(photoModified(Contact*,std::string)));

    connect(afficheFich, SIGNAL(interactionDateEdited(Interaction*,QDate)), this, SIGNAL(interactionDateEdited(Interaction*,QDate)));
    connect(afficheFich, SIGNAL(interactionResumeEdited(Interaction*,QString)), this, SIGNAL(interactionResumeEdited(Interaction*,QString)));

    connect(afficheFich, SIGNAL(ajoutInteraction(Contact*,QString)), this, SIGNAL(ajoutInteraction(Contact*,QString)));
    connect(afficheFich, SIGNAL(ajoutInteraction(Contact*,Interaction*)), this, SIGNAL(ajoutInteraction(Contact*,Interaction*)));

    connect(creatfich, SIGNAL(contactCreated(std::string,std::string,std::string,std::string,std::string,std::string)),
            this, SIGNAL(contactCreated(std::string,std::string,std::string,std::string,std::string,std::string)));

    connect(requete, SIGNAL(todoSetEffectue(Todo*,bool)), this, SIGNAL(todoSetEffectue(Todo*,bool)));

    connect(ui->actionA_propos, SIGNAL(triggered(bool)), this, SLOT(slot_aPropos()));
    connect(ui->ButtonCreerFiche, SIGNAL(clicked()), creatfich, SLOT(show()));
    connect(ui->ButtonRechercherContact, SIGNAL(clicked()), rechcontact, SLOT(show()));
    connect(ui->ButtonFicheContact, SIGNAL(clicked()), afficheFich, SLOT(show()));
    connect(ui->ButtonRequete, SIGNAL(clicked()), requete, SLOT(show()));
    connect(ui->actionExporter_en_JSON, SIGNAL(triggered()), SLOT(exportJSON()));
    connect(ui->actionImporter_un_fichier_JSON, SIGNAL(triggered()), SLOT(importJSON()));
}

/**
 *  \brief Mis a jour de la date de la derniere suppression
 *
 *  Slot pour mettre a jour l'affichage de la date de la derniere suppression
 *
 *  \param date : la nouvelle date
 */
void MainWindow::updateDateDerniereSuppression(string date)
{
    ui->labelDateSuppression->setText(QString::fromStdString("<i> " + date + "</i>"));
}

/**
 *  \brief Selection du contact
 *
 *  Slot pour selectionner le contact
 *
 *  \param date : la nouvelle date
 */
void MainWindow::selectContact()
{
    selectContact(nullptr);
}

/**
 *  \brief Selection du contact
 *
 *  Slot pour selectionner le contact
 *
 *  \param c : le contact
 */
void MainWindow::selectContact(Contact* c)
{
    curContact = c;
}

/**
 *  \brief Mis a jour du contact
 *
 *  Mis a jour de l'affichage des donnees du contact
 */
void MainWindow::updateContactValues()
{
    bool contactExistant = curContact != nullptr;
    ui->ButtonFicheContact->setEnabled(contactExistant);

    if(contactExistant)
    {
        ui->contactSelectionneLabel->setText(QString::fromStdString(curContact->toString()));
        ui->ButtonRechercherContact->setText(QString::fromStdString("Chercher un autre contact"));
    }
    else
    {
        ui->contactSelectionneLabel->setText(QString::fromStdString("Aucun"));
        ui->ButtonRechercherContact->setText(QString::fromStdString("Chercher un contact"));
    }
}

/**
  *  \brief A propos de l'application
  *
  *  Affiche le fonctionnement globale de l'application dans un QMessageBox
  */
void MainWindow::slot_aPropos()
{
    QMessageBox messageAbout;
    messageAbout.about(this, "À-propos",
    "Le but de cette application est la gestion de relations clients "
    "prenant en compte des interactions et des tâches à faire, extraites automatiquement de ces interactions. "
    "L'application tilise également une base de données SQLite afin de stocker les contacts et les interactions; et les données sont exportables en JSON.");
}

/**
 *  \brief Evenement de fermeture de la fenetre
 *
 *  Quitte toute l'application lors de la fermeture de la fenetre principale
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
    QWidget::closeEvent(event);
    QApplication::quit();
}

/**
 *  \brief Export en JSON
 *
 *  Selectionne un fichier pour exporter les donnees en JSON
 */
void MainWindow::exportJSON()
{
    QString file = QFileDialog::getSaveFileName(this, "Save JSON file", QDir::homePath(), "JSON File (*.json)");

    emit exportJSON(file);
}

/**
 *  \brief Import en JSON
 *
 *  Selectionne un fichier pour importer les donnees en JSON
 */
void MainWindow::importJSON()
{
    QString file = QFileDialog::getOpenFileName(this, "Choose JSON file", QDir::homePath(), "JSON File (*.json)");

    emit importJSON(file);
}

/**
 *  \brief Destructeur de MainWindow
 *
 *  Detruis en memoire la fenetre
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete creatfich;
    delete afficheFich;
    delete rechcontact;
    delete requete;
}
