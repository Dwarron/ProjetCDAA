/**
 * \file RequeteWindow.cpp
 * \class RequeteWindow RequeteWindow.h
 * \brief Fenetre qui affiche differentes requetes selectionnables
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "RequeteWindow.h"
#include "ui_RequeteWindow.h"

/**
 *  \brief Constructeur standard
 *
 *  Constructeur standard de la classe RequeteWindow.
 *  Effectue les connexions entre les differents Widget et evenement a declencher.
 *  Permet de remplir les comboBox pour le trie et pour la recherche d'un contact.
 *
 *  \param g : gestion des contacts
 *  \param parent : fenetre parent
 */
RequeteWindow::RequeteWindow(GestionContact *g, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RequeteWindow)
{
    ui->setupUi(this);

    gestCont = g;

    connect(ui->contactsButton, SIGNAL(clicked()), this, SLOT(NombreContacts()));
    connect(ui->eventButton, SIGNAL(clicked()), this, SLOT(EvenementEntre2Dates()));
    connect(ui->listContactButton, SIGNAL(clicked()), this, SLOT(ListeTodoDateContact()));
    connect(ui->listContactsButton, SIGNAL(clicked()), this, SLOT(ListeTodoDateContacts()));
    connect(ui->validIntervalButton, SIGNAL(clicked()), this, SLOT(LoadInfosEvent2Dates()));
    connect(ui->validInfosContactPushButton, SIGNAL(clicked()), this, SLOT(LoadInfosSelectContact()));
    connect(ui->validInfosContactsPushButton, SIGNAL(clicked()), this, SLOT(LoadInfosContacts()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));

    ui->stackedWidget->setCurrentIndex(0);
}

/**
  *  \brief Nombre de contact
  *
  *  Slot avec lequel on va ouvrir la premiere page du stackedWideg afin d'afficher le nombre de contacts.
  *
  */
void RequeteWindow::NombreContacts()
{
    ui->stackedWidget->setCurrentIndex(1);

    std::string nbrContacts = std::to_string(gestCont->getContacts().size());
    ui->nombreContacts->setText("Pour le moment il y a : " + QString::fromStdString(nbrContacts) + " fiches de contacts sur l'application.");
}

/**
  *  \brief Interactions entre 2 dates
  *
  *  Slot qui permet d'ouvrir la second page du stackedWideg.
  *  Dans celle-ci il est possible d'afficher toutes les interactions entre 2 dates donnees.
  *
  */
void RequeteWindow::EvenementEntre2Dates()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->listeEvenementPlainTextEdit->setReadOnly(true);
}

/**
  *  \brief Chargement des informations entres 2 dates
  *
  *  Slot qui va recuperer les dates et afficher les interactions.
  *
  */
void RequeteWindow::LoadInfosEvent2Dates()
{
    Date dateDebut(ui->dateDebutDateEdit->dateTime().toString("dd/MM/yyyy").toStdString());
    Date dateFin(ui->dateFinDateEdit->dateTime().toString("dd/MM/yyyy").toStdString());

    ui->listeEvenementPlainTextEdit->clear();

    for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
    {
        for(auto it2 = (*it)->getInteractions().begin(); it2 != (*it)->getInteractions().end(); it2++)
        {
            ui->listeEvenementPlainTextEdit->appendPlainText(QString::fromStdString((*it2)->toString()) + "\n");
        }
    }
}

/**
  *  \brief Nombre de contact
  *
  *  Slot avec lequel on va ouvrir la troisiement page du stackedWideg afin d'afficher les todos ou dates d'un contact.
  *  Initialise egalement la comboBox des contacts et la comboBox pour le choix de l'utilisateur.
  *
  */
void RequeteWindow::ListeTodoDateContact()
{
    ui->stackedWidget->setCurrentIndex(3);

    ui->afficherInfosContactComboBox->clear();
    ui->afficherInfosContactComboBox->addItem("la liste des todos pour le contact");
    ui->afficherInfosContactComboBox->addItem("la liste des dates pour le contact");

    ui->selectContactComboBox->clear();
    //on remplie la combo box des contacts
    for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
    {
        ui->selectContactComboBox->addItem(QString::fromStdString((*it)->toString()));
    }
}

