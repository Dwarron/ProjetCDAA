/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionA_propos;
    QAction *actionExporter_en_JSON;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *contactSelectionneLabel;
    QVBoxLayout *verticalLayout;
    QPushButton *ButtonCreerFiche;
    QPushButton *ButtonFicheContact;
    QPushButton *ButtonRechercherContact;
    QPushButton *ButtonRequete;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *labelDateSuppression;
    QMenuBar *menubar;
    QMenu *menuOptions;
    QMenu *menuaide;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(546, 332);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionA_propos = new QAction(MainWindow);
        actionA_propos->setObjectName(QString::fromUtf8("actionA_propos"));
        actionExporter_en_JSON = new QAction(MainWindow);
        actionExporter_en_JSON->setObjectName(QString::fromUtf8("actionExporter_en_JSON"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(true);

        horizontalLayout->addWidget(label_3);

        contactSelectionneLabel = new QLabel(centralwidget);
        contactSelectionneLabel->setObjectName(QString::fromUtf8("contactSelectionneLabel"));

        horizontalLayout->addWidget(contactSelectionneLabel);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ButtonCreerFiche = new QPushButton(centralwidget);
        ButtonCreerFiche->setObjectName(QString::fromUtf8("ButtonCreerFiche"));

        verticalLayout->addWidget(ButtonCreerFiche);

        ButtonFicheContact = new QPushButton(centralwidget);
        ButtonFicheContact->setObjectName(QString::fromUtf8("ButtonFicheContact"));
        ButtonFicheContact->setEnabled(false);

        verticalLayout->addWidget(ButtonFicheContact);

        ButtonRechercherContact = new QPushButton(centralwidget);
        ButtonRechercherContact->setObjectName(QString::fromUtf8("ButtonRechercherContact"));

        verticalLayout->addWidget(ButtonRechercherContact);

        ButtonRequete = new QPushButton(centralwidget);
        ButtonRequete->setObjectName(QString::fromUtf8("ButtonRequete"));

        verticalLayout->addWidget(ButtonRequete);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        labelDateSuppression = new QLabel(centralwidget);
        labelDateSuppression->setObjectName(QString::fromUtf8("labelDateSuppression"));

        horizontalLayout_2->addWidget(labelDateSuppression);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 2, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 546, 25));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuaide = new QMenu(menubar);
        menuaide->setObjectName(QString::fromUtf8("menuaide"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOptions->menuAction());
        menubar->addAction(menuaide->menuAction());
        menuOptions->addAction(actionExporter_en_JSON);
        menuOptions->addAction(actionQuitter);
        menuaide->addAction(actionA_propos);

        retranslateUi(MainWindow);
        QObject::connect(actionQuitter, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestionnaire de relations clients", nullptr));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", nullptr));
        actionA_propos->setText(QApplication::translate("MainWindow", "A propos", nullptr));
        actionExporter_en_JSON->setText(QApplication::translate("MainWindow", "Exporter en JSON", nullptr));
        label->setText(QApplication::translate("MainWindow", "Bienvenue sur l'application de gestion de relation.", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Que souhaitez vous faire :", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Contact s\303\251lectionn\303\251 :", nullptr));
        contactSelectionneLabel->setText(QApplication::translate("MainWindow", "Aucun", nullptr));
        ButtonCreerFiche->setText(QApplication::translate("MainWindow", "Cr\303\251er la fiche d'un contact", nullptr));
        ButtonFicheContact->setText(QApplication::translate("MainWindow", "Afficher la fiche du contact", nullptr));
        ButtonRechercherContact->setText(QApplication::translate("MainWindow", "Chercher un contact", nullptr));
        ButtonRequete->setText(QApplication::translate("MainWindow", "Requ\303\252te sur les contacts", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "<i>Date de la derni\303\250re suppression de fiche : </i>", nullptr));
        labelDateSuppression->setText(QApplication::translate("MainWindow", "<i>01/01/2021</i>", nullptr));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", nullptr));
        menuaide->setTitle(QApplication::translate("MainWindow", "Aide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
