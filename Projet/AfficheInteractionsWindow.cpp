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


/**
  *  \brief Constructeur standard
  *
  *  Constructeur standard de AfficheInteractionsWindow
  *
  *  \param parent : le widget parent
  */
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

/**
  *  \brief slot interactionEdited, appele quand une interaction a ete modifiee
  *
  *  affiche a nouveau les informations
  */
void AfficheInteractionsWindow::interactionEdited()
{
    selectContact(curContact);
}

/**
  *  \brief slot appele pour selectionner un contact
  *
  *  affiche les informations du contact s'il existe
  *
  *  \param c : le contact
  */
void AfficheInteractionsWindow::selectContact(Contact* c)
{
    curContact = c;
    if(curContact != nullptr)
    {
        std::list<Interaction*> interactions = c->getInteractions();
        interactions.sort([](Interaction* a, Interaction* b) {return *a > *b;});   //tri de la plus recente a la plus ancienne

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

/**
  *  \brief slot appele lors de la selection d'une interaction
  *
  *  Selection d'une interaction apres click dans la liste
  *
  *  \param newItem : l'item de selection
  */
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

/**
  *  \brief slot appele lors de la selection d'une interaction
  *
  *  Selection d'une interaction, affiche les informations dans la fenetre
  */
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

/**
  *  \brief slot appele lors de l'edition de la date
  *
  *  Modifie la date via un signal
  *
  *  \param d : la nouvelle date
  */
void AfficheInteractionsWindow::editDate(QDate d)
{
    if(curInteraction != nullptr)
        emit interactionDateEdited(curInteraction, d);
}

/**
  *  \brief slot appele lors de l'edition du resume
  *
  *  Modifie le resume via un signal
  */
void AfficheInteractionsWindow::modifResume()
{
    if(curInteraction != nullptr)
        emit interactionResumeEdited(curInteraction, ui->textEdit->toPlainText());
}

/**
 *  \brief Destructeur de Contact
 *
 *  Detruis en memoire la fenetre
 */
AfficheInteractionsWindow::~AfficheInteractionsWindow()
{
    delete ui;
}
