#include "ModificationContactWindow.h"
#include "ui_ModificationContactWindow.h"
#include "iostream"
#include "QString"

using namespace std;

ModificationContactWindow::ModificationContactWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModificationContactWindow)
{
    ui->setupUi(this);
    connect(ui->validButton, SIGNAL(clicked()), this, SLOT(CreationFiche()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));


    //on remplie la combo box
    g->creeContact("Duportail", "Damien", "Unirex compagnie", "0673332557", "damien.duportail@btc.fr", "/home/Directory/Document/Image/duportail.jpg");
    for(auto it = g->getContacts().begin(); it != g->getContacts().end(); it++)
    {
        ui->comboContacts->addItem(QString::fromStdString((*it)->getNom()));
    }
}

ModificationContactWindow::~ModificationContactWindow()
{
    delete ui;
}

void ModificationContactWindow::ModifFiche()
{
    //on va regarder quelle champ sont modifier pour utiliser les setters/mutateur

    //utiliser proposeNom pour le nom et le prénom


    //apres avoir modifier le contact avec les informations de la fentre on la ferme
    this->close();
}
