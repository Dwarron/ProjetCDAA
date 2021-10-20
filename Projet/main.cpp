#include "mainwindow.h"
#include "Contact.h"
#include "Date.h"
#include "Interaction.h"
#include "gestioncontact.h"
#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  /*  MainWindow w;
    w.show();*/

    GestionContact g;

    Contact* contact1 = g.creeContact("Duportail", "Damien", "Unirex compagnie", "06.73.33.25.57", "damien.duportail@btc.fr", "/home/Directory/Document/Image/duportail.jpg");
    Contact* contact2 = g.creeContact("14Delafenetrel68", "Jean78-Pierre56", "Btc compagnie", "06.07.48.75.37", "delafenetre.jp@eth.fr", "/home/Directory/Document/Photo/dlf.jpg");
    contact1->addInteraction(new Interaction("rdv tel ras\n@todo rappeler 1 le @date 21/10/2021\n@todo rappeler 2 le @date 22/10/2021"));
    cout << contact1->todosToString() << endl;
    // TODO : fonctions pour tester, addinteraction pris en charge par gestioncontact, fix bug sort interactions/todos, manque quelques getters/setters dans contact
    cout << *contact1 << endl;
    cout << *contact2 << endl;
    contact1->setEntreprise("Pancakesquad NFT");
    cout << contact1->interactionsToString() << endl;

    Date d = Date();
    cout << "Date du jour : " << d << endl;
    d.addDelay(7);
    cout << "Dans une semaine nous serons le : " << d << endl;
    d.addDelay(10, 2, 1);
    cout << "Dans 10 jours, 2 semaines et 1 an nous serons le : " << d << endl;
    d.addDelay(500);
    cout << "Dans 500 jours nous serons le : " << d << endl;
    Date d2 = Date(16, 8, 2023);
    cout << "Creee avec comme jour 16, mois 8 et annee 2023 : " << d2 << endl;
    Date d3 = Date("05/2/2028");
    cout << "Creee avec le texte '05/02/2028' : " << d3 << endl;
    cout << d2 << " est-il avant " << d3 << " ? " << (d2 < d3) << endl;
    cout << d << " est-il avant " << d2 << " ? " << (d < d2) << endl;
    Date d4 = Date(16, 9, 2023);
    cout << d4 << " est-il avant " << d2 << " ? " << (d4 < d2) << endl;
    Date d5 = Date(15, 8, 2023);
    cout << d5 << " est-il avant " << d2 << " ? " << (d5 < d2) << endl;
    //return a.exec();
}
