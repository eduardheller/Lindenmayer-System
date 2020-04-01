/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dlgHelp
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *dlgHelp)
    {
        if (dlgHelp->objectName().isEmpty())
            dlgHelp->setObjectName(QStringLiteral("dlgHelp"));
        dlgHelp->resize(561, 468);
        gridLayout = new QGridLayout(dlgHelp);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textBrowser = new QTextBrowser(dlgHelp);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 0, 0, 1, 1);


        retranslateUi(dlgHelp);

        QMetaObject::connectSlotsByName(dlgHelp);
    } // setupUi

    void retranslateUi(QWidget *dlgHelp)
    {
        dlgHelp->setWindowTitle(QApplication::translate("dlgHelp", "Help", 0));
        textBrowser->setHtml(QApplication::translate("dlgHelp", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">Defined L-System Axioms:</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-weight:600;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">F   :</span><span style=\" font-size:12pt; font-style:italic;\"> Draws "
                        "branch in direction x</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">L</span><span style=\" font-size:12pt; font-style:italic;\">   </span><span style=\" font-size:12pt; font-weight:600;\">:</span><span style=\" font-size:12pt; font-style:italic;\"> Draws a leaf in directions x</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">!</span><span style=\" font-size:12pt; font-style:italic;\">   </span><span style=\" font-size:12pt; font-weight:600;\"> :</span><span style=\" font-size:12pt; font-style:italic;\"> Scales down the size of branch and leaf drawings </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-style:italic;\">+"
                        " </span><span style=\" font-size:12pt; font-weight:600;\">  : </span><span style=\" font-size:12pt; font-style:italic;\">Rotates positiv about the up vector </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-style:italic;\">-    </span><span style=\" font-size:12pt; font-weight:600;\">: </span><span style=\" font-size:12pt; font-style:italic;\">Rotates negativ about the up vector </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-style:italic;\">&amp; </span><span style=\" font-size:12pt; font-weight:600;\">  : </span><span style=\" font-size:12pt; font-style:italic;\">Rotates positiv about the left vector </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;"
                        " font-style:italic;\">^   </span><span style=\" font-size:12pt; font-weight:600;\">: </span><span style=\" font-size:12pt; font-style:italic;\">Rotates negativ about the left vector </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-style:italic;\">+ </span><span style=\" font-size:12pt; font-weight:600;\">  : </span><span style=\" font-size:12pt; font-style:italic;\">Rotates positiv about the heading vector </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-style:italic;\">-    </span><span style=\" font-size:12pt; font-weight:600;\">: </span><span style=\" font-size:12pt; font-style:italic;\">Rotates negativ about the heading vector </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><"
                        "span style=\" font-size:12pt; font-style:italic;\">|    </span><span style=\" font-size:12pt; font-weight:600;\">: </span><span style=\" font-size:12pt; font-style:italic;\">Rotates positiv 180\302\260 about the up vector </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-style:italic;\">[    </span><span style=\" font-size:12pt; font-weight:600;\">: </span><span style=\" font-size:12pt; font-style:italic;\">Pushes state in the stack</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-style:italic;\">]    </span><span style=\" font-size:12pt; font-weight:600;\">: </span><span style=\" font-size:12pt; font-style:italic;\">Pops state from the stack</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bl"
                        "ock-indent:0; text-indent:0px; font-size:12pt; font-style:italic;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">Movement Binding:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">W A S D </span><span style=\" font-size:12pt;\">- Move Camera</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">Mouswheel</span><span style=\" font-size:12pt;\"> - Move forward and back</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">Right Mouse Button</span><span style=\" font-size:12pt;\"> "
                        "- Rotate Camera</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-style:italic;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">Good to know:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">This L-System software always starts with heading vector (0,1,0) , this means that F starts drawing a branch in (0,1,0) direction if not rotated.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text"
                        "-indent:0px;\"><span style=\" font-size:12pt;\">To get started you should check the examples in the /examples folder.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-weight:600;\"><br /></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgHelp: public Ui_dlgHelp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
