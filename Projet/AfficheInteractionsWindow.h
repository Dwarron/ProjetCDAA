#ifndef AFFICHEINTERACTIONSWINDOW_H
#define AFFICHEINTERACTIONSWINDOW_H


/**
 * \file AfficheInteractionsWindow.h
 * \class AfficheInteractionsWindow AfficheInteractionsWindow.h
 * \brief Fenêtre d'affichage des interactions d'un contact
 * \author Pinon Alexandre, Perion Maxence
 * \version 0.1
 */

#include <QWidget>
#include <QStringListModel>
#include <QDate>
#include "Contact.h"

namespace Ui { class AfficheInteractionsWindow; }

class AfficheInteractionsWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AfficheInteractionsWindow(QWidget* parent = nullptr);
    ~AfficheInteractionsWindow();

private:
    Ui::AfficheInteractionsWindow* ui;
    QStringListModel* listeInteractionsModel;
    std::list<Interaction*> interactionsShown;
    Interaction* curInteraction;
    Contact* curContact;

    void selectInteraction();

signals:
    void interactionSelected(Interaction*);
    void interactionDateEdited(Interaction*, QDate);
    void interactionResumeEdited(Interaction*, QString);

private slots:
    void selectContact(Contact*);
    void selectInteraction(QModelIndex);
    void editDate(QDate);
    void modifResume();
    void interactionEdited();
};

#endif // AFFICHEINTERACTIONSWINDOW_H
