#ifndef AJOUTEVENEMENTWINDOW_H
#define AJOUTEVENEMENTWINDOW_H

/**
 * \file AjoutEvenementWindow.h
 * \class AjoutEvenementWindow AjoutEvenementWindow.h
 * \brief Fenetre qui permet de creer de nouvelle interactions ou d'en reutiliser des anciennes
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QWidget>
#include "gestioncontact.h"

namespace Ui { class AjoutEvenementWindow; }

class AjoutEvenementWindow : public QWidget
{
    Q_OBJECT

public:
    AjoutEvenementWindow(GestionContact*, QWidget* parent = nullptr);
    ~AjoutEvenementWindow();

private:
    Ui::AjoutEvenementWindow* ui;
    GestionContact* gestCont;
    Contact* curContact;
    Interaction* i;
    std::string interaction;
    void FillEventComboBox();

private slots:
    void selectContact(Contact*);
    void LoadEvenement(QString);
    void AjoutEvenement();
    void ChoixEvenement();
    void NouvelEvenement();

};

#endif // AJOUTEVENEMENTWINDOW_H
