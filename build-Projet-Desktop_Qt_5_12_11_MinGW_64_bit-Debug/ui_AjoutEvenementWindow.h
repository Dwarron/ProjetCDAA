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
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QRadioButton *eventRadionButton;
    QComboBox *eventComboBox;
    QRadioButton *newEventRadionButton;
    QTextEdit *newEventText;
    QHBoxLayout *horizontalLayout;
    QPushButton *validButton;
    QPushButton *quitButton;
    QButtonGroup *GroupeInteraction;

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
        eventRadionButton = new QRadioButton(AjoutEvenementWindow);
        GroupeInteraction = new QButtonGroup(AjoutEvenementWindow);
        GroupeInteraction->setObjectName(QString::fromUtf8("GroupeInteraction"));
        GroupeInteraction->addButton(eventRadionButton);
        eventRadionButton->setObjectName(QString::fromUtf8("eventRadionButton"));

        formLayout->setWidget(0, QFormLayout::LabelRole, eventRadionButton);

        eventComboBox = new QComboBox(AjoutEvenementWindow);
        eventComboBox->setObjectName(QString::fromUtf8("eventComboBox"));
        eventComboBox->setSizeIncrement(QSize(0, 0));
        eventComboBox->setMinimumContentsLength(0);

        formLayout->setWidget(0, QFormLayout::FieldRole, eventComboBox);

        newEventRadionButton = new QRadioButton(AjoutEvenementWindow);
        GroupeInteraction->addButton(newEventRadionButton);
        newEventRadionButton->setObjectName(QString::fromUtf8("newEventRadionButton"));

        formLayout->setWidget(1, QFormLayout::LabelRole, newEventRadionButton);

        newEventText = new QTextEdit(AjoutEvenementWindow);
        newEventText->setObjectName(QString::fromUtf8("newEventText"));

        formLayout->setWidget(1, QFormLayout::FieldRole, newEventText);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        validButton = new QPushButton(AjoutEvenementWindow);
        validButton->setObjectName(QString::fromUtf8("validButton"));

        horizontalLayout->addWidget(validButton);

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
        eventRadionButton->setText(QApplication::translate("AjoutEvenementWindow", "Ajouter un \303\251v\303\251nement existant", nullptr));
        newEventRadionButton->setText(QApplication::translate("AjoutEvenementWindow", "Ajouter un nouvel \303\251v\303\251nement ", nullptr));
        validButton->setText(QApplication::translate("AjoutEvenementWindow", "Valider", nullptr));
        quitButton->setText(QApplication::translate("AjoutEvenementWindow", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutEvenementWindow: public Ui_AjoutEvenementWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTEVENEMENTWINDOW_H
