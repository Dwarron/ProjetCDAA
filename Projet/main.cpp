#include "mainwindow.h"
#include "Contact.h"
#include "Date.h"
#include "Interaction.h"
#include "GestionContact.h"
#include <QApplication>
#include <iostream>

using namespace std;

/*! \mainpage Projet de CDAA : Logiciel de gestion de relations clients (CRM)
 *
 * \section intro_sec Introduction
 *
 *  Le sujet du projet est de produire un logiciel permettant de g&eacute;rer des contacts et leurs interactions avec une entit&eacute;.
 *  Il est &eacute;galement question d'extraire des t&acirc;ches a faire des interactions gr&acirc;ce &acirc; des tags (@ todo et @ date).
 *
 *  \section prog_sec Programmation en 3 parties
 *  La programmation du projet est realis&eacute;e en 3 parties distinctes : la programmation orient&eacute;e object, l'interface graphique
 *  et la persistence des donn&eacute;es.
 *
 *  \subsection poo_subsec Partie Programmation Orient&eacute;e Object
 *  Dans cette premiere partie, le but a ete de simplement d&eacute;crire les differents objets qui interviendront tout le long du projet et les
 *  relations/interactions entre eux. Nous avons notamment cr&eacute;e les classes Contact, GestionContact, Interaction et Todo. Ces classes ayant besoin
 *  de gerer le temps, nous avons &eacute;galement produit la classe Date.
 *
 *  \subsection ihm_subsec Partie Interface Graphique
 *  <em> A venir... </em>
 *
 *  \subsection persistence_subsec Partie Persistence des donn&eacute;es
 *  <em> A venir... </em>
 *
 * \authors Alexandre Pinon et Maxence Perion
 */

bool dateUnitTest1()
{
    Date d = Date(22, 01, 2025);
    Date d2 = Date("22/01/2025");

    return d == d2;
}

bool dateUnitTest2()
{
    Date d = Date(22, 05, 2024);
    d.addDelay(1);
    Date d2 = Date(23, 05, 2024);

    return d == d2;
}

bool dateUnitTest3()
{
    Date d = Date(18, 05, 2024);
    Date d2 = Date(23, 05, 2024);

    return d < d2;
}

bool dateUnitTest4()
{
    Date d = Date(18, 05, 2024);
    Date d2 = Date(23, 05, 2025);
    Date d3 = Date(2, 06, 2025);
    list<Date> dates = list<Date>();
    dates.push_back(d);
    dates.push_back(d3);
    dates.push_back(d2);
    dates.sort();

    Date rd = *dates.begin();
    dates.pop_front();
    Date rd2 = *dates.begin();
    dates.pop_front();
    Date rd3 = *dates.begin();
    dates.pop_front();

    return rd < rd2 && rd2 < rd3;
}

void testDate()
{
    int testSucces = 0;

    if(dateUnitTest1())
    {
        testSucces++;
    }
    if(dateUnitTest2())
    {
        testSucces++;
    }
    if(dateUnitTest3())
    {
        testSucces++;
    }
    if(dateUnitTest4())
    {
        testSucces++;
    }

    cout << "Tests Unitaires pour Date : " << testSucces << "/4 tests reussis" << endl;
}

int main(int argc, char *argv[])
{
    GestionContact g = GestionContact();    //classe de gestion des contacts
    Contact* contact1 = g.creeContact("Duportail", "Damien", "Unirex compagnie", "0673332557", "damien.duportail@btc.fr", "/home/Directory/Document/Image/duportail.jpg");
    Contact* contact2 = g.creeContact("Delafenetre", "Jean-Pierre", "Btc compagnie", "0607487537", "", "/home/Directory/Document/Photo/dlf.jpg");

    cout << "affichage des contacts directement avec <<" << endl << "contact1 : " << *contact1 << endl;
    cout << "contact2 : " << *contact2 << endl;
    cout << endl;

    contact1->setEntreprise("Pancakesquad NFT");
    cout << "interactions apres modification via un setter de la fiche d'un contact : " << endl << contact1->interactionsToString() << endl;
    cout << endl;

    Interaction* i = g.ajoutInteraction(contact1, "rdv tel ras\n@todo rappeler 1 le @date 10/11/2021\n@todo rappeler 2 le @date 22/10/2021");

    cout << "contact1->todosToString() (tries par rapport a leur ajout) : " << endl << contact1->todosToString() << endl;
    cout << endl;

    i->setResume("en fait RAS, @todo rappeler seulement @date 25/10/2021"); //modification d'une interaction
    cout << "apres modification de l'interaction contact1->todosToString() : " << endl << contact1->todosToString() << endl;
    cout << endl;

    g.ajoutInteraction(contact2, i);        //possibilite d'ajouter une meme interaction a deux contacts differents
    cout << "ajout de la meme interaction au contact2, affichage uniquement des interactions : " << endl;
    cout << "contact2->interactionsToString() " << endl << contact2->interactionsToString() << endl;
    cout << endl;

    Date dateTodo1 = Date(21, 10, 2022);
    Date dateTodo2 = Date(5, 5, 2025);
    Todo t1 = Todo("todo1", dateTodo1, nullptr);
    Todo t2 = Todo("Todo 2", dateTodo2, nullptr);
    cout << "Comparaison de todos : " << endl;
    cout << t1 << " < " << t2 << " ? " << (t1 < t2) << endl;
    cout << endl;
    // TODO : pdf 3 pages maxi, deposer sources

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
    cout << endl;

    testDate();

    QApplication a(argc, argv);
    MainWindow w(&g);
    w.show();
    return a.exec();
}
