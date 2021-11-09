#pragma once //probleme d'include, vu avec Monsieur Raffin et pas de meilleur solution trouvee

#include <QWidget>
#include "gestioncontact.h"

namespace Ui { class RechercheContactWindow; }

class RechercheContactWindow : public QWidget
{
    Q_OBJECT

public:
    RechercheContactWindow(GestionContact *g, QWidget *parent = nullptr);
    ~RechercheContactWindow();
    GestionContact *gestCont;

private:
    Ui::RechercheContactWindow *ui;

private slots:
    void rechercheContact(QString infos);
    void dateContact(QDate &q);
    void trieContact(QString trie);

};
