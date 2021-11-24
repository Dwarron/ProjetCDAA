#ifndef FICHECONTACTWINDOW_H
#define FICHECONTACTWINDOW_H

/**
 * \file FicheContactWindow.h
 * \class FicheContactWindow FicheContactWindow.h
 * \brief Fenetre qui permet d'afficher et modifier la fiche d'un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QWidget>
#include <QDate>
#include "AfficheInteractionsWindow.h"
#include "AjoutInteractionWindow.h"

namespace Ui { class FicheContactWindow; }

class FicheContactWindow : public QWidget
{
    Q_OBJECT

public:
    FicheContactWindow(std::list<Contact*>, QWidget* parent = nullptr);
    ~FicheContactWindow();

protected:
    void resizeEvent(QResizeEvent*) override;

private:
    Ui::FicheContactWindow* ui;
    Contact* curContact;
    QString file_name;
    AfficheInteractionsWindow* afficheInteractionsWindow;
    AjoutInteractionWindow* ajoutinter;

public slots:
    void reloadDateModif();
    void loadContact(Contact*);
    void modifFiche();
    void changeFile();
    void supprimerContact();
    void showImage(QString);

signals:
    void imageSelected(QString);
    void contactDeleted(Contact*);
    void prenomModified(Contact*, std::string);
    void nomModified(Contact*, std::string);
    void entrepriseModified(Contact*, std::string);
    void telephoneModified(Contact*, std::string);
    void mailModified(Contact*, std::string);
    void photoModified(Contact*, std::string);
    void contactSelected(Contact*);
    void interactionDateEdited(Interaction*, QDate);
    void interactionResumeEdited(Interaction*, QString);
    void onInteractionEdited();
    void ajoutInteraction(Contact*, QString);
    void ajoutInteraction(Contact*, Interaction*);
    void listContactsUpdated(std::list<Contact*>);
    void onEndModifContact();
};

#endif // FICHECONTACTWINDOW_H
