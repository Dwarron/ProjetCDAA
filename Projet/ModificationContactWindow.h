#ifndef MODIFICATIONCONTACTWINDOW_H
#define MODIFICATIONCONTACTWINDOW_H

/**
 * \file ModificationContactWindow.h
 * \class ModificationContactWindow ModificationContactWindow.h
 * \brief Fenetre qui permet de modifier la fiche d'un contact
 * \author Perion Maxence, Pinon Alexandre
 * \version 0.1
 */

#include <QWidget>
#include "gestioncontact.h"

namespace Ui { class ModificationContactWindow; }

class ModificationContactWindow : public QWidget
{
    Q_OBJECT

public:
    ModificationContactWindow(GestionContact *g, QWidget *parent = nullptr);
    ~ModificationContactWindow();

private:
    Ui::ModificationContactWindow *ui;
    GestionContact *gestCont;
    Contact *c;

private slots:
    void LoadContactSelectionner(QString contact);
    void ModifFiche();

signals:
    void RemplieInfos(Contact *c);
};

#endif // MODIFICATIONCONTACTWINDOW_H
