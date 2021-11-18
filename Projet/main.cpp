#include "mainwindow.h"
#include "Contact.h"
#include "Date.h"
#include "Interaction.h"
#include "GestionnaireQObject.h"
#include <QApplication>
#include <iostream>
#include <QObject>

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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionnaireQObject g;

    return a.exec();
}
