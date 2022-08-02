#include "ModelParametersWindow.hpp"
#include "ui_ModelParametersWindow.h"
#include <QMessageBox>

ModelParametersWindow::ModelParametersWindow(QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::ModelParametersWindow())
{
    ui->setupUi(this);
}

ModelParametersWindow::~ModelParametersWindow() {
    delete ui;
}

void ModelParametersWindow::on_setParametersButton_pressed() {
    bool ok;
    uint32_t carsCount = ui->carsLineEdit->text().toULong(&ok);
    if (not ok) {
        QMessageBox::warning(this, "Incorrect Parameters", "Incorrect cars input. Check it.");
        return;
    }
    if (carsCount == 0) {
        QMessageBox::warning(this, "Incorrect Value", "Cars count equals 0. Please, enter a positive value.");
        return;
    }

    uint32_t cargoCarsCount = ui->cargoCarsLineEdit->text().toULong(&ok);
    if (not ok) {
        QMessageBox::warning(this, "Incorrect Input", "Incorrect cargo cars input. Check it.");
        return;
    }

    if (cargoCarsCount > carsCount) {
        QMessageBox::warning(this, "Incorrect Parameters", "Cargo cars count is greater cars count.");
        return;
    }

    uint32_t mechanicsCount = ui->mechanicsLineEdit->text().toULong(&ok);
    if (not ok) {
        QMessageBox::warning(this, "Incorrect Input", "Incorrect mechanics count input. Check it.");
        return;
    }
    if (mechanicsCount == 0) {
        QMessageBox::warning(this, "Incorrect Value", "Mechanics count equals 0. Please, enter a positive value.");
        return;
    }

    double l = ui->lCoeffLineEdit->text().toDouble(&ok);
    if (not ok) {
        l = ui->lCoeffLineEdit->text().toInt(&ok);
        if (not ok) {
            QMessageBox::warning(this, "Incorrect Input", "Incorrect l coefficient input. Check it.");
            return;
        }
    }
    if (l < 1.0) {
        QMessageBox::warning(this, "Incorrect Value", "L coefficient is less than 1. Please, enter a value greater 1");
        return;
    }
    emit modelParametersChanged(carsCount, cargoCarsCount, mechanicsCount, l);
}

