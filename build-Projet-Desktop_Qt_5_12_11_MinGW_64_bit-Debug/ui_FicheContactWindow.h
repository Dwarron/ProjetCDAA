/********************************************************************************
** Form generated from reading UI file 'FicheContactWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FICHECONTACTWINDOW_H
#define UI_FICHECONTACTWINDOW_H

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

class Ui_FicheContactWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QGraphicsView *photoView;
    QSpacerItem *horizontalSpacer;
    QPushButton *interactionsButton;
    QPushButton *ButtonAjouterInteraction;
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
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *labelDateCreation;
    QLabel *label_2;
    QLabel *labelDateModif;
    QHBoxLayout *horizontalLayout;
    QPushButton *validButton;
    QPushButton *supprButton;
    QPushButton *quitButton;

    void setupUi(QWidget *FicheContactWindow)
    {
        if (FicheContactWindow->objectName().isEmpty())
            FicheContactWindow->setObjectName(QString::fromUtf8("FicheContactWindow"));
        FicheContactWindow->setWindowModality(Qt::NonModal);
        FicheContactWindow->resize(708, 545);
        gridLayout = new QGridLayout(FicheContactWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        photoView = new QGraphicsView(FicheContactWindow);
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

        interactionsButton = new QPushButton(FicheContactWindow);
        interactionsButton->setObjectName(QString::fromUtf8("interactionsButton"));

        verticalLayout->addWidget(interactionsButton);

        ButtonAjouterInteraction = new QPushButton(FicheContactWindow);
        ButtonAjouterInteraction->setObjectName(QString::fromUtf8("ButtonAjouterInteraction"));

        verticalLayout->addWidget(ButtonAjouterInteraction);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        nomLabel = new QLabel(FicheContactWindow);
        nomLabel->setObjectName(QString::fromUtf8("nomLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, nomLabel);

        nomLineEdit = new QLineEdit(FicheContactWindow);
        nomLineEdit->setObjectName(QString::fromUtf8("nomLineEdit"));
        nomLineEdit->setEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, nomLineEdit);

        prenomLabel = new QLabel(FicheContactWindow);
        prenomLabel->setObjectName(QString::fromUtf8("prenomLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, prenomLabel);

        prenomLineEdit = new QLineEdit(FicheContactWindow);
        prenomLineEdit->setObjectName(QString::fromUtf8("prenomLineEdit"));
        prenomLineEdit->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, prenomLineEdit);

        entrepriseLabel = new QLabel(FicheContactWindow);
        entrepriseLabel->setObjectName(QString::fromUtf8("entrepriseLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, entrepriseLabel);

        entrepriseLineEdit = new QLineEdit(FicheContactWindow);
        entrepriseLineEdit->setObjectName(QString::fromUtf8("entrepriseLineEdit"));
        entrepriseLineEdit->setEnabled(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, entrepriseLineEdit);

        telLabel = new QLabel(FicheContactWindow);
        telLabel->setObjectName(QString::fromUtf8("telLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, telLabel);

        telLineEdit = new QLineEdit(FicheContactWindow);
        telLineEdit->setObjectName(QString::fromUtf8("telLineEdit"));
        telLineEdit->setEnabled(false);

        formLayout->setWidget(4, QFormLayout::FieldRole, telLineEdit);

        mailLabel = new QLabel(FicheContactWindow);
        mailLabel->setObjectName(QString::fromUtf8("mailLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, mailLabel);

        mailLineEdit = new QLineEdit(FicheContactWindow);
        mailLineEdit->setObjectName(QString::fromUtf8("mailLineEdit"));
        mailLineEdit->setEnabled(false);

        formLayout->setWidget(5, QFormLayout::FieldRole, mailLineEdit);

        photoLabel = new QLabel(FicheContactWindow);
        photoLabel->setObjectName(QString::fromUtf8("photoLabel"));

        formLayout->setWidget(6, QFormLayout::LabelRole, photoLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        photoLineEdit = new QLineEdit(FicheContactWindow);
        photoLineEdit->setObjectName(QString::fromUtf8("photoLineEdit"));
        photoLineEdit->setEnabled(false);

        horizontalLayout_3->addWidget(photoLineEdit);

        changeFilePushButton = new QPushButton(FicheContactWindow);
        changeFilePushButton->setObjectName(QString::fromUtf8("changeFilePushButton"));

        horizontalLayout_3->addWidget(changeFilePushButton);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout_3);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(FicheContactWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        labelDateCreation = new QLabel(FicheContactWindow);
        labelDateCreation->setObjectName(QString::fromUtf8("labelDateCreation"));

        horizontalLayout_4->addWidget(labelDateCreation);

        label_2 = new QLabel(FicheContactWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        labelDateModif = new QLabel(FicheContactWindow);
        labelDateModif->setObjectName(QString::fromUtf8("labelDateModif"));

        horizontalLayout_4->addWidget(labelDateModif);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        validButton = new QPushButton(FicheContactWindow);
        validButton->setObjectName(QString::fromUtf8("validButton"));

        horizontalLayout->addWidget(validButton);

        supprButton = new QPushButton(FicheContactWindow);
        supprButton->setObjectName(QString::fromUtf8("supprButton"));

        horizontalLayout->addWidget(supprButton);

        quitButton = new QPushButton(FicheContactWindow);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        horizontalLayout->addWidget(quitButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);


        retranslateUi(FicheContactWindow);

        QMetaObject::connectSlotsByName(FicheContactWindow);
    } // setupUi

    void retranslateUi(QWidget *FicheContactWindow)
    {
        FicheContactWindow->setWindowTitle(QApplication::translate("FicheContactWindow", "Fiche du contact", nullptr));
        interactionsButton->setText(QApplication::translate("FicheContactWindow", "Afficher les interactions", nullptr));
        ButtonAjouterInteraction->setText(QApplication::translate("FicheContactWindow", "Ajouter une interaction", nullptr));
        nomLabel->setText(QApplication::translate("FicheContactWindow", "Nom", nullptr));
        prenomLabel->setText(QApplication::translate("FicheContactWindow", "Pr\303\251nom", nullptr));
        entrepriseLabel->setText(QApplication::translate("FicheContactWindow", "Entreprise", nullptr));
        telLabel->setText(QApplication::translate("FicheContactWindow", "T\303\251l\303\251phone", nullptr));
        mailLabel->setText(QApplication::translate("FicheContactWindow", "Mail", nullptr));
        photoLabel->setText(QApplication::translate("FicheContactWindow", "Photo", nullptr));
        changeFilePushButton->setText(QApplication::translate("FicheContactWindow", "Changer de photo", nullptr));
        label_4->setText(QApplication::translate("FicheContactWindow", "<i>Date de cr\303\251ation de la fiche :</i>", nullptr));
        labelDateCreation->setText(QString());
        label_2->setText(QApplication::translate("FicheContactWindow", "<i>Date de derni\303\250re modification:</i>", nullptr));
        labelDateModif->setText(QString());
        validButton->setText(QApplication::translate("FicheContactWindow", "Valider les modifications", nullptr));
        supprButton->setText(QApplication::translate("FicheContactWindow", "Supprimer le contact", nullptr));
        quitButton->setText(QApplication::translate("FicheContactWindow", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FicheContactWindow: public Ui_FicheContactWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FICHECONTACTWINDOW_H
