#pragma once //probleme d'include, vu avec Monsieur Raffin et pas de meilleur solution trouvee

#include <QDialog>

namespace Ui { class CreationFicheWindow; }

class CreationFicheWindow : public QDialog
{
    Q_OBJECT

public:
    CreationFicheWindow(QWidget *parent = nullptr);
    ~CreationFicheWindow();

private:
    Ui::CreationFicheWindow *ui;

private slots:
    void CreationFiche();
};
