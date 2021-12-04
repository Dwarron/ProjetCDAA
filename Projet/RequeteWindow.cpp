/**
 * \file RequeteWindow.cpp
 * \class RequeteWindow RequeteWindow.h
 * \brief Fenetre qui affiche differentes requetes selectionnables
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include "RequeteWindow.h"
#include "ui_RequeteWindow.h"

using namespace std;

/**
 *  \brief Constructeur standard
 *
 *  Constructeur standard de la classe RequeteWindow.
 *  Effectue les connexions signaux/slots
 *
 *  \param g : gestion des contacts
 *  \param parent : fenetre parent
 */
RequeteWindow::RequeteWindow(list<Contact*> c, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RequeteWindow)
{
    ui->setupUi(this);
    ui->buttonGroup->setId(ui->contactsButton, 1);
    ui->buttonGroup->setId(ui->interactionsButton, 2);
    ui->buttonGroup->setId(ui->listContactButton, 3);
    ui->buttonGroup->setId(ui->listAllContactsButton, 4);

    contacts = c;
    curContact = nullptr;

    ui->afficherInfosContactComboBox->addItem("la liste des todos pour le contact");
    ui->afficherInfosContactComboBox->addItem("la liste des dates pour le contact");
    ui->afficherInfosAllContactsComboBox->addItem("la liste des todos pour les contacts");
    ui->afficherInfosAllContactsComboBox->addItem("la liste des dates pour les contacts");

    modelCheckableListViewContact = new QStandardItemModel();
    modelStringListViewContact = new QStringListModel();
    modelCheckableListViewAllContacts = new QStandardItemModel();
    modelStringListViewAllContacts = new QStringListModel();

    updateListContacts(c);
    loadInfosInteractions2Dates();

    connect(ui->dateDebutInteractions2Dates, SIGNAL(dateChanged(QDate)), this, SLOT(loadInfosInteractions2Dates()));
    connect(ui->dateFinInteractions2Dates, SIGNAL(dateChanged(QDate)), this, SLOT(loadInfosInteractions2Dates()));
    connect(ui->buttonGroup, SIGNAL(buttonClicked(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));

    connect(ui->dateDebutContact, SIGNAL(dateChanged(QDate)), this, SLOT(loadInfosContact()));
    connect(ui->dateFinContact, SIGNAL(dateChanged(QDate)), this, SLOT(loadInfosContact()));
    connect(ui->afficherInfosContactComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(loadInfosContact()));

    connect(ui->dateDebutAllContacts, SIGNAL(dateChanged(QDate)), this, SLOT(loadInfosAllContacts()));
    connect(ui->dateFinAllContacts, SIGNAL(dateChanged(QDate)), this, SLOT(loadInfosAllContacts()));
    connect(ui->afficherInfosAllContactsComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(loadInfosAllContacts()));

    connect(modelCheckableListViewContact, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(todoItemCheckedListViewContact(QStandardItem*)));
    connect(modelCheckableListViewAllContacts, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(todoItemCheckedListViewAllContacts(QStandardItem*)));

    connect(ui->checkBoxOnlyNotDoneContact, SIGNAL(stateChanged(int)), this, SLOT(loadInfosContact()));
    connect(ui->checkBoxOnlyNotDoneAllContacts, SIGNAL(stateChanged(int)), this, SLOT(loadInfosAllContacts()));

    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(hide()));

    ui->stackedWidget->setCurrentIndex(0);
}

/**
 *  \brief Mis a jour de la liste des contacts
 *
 *  Slot pour mettre a jour la liste des contacts
 *
 *  \param c : la nouvelle liste
 */
void RequeteWindow::updateListContacts(list<Contact*> c)
{
    contacts = c;
    ui->nombreContacts->setText("Pour le moment, il y a " + QString::fromStdString(to_string(contacts.size())) + " fiches de contacts sur l'application.");
    loadInfosAllContacts();
}

/**
  *  \brief Chargement des interactions entres 2 dates
  *
  *  Slot qui va recuperer les dates et afficher les interactions dans l'intervalle.
  *  Si les deux dates sont au 01/01/2020 alors on affiche toutes les interactions.
  *
  */
