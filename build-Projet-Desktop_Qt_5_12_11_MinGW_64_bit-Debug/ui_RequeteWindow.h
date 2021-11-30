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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
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
    QRadioButton *interactionsButton;
    QRadioButton *listContactButton;
    QRadioButton *listAllContactsButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QGridLayout *gridLayout_5;
    QLabel *nombreContacts;
    QWidget *page_3;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QListView *listViewInteractions2Dates;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDateEdit *dateDebutInteractions2Dates;
    QLabel *label_4;
    QDateEdit *dateFinInteractions2Dates;
    QWidget *page_4;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDateEdit *dateDebutContact;
    QLabel *label_5;
    QDateEdit *dateFinContact;
    QFormLayout *formLayout_2;
    QLabel *afficherLabel;
    QComboBox *afficherInfosContactComboBox;
    QCheckBox *checkBoxOnlyNotDoneContact;
    QListView *listViewRequeteContact;
    QWidget *page_5;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QDateEdit *dateDebutAllContacts;
    QLabel *label_7;
    QDateEdit *dateFinAllContacts;
    QFormLayout *formLayout_4;
    QLabel *afficherLabel_2;
    QComboBox *afficherInfosAllContactsComboBox;
    QListView *listViewRequeteAllContacts;
    QCheckBox *checkBoxOnlyNotDoneAllContacts;
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

        interactionsButton = new QRadioButton(RequeteWindow);
        buttonGroup->addButton(interactionsButton);
        interactionsButton->setObjectName(QString::fromUtf8("interactionsButton"));

        verticalLayout->addWidget(interactionsButton);

        listContactButton = new QRadioButton(RequeteWindow);
        buttonGroup->addButton(listContactButton);
        listContactButton->setObjectName(QString::fromUtf8("listContactButton"));

        verticalLayout->addWidget(listContactButton);

        listAllContactsButton = new QRadioButton(RequeteWindow);
        buttonGroup->addButton(listAllContactsButton);
        listAllContactsButton->setObjectName(QString::fromUtf8("listAllContactsButton"));

        verticalLayout->addWidget(listAllContactsButton);


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
        listViewInteractions2Dates = new QListView(page_3);
        listViewInteractions2Dates->setObjectName(QString::fromUtf8("listViewInteractions2Dates"));
        listViewInteractions2Dates->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_3->addWidget(listViewInteractions2Dates, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        dateDebutInteractions2Dates = new QDateEdit(page_3);
        dateDebutInteractions2Dates->setObjectName(QString::fromUtf8("dateDebutInteractions2Dates"));
        dateDebutInteractions2Dates->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));

        horizontalLayout_2->addWidget(dateDebutInteractions2Dates);

        label_4 = new QLabel(page_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        dateFinInteractions2Dates = new QDateEdit(page_3);
        dateFinInteractions2Dates->setObjectName(QString::fromUtf8("dateFinInteractions2Dates"));
        dateFinInteractions2Dates->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));

        horizontalLayout_2->addWidget(dateFinInteractions2Dates);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        gridLayout_7 = new QGridLayout(page_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(page_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        dateDebutContact = new QDateEdit(page_4);
        dateDebutContact->setObjectName(QString::fromUtf8("dateDebutContact"));
        dateDebutContact->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));

        horizontalLayout->addWidget(dateDebutContact);

        label_5 = new QLabel(page_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        dateFinContact = new QDateEdit(page_4);
        dateFinContact->setObjectName(QString::fromUtf8("dateFinContact"));
        dateFinContact->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));

        horizontalLayout->addWidget(dateFinContact);


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

        checkBoxOnlyNotDoneContact = new QCheckBox(page_4);
        checkBoxOnlyNotDoneContact->setObjectName(QString::fromUtf8("checkBoxOnlyNotDoneContact"));
        checkBoxOnlyNotDoneContact->setEnabled(false);

        verticalLayout_3->addWidget(checkBoxOnlyNotDoneContact);

        listViewRequeteContact = new QListView(page_4);
        listViewRequeteContact->setObjectName(QString::fromUtf8("listViewRequeteContact"));
        listViewRequeteContact->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listViewRequeteContact->setTabKeyNavigation(true);

        verticalLayout_3->addWidget(listViewRequeteContact);


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

        dateDebutAllContacts = new QDateEdit(page_5);
        dateDebutAllContacts->setObjectName(QString::fromUtf8("dateDebutAllContacts"));
        dateDebutAllContacts->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));

        horizontalLayout_3->addWidget(dateDebutAllContacts);

        label_7 = new QLabel(page_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        dateFinAllContacts = new QDateEdit(page_5);
        dateFinAllContacts->setObjectName(QString::fromUtf8("dateFinAllContacts"));
        dateFinAllContacts->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));

        horizontalLayout_3->addWidget(dateFinAllContacts);


        verticalLayout_4->addLayout(horizontalLayout_3);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        afficherLabel_2 = new QLabel(page_5);
        afficherLabel_2->setObjectName(QString::fromUtf8("afficherLabel_2"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, afficherLabel_2);

        afficherInfosAllContactsComboBox = new QComboBox(page_5);
        afficherInfosAllContactsComboBox->setObjectName(QString::fromUtf8("afficherInfosAllContactsComboBox"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, afficherInfosAllContactsComboBox);


        verticalLayout_4->addLayout(formLayout_4);


        gridLayout_6->addLayout(verticalLayout_4, 0, 0, 1, 1);

        listViewRequeteAllContacts = new QListView(page_5);
        listViewRequeteAllContacts->setObjectName(QString::fromUtf8("listViewRequeteAllContacts"));
        listViewRequeteAllContacts->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_6->addWidget(listViewRequeteAllContacts, 2, 0, 1, 1);

        checkBoxOnlyNotDoneAllContacts = new QCheckBox(page_5);
        checkBoxOnlyNotDoneAllContacts->setObjectName(QString::fromUtf8("checkBoxOnlyNotDoneAllContacts"));
        checkBoxOnlyNotDoneAllContacts->setEnabled(false);

        gridLayout_6->addWidget(checkBoxOnlyNotDoneAllContacts, 1, 0, 1, 1);

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
        RequeteWindow->setWindowTitle(QApplication::translate("RequeteWindow", "Requ\303\252tes", nullptr));
        label->setText(QApplication::translate("RequeteWindow", "Effectuer des requ\303\252tes :", nullptr));
        contactsButton->setText(QApplication::translate("RequeteWindow", "Nombre de contacts", nullptr));
        interactionsButton->setText(QApplication::translate("RequeteWindow", "Interactions entre 2 dates", nullptr));
        listContactButton->setText(QApplication::translate("RequeteWindow", "Liste des choses \303\240 faire ou des dates d'interactions pour un contact dans un intervalle", nullptr));
        listAllContactsButton->setText(QApplication::translate("RequeteWindow", "Liste des choses \303\240 faire ou des dates d'interactions pour tous les contacts dans un intervalle", nullptr));
        nombreContacts->setText(QString());
        label_3->setText(QApplication::translate("RequeteWindow", "Interactions entre le", nullptr));
        label_4->setText(QApplication::translate("RequeteWindow", " et le ", nullptr));
        label_2->setText(QApplication::translate("RequeteWindow", "Dates entre le ", nullptr));
        label_5->setText(QApplication::translate("RequeteWindow", "et le", nullptr));
        afficherLabel->setText(QApplication::translate("RequeteWindow", "Afficher : ", nullptr));
        checkBoxOnlyNotDoneContact->setText(QApplication::translate("RequeteWindow", "Seulement non effectu\303\251s", nullptr));
        label_6->setText(QApplication::translate("RequeteWindow", "Dates entre le ", nullptr));
        label_7->setText(QApplication::translate("RequeteWindow", "et le", nullptr));
        afficherLabel_2->setText(QApplication::translate("RequeteWindow", "Afficher :  ", nullptr));
        checkBoxOnlyNotDoneAllContacts->setText(QApplication::translate("RequeteWindow", "Seulement non effectu\303\251s", nullptr));
        quitButton->setText(QApplication::translate("RequeteWindow", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RequeteWindow: public Ui_RequeteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQUETEWINDOW_H
