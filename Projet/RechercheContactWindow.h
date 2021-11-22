#ifndef RECHERCHECONTACTWINDOW_H
#define RECHERCHECONTACTWINDOW_H

/**
 * \file RechercheContactWindow.h
 * \class RechercheContactWindow RechercheContactWindow.h
 * \brief Fenetre permettant la recherche et la selection d'un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QWidget>
#include <QStringListModel>
#include "Contact.h"

namespace Ui { class RechercheContactWindow; }

class RechercheContactWindow : public QWidget
{
    Q_OBJECT

public:
    RechercheContactWindow(QWidget* parent = nullptr);
    ~RechercheContactWindow();

private:
    Ui::RechercheContactWindow *ui;
    std::list<Contact*> contacts;
    std::list<Contact*> contactsAffiches;
    QStringListModel* listeContactsModel;

public slots:
    void updateListContacts(std::list<Contact*>);
    void rechercheContact(QString);
    void rechercheContact();
    void selectContact(QModelIndex);

signals:
    void contactSelected(Contact*);
    void listContactsUpdated(std::list<Contact*>);
};

#endif // RECHERCHECONTACTWINDOW_H
