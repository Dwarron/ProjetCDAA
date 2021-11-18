/********************************************************************************
** Form generated from reading UI file 'RequeteWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REQUETEWINDOW_H
#define UI_REQUETEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RequeteWindow
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QRadioButton *contactsButton;
    QRadioButton *eventButton;
    QRadioButton *listContactButton;
    QRadioButton *listContactsButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QGridLayout *gridLayout_5;
    QLabel *nombreContacts;
    QWidget *page_3;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDateEdit *dateDebutDateEdit;
    QLabel *label_4;
    QDateEdit *dateFinDateEdit;
    QPlainTextEdit *listeEvenementPlainTextEdit;
    QPushButton *validIntervalButton;
    QWidget *page_4;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLabel *selectContactLabel;
    QComboBox *selectContactComboBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDateEdit *debutContactDateEdit;
    QLabel *label_5;
    QDateEdit *finContactDateEdit;
    QFormLayout *formLayout_2;
    QLabel *afficherLabel;
    QComboBox *afficherInfosContactComboBox;
    QPushButton *validInfosContactPushButton;
    QPlainTextEdit *listeInfosContactplainTextEdit;
    QWidget *page_5;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QDateEdit *debutContactsDateEdit;
    QLabel *label_7;
    QDateEdit *finContactsDateEdit;
    QFormLayout *formLayout_4;
    QLabel *afficherLabel_2;
    QComboBox *afficherInfosContactsComboBox;
    QPushButton *validInfosContactsPushButton;
    QPlainTextEdit *listeInfosplainTextEdit;
    QPushButton *quitButton;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *RequeteWindow)
    {
        if (RequeteWindow->objectName().isEmpty())
            RequeteWindow->setObjectName(QString::fromUtf8("RequeteWindow"));
        RequeteWindow->setWindowModality(Qt::NonModal);
        RequeteWindow->resize(1003, 576);
        gridLayout_2 = new QGridLayout(RequeteWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(RequeteWindow);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        contactsButton = new QRadioButton(RequeteWindow);
        buttonGroup = new QButtonGroup(RequeteWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(contactsButton);
        contactsButton->setObjectName(QString::fromUtf8("contactsButton"));

        verticalLayout->addWidget(contactsButton);

        eventButton = new QRadioButton(RequeteWindow);
        buttonGroup->addButton(eventButton);
        eventButton->setObjectName(QString::fromUtf8("eventButton"));

        verticalLayout->addWidget(eventButton);

        listContactButton = new QRadioButton(RequeteWindow);
        buttonGroup->addButton(listContactButton);
        listContactButton->setObjectName(QString::fromUtf8("listContactButton"));

        verticalLayout->addWidget(listContactButton);

        listContactsButton = new QRadioButton(RequeteWindow);
        buttonGroup->addButton(listContactsButton);
        listContactsButton->setObjectName(QString::fromUtf8("listContactsButton"));

        verticalLayout->addWidget(listContactsButton);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(RequeteWindow);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setFrameShape(QFrame::WinPanel);
        stackedWidget->setFrameShadow(QFrame::Plain);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_5 = new QGridLayout(page_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        nombreContacts = new QLabel(page_2);
        nombreContacts->setObjectName(QString::fromUtf8("nombreContacts"));

        gridLayout_5->addWidget(nombreContacts, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_4 = new QGridLayout(page_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        dateDebutDateEdit = new QDateEdit(page_3);
        dateDebutDateEdit->setObjectName(QString::fromUtf8("dateDebutDateEdit"));
        dateDebutDateEdit->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));

        horizontalLayout_2->addWidget(dateDebutDateEdit);

        label_4 = new QLabel(page_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        dateFinDateEdit = new QDateEdit(page_3);
        dateFinDateEdit->setObjectName(QString::fromUtf8("dateFinDateEdit"));
        dateFinDateEdit->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));

        horizontalLayout_2->addWidget(dateFinDateEdit);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        listeEvenementPlainTextEdit = new QPlainTextEdit(page_3);
        listeEvenementPlainTextEdit->setObjectName(QString::fromUtf8("listeEvenementPlainTextEdit"));
        listeEvenementPlainTextEdit->setReadOnly(false);

        gridLayout_3->addWidget(listeEvenementPlainTextEdit, 2, 0, 1, 1);

        validIntervalButton = new QPushButton(page_3);
        validIntervalButton->setObjectName(QString::fromUtf8("validIntervalButton"));

        gridLayout_3->addWidget(validIntervalButton, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        gridLayout_7 = new QGridLayout(page_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        selectContactLabel = new QLabel(page_4);
        selectContactLabel->setObjectName(QString::fromUtf8("selectContactLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, selectContactLabel);

        selectContactComboBox = new QComboBox(page_4);
        selectContactComboBox->setObjectName(QString::fromUtf8("selectContactComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, selectContactComboBox);


        verticalLayout_3->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(page_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        debutContactDateEdit = new QDateEdit(page_4);
        debutContactDateEdit->setObjectName(QString::fromUtf8("debutContactDateEdit"));
        debutContactDateEdit->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));

        horizontalLayout->addWidget(debutContactDateEdit);

        label_5 = new QLabel(page_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        finContactDateEdit = new QDateEdit(page_4);
        finContactDateEdit->setObjectName(QString::fromUtf8("finContactDateEdit"));
        finContactDateEdit->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));

        horizontalLayout->addWidget(finContactDateEdit);


        verticalLayout_3->addLayout(horizontalLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        afficherLabel = new QLabel(page_4);
        afficherLabel->setObjectName(QString::fromUtf8("afficherLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, afficherLabel);

        afficherInfosContactComboBox = new QComboBox(page_4);
        afficherInfosContactComboBox->setObjectName(QString::fromUtf8("afficherInfosContactComboBox"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, afficherInfosContactComboBox);


        verticalLayout_3->addLayout(formLayout_2);

        validInfosContactPushButton = new QPushButton(page_4);
        validInfosContactPushButton->setObjectName(QString::fromUtf8("validInfosContactPushButton"));

        verticalLayout_3->addWidget(validInfosContactPushButton);

        listeInfosContactplainTextEdit = new QPlainTextEdit(page_4);
        listeInfosContactplainTextEdit->setObjectName(QString::fromUtf8("listeInfosContactplainTextEdit"));

        verticalLayout_3->addWidget(listeInfosContactplainTextEdit);


        gridLayout_7->addLayout(verticalLayout_3, 0, 0, 1, 1);

        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        gridLayout_6 = new QGridLayout(page_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(page_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        debutContactsDateEdit = new QDateEdit(page_5);
        debutContactsDateEdit->setObjectName(QString::fromUtf8("debutContactsDateEdit"));
        debutContactsDateEdit->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));

        horizontalLayout_3->addWidget(debutContactsDateEdit);

        label_7 = new QLabel(page_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        finContactsDateEdit = new QDateEdit(page_5);
        finContactsDateEdit->setObjectName(QString::fromUtf8("finContactsDateEdit"));
        finContactsDateEdit->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));

        horizontalLayout_3->addWidget(finContactsDateEdit);


        verticalLayout_4->addLayout(horizontalLayout_3);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        afficherLabel_2 = new QLabel(page_5);
        afficherLabel_2->setObjectName(QString::fromUtf8("afficherLabel_2"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, afficherLabel_2);

        afficherInfosContactsComboBox = new QComboBox(page_5);
        afficherInfosContactsComboBox->setObjectName(QString::fromUtf8("afficherInfosContactsComboBox"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, afficherInfosContactsComboBox);


        verticalLayout_4->addLayout(formLayout_4);

        validInfosContactsPushButton = new QPushButton(page_5);
        validInfosContactsPushButton->setObjectName(QString::fromUtf8("validInfosContactsPushButton"));

        verticalLayout_4->addWidget(validInfosContactsPushButton);

        listeInfosplainTextEdit = new QPlainTextEdit(page_5);
        listeInfosplainTextEdit->setObjectName(QString::fromUtf8("listeInfosplainTextEdit"));

        verticalLayout_4->addWidget(listeInfosplainTextEdit);


        gridLayout_6->addLayout(verticalLayout_4, 0, 0, 1, 1);

        stackedWidget->addWidget(page_5);

        gridLayout->addWidget(stackedWidget, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        quitButton = new QPushButton(RequeteWindow);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        gridLayout_2->addWidget(quitButton, 1, 0, 1, 1);


        retranslateUi(RequeteWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(RequeteWindow);
    } // setupUi

    void retranslateUi(QWidget *RequeteWindow)
    {
        RequeteWindow->setWindowTitle(QApplication::translate("RequeteWindow", "Requ\303\252te", nullptr));
        label->setText(QApplication::translate("RequeteWindow", "Effectuer des requ\303\252tes :", nullptr));
        contactsButton->setText(QApplication::translate("RequeteWindow", "Nombre de contacts", nullptr));
        eventButton->setText(QApplication::translate("RequeteWindow", "Ev\303\251nements entre 2 dates", nullptr));
        listContactButton->setText(QApplication::translate("RequeteWindow", "Liste des choses \303\240 faire ou des dates d'\303\251v\303\251nement pour un contact dans un intervalle", nullptr));
        listContactsButton->setText(QApplication::translate("RequeteWindow", "Liste des choses \303\240 faire ou des dates d'\303\251v\303\251nement pour tous les contact dans un intervalle", nullptr));
        nombreContacts->setText(QString());
        label_3->setText(QApplication::translate("RequeteWindow", "Ev\303\251nement entre ", nullptr));
        label_4->setText(QApplication::translate("RequeteWindow", " et le ", nullptr));
        validIntervalButton->setText(QApplication::translate("RequeteWindow", "Valider l'intervalle", nullptr));
        selectContactLabel->setText(QApplication::translate("RequeteWindow", "Selectionner le contact", nullptr));
        label_2->setText(QApplication::translate("RequeteWindow", "Intervalle de dates entre le ", nullptr));
        label_5->setText(QApplication::translate("RequeteWindow", "et le", nullptr));
        afficherLabel->setText(QApplication::translate("RequeteWindow", "Afficher ", nullptr));
        validInfosContactPushButton->setText(QApplication::translate("RequeteWindow", "Effectuer la requ\303\252te", nullptr));
        label_6->setText(QApplication::translate("RequeteWindow", "Intervalles de dates entre le ", nullptr));
        label_7->setText(QApplication::translate("RequeteWindow", "et le", nullptr));
        afficherLabel_2->setText(QApplication::translate("RequeteWindow", "Afficher ", nullptr));
        validInfosContactsPushButton->setText(QApplication::translate("RequeteWindow", "Valider les informations s\303\251l\303\251ctionner", nullptr));
        quitButton->setText(QApplication::translate("RequeteWindow", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RequeteWindow: public Ui_RequeteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQUETEWINDOW_H
