#ifndef RECHERCHECONTACTWINDOW_H
#define RECHERCHECONTACTWINDOW_H

/**
 * \file RechercheContactWindow.h
 * \class RechercheContactWindow RechercheContactWindow.h
 * \brief Fenetre avec laquel on peut rechercher un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QWidget>
#include "GestionContact.h"
#include <QStringListModel>

namespace Ui { class RechercheContactWindow; }

class RechercheContactWindow : public QWidget
{
    Q_OBJECT

public:
    RechercheContactWindow(GestionContact*, QWidget* parent = nullptr);
    ~RechercheContactWindow();

private:
    Ui::RechercheContactWindow *ui;
    GestionContact *gestCont;
    std::list<Contact*> contactsAffiches;
    QStringListModel* listeContactsModel;

public slots:
    void rechercheContact(QString);
    void rechercheContact();
    void selectContact(QModelIndex);
    void updateListContacts();

signals:
    void contactSelected(Contact*);
    void listContactsUpdated();
};

#endif // RECHERCHECONTACTWINDOW_H
