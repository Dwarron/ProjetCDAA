/********************************************************************************
** Form generated from reading UI file 'AjoutInteractionWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTINTERACTIONWINDOW_H
#define UI_AJOUTINTERACTIONWINDOW_H

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

class Ui_AjoutInteractionWindow
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

    void setupUi(QWidget *AjoutInteractionWindow)
    {
        if (AjoutInteractionWindow->objectName().isEmpty())
            AjoutInteractionWindow->setObjectName(QString::fromUtf8("AjoutInteractionWindow"));
        AjoutInteractionWindow->setWindowModality(Qt::NonModal);
        AjoutInteractionWindow->resize(492, 207);
        gridLayout = new QGridLayout(AjoutInteractionWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        newEventText = new QTextEdit(AjoutInteractionWindow);
        newEventText->setObjectName(QString::fromUtf8("newEventText"));

        formLayout->setWidget(1, QFormLayout::FieldRole, newEventText);

        existingEventButton = new QPushButton(AjoutInteractionWindow);
        existingEventButton->setObjectName(QString::fromUtf8("existingEventButton"));

        formLayout->setWidget(0, QFormLayout::FieldRole, existingEventButton);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        newEventButton = new QPushButton(AjoutInteractionWindow);
        newEventButton->setObjectName(QString::fromUtf8("newEventButton"));

        horizontalLayout->addWidget(newEventButton);

        quitButton = new QPushButton(AjoutInteractionWindow);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        horizontalLayout->addWidget(quitButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(AjoutInteractionWindow);

        QMetaObject::connectSlotsByName(AjoutInteractionWindow);
    } // setupUi

    void retranslateUi(QWidget *AjoutInteractionWindow)
    {
        AjoutInteractionWindow->setWindowTitle(QApplication::translate("AjoutInteractionWindow", "Ajouter une interaction", nullptr));
        existingEventButton->setText(QApplication::translate("AjoutInteractionWindow", "Ajouter une interaction existante", nullptr));
        newEventButton->setText(QApplication::translate("AjoutInteractionWindow", "Ajouter une nouvelle interaction", nullptr));
        quitButton->setText(QApplication::translate("AjoutInteractionWindow", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutInteractionWindow: public Ui_AjoutInteractionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTINTERACTIONWINDOW_H
