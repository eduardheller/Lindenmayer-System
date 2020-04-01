/********************************************************************************
** Form generated from reading UI file 'addproduction.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPRODUCTION_H
#define UI_ADDPRODUCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dlgProduction
{
public:
    QDialogButtonBox *btnBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtRule;
    QLabel *label_2;
    QLineEdit *txtProduction;
    QDoubleSpinBox *sBoxChance;
    QLabel *label_3;

    void setupUi(QDialog *dlgProduction)
    {
        if (dlgProduction->objectName().isEmpty())
            dlgProduction->setObjectName(QStringLiteral("dlgProduction"));
        dlgProduction->resize(397, 137);
        btnBox = new QDialogButtonBox(dlgProduction);
        btnBox->setObjectName(QStringLiteral("btnBox"));
        btnBox->setGeometry(QRect(40, 100, 341, 32));
        btnBox->setOrientation(Qt::Horizontal);
        btnBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(dlgProduction);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 20, 361, 74));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtRule = new QLineEdit(formLayoutWidget);
        txtRule->setObjectName(QStringLiteral("txtRule"));
        txtRule->setMaxLength(1);

        formLayout->setWidget(0, QFormLayout::FieldRole, txtRule);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        txtProduction = new QLineEdit(formLayoutWidget);
        txtProduction->setObjectName(QStringLiteral("txtProduction"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtProduction);

        sBoxChance = new QDoubleSpinBox(formLayoutWidget);
        sBoxChance->setObjectName(QStringLiteral("sBoxChance"));
        sBoxChance->setSingleStep(0.01);
        sBoxChance->setValue(1);

        formLayout->setWidget(2, QFormLayout::FieldRole, sBoxChance);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);


        retranslateUi(dlgProduction);
        QObject::connect(btnBox, SIGNAL(accepted()), dlgProduction, SLOT(accept()));
        QObject::connect(btnBox, SIGNAL(rejected()), dlgProduction, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgProduction);
    } // setupUi

    void retranslateUi(QDialog *dlgProduction)
    {
        dlgProduction->setWindowTitle(QApplication::translate("dlgProduction", "Add Production", 0));
        label->setText(QApplication::translate("dlgProduction", "Predecessor", 0));
        label_2->setText(QApplication::translate("dlgProduction", "Sucessor", 0));
        label_3->setText(QApplication::translate("dlgProduction", "Chance", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgProduction: public Ui_dlgProduction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPRODUCTION_H
