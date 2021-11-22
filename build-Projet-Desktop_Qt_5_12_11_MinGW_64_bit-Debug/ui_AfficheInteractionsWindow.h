/********************************************************************************
** Form generated from reading UI file 'AfficheInteractionsWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFICHEINTERACTIONSWINDOW_H
#define UI_AFFICHEINTERACTIONSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AfficheInteractionsWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QListView *interactionsList;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QTextEdit *textEdit;
    QPushButton *editTextButton;

    void setupUi(QWidget *AfficheInteractionsWindow)
    {
        if (AfficheInteractionsWindow->objectName().isEmpty())
            AfficheInteractionsWindow->setObjectName(QString::fromUtf8("AfficheInteractionsWindow"));
        AfficheInteractionsWindow->resize(400, 300);
        AfficheInteractionsWindow->setFocusPolicy(Qt::ClickFocus);
        gridLayout = new QGridLayout(AfficheInteractionsWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        interactionsList = new QListView(AfficheInteractionsWindow);
        interactionsList->setObjectName(QString::fromUtf8("interactionsList"));
        interactionsList->setMouseTracking(false);
        interactionsList->setFocusPolicy(Qt::NoFocus);
        interactionsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        interactionsList->setTabKeyNavigation(true);

        verticalLayout_2->addWidget(interactionsList);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(AfficheInteractionsWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);

        verticalLayout->addWidget(label);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(AfficheInteractionsWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        dateEdit = new QDateEdit(AfficheInteractionsWindow);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setEnabled(false);
        dateEdit->setFocusPolicy(Qt::ClickFocus);
        dateEdit->setDateTime(QDateTime(QDate(2021, 1, 1), QTime(0, 0, 0)));

        horizontalLayout->addWidget(dateEdit);


        verticalLayout_3->addLayout(horizontalLayout);

        textEdit = new QTextEdit(AfficheInteractionsWindow);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(false);
        textEdit->setFocusPolicy(Qt::ClickFocus);

        verticalLayout_3->addWidget(textEdit);

        editTextButton = new QPushButton(AfficheInteractionsWindow);
        editTextButton->setObjectName(QString::fromUtf8("editTextButton"));

        verticalLayout_3->addWidget(editTextButton);


        verticalLayout->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(AfficheInteractionsWindow);

        QMetaObject::connectSlotsByName(AfficheInteractionsWindow);
    } // setupUi

    void retranslateUi(QWidget *AfficheInteractionsWindow)
    {
        AfficheInteractionsWindow->setWindowTitle(QApplication::translate("AfficheInteractionsWindow", "Interactions", nullptr));
        label->setText(QApplication::translate("AfficheInteractionsWindow", "D\303\251tails :", nullptr));
        label_2->setText(QApplication::translate("AfficheInteractionsWindow", "Date de l'interaction: ", nullptr));
        editTextButton->setText(QApplication::translate("AfficheInteractionsWindow", "Modifier le r\303\251sum\303\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AfficheInteractionsWindow: public Ui_AfficheInteractionsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFICHEINTERACTIONSWINDOW_H
