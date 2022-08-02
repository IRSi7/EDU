/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *eventButton;
    QPushButton *parametersButton;
    QPushButton *openStateButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(563, 203);
        MainWindow->setMinimumSize(QSize(563, 203));
        MainWindow->setMaximumSize(QSize(563, 203));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        QFont font;
        font.setKerning(false);
        centralwidget->setFont(font);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        eventButton = new QPushButton(centralwidget);
        eventButton->setObjectName(QString::fromUtf8("eventButton"));
        sizePolicy.setHeightForWidth(eventButton->sizePolicy().hasHeightForWidth());
        eventButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(eventButton, 0, 0, 1, 1);

        parametersButton = new QPushButton(centralwidget);
        parametersButton->setObjectName(QString::fromUtf8("parametersButton"));
        sizePolicy.setHeightForWidth(parametersButton->sizePolicy().hasHeightForWidth());
        parametersButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(parametersButton, 0, 1, 1, 1);

        openStateButton = new QPushButton(centralwidget);
        openStateButton->setObjectName(QString::fromUtf8("openStateButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(openStateButton->sizePolicy().hasHeightForWidth());
        openStateButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(openStateButton, 1, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Company", nullptr));
        eventButton->setText(QCoreApplication::translate("MainWindow", "Open Events", nullptr));
        parametersButton->setText(QCoreApplication::translate("MainWindow", "Open Parameters", nullptr));
        openStateButton->setText(QCoreApplication::translate("MainWindow", "Open State", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