/**
  *  \brief Chargement des informations pour l'affichage
  *
  *  Ce slot recupere qu'elle informations l'utilisateur veut afficher (todo/date).
  *  Et fait l'affichage en fonction pour le contact selectionne.
  *
  */
void RequeteWindow::LoadInfosSelectContact()
{
    ui->listeInfosContactplainTextEdit->clear();

    QString contact = ui->selectContactComboBox->currentText();

    //on recupere le contact
    for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
    {
        if( (*it)->toString() == contact.toStdString() )
            c = *it;
    }

    Date dateDebut(ui->debutContactDateEdit->dateTime().toString("dd/MM/yyyy").toStdString());
    Date dateFin(ui->finContactDateEdit->dateTime().toString("dd/MM/yyyy").toStdString());

    QString listeInfos = ui->afficherInfosContactComboBox->currentText();

    std::list<Todo*> todostemp = c->getTodos();

    if( listeInfos == "la liste des todos pour le contact")
    {
        for(auto it = todostemp.begin(); it != todostemp.end(); it++)
        {
            if( dateDebut < (*it)->getEcheance() && (*it)->getEcheance() < dateFin )
                ui->listeInfosContactplainTextEdit->insertPlainText(QString::fromStdString((*it)->toString()) + "\n");
        }
    }
    else
    {
        for(auto it = todostemp.begin(); it != todostemp.end(); it++)
        {
            if( dateDebut < (*it)->getEcheance() && (*it)->getEcheance() < dateFin )
                ui->listeInfosContactplainTextEdit->insertPlainText(QString::fromStdString("Contact " + c->getNom() + " " + c->getPrenom() + " : " + (*it)->getEcheance().toString()) + "\n");
        }
    }
}

/**
  *  \brief Nombre de contact
  *
  *  Slot avec lequel on va ouvrir la quatrieme et derniere page du stackedWideg afin d'afficher les todos ou dates de tous les contacts.
  *
  */
void RequeteWindow::ListeTodoDateContacts()
{
    ui->stackedWidget->setCurrentIndex(4);

    ui->afficherInfosContactsComboBox->clear();
    ui->afficherInfosContactsComboBox->addItem("la liste des todos pour le contact");
    ui->afficherInfosContactsComboBox->addItem("la liste des dates pour le contact");
}

/**
  *  \brief Chargement des informations pour l'affichage
  *
  *  Ce slot recupere qu'elle informations l'utilisateur veut afficher (todo/date).
  *  Et fait l'affichage en fonction pour tous les contacts.
  *
  */
void RequeteWindow::LoadInfosContacts()
{
    ui->listeInfosplainTextEdit->clear();

    Date dateDebut(ui->debutContactsDateEdit->dateTime().toString("dd/MM/yyyy").toStdString());
    Date dateFin(ui->finContactsDateEdit->dateTime().toString("dd/MM/yyyy").toStdString());

    QString listeInfos = ui->afficherInfosContactsComboBox->currentText();

    std::list<Todo*> todostemp;

    for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
    {
        todostemp = (*it)->getTodos();

        if( listeInfos == "la liste des todos pour le contact")
        {
            for(auto it2 = todostemp.begin(); it2 != todostemp.end(); it2++)
            {
                if( dateDebut < (*it2)->getEcheance() && (*it2)->getEcheance() < dateFin )
                    ui->listeInfosplainTextEdit->insertPlainText(QString::fromStdString((*it2)->toString()) + "\n");
            }
        }
        else
        {
            for(auto it2 = todostemp.begin(); it2 != todostemp.end(); it2++)
            {
                if( dateDebut < (*it2)->getEcheance() && (*it2)->getEcheance() < dateFin )
                    ui->listeInfosplainTextEdit->insertPlainText(QString::fromStdString("Contact " + (*it)->getNom() + " " + (*it)->getPrenom() + " : " + (*it2)->getEcheance().toString()) + "\n");
            }
        }
    }
}

/**
 *  \brief Destructeur de RequeteWindow
 *
 *  Detruis en memoire la fenetre
 */
RequeteWindow::~RequeteWindow()
{
    delete ui;
}
