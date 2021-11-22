#ifndef AJOUTINTERACTIONWINDOW_H
#define AJOUTINTERACTIONWINDOW_H

/**
 * \file AjoutEvenementWindow.h
 * \class AjoutEvenementWindow AjoutEvenementWindow.h
 * \brief Fenetre qui permet de creer une nouvelle interaction ou d'ajouter une existante qui a ete auparavant ajoutee sur un autre contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QWidget>
#include "RechercheContactWindow.h"
#include "AfficheInteractionsWindow.h"

namespace Ui { class AjoutInteractionWindow; }

class AjoutInteractionWindow : public QWidget
{
    Q_OBJECT

public:
    AjoutInteractionWindow(QWidget* parent = nullptr);
    ~AjoutInteractionWindow();

private:
    Ui::AjoutInteractionWindow* ui;
    Contact* curContact;
    RechercheContactWindow* rechContactWindow;
    AfficheInteractionsWindow* afficheInteractionsWindow;

public slots:
    void selectContact(Contact*);
    void ajoutEvenement();
    void selectInteraction(Interaction*);

signals:
    void ajoutInteraction(Contact*, QString);
    void ajoutInteraction(Contact*, Interaction*);
    void listContactsUpdated(std::list<Contact*>);
    void onEndModifContact();
};

#endif // AJOUTINTERACTIONWINDOW_H
