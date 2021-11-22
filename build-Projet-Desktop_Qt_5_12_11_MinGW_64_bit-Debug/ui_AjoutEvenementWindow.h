/********************************************************************************
** Form generated from reading UI file 'AjoutEvenementWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTEVENEMENTWINDOW_H
#define UI_AJOUTEVENEMENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AjoutEvenementWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QTextEdit *newEventText;
    QPushButton *existingEventButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *newEventButton;
    QPushButton *quitButton;

    void setupUi(QWidget *AjoutEvenementWindow)
    {
        if (AjoutEvenementWindow->objectName().isEmpty())
            AjoutEvenementWindow->setObjectName(QString::fromUtf8("AjoutEvenementWindow"));
        AjoutEvenementWindow->setWindowModality(Qt::NonModal);
        AjoutEvenementWindow->resize(492, 207);
        gridLayout = new QGridLayout(AjoutEvenementWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        newEventText = new QTextEdit(AjoutEvenementWindow);
        newEventText->setObjectName(QString::fromUtf8("newEventText"));

        formLayout->setWidget(1, QFormLayout::FieldRole, newEventText);

        existingEventButton = new QPushButton(AjoutEvenementWindow);
        existingEventButton->setObjectName(QString::fromUtf8("existingEventButton"));

        formLayout->setWidget(0, QFormLayout::FieldRole, existingEventButton);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        newEventButton = new QPushButton(AjoutEvenementWindow);
        newEventButton->setObjectName(QString::fromUtf8("newEventButton"));

        horizontalLayout->addWidget(newEventButton);

        quitButton = new QPushButton(AjoutEvenementWindow);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        horizontalLayout->addWidget(quitButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(AjoutEvenementWindow);

        QMetaObject::connectSlotsByName(AjoutEvenementWindow);
    } // setupUi

    void retranslateUi(QWidget *AjoutEvenementWindow)
    {
        AjoutEvenementWindow->setWindowTitle(QApplication::translate("AjoutEvenementWindow", "Ajouter un \303\251v\303\251nement", nullptr));
        existingEventButton->setText(QApplication::translate("AjoutEvenementWindow", "Ajouter un \303\251v\303\250nement existant", nullptr));
        newEventButton->setText(QApplication::translate("AjoutEvenementWindow", "Ajouter un nouvel \303\251v\303\250nement", nullptr));
        quitButton->setText(QApplication::translate("AjoutEvenementWindow", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutEvenementWindow: public Ui_AjoutEvenementWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTEVENEMENTWINDOW_H
