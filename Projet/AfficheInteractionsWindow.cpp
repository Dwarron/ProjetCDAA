/**
 * \file AfficheInteractionsWindow.cpp
 * \class AfficheInteractionsWindow AfficheInteractionsWindow.h
 * \brief Fenêtre d'affichage des interactions d'un contact
 * \author Pinon Alexandre, Perion Maxence
 * \version 0.1
 */

#include <QDate>
#include "AfficheInteractionsWindow.h"
#include "ui_AfficheInteractionsWindow.h"
#include <iostream>
AfficheInteractionsWindow::AfficheInteractionsWindow(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::AfficheInteractionsWindow)
{
    ui->setupUi(this);

    listeInteractionsModel = new QStringListModel();
    ui->interactionsList->setModel(listeInteractionsModel);

    connect(ui->interactionsList->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), this, SLOT(selectInteraction(QModelIndex)));
    connect(ui->dateEdit, SIGNAL(dateChanged(QDate)), this, SLOT(editDate(QDate)));
    connect(ui->editTextButton, SIGNAL(clicked()), this, SLOT(modifResume()));
}

void AfficheInteractionsWindow::interactionEdited()
{
    selectContact(curContact);
}

void AfficheInteractionsWindow::selectContact(Contact* c)
{
    curContact = c;
    if(curContact != nullptr)
    {
        std::list<Interaction*> interactions = c->getInteractions();
        interactionsShown.clear();

        QStringList list;
        for(auto it = interactions.begin(); it != interactions.end(); it++)
        {
            interactionsShown.push_back(*it);
            list << QString::fromStdString((*it)->toString());
        }

        listeInteractionsModel->setStringList(list);

        setWindowTitle(QString::fromStdString("Interactions de " + c->toString()));

        curInteraction = nullptr;
        selectInteraction();
    }
    else
    {
        this->hide();
    }
}

void AfficheInteractionsWindow::selectInteraction(QModelIndex newItem)
{
    auto it = interactionsShown.begin();
    for( int i = 0; i < newItem.row(); i++)
    {
        it++;
    }
    curInteraction = *it;

    selectInteraction();
}

void AfficheInteractionsWindow::selectInteraction()
{
    if(curInteraction != nullptr)
    {
        emit interactionSelected(curInteraction);

        ui->textEdit->setText(QString::fromStdString(curInteraction->getResume()));
        ui->dateEdit->setDate(QDate::fromString(QString::fromStdString(curInteraction->getDate().toString()), "dd/MM/yyyy"));

        ui->textEdit->setEnabled(true);
        ui->editTextButton->setEnabled(true);
        ui->dateEdit->setEnabled(true);
    }
    else
    {
        ui->textEdit->setText("");
        ui->dateEdit->setDate(QDate::fromString("01/01/2021", "dd/MM/yyyy"));

        ui->textEdit->setEnabled(false);
        ui->editTextButton->setEnabled(false);
        ui->dateEdit->setEnabled(false);
    }
}

void AfficheInteractionsWindow::editDate(QDate d)
{
    if(curInteraction != nullptr)
        emit interactionDateEdited(curInteraction, d);
}

void AfficheInteractionsWindow::modifResume()
{
    if(curInteraction != nullptr)
        emit interactionResumeEdited(curInteraction, ui->textEdit->toPlainText());
}

AfficheInteractionsWindow::~AfficheInteractionsWindow()
{
    delete ui;
}
