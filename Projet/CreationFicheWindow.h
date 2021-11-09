#pragma once //probleme d'include, vu avec Monsieur Raffin et pas de meilleur solution trouvee

#include <QWidget>
#include "gestioncontact.h"

namespace Ui { class CreationFicheWindow; }

class CreationFicheWindow : public QWidget
{
    Q_OBJECT

public:
    CreationFicheWindow(GestionContact *g, QWidget *parent = nullptr);
    ~CreationFicheWindow();

private:
    Ui::CreationFicheWindow *ui;
    GestionContact *gestCont;

private slots:
    void CreationFiche();
};
