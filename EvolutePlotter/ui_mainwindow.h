/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QLabel *radiusLabel;
    QLineEdit *aLineEdit;
    QLineEdit *bLineEdit;
    QPushButton *toPolarButton;
    QCustomPlot *plot;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(642, 578);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(642, 539));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(60, -1, 60, -1);
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy1);
        checkBox->setMinimumSize(QSize(85, 17));
        checkBox->setMaximumSize(QSize(85, 17));

        horizontalLayout->addWidget(checkBox);

        radiusLabel = new QLabel(centralwidget);
        radiusLabel->setObjectName(QString::fromUtf8("radiusLabel"));
        sizePolicy1.setHeightForWidth(radiusLabel->sizePolicy().hasHeightForWidth());
        radiusLabel->setSizePolicy(sizePolicy1);
        radiusLabel->setMinimumSize(QSize(48, 17));
        radiusLabel->setMaximumSize(QSize(66, 17));
        radiusLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(radiusLabel);

        aLineEdit = new QLineEdit(centralwidget);
        aLineEdit->setObjectName(QString::fromUtf8("aLineEdit"));
        sizePolicy1.setHeightForWidth(aLineEdit->sizePolicy().hasHeightForWidth());
        aLineEdit->setSizePolicy(sizePolicy1);
        aLineEdit->setMinimumSize(QSize(66, 17));
        aLineEdit->setMaximumSize(QSize(120, 17));

        horizontalLayout->addWidget(aLineEdit);

        bLineEdit = new QLineEdit(centralwidget);
        bLineEdit->setObjectName(QString::fromUtf8("bLineEdit"));

        horizontalLayout->addWidget(bLineEdit);

        toPolarButton = new QPushButton(centralwidget);
        toPolarButton->setObjectName(QString::fromUtf8("toPolarButton"));
        sizePolicy1.setHeightForWidth(toPolarButton->sizePolicy().hasHeightForWidth());
        toPolarButton->setSizePolicy(sizePolicy1);
        toPolarButton->setMinimumSize(QSize(80, 17));
        toPolarButton->setMaximumSize(QSize(120, 17));

        horizontalLayout->addWidget(toPolarButton);


        verticalLayout->addLayout(horizontalLayout);

        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);
        plot->setMinimumSize(QSize(600, 400));
        plot->setMaximumSize(QSize(1920, 1080));

        verticalLayout->addWidget(plot);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 642, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\270\321\202\320\270\320\262", nullptr));
        radiusLabel->setText(QCoreApplication::translate("MainWindow", "a & b:", nullptr));
        toPolarButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\217\321\200\320\275\320\260\321\217 \321\201\320\270\321\201\321\202\320\265\320\274\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
