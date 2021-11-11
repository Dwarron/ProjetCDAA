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
    AjoutEvenementWindow(GestionContact *g, QWidget *parent = nullptr);
    ~AjoutEvenementWindow();

private:
    Ui::AjoutEvenementWindow *ui;
    GestionContact *gestCont;
    Contact *c;
    Interaction *i;
    std::string interaction;

private slots:
    void LoadContactSelectionner(QString contact);
    void LoadEvenementSelectionner(QString event);
    void AjoutEvenement();
    void ChoixEvenement();
    void NouvelleEvenement();

signals:
    void FillEventComboBox();
};

#endif // AJOUTEVENEMENTWINDOW_H
