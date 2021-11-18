#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * \file MainWindow.h
 * \class MainWindow MainWindow.h
 * \brief Fenetre qui permet de gerer l'ensemble des fenetres de cette application
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QMainWindow>
#include <CreationFicheWindow.h>
#include <ModificationContactWindow.h>
#include <RechercheContactWindow.h>
#include <AjoutEvenementWindow.h>
#include <ModificationEvenementWindow.h>
#include <RequeteWindow.h>
#include <GestionContact.h>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(GestionContact*, QWidget* parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent*) override;

private:
    GestionContact* gestCont;
    Ui::MainWindow* ui;
    CreationFicheWindow* creatfich;
    ModificationContactWindow* modiffich;
    RechercheContactWindow* rechcontact;
    AjoutEvenementWindow* ajoutinter;
    ModificationEvenementWindow* modifevent;
    RequeteWindow* requete;
    Contact* curContact;

public slots:
    void openWindowCreeFiche();
    void openWindowModifFiche();
    void openWindowRechercheContact();
    void openWindowAjoutInteraction();
    void openWindowModifEvent();
    void openWindowRequete();
    void slot_aPropos();
    void selectContact(Contact*);
    void deleteContact(Contact*);
    void modifPrenom(Contact*, std::string);
    void modifNom(Contact*, std::string);
    void modifEntreprise(Contact*, std::string);
    void modifTelephone(Contact*, std::string);
    void modifMail(Contact*, std::string);
    void modifPhoto(Contact*, std::string);
    void updateListContacts();
    void createContact(std::string, std::string, std::string, std::string, std::string, std::string);
    void onContactCreated(Contact*);

signals:
    void contactDeleted(Contact*);
    void contactSelected(Contact*);
    void prenomModified(Contact*, std::string);
    void nomModified(Contact*, std::string);
    void entrepriseModified(Contact*, std::string);
    void telephoneModified(Contact*, std::string);
    void mailModified(Contact*, std::string);
    void photoModified(Contact*, std::string);
    void listContactsUpdated();
    void contactCreated(std::string, std::string, std::string, std::string, std::string, std::string);
};
#endif // MAINWINDOW_H
