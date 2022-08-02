/********************************************************************************
** Form generated from reading UI file 'ModelParametersWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELPARAMETERSWINDOW_H
#define UI_MODELPARAMETERSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelParametersWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *carsLineEdit;
    QLabel *label_2;
    QLineEdit *cargoCarsLineEdit;
    QLabel *label_4;
    QLineEdit *mechanicsLineEdit;
    QLabel *label_5;
    QLineEdit *lCoeffLineEdit;
    QPushButton *setParametersButton;

    void setupUi(QMainWindow *ModelParametersWindow)
    {
        if (ModelParametersWindow->objectName().isEmpty())
            ModelParametersWindow->setObjectName(QString::fromUtf8("ModelParametersWindow"));
        ModelParametersWindow->resize(537, 196);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ModelParametersWindow->sizePolicy().hasHeightForWidth());
        ModelParametersWindow->setSizePolicy(sizePolicy);
        ModelParametersWindow->setMinimumSize(QSize(537, 196));
        ModelParametersWindow->setMaximumSize(QSize(537, 196));
        centralwidget = new QWidget(ModelParametersWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        carsLineEdit = new QLineEdit(centralwidget);
        carsLineEdit->setObjectName(QString::fromUtf8("carsLineEdit"));

        gridLayout->addWidget(carsLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        cargoCarsLineEdit = new QLineEdit(centralwidget);
        cargoCarsLineEdit->setObjectName(QString::fromUtf8("cargoCarsLineEdit"));

        gridLayout->addWidget(cargoCarsLineEdit, 1, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        mechanicsLineEdit = new QLineEdit(centralwidget);
        mechanicsLineEdit->setObjectName(QString::fromUtf8("mechanicsLineEdit"));

        gridLayout->addWidget(mechanicsLineEdit, 2, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        lCoeffLineEdit = new QLineEdit(centralwidget);
        lCoeffLineEdit->setObjectName(QString::fromUtf8("lCoeffLineEdit"));

        gridLayout->addWidget(lCoeffLineEdit, 3, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        setParametersButton = new QPushButton(centralwidget);
        setParametersButton->setObjectName(QString::fromUtf8("setParametersButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(setParametersButton->sizePolicy().hasHeightForWidth());
        setParametersButton->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(setParametersButton, 1, 0, 1, 1);

        ModelParametersWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(carsLineEdit, cargoCarsLineEdit);
        QWidget::setTabOrder(cargoCarsLineEdit, mechanicsLineEdit);
        QWidget::setTabOrder(mechanicsLineEdit, lCoeffLineEdit);
        QWidget::setTabOrder(lCoeffLineEdit, setParametersButton);

        retranslateUi(ModelParametersWindow);

        QMetaObject::connectSlotsByName(ModelParametersWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ModelParametersWindow)
    {
        ModelParametersWindow->setWindowTitle(QCoreApplication::translate("ModelParametersWindow", "Model Parameters", nullptr));
        label->setText(QCoreApplication::translate("ModelParametersWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\320\265\320\271", nullptr));
        label_2->setText(QCoreApplication::translate("ModelParametersWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\263\321\200\321\203\320\267\320\276\320\262\321\213\321\205 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\320\265\320\271", nullptr));
        label_4->setText(QCoreApplication::translate("ModelParametersWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\274\320\265\321\205\320\260\320\275\320\270\320\272\320\276\320\262", nullptr));
        label_5->setText(QCoreApplication::translate("ModelParametersWindow", "L = ", nullptr));
        setParametersButton->setText(QCoreApplication::translate("ModelParametersWindow", "Change model parameters", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModelParametersWindow: public Ui_ModelParametersWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELPARAMETERSWINDOW_H
