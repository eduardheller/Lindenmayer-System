/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "oglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_wndMain
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExport;
    QAction *actionClose;
    QAction *actionAnimation;
    QAction *actionShadow;
    QAction *actionHelp;
    QAction *actionWireframe;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    OGLWidget *openGLWidget;
    QTextBrowser *txtLog;
    QVBoxLayout *verticalLayout_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_2;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_4;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_2;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QLabel *label;
    QLineEdit *txtAxiom;
    QLabel *label_10;
    QSpinBox *sBoxIterations;
    QLabel *label_8;
    QDoubleSpinBox *sBoxAngle;
    QGroupBox *groupBox_3;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_4;
    QLabel *label_9;
    QDoubleSpinBox *sBoxLength;
    QLabel *label_11;
    QDoubleSpinBox *sBoxThickness;
    QLabel *label_12;
    QSpinBox *sBoxCylinder;
    QLabel *label_13;
    QSpinBox *sBoxHermite;
    QLabel *label_14;
    QDoubleSpinBox *sBoxTangent;
    QLabel *label_15;
    QDoubleSpinBox *sBoxDecrease;
    QPushButton *btnTextureBranch;
    QLabel *lblBranchTexture;
    QDoubleSpinBox *sBoxTangent2;
    QLabel *label_20;
    QDoubleSpinBox *sBoxDist;
    QLabel *label_21;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_5;
    QLabel *label_16;
    QDoubleSpinBox *sBoxLeafX;
    QLabel *label_18;
    QDoubleSpinBox *sBoxLeafY;
    QLabel *label_17;
    QDoubleSpinBox *sBoxDecreaseLeaf;
    QPushButton *btnTextureLeaf;
    QLabel *lblLeafTexture;
    QDoubleSpinBox *sBoxBending;
    QLabel *label_19;
    QPushButton *btnGenerate;
    QPushButton *btnClear;
    QMenuBar *menubar;
    QMenu *menuNew;
    QMenu *menuView;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *wndMain)
    {
        if (wndMain->objectName().isEmpty())
            wndMain->setObjectName(QStringLiteral("wndMain"));
        wndMain->resize(1044, 1217);
        actionOpen = new QAction(wndMain);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(wndMain);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExport = new QAction(wndMain);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        actionClose = new QAction(wndMain);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionAnimation = new QAction(wndMain);
        actionAnimation->setObjectName(QStringLiteral("actionAnimation"));
        actionAnimation->setCheckable(true);
        actionAnimation->setChecked(true);
        actionShadow = new QAction(wndMain);
        actionShadow->setObjectName(QStringLiteral("actionShadow"));
        actionShadow->setCheckable(true);
        actionShadow->setChecked(true);
        actionHelp = new QAction(wndMain);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionWireframe = new QAction(wndMain);
        actionWireframe->setObjectName(QStringLiteral("actionWireframe"));
        actionWireframe->setCheckable(true);
        centralwidget = new QWidget(wndMain);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, 0, -1);
        openGLWidget = new OGLWidget(centralwidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy);
        openGLWidget->setMaximumSize(QSize(1920, 1080));
        openGLWidget->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_2->addWidget(openGLWidget);

        txtLog = new QTextBrowser(centralwidget);
        txtLog->setObjectName(QStringLiteral("txtLog"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(txtLog->sizePolicy().hasHeightForWidth());
        txtLog->setSizePolicy(sizePolicy1);
        txtLog->setMinimumSize(QSize(0, 55));
        txtLog->setMaximumSize(QSize(16777215, 100));
        txtLog->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout_2->addWidget(txtLog);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, -1, 0, 0);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy2);
        scrollArea->setMinimumSize(QSize(400, 0));
        scrollArea->setMaximumSize(QSize(400, 16777215));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 398, 1045));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(scrollAreaWidgetContents);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_7 = new QVBoxLayout(tab);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy3);
        groupBox_2->setMinimumSize(QSize(0, 250));
        groupBox_2->setMaximumSize(QSize(16777215, 250));
        tableWidget = new QTableWidget(groupBox_2);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 341, 211));
        tableWidget->setMaximumSize(QSize(16777215, 260));

        verticalLayout_7->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        sizePolicy3.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy3);
        groupBox_4->setMinimumSize(QSize(0, 135));
        formLayoutWidget = new QWidget(groupBox_4);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 341, 111));
        formLayout_2 = new QFormLayout(formLayoutWidget);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        btnAdd = new QPushButton(formLayoutWidget);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, btnAdd);

        btnRemove = new QPushButton(formLayoutWidget);
        btnRemove->setObjectName(QStringLiteral("btnRemove"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, btnRemove);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label);

        txtAxiom = new QLineEdit(formLayoutWidget);
        txtAxiom->setObjectName(QStringLiteral("txtAxiom"));
        txtAxiom->setMaxLength(1);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, txtAxiom);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_10);

        sBoxIterations = new QSpinBox(formLayoutWidget);
        sBoxIterations->setObjectName(QStringLiteral("sBoxIterations"));
        sBoxIterations->setValue(1);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, sBoxIterations);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_8);

        sBoxAngle = new QDoubleSpinBox(formLayoutWidget);
        sBoxAngle->setObjectName(QStringLiteral("sBoxAngle"));
        sBoxAngle->setMaximum(360);
        sBoxAngle->setValue(30);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, sBoxAngle);


        verticalLayout_7->addWidget(groupBox_4);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy3.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy3);
        groupBox_3->setMinimumSize(QSize(0, 255));
        groupBox_3->setMaximumSize(QSize(16777215, 260));
        groupBox_3->setFlat(false);
        formLayoutWidget_3 = new QWidget(groupBox_3);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(10, 20, 341, 233));
        formLayout_4 = new QFormLayout(formLayoutWidget_3);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(formLayoutWidget_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_9);

        sBoxLength = new QDoubleSpinBox(formLayoutWidget_3);
        sBoxLength->setObjectName(QStringLiteral("sBoxLength"));
        sBoxLength->setValue(0.7);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, sBoxLength);

        label_11 = new QLabel(formLayoutWidget_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_11);

        sBoxThickness = new QDoubleSpinBox(formLayoutWidget_3);
        sBoxThickness->setObjectName(QStringLiteral("sBoxThickness"));
        sBoxThickness->setValue(0.02);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, sBoxThickness);

        label_12 = new QLabel(formLayoutWidget_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_12);

        sBoxCylinder = new QSpinBox(formLayoutWidget_3);
        sBoxCylinder->setObjectName(QStringLiteral("sBoxCylinder"));
        sBoxCylinder->setMaximum(999);
        sBoxCylinder->setValue(16);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, sBoxCylinder);

        label_13 = new QLabel(formLayoutWidget_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_13);

        sBoxHermite = new QSpinBox(formLayoutWidget_3);
        sBoxHermite->setObjectName(QStringLiteral("sBoxHermite"));
        sBoxHermite->setMaximum(999);
        sBoxHermite->setValue(8);

        formLayout_4->setWidget(3, QFormLayout::FieldRole, sBoxHermite);

        label_14 = new QLabel(formLayoutWidget_3);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_4->setWidget(4, QFormLayout::LabelRole, label_14);

        sBoxTangent = new QDoubleSpinBox(formLayoutWidget_3);
        sBoxTangent->setObjectName(QStringLiteral("sBoxTangent"));
        sBoxTangent->setMinimum(-99);
        sBoxTangent->setValue(1);

        formLayout_4->setWidget(4, QFormLayout::FieldRole, sBoxTangent);

        label_15 = new QLabel(formLayoutWidget_3);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout_4->setWidget(7, QFormLayout::LabelRole, label_15);

        sBoxDecrease = new QDoubleSpinBox(formLayoutWidget_3);
        sBoxDecrease->setObjectName(QStringLiteral("sBoxDecrease"));
        sBoxDecrease->setMinimum(-99);
        sBoxDecrease->setValue(0.5);

        formLayout_4->setWidget(7, QFormLayout::FieldRole, sBoxDecrease);

        btnTextureBranch = new QPushButton(formLayoutWidget_3);
        btnTextureBranch->setObjectName(QStringLiteral("btnTextureBranch"));

        formLayout_4->setWidget(8, QFormLayout::LabelRole, btnTextureBranch);

        lblBranchTexture = new QLabel(formLayoutWidget_3);
        lblBranchTexture->setObjectName(QStringLiteral("lblBranchTexture"));

        formLayout_4->setWidget(8, QFormLayout::FieldRole, lblBranchTexture);

        sBoxTangent2 = new QDoubleSpinBox(formLayoutWidget_3);
        sBoxTangent2->setObjectName(QStringLiteral("sBoxTangent2"));
        sBoxTangent2->setMinimum(-99);
        sBoxTangent2->setValue(1);

        formLayout_4->setWidget(5, QFormLayout::FieldRole, sBoxTangent2);

        label_20 = new QLabel(formLayoutWidget_3);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout_4->setWidget(5, QFormLayout::LabelRole, label_20);

        sBoxDist = new QDoubleSpinBox(formLayoutWidget_3);
        sBoxDist->setObjectName(QStringLiteral("sBoxDist"));
        sBoxDist->setDecimals(6);
        sBoxDist->setMinimum(-99);
        sBoxDist->setSingleStep(0.01);
        sBoxDist->setValue(0.01);

        formLayout_4->setWidget(6, QFormLayout::FieldRole, sBoxDist);

        label_21 = new QLabel(formLayoutWidget_3);
        label_21->setObjectName(QStringLiteral("label_21"));

        formLayout_4->setWidget(6, QFormLayout::LabelRole, label_21);


        verticalLayout_7->addWidget(groupBox_3);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy4);
        groupBox->setMinimumSize(QSize(0, 150));
        groupBox->setMaximumSize(QSize(16777215, 150));
        formLayoutWidget_4 = new QWidget(groupBox);
        formLayoutWidget_4->setObjectName(QStringLiteral("formLayoutWidget_4"));
        formLayoutWidget_4->setGeometry(QRect(10, 20, 341, 148));
        formLayout_5 = new QFormLayout(formLayoutWidget_4);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        formLayout_5->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_5->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(formLayoutWidget_4);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_16);

        sBoxLeafX = new QDoubleSpinBox(formLayoutWidget_4);
        sBoxLeafX->setObjectName(QStringLiteral("sBoxLeafX"));
        sBoxLeafX->setMinimum(-999);
        sBoxLeafX->setMaximum(999.99);
        sBoxLeafX->setValue(1);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, sBoxLeafX);

        label_18 = new QLabel(formLayoutWidget_4);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_18);

        sBoxLeafY = new QDoubleSpinBox(formLayoutWidget_4);
        sBoxLeafY->setObjectName(QStringLiteral("sBoxLeafY"));
        sBoxLeafY->setMinimum(-999);
        sBoxLeafY->setMaximum(999.99);
        sBoxLeafY->setValue(1);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, sBoxLeafY);

        label_17 = new QLabel(formLayoutWidget_4);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout_5->setWidget(3, QFormLayout::LabelRole, label_17);

        sBoxDecreaseLeaf = new QDoubleSpinBox(formLayoutWidget_4);
        sBoxDecreaseLeaf->setObjectName(QStringLiteral("sBoxDecreaseLeaf"));
        sBoxDecreaseLeaf->setMaximum(99);
        sBoxDecreaseLeaf->setValue(0.5);

        formLayout_5->setWidget(3, QFormLayout::FieldRole, sBoxDecreaseLeaf);

        btnTextureLeaf = new QPushButton(formLayoutWidget_4);
        btnTextureLeaf->setObjectName(QStringLiteral("btnTextureLeaf"));

        formLayout_5->setWidget(4, QFormLayout::LabelRole, btnTextureLeaf);

        lblLeafTexture = new QLabel(formLayoutWidget_4);
        lblLeafTexture->setObjectName(QStringLiteral("lblLeafTexture"));

        formLayout_5->setWidget(4, QFormLayout::FieldRole, lblLeafTexture);

        sBoxBending = new QDoubleSpinBox(formLayoutWidget_4);
        sBoxBending->setObjectName(QStringLiteral("sBoxBending"));
        sBoxBending->setMaximum(99);
        sBoxBending->setValue(0.05);

        formLayout_5->setWidget(2, QFormLayout::FieldRole, sBoxBending);

        label_19 = new QLabel(formLayoutWidget_4);
        label_19->setObjectName(QStringLiteral("label_19"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_19);


        verticalLayout_7->addWidget(groupBox);

        tabWidget->addTab(tab, QString());

        verticalLayout_3->addWidget(tabWidget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_6->addWidget(scrollArea);

        btnGenerate = new QPushButton(centralwidget);
        btnGenerate->setObjectName(QStringLiteral("btnGenerate"));
        sizePolicy4.setHeightForWidth(btnGenerate->sizePolicy().hasHeightForWidth());
        btnGenerate->setSizePolicy(sizePolicy4);
        btnGenerate->setMinimumSize(QSize(0, 72));
        btnGenerate->setMaximumSize(QSize(16777215, 250));

        verticalLayout_6->addWidget(btnGenerate);

        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName(QStringLiteral("btnClear"));

        verticalLayout_6->addWidget(btnClear);


        horizontalLayout_2->addLayout(verticalLayout_6);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        wndMain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(wndMain);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1044, 21));
        menuNew = new QMenu(menubar);
        menuNew->setObjectName(QStringLiteral("menuNew"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        wndMain->setMenuBar(menubar);
        statusbar = new QStatusBar(wndMain);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        wndMain->setStatusBar(statusbar);

        menubar->addAction(menuNew->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuNew->addAction(actionOpen);
        menuNew->addAction(actionSave);
        menuNew->addAction(actionExport);
        menuNew->addAction(actionClose);
        menuView->addAction(actionAnimation);
        menuView->addAction(actionShadow);
        menuView->addAction(actionWireframe);
        menuHelp->addAction(actionHelp);

        retranslateUi(wndMain);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(wndMain);
    } // setupUi

    void retranslateUi(QMainWindow *wndMain)
    {
        wndMain->setWindowTitle(QApplication::translate("wndMain", "Stochastic L-Systems", 0));
        actionOpen->setText(QApplication::translate("wndMain", "Open", 0));
        actionSave->setText(QApplication::translate("wndMain", "Save", 0));
        actionExport->setText(QApplication::translate("wndMain", "Export .OBJ", 0));
        actionClose->setText(QApplication::translate("wndMain", "Exit", 0));
        actionAnimation->setText(QApplication::translate("wndMain", "Animation", 0));
        actionShadow->setText(QApplication::translate("wndMain", "Shadow", 0));
        actionHelp->setText(QApplication::translate("wndMain", "Help", 0));
        actionWireframe->setText(QApplication::translate("wndMain", "Wireframe", 0));
        txtLog->setHtml(QApplication::translate("wndMain", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        groupBox_2->setTitle(QApplication::translate("wndMain", "L-System-Productions", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("wndMain", "Rule", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("wndMain", "Production", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("wndMain", "Chance", 0));
        groupBox_4->setTitle(QApplication::translate("wndMain", "General", 0));
        btnAdd->setText(QApplication::translate("wndMain", "Add Production", 0));
        btnRemove->setText(QApplication::translate("wndMain", "Remove Selected Production", 0));
        label->setText(QApplication::translate("wndMain", "Axiom:", 0));
        txtAxiom->setText(QApplication::translate("wndMain", "F", 0));
        label_10->setText(QApplication::translate("wndMain", "Iterations", 0));
        label_8->setText(QApplication::translate("wndMain", "Angle", 0));
        groupBox_3->setTitle(QApplication::translate("wndMain", "Branches", 0));
        label_9->setText(QApplication::translate("wndMain", "Branch-Length", 0));
        label_11->setText(QApplication::translate("wndMain", "Branch-Thickness", 0));
        label_12->setText(QApplication::translate("wndMain", "Cylinder-Aproximation", 0));
        label_13->setText(QApplication::translate("wndMain", "Hermite-Interp-Steps", 0));
        label_14->setText(QApplication::translate("wndMain", "Tangent-1", 0));
        label_15->setText(QApplication::translate("wndMain", "Decrease-Factor", 0));
        btnTextureBranch->setText(QApplication::translate("wndMain", "assign texture", 0));
        lblBranchTexture->setText(QApplication::translate("wndMain", "No Texture", 0));
        label_20->setText(QApplication::translate("wndMain", "Tangent-2", 0));
        label_21->setText(QApplication::translate("wndMain", "Min-Tangent-Dist", 0));
        groupBox->setTitle(QApplication::translate("wndMain", "Leafs", 0));
        label_16->setText(QApplication::translate("wndMain", "X-Scale", 0));
        label_18->setText(QApplication::translate("wndMain", "Y-Scale", 0));
        label_17->setText(QApplication::translate("wndMain", "Decrease-Factor", 0));
        btnTextureLeaf->setText(QApplication::translate("wndMain", "assign texture", 0));
        lblLeafTexture->setText(QApplication::translate("wndMain", "No Texture", 0));
        label_19->setText(QApplication::translate("wndMain", "Bending", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("wndMain", "Stochastic L-System", 0));
        btnGenerate->setText(QApplication::translate("wndMain", "Generate", 0));
        btnClear->setText(QApplication::translate("wndMain", "Reset Camera", 0));
        menuNew->setTitle(QApplication::translate("wndMain", "File", 0));
        menuView->setTitle(QApplication::translate("wndMain", "View", 0));
        menuHelp->setTitle(QApplication::translate("wndMain", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class wndMain: public Ui_wndMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
