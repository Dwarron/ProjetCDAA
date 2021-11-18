/********************************************************************************
** Form generated from reading UI file 'ModificationEvenementWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICATIONEVENEMENTWINDOW_H
#define UI_MODIFICATIONEVENEMENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModificationEvenementWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *contactLabel;
    QComboBox *contactComboBox;
    QLabel *eventLabel;
    QComboBox *eventComboBox;
    QLabel *modifEventLabel;
    QLineEdit *modifEventLineEdit;
    QLabel *addTimeLabel;
    QSpinBox *addTimeSpinBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *validButton;
    QPushButton *quitButton;

    void setupUi(QWidget *ModificationEvenementWindow)
    {
        if (ModificationEvenementWindow->objectName().isEmpty())
            ModificationEvenementWindow->setObjectName(QString::fromUtf8("ModificationEvenementWindow"));
        ModificationEvenementWindow->setWindowModality(Qt::NonModal);
        ModificationEvenementWindow->resize(435, 178);
        gridLayout = new QGridLayout(ModificationEvenementWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        contactLabel = new QLabel(ModificationEvenementWindow);
        contactLabel->setObjectName(QString::fromUtf8("contactLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, contactLabel);

        contactComboBox = new QComboBox(ModificationEvenementWindow);
        contactComboBox->setObjectName(QString::fromUtf8("contactComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, contactComboBox);

        eventLabel = new QLabel(ModificationEvenementWindow);
        eventLabel->setObjectName(QString::fromUtf8("eventLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, eventLabel);

        eventComboBox = new QComboBox(ModificationEvenementWindow);
        eventComboBox->setObjectName(QString::fromUtf8("eventComboBox"));
        eventComboBox->setEnabled(true);
        eventComboBox->setMaxVisibleItems(100);

        formLayout->setWidget(1, QFormLayout::FieldRole, eventComboBox);

        modifEventLabel = new QLabel(ModificationEvenementWindow);
        modifEventLabel->setObjectName(QString::fromUtf8("modifEventLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, modifEventLabel);

        modifEventLineEdit = new QLineEdit(ModificationEvenementWindow);
        modifEventLineEdit->setObjectName(QString::fromUtf8("modifEventLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, modifEventLineEdit);

        addTimeLabel = new QLabel(ModificationEvenementWindow);
        addTimeLabel->setObjectName(QString::fromUtf8("addTimeLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, addTimeLabel);

        addTimeSpinBox = new QSpinBox(ModificationEvenementWindow);
        addTimeSpinBox->setObjectName(QString::fromUtf8("addTimeSpinBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, addTimeSpinBox);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        validButton = new QPushButton(ModificationEvenementWindow);
        validButton->setObjectName(QString::fromUtf8("validButton"));

        horizontalLayout->addWidget(validButton);

        quitButton = new QPushButton(ModificationEvenementWindow);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        horizontalLayout->addWidget(quitButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(ModificationEvenementWindow);

        QMetaObject::connectSlotsByName(ModificationEvenementWindow);
    } // setupUi

    void retranslateUi(QWidget *ModificationEvenementWindow)
    {
        ModificationEvenementWindow->setWindowTitle(QApplication::translate("ModificationEvenementWindow", "Modification d'un \303\251v\303\251nement", nullptr));
        contactLabel->setText(QApplication::translate("ModificationEvenementWindow", "Contact ", nullptr));
        eventLabel->setText(QApplication::translate("ModificationEvenementWindow", "Ev\303\251nement ", nullptr));
        modifEventLabel->setText(QApplication::translate("ModificationEvenementWindow", "Modifier votre \303\251v\303\251nement ", nullptr));
        addTimeLabel->setText(QApplication::translate("ModificationEvenementWindow", "Ajouter un d\303\251lai \303\240 une t\303\242che (en jours)", nullptr));
        validButton->setText(QApplication::translate("ModificationEvenementWindow", "Valider", nullptr));
        quitButton->setText(QApplication::translate("ModificationEvenementWindow", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModificationEvenementWindow: public Ui_ModificationEvenementWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICATIONEVENEMENTWINDOW_H
