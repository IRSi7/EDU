/********************************************************************************
** Form generated from reading UI file 'CompanyStateWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPANYSTATEWINDOW_H
#define UI_COMPANYSTATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompanyStateWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QTableWidget *mechanicTable;
    QTableWidget *carsTable;
    QLabel *label_2;

    void setupUi(QMainWindow *CompanyStateWindow)
    {
        if (CompanyStateWindow->objectName().isEmpty())
            CompanyStateWindow->setObjectName(QString::fromUtf8("CompanyStateWindow"));
        CompanyStateWindow->resize(800, 600);
        CompanyStateWindow->setMinimumSize(QSize(800, 600));
        centralwidget = new QWidget(CompanyStateWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(22);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        mechanicTable = new QTableWidget(centralwidget);
        mechanicTable->setObjectName(QString::fromUtf8("mechanicTable"));

        gridLayout->addWidget(mechanicTable, 2, 0, 1, 1);

        carsTable = new QTableWidget(centralwidget);
        carsTable->setObjectName(QString::fromUtf8("carsTable"));

        gridLayout->addWidget(carsTable, 2, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        CompanyStateWindow->setCentralWidget(centralwidget);

        retranslateUi(CompanyStateWindow);

        QMetaObject::connectSlotsByName(CompanyStateWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CompanyStateWindow)
    {
        CompanyStateWindow->setWindowTitle(QCoreApplication::translate("CompanyStateWindow", "Company State", nullptr));
        label->setText(QCoreApplication::translate("CompanyStateWindow", "Mechanics", nullptr));
        label_2->setText(QCoreApplication::translate("CompanyStateWindow", "Cars", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CompanyStateWindow: public Ui_CompanyStateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPANYSTATEWINDOW_H
