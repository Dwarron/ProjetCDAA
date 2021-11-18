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
    ModificationContactWindow(GestionContact*, QWidget* parent = nullptr);
    ~ModificationContactWindow();

protected:
    void resizeEvent(QResizeEvent*) override;

private:
    Ui::ModificationContactWindow* ui;
    GestionContact* gestCont;
    Contact* curContact;
    QString file_name;
    void RemplieInfos(Contact*);

public slots:
    void loadContact(Contact*);
    void ModifFiche();
    void ChangeFile();
    void supprimerContact();
    void showImage(QString);

signals:
    void imageSelected(QString);
    void contactDeleted(Contact*);
    void prenomModified(Contact*, std::string);
    void nomModified(Contact*, std::string);
    void entrepriseModified(Contact*, std::string);
    void telephoneModified(Contact*, std::string);
    void mailModified(Contact*, std::string);
    void photoModified(Contact*, std::string);
};

#endif // MODIFICATIONCONTACTWINDOW_H
