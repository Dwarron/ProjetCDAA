/********************************************************************************
** Form generated from reading UI file 'CreationFicheWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATIONFICHEWINDOW_H
#define UI_CREATIONFICHEWINDOW_H

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

class Ui_CreationFicheWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
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
    QLabel *tLPhoneLabel;
    QLineEdit *telLineEdit;
    QLabel *mailLabel;
    QLineEdit *mailLineEdit;
    QLabel *photoLabel_2;
    QPushButton *selectFilePushButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *validButton;
    QPushButton *quitButton;

    void setupUi(QWidget *CreationFicheWindow)
    {
        if (CreationFicheWindow->objectName().isEmpty())
            CreationFicheWindow->setObjectName(QString::fromUtf8("CreationFicheWindow"));
        CreationFicheWindow->setWindowModality(Qt::NonModal);
        CreationFicheWindow->resize(400, 282);
        gridLayout = new QGridLayout(CreationFicheWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(CreationFicheWindow);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(250, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        photoView = new QGraphicsView(CreationFicheWindow);
        photoView->setObjectName(QString::fromUtf8("photoView"));
        photoView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        photoView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_2->addWidget(photoView);

        horizontalSpacer = new QSpacerItem(250, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        nomLabel = new QLabel(CreationFicheWindow);
        nomLabel->setObjectName(QString::fromUtf8("nomLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, nomLabel);

        nomLineEdit = new QLineEdit(CreationFicheWindow);
        nomLineEdit->setObjectName(QString::fromUtf8("nomLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, nomLineEdit);

        prenomLabel = new QLabel(CreationFicheWindow);
        prenomLabel->setObjectName(QString::fromUtf8("prenomLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, prenomLabel);

        prenomLineEdit = new QLineEdit(CreationFicheWindow);
        prenomLineEdit->setObjectName(QString::fromUtf8("prenomLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, prenomLineEdit);

        entrepriseLabel = new QLabel(CreationFicheWindow);
        entrepriseLabel->setObjectName(QString::fromUtf8("entrepriseLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, entrepriseLabel);

        entrepriseLineEdit = new QLineEdit(CreationFicheWindow);
        entrepriseLineEdit->setObjectName(QString::fromUtf8("entrepriseLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, entrepriseLineEdit);

        tLPhoneLabel = new QLabel(CreationFicheWindow);
        tLPhoneLabel->setObjectName(QString::fromUtf8("tLPhoneLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, tLPhoneLabel);

        telLineEdit = new QLineEdit(CreationFicheWindow);
        telLineEdit->setObjectName(QString::fromUtf8("telLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, telLineEdit);

        mailLabel = new QLabel(CreationFicheWindow);
        mailLabel->setObjectName(QString::fromUtf8("mailLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, mailLabel);

        mailLineEdit = new QLineEdit(CreationFicheWindow);
        mailLineEdit->setObjectName(QString::fromUtf8("mailLineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, mailLineEdit);

        photoLabel_2 = new QLabel(CreationFicheWindow);
        photoLabel_2->setObjectName(QString::fromUtf8("photoLabel_2"));

        formLayout->setWidget(6, QFormLayout::LabelRole, photoLabel_2);

        selectFilePushButton = new QPushButton(CreationFicheWindow);
        selectFilePushButton->setObjectName(QString::fromUtf8("selectFilePushButton"));

        formLayout->setWidget(6, QFormLayout::FieldRole, selectFilePushButton);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        validButton = new QPushButton(CreationFicheWindow);
        validButton->setObjectName(QString::fromUtf8("validButton"));

        horizontalLayout->addWidget(validButton);

        quitButton = new QPushButton(CreationFicheWindow);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        horizontalLayout->addWidget(quitButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(CreationFicheWindow);

        QMetaObject::connectSlotsByName(CreationFicheWindow);
    } // setupUi

    void retranslateUi(QWidget *CreationFicheWindow)
    {
        CreationFicheWindow->setWindowTitle(QApplication::translate("CreationFicheWindow", "Cr\303\251er un contact", nullptr));
        label->setText(QApplication::translate("CreationFicheWindow", "Cr\303\251er la fiche d'un contact :", nullptr));
        nomLabel->setText(QApplication::translate("CreationFicheWindow", "Nom", nullptr));
        prenomLabel->setText(QApplication::translate("CreationFicheWindow", "Pr\303\251nom", nullptr));
        entrepriseLabel->setText(QApplication::translate("CreationFicheWindow", "Entreprise", nullptr));
        tLPhoneLabel->setText(QApplication::translate("CreationFicheWindow", "T\303\251l\303\251phone", nullptr));
        mailLabel->setText(QApplication::translate("CreationFicheWindow", "Mail", nullptr));
        photoLabel_2->setText(QApplication::translate("CreationFicheWindow", "Photo", nullptr));
        selectFilePushButton->setText(QApplication::translate("CreationFicheWindow", "Choisissez votre photo", nullptr));
        validButton->setText(QApplication::translate("CreationFicheWindow", "Valider", nullptr));
        quitButton->setText(QApplication::translate("CreationFicheWindow", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreationFicheWindow: public Ui_CreationFicheWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATIONFICHEWINDOW_H
