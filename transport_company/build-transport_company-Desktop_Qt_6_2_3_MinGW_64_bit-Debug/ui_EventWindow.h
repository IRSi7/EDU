/********************************************************************************
** Form generated from reading UI file 'EventWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTWINDOW_H
#define UI_EVENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EventWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QComboBox *repairCarIdBox;
    QPushButton *repairPushButton;
    QPushButton *requestPushButton;
    QComboBox *serviceCarIdBox;

    void setupUi(QMainWindow *EventWindow)
    {
        if (EventWindow->objectName().isEmpty())
            EventWindow->setObjectName(QString::fromUtf8("EventWindow"));
        EventWindow->resize(720, 118);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EventWindow->sizePolicy().hasHeightForWidth());
        EventWindow->setSizePolicy(sizePolicy);
        EventWindow->setMinimumSize(QSize(720, 118));
        EventWindow->setMaximumSize(QSize(720, 118));
        centralwidget = new QWidget(EventWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        repairCarIdBox = new QComboBox(centralwidget);
        repairCarIdBox->setObjectName(QString::fromUtf8("repairCarIdBox"));

        gridLayout->addWidget(repairCarIdBox, 1, 1, 1, 1);

        repairPushButton = new QPushButton(centralwidget);
        repairPushButton->setObjectName(QString::fromUtf8("repairPushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(repairPushButton->sizePolicy().hasHeightForWidth());
        repairPushButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(repairPushButton, 1, 0, 1, 1);

        requestPushButton = new QPushButton(centralwidget);
        requestPushButton->setObjectName(QString::fromUtf8("requestPushButton"));
        sizePolicy2.setHeightForWidth(requestPushButton->sizePolicy().hasHeightForWidth());
        requestPushButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(requestPushButton, 0, 0, 1, 1);

        serviceCarIdBox = new QComboBox(centralwidget);
        serviceCarIdBox->setObjectName(QString::fromUtf8("serviceCarIdBox"));

        gridLayout->addWidget(serviceCarIdBox, 0, 1, 1, 1);

        EventWindow->setCentralWidget(centralwidget);

        retranslateUi(EventWindow);

        QMetaObject::connectSlotsByName(EventWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EventWindow)
    {
        EventWindow->setWindowTitle(QCoreApplication::translate("EventWindow", "Events", nullptr));
        repairPushButton->setText(QCoreApplication::translate("EventWindow", "Repair car", nullptr));
        requestPushButton->setText(QCoreApplication::translate("EventWindow", "Request service car", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventWindow: public Ui_EventWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTWINDOW_H
