/********************************************************************************
** Form generated from reading UI file 'pwin.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PWIN_H
#define UI_PWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_PWin
{
public:
    QChartView *chartView;

    void setupUi(QWidget *PWin)
    {
        if (PWin->objectName().isEmpty())
            PWin->setObjectName(QString::fromUtf8("PWin"));
        PWin->resize(640, 480);
        chartView = new QChartView(PWin);
        chartView->setObjectName(QString::fromUtf8("chartView"));
        chartView->setGeometry(QRect(15, 11, 611, 451));

        retranslateUi(PWin);

        QMetaObject::connectSlotsByName(PWin);
    } // setupUi

    void retranslateUi(QWidget *PWin)
    {
        PWin->setWindowTitle(QCoreApplication::translate("PWin", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PWin: public Ui_PWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PWIN_H
