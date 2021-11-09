#ifndef MODIFICATIONCONTACTWINDOW_H
#define MODIFICATIONCONTACTWINDOW_H

#include <QWidget>
#include "gestioncontact.h"

namespace Ui { class ModificationContactWindow; }

class ModificationContactWindow : public QWidget
{
    Q_OBJECT
public:
    ModificationContactWindow(GestionContact *g, QWidget *parent = nullptr);
    ~ModificationContactWindow();
    GestionContact *gestCont;

private:
    Ui::ModificationContactWindow *ui;
    Contact *c;

private slots:
    void LoadContactSelectionner(QString contact);
    void ModifFiche();

signals:
    void RemplieInfos(Contact *c);
};

#endif // MODIFICATIONCONTACTWINDOW_H
