#include "mainwindow.h"
#include "Contact.h"

#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Contact contact1("Duportail", "Damien", "Unirex compagnie", "06.73.33.25.57", "damien.duportail@btc.fr", "/home/Directory/Document/Image/duportail.jpg");
    Contact contact2("14Delafenetrel68", "Jean78-Pierre56", "Btc compagnie", "06.07.48.75.37", "delafenetre.jp@eth.fr", "/home/Directory/Document/Photo/dlf.jpg");

    //cout << contact1 << endl;
    //cout << contact2 << endl;

    return a.exec();
}
