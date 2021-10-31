#ifndef MODIFICATIONCONTACTWINDOW_H
#define MODIFICATIONCONTACTWINDOW_H

#include <QDialog>
#include "gestioncontact.h"

namespace Ui { class ModificationContactWindow; }

class ModificationContactWindow : public QDialog
{
    Q_OBJECT
public:
    ModificationContactWindow(QWidget *parent = nullptr);
    ~ModificationContactWindow();
    GestionContact *g;

private:
    Ui::ModificationContactWindow *ui;

private slots:
    void ModifFiche();
};

#endif // MODIFICATIONCONTACTWINDOW_H
