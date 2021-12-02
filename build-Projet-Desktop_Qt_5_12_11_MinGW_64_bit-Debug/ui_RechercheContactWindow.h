/********************************************************************************
** Form generated from reading UI file 'RechercheContactWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECHERCHECONTACTWINDOW_H
#define UI_RECHERCHECONTACTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RechercheContactWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *rechercheContactComboBox;
    QLineEdit *rechercheLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDateEdit *dateEditDebut;
    QLabel *label_3;
    QDateEdit *dateEditFin;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *triListeComboBox;
    QPushButton *quitButton;
    QListView *listeContacts;

    void setupUi(QWidget *RechercheContactWindow)
    {
        if (RechercheContactWindow->objectName().isEmpty())
            RechercheContactWindow->setObjectName(QString::fromUtf8("RechercheContactWindow"));
        RechercheContactWindow->setWindowModality(Qt::NonModal);
        RechercheContactWindow->resize(627, 503);
        gridLayout = new QGridLayout(RechercheContactWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(RechercheContactWindow);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        rechercheContactComboBox = new QComboBox(RechercheContactWindow);
        rechercheContactComboBox->setObjectName(QString::fromUtf8("rechercheContactComboBox"));

        horizontalLayout->addWidget(rechercheContactComboBox);

        rechercheLineEdit = new QLineEdit(RechercheContactWindow);
        rechercheLineEdit->setObjectName(QString::fromUtf8("rechercheLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rechercheLineEdit->sizePolicy().hasHeightForWidth());
        rechercheLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(rechercheLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(RechercheContactWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        dateEditDebut = new QDateEdit(RechercheContactWindow);
        dateEditDebut->setObjectName(QString::fromUtf8("dateEditDebut"));
        dateEditDebut->setDateTime(QDateTime(QDate(2021, 1, 1), QTime(0, 0, 0)));

        horizontalLayout_2->addWidget(dateEditDebut);

        label_3 = new QLabel(RechercheContactWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        dateEditFin = new QDateEdit(RechercheContactWindow);
        dateEditFin->setObjectName(QString::fromUtf8("dateEditFin"));
        dateEditFin->setDateTime(QDateTime(QDate(2021, 1, 1), QTime(0, 0, 0)));

        horizontalLayout_2->addWidget(dateEditFin);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(RechercheContactWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        triListeComboBox = new QComboBox(RechercheContactWindow);
        triListeComboBox->setObjectName(QString::fromUtf8("triListeComboBox"));

        horizontalLayout_3->addWidget(triListeComboBox);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        quitButton = new QPushButton(RechercheContactWindow);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        gridLayout->addWidget(quitButton, 4, 0, 1, 1);

        listeContacts = new QListView(RechercheContactWindow);
        listeContacts->setObjectName(QString::fromUtf8("listeContacts"));
        listeContacts->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        listeContacts->setFocusPolicy(Qt::NoFocus);
        listeContacts->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listeContacts->setTabKeyNavigation(true);

        gridLayout->addWidget(listeContacts, 3, 0, 1, 1);


        retranslateUi(RechercheContactWindow);

        QMetaObject::connectSlotsByName(RechercheContactWindow);
    } // setupUi

    void retranslateUi(QWidget *RechercheContactWindow)
    {
        RechercheContactWindow->setWindowTitle(QApplication::translate("RechercheContactWindow", "Chercher un contact", nullptr));
        label->setText(QApplication::translate("RechercheContactWindow", "Chercher un contact par :", nullptr));
        rechercheLineEdit->setPlaceholderText(QApplication::translate("RechercheContactWindow", "Nom ou Entreprise", nullptr));
        label_2->setText(QApplication::translate("RechercheContactWindow", "Cr\303\251\303\251 entre le", nullptr));
        label_3->setText(QApplication::translate("RechercheContactWindow", "et le", nullptr));
        label_4->setText(QApplication::translate("RechercheContactWindow", "Trier par :", nullptr));
        quitButton->setText(QApplication::translate("RechercheContactWindow", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RechercheContactWindow: public Ui_RechercheContactWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECHERCHECONTACTWINDOW_H
