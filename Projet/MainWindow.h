#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * \file MainWindow.h
 * \class MainWindow MainWindow.h
 * \brief Fenetre principale qui permet de gerer l'ensemble des fenetres
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QMainWindow>
#include "CreationFicheWindow.h"
#include "FicheContactWindow.h"
#include "RechercheContactWindow.h"
#include "AjoutInteractionWindow.h"
#include "RequeteWindow.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent*) override;

private:
    Ui::MainWindow* ui;
    CreationFicheWindow* creatfich;
    FicheContactWindow* afficheFich;
    RechercheContactWindow* rechcontact;
    RequeteWindow* requete;
    Contact* curContact;

public slots:
    void slot_aPropos();
    void selectContact(Contact*);
    void selectContact();
    void updateContactValues();

signals:
    void contactDeleted(Contact*);
    void contactSelected(Contact*);
    void prenomModified(Contact*, std::string);
    void nomModified(Contact*, std::string);
    void entrepriseModified(Contact*, std::string);
    void telephoneModified(Contact*, std::string);
    void mailModified(Contact*, std::string);
    void photoModified(Contact*, std::string);
    void listContactsUpdated(std::list<Contact*>);
    void contactCreated(std::string, std::string, std::string, std::string, std::string, std::string);
    void onEndModifContact();
    void interactionDateEdited(Interaction*, QDate);
    void interactionResumeEdited(Interaction*, QString);
    void onInteractionEdited();
    void ajoutInteraction(Contact*, QString);
    void ajoutInteraction(Contact*, Interaction*);
};
#endif // MAINWINDOW_H