void RequeteWindow::loadInfosInteractions2Dates()
{
    Date dateDebut(ui->dateDebutInteractions2Dates->dateTime().toString("dd/MM/yyyy").toStdString());
    Date dateFin(ui->dateFinInteractions2Dates->dateTime().toString("dd/MM/yyyy").toStdString());

    QStringListModel* listeInteractionsModel = new QStringListModel();
    QStringList list;

    bool dontLookDates = dateDebut == dateFin && dateDebut == Date(1, 1, 2020);

    std::list<pair<Contact*, Interaction*>> interactions;

    for(auto c = contacts.begin(); c != contacts.end(); c++)
    {
        for(auto i = (*c)->getInteractions().begin(); i != (*c)->getInteractions().end(); i++)
        {
            if(dontLookDates || (dateDebut <= (*i)->getDate() && (*i)->getDate() <= dateFin))
            {
                interactions.push_back(make_pair(*c, *i));
            }
        }
    }

    interactions.sort([](pair<Contact*, Interaction*> a, pair<Contact*, Interaction*> b) {return *a.second > *b.second;});//tri de la plus recente a la plus ancienne

    for(auto it = interactions.begin(); it != interactions.end(); it++)
    {
        list << QString::fromStdString((*it).first->toString() + " : " + (*it).second->toString());
    }

    listeInteractionsModel->setStringList(list);
    ui->listViewInteractions2Dates->setModel(listeInteractionsModel);
}

/**
  *  \brief Affiche des requetes pour un contact
  *
  *  Ce slot recupere ce que l'on veut afficher (todo/date) et effectue la requete
  *  \param c : le contact selectionne
  */
void RequeteWindow::loadInfosContact(Contact* c)
{
    curContact = c;
    if(c != nullptr)
        loadInfosContact();
}

/**
  *  \brief Affiche des requetes pour un contact
  *
  *  Ce slot recupere ce que l'on veut afficher (todo/date) et effectue la requete
  *
  */
void RequeteWindow::loadInfosContact()
{
    if(curContact != nullptr)
    {
        Date dateDebut(ui->dateDebutContact->dateTime().toString("dd/MM/yyyy").toStdString());
        Date dateFin(ui->dateFinContact->dateTime().toString("dd/MM/yyyy").toStdString());

        QString listeInfos = ui->afficherInfosContactComboBox->currentText();

        bool dontLookDates = dateDebut == dateFin && dateDebut == Date(1, 1, 2020);

        if(listeInfos == "la liste des todos pour le contact")
        {
            ui->checkBoxOnlyNotDoneContact->setEnabled(true);
            bool onlyNotDone = ui->checkBoxOnlyNotDoneContact->checkState() == Qt::Checked;

            modelCheckableListViewContact->clear();
            todosShownListViewContact.clear();

            std::list<Todo*> todos = curContact->getTodos();
            for(auto it = todos.begin(); it != todos.end(); it++)
            {
                if(dontLookDates || (dateDebut <= (*it)->getEcheance() && (*it)->getEcheance() <= dateFin))
                {
                    if((onlyNotDone && !(*it)->getEffectue()) || !onlyNotDone)
                    {
                        QStandardItem* item = new QStandardItem();
                        item->setCheckable(true);
                        item->setCheckState((*it)->getEffectue() ? Qt::Checked : Qt::Unchecked);
                        item->setText(QString::fromStdString((*it)->toString()));
                        if(!(*it)->getEffectue() && (*it)->getEcheance().depassee())
                        {
                            item->setBackground(Qt::red);
                        }

                        modelCheckableListViewContact->appendRow(item);
                        todosShownListViewContact.push_back(*it);
                    }
                }
            }

            ui->listViewRequeteContact->setModel(modelCheckableListViewContact);
        }
        else
        {
            ui->checkBoxOnlyNotDoneContact->setEnabled(false);

            QStringList list;
            std::list<Interaction*> interactions = curContact->getInteractions();
            for(auto it = interactions.begin(); it != interactions.end(); it++)
            {
                if(dontLookDates|| (dateDebut < (*it)->getDate() && (*it)->getDate() < dateFin))
                    list << QString::fromStdString((*it)->getDate().toString());
            }

            modelStringListViewContact->setStringList(list);
            ui->listViewRequeteContact->setModel(modelStringListViewContact);
        }
    }
}

/**
  *  \brief Affiche des requetes pour tous les contacts
  *
  *  Ce slot recupere ce que l'on veut afficher (todo/date) et effectue la requete
  *
  */
