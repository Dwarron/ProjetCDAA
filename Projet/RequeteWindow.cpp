/**
 * \file RequeteWindow.cpp
 * \class RequeteWindow RequeteWindow.h
 * \brief Fenetre avec laquel on peut rechercher un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "RequeteWindow.h"
#include "ui_RequeteWindow.h"

#include <QDebug>

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

void RequeteWindow::NombreContacts()
{
    ui->stackedWidget->setCurrentIndex(1);

    std::string nbrContacts = std::to_string(gestCont->getContacts().size());
    ui->nombreContacts->setText("Pour le moment il y a : " + QString::fromStdString(nbrContacts) + " fiches de contacts sur l'application.");
}

void RequeteWindow::EvenementEntre2Dates()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->listeEvenementPlainTextEdit->setReadOnly(true);
}

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

void RequeteWindow::ListeTodoDateContact()
{
    ui->stackedWidget->setCurrentIndex(3);

    ui->afficherInfosContactComboBox->addItem("la liste des todos pour le contact");
    ui->afficherInfosContactComboBox->addItem("la liste des dates pour le contact");

    //on remplie la combo box des contacts
    for(auto it = gestCont->getContacts().begin(); it != gestCont->getContacts().end(); it++)
    {
        ui->selectContactComboBox->addItem(QString::fromStdString((*it)->toString()));
    }
}

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
        for(auto it = c->getInteractions().begin(); it != c->getInteractions().end(); it++)
        {
            if( dateDebut < (*it)->getDate() && (*it)->getDate() < dateFin )
                ui->listeInfosContactplainTextEdit->insertPlainText(QString::fromStdString("Contact " + c->getNom() + " " + c->getPrenom() + " : " + (*it)->getDate().toString()) + "\n");
        }
    }
}

void RequeteWindow::ListeTodoDateContacts()
{
    ui->stackedWidget->setCurrentIndex(4);

    ui->afficherInfosContactsComboBox->addItem("la liste des todos pour le contact");
    ui->afficherInfosContactsComboBox->addItem("la liste des dates pour le contact");
}

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
            for(auto it2 = (*it)->getInteractions().begin(); it2 != (*it)->getInteractions().end(); it2++)
            {
                if( dateDebut < (*it2)->getDate() && (*it2)->getDate() < dateFin )
                    ui->listeInfosplainTextEdit->insertPlainText(QString::fromStdString("Contact " + (*it)->getNom() + " " + (*it)->getPrenom() + " : " + (*it2)->getDate().toString()) + "\n");
            }
        }
    }
}

RequeteWindow::~RequeteWindow()
{
    delete ui;
}
