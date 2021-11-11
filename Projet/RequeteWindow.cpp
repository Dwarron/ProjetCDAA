/**
 * \file RequeteWindow.cpp
 * \class RequeteWindow RequeteWindow.h
 * \brief Fenetre avec laquel on peut rechercher un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "RequeteWindow.h"
#include "ui_RequeteWindow.h"

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
}

void RequeteWindow::ListeTodoDateContacts()
{
    ui->stackedWidget->setCurrentIndex(4);
}

RequeteWindow::~RequeteWindow()
{
    delete ui;
}