void RequeteWindow::loadInfosAllContacts()
{
    Date dateDebut(ui->dateDebutAllContacts->dateTime().toString("dd/MM/yyyy").toStdString());
    Date dateFin(ui->dateFinAllContacts->dateTime().toString("dd/MM/yyyy").toStdString());

    QString listeInfos = ui->afficherInfosAllContactsComboBox->currentText();

    bool dontLookDates = dateDebut == dateFin && dateDebut == Date(1, 1, 2020);

    if(listeInfos == "la liste des todos pour les contacts")
    {
        ui->checkBoxOnlyNotDoneAllContacts->setEnabled(true);
        bool onlyNotDone = ui->checkBoxOnlyNotDoneAllContacts->checkState() == Qt::Checked;

        std::list<pair<string, Todo*>> datesContent;
        for(auto c = contacts.begin(); c != contacts.end(); c++)
        {
            std::list<Todo*> todosContact = (*c)->getTodos();
            for(auto t = todosContact.begin(); t != todosContact.end(); t++)
            {
                if(dontLookDates || (dateDebut <= (*t)->getEcheance() && (*t)->getEcheance() <= dateFin))
                {
                    if((onlyNotDone && !(*t)->getEffectue()) || !onlyNotDone)
                    {
                        datesContent.push_back(make_pair((*c)->toString() + " : " + (*t)->toString(), *t));
                    }
                }
            }
        }

        datesContent.sort([](pair<string, Todo*> a, pair<string, Todo*> b) {return *a.second < *b.second;});

        todosShownListViewAllContacts.clear();
        modelCheckableListViewAllContacts->clear();

        for(auto it = datesContent.begin(); it != datesContent.end(); it++)
        {
            QStandardItem* item = new QStandardItem();
            item->setCheckable(true);
            item->setCheckState((*it).second->getEffectue() ? Qt::Checked : Qt::Unchecked);
            item->setText(QString::fromStdString((*it).first));
            if(!(*it).second->getEffectue() && (*it).second->getEcheance().depassee())
            {
                item->setBackground(Qt::red);
            }
            modelCheckableListViewAllContacts->appendRow(item);
            todosShownListViewAllContacts.push_back((*it).second);
        }

        ui->listViewRequeteAllContacts->setModel(modelCheckableListViewAllContacts);
    }
    else
    {
        ui->checkBoxOnlyNotDoneAllContacts->setEnabled(false);

        map<Date, std::list<Contact*>> mapDateContact;
        for(auto c = contacts.begin(); c != contacts.end(); c++)
        {
            std::list<Interaction*> interactionsContact = (*c)->getInteractions();
            for(auto t = interactionsContact.begin(); t != interactionsContact.end(); t++)
            {
                if(dontLookDates || (dateDebut <= (*t)->getDate() && (*t)->getDate() <= dateFin))
                    mapDateContact[(*t)->getDate()].push_back(*c);
            }
        }

        QStringList list;

        for(auto d = mapDateContact.begin(); d != mapDateContact.end(); d++)
        {
            (*d).second.sort();
            (*d).second.unique();

            auto c = (*d).second.begin();
            string line = (*d).first.toString() + " : " + (*c)->toString();
            for(c++; c != (*d).second.end(); c++)
            {
                line += ", " + (*c)->toString();
            }

            list << QString::fromStdString(line);
        }

        modelStringListViewAllContacts->setStringList(list);
        ui->listViewRequeteAllContacts->setModel(modelStringListViewAllContacts);
    }
}

/**
 *  \brief Changement de l'etat fait ou non pour un todo
 *
 *  Slot changeant la valeur de l'etat effectue d'un todo affiche dans la liste view d'un contact
 *
 *  \param item : l'item dans la liste view du todo
 */
void RequeteWindow::todoItemCheckedListViewContact(QStandardItem* item)
{
    auto it = todosShownListViewContact.begin();
    for(int i = 0; i < item->row(); i++)
    {
        it++;
    }

    emit todoSetEffectue(*it, item->checkState() == Qt::Checked);
}

/**
 *  \brief Changement de l'etat fait ou non pour un todo
 *
 *  Slot changeant la valeur de l'etat effectue d'un todo affiche dans la liste view de tous les contacts
 *
 *  \param item : l'item dans la liste view du todo
 */
void RequeteWindow::todoItemCheckedListViewAllContacts(QStandardItem* item)
{
    auto it = todosShownListViewAllContacts.begin();
    for(int i = 0; i < item->row(); i++)
    {
        it++;
    }

    emit todoSetEffectue(*it, item->checkState() == Qt::Checked);
}

/**
 *  \brief Destructeur de RequeteWindow
 *
 *  Detruis en memoire la fenetre
 */
RequeteWindow::~RequeteWindow()
{
    delete ui;
    delete modelCheckableListViewContact;
    delete modelStringListViewContact;
}
