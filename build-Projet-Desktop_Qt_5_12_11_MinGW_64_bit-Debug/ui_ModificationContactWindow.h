/********************************************************************************
** Form generated from reading UI file 'ModificationContactWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICATIONCONTACTWINDOW_H
#define UI_MODIFICATIONCONTACTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModificationContactWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QGraphicsView *photoView;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLabel *nomLabel;
    QLineEdit *nomLineEdit;
    QLabel *prenomLabel;
    QLineEdit *prenomLineEdit;
    QLabel *entrepriseLabel;
    QLineEdit *entrepriseLineEdit;
    QLabel *telLabel;
    QLineEdit *telLineEdit;
    QLabel *mailLabel;
    QLineEdit *mailLineEdit;
    QLabel *photoLabel;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *photoLineEdit;
    QPushButton *changeFilePushButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *validButton;
    QPushButton *supprButton;
    QPushButton *quitButton;

    void setupUi(QWidget *ModificationContactWindow)
    {
        if (ModificationContactWindow->objectName().isEmpty())
            ModificationContactWindow->setObjectName(QString::fromUtf8("ModificationContactWindow"));
        ModificationContactWindow->setWindowModality(Qt::NonModal);
        ModificationContactWindow->resize(708, 545);
        gridLayout = new QGridLayout(ModificationContactWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        photoView = new QGraphicsView(ModificationContactWindow);
        photoView->setObjectName(QString::fromUtf8("photoView"));
        photoView->setLayoutDirection(Qt::LeftToRight);
        photoView->setAutoFillBackground(false);
        photoView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        photoView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        photoView->setTransformationAnchor(QGraphicsView::AnchorViewCenter);

        horizontalLayout_2->addWidget(photoView);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        nomLabel = new QLabel(ModificationContactWindow);
        nomLabel->setObjectName(QString::fromUtf8("nomLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, nomLabel);

        nomLineEdit = new QLineEdit(ModificationContactWindow);
        nomLineEdit->setObjectName(QString::fromUtf8("nomLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, nomLineEdit);

        prenomLabel = new QLabel(ModificationContactWindow);
        prenomLabel->setObjectName(QString::fromUtf8("prenomLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, prenomLabel);

        prenomLineEdit = new QLineEdit(ModificationContactWindow);
        prenomLineEdit->setObjectName(QString::fromUtf8("prenomLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, prenomLineEdit);

        entrepriseLabel = new QLabel(ModificationContactWindow);
        entrepriseLabel->setObjectName(QString::fromUtf8("entrepriseLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, entrepriseLabel);

        entrepriseLineEdit = new QLineEdit(ModificationContactWindow);
        entrepriseLineEdit->setObjectName(QString::fromUtf8("entrepriseLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, entrepriseLineEdit);

        telLabel = new QLabel(ModificationContactWindow);
        telLabel->setObjectName(QString::fromUtf8("telLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, telLabel);

        telLineEdit = new QLineEdit(ModificationContactWindow);
        telLineEdit->setObjectName(QString::fromUtf8("telLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, telLineEdit);

        mailLabel = new QLabel(ModificationContactWindow);
        mailLabel->setObjectName(QString::fromUtf8("mailLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, mailLabel);

        mailLineEdit = new QLineEdit(ModificationContactWindow);
        mailLineEdit->setObjectName(QString::fromUtf8("mailLineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, mailLineEdit);

        photoLabel = new QLabel(ModificationContactWindow);
        photoLabel->setObjectName(QString::fromUtf8("photoLabel"));

        formLayout->setWidget(6, QFormLayout::LabelRole, photoLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        photoLineEdit = new QLineEdit(ModificationContactWindow);
        photoLineEdit->setObjectName(QString::fromUtf8("photoLineEdit"));

        horizontalLayout_3->addWidget(photoLineEdit);

        changeFilePushButton = new QPushButton(ModificationContactWindow);
        changeFilePushButton->setObjectName(QString::fromUtf8("changeFilePushButton"));

        horizontalLayout_3->addWidget(changeFilePushButton);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout_3);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        validButton = new QPushButton(ModificationContactWindow);
        validButton->setObjectName(QString::fromUtf8("validButton"));

        horizontalLayout->addWidget(validButton);

        supprButton = new QPushButton(ModificationContactWindow);
        supprButton->setObjectName(QString::fromUtf8("supprButton"));

        horizontalLayout->addWidget(supprButton);

        quitButton = new QPushButton(ModificationContactWindow);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        horizontalLayout->addWidget(quitButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);


        retranslateUi(ModificationContactWindow);

        QMetaObject::connectSlotsByName(ModificationContactWindow);
    } // setupUi

    void retranslateUi(QWidget *ModificationContactWindow)
    {
        ModificationContactWindow->setWindowTitle(QApplication::translate("ModificationContactWindow", "Modifier un contact", nullptr));
        nomLabel->setText(QApplication::translate("ModificationContactWindow", "Nom", nullptr));
        prenomLabel->setText(QApplication::translate("ModificationContactWindow", "Pr\303\251nom", nullptr));
        entrepriseLabel->setText(QApplication::translate("ModificationContactWindow", "Entreprise", nullptr));
        telLabel->setText(QApplication::translate("ModificationContactWindow", "T\303\251l\303\251phone", nullptr));
        mailLabel->setText(QApplication::translate("ModificationContactWindow", "Mail", nullptr));
        photoLabel->setText(QApplication::translate("ModificationContactWindow", "Photo", nullptr));
        changeFilePushButton->setText(QApplication::translate("ModificationContactWindow", "Changer de photo", nullptr));
        validButton->setText(QApplication::translate("ModificationContactWindow", "Valider les modifications", nullptr));
        supprButton->setText(QApplication::translate("ModificationContactWindow", "Supprimer le contact", nullptr));
        quitButton->setText(QApplication::translate("ModificationContactWindow", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModificationContactWindow: public Ui_ModificationContactWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICATIONCONTACTWINDOW_H
