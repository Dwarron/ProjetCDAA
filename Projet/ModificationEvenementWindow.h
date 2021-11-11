#ifndef MODIFICATIONEVENEMENTWINDOW_H
#define MODIFICATIONEVENEMENTWINDOW_H

/**
 * \file ModificationEvenementWindow.h
 * \class ModificationEvenementWindow ModificationEvenementWindow.h
 * \brief Fenetre qui permet de modifier un evenement
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QWidget>
#include "gestioncontact.h"

namespace Ui { class ModificationEvenementWindow; }

class ModificationEvenementWindow: public QWidget
{
    Q_OBJECT

public:
    ModificationEvenementWindow(GestionContact *g, QWidget *parent = nullptr);
    ~ModificationEvenementWindow();



private:
    Ui::ModificationEvenementWindow *ui;
    GestionContact *gestCont;
    Contact *c;
    Interaction *i;
    std::string interaction;
    std::string temps;

private slots:
    void LoadContactSelectionner(QString contact);
    void LoadEvenementSelectionner(QString event);
    void ModifEvent();

signals:
    void ContactChoisie(Contact *c);
    void FillEventComboBox();
};

#endif // MODIFICATIONEVENEMENTWINDOW_H
