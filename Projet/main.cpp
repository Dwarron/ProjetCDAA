#include <QApplication>
#include "GestionnaireQObject.h"

/*! \mainpage Projet de CDAA : Logiciel de gestion de relations clients (CRM)
 *
 * \section intro_sec Introduction
 *
 *  Le sujet du projet est de produire un logiciel permettant de g&eacute;rer des contacts et leurs interactions avec une entit&eacute;.
 *  Il est &eacute;galement question d'extraire des t&acirc;ches a faire des interactions gr&acirc;ce &acirc; des tags (@ todo et @ date).
 *  Nous avons utilis&eacute; Github pour collaborer: https://github.com/Dwarron/ProjetCDAA.
 *
 *  \section prog_sec Programmation en 3 parties
 *  La programmation du projet est realis&eacute;e en 3 parties distinctes : la programmation orient&eacute;e object, l'interface graphique
 *  et la persistence des donn&eacute;es.
 *
 *  \subsection poo_subsec Partie Programmation Orient&eacute;e Object
 *  Dans cette premiere partie, le but a ete de simplement d&eacute;crire les differents objets qui interviendront tout le long du projet et les
 *  relations/interactions entre eux. Nous avons notamment cr&eacute;e les classes Contact, Verificator, GestionContact, Interaction et Todo.
 *  Ces classes ayant besoin ,de gerer le temps, nous avons &eacute;galement produit la classe Date.
 *
 *  \subsection ihm_subsec Partie Interface Graphique
 *  Dans cette seconde partie, nous avons d&eacute;velopp&eacute; differente interfaces permettant aux utilisateurs d'interagir avec notre application.
 *  Ces fen$egrave;etres sont g&eacute;r&eacute;es par les classes AfficheInteractionsWindow, AjoutInteractionWindow, CreationFicheWindow, FicheContactWindow, MainWindow, RechercheContactWindow et RequeteWindow.
 *
 *  \subsection persistence_subsec Partie Persistence des donn&eacute;es
 *  Dans cette troisi&eagrave;me et derni&eacute;re partie, une base de donn&eacute;es SQLite a &eacute;t&eacute; mise en place afin de garder en m&eacute;moire les donn&eacute;es entr&eacute;es par l'utilisateur.
 *  Nous utilisons la classe DatabaseManager pour interagir avec celle ci.
 *
 * \authors Alexandre Pinon et Maxence Perion
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionnaireQObject g;

    return a.exec();
}
