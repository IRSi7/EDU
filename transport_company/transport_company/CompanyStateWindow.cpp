#include "CompanyStateWindow.hpp"
#include "ui_CompanyStateWindow.h"

CompanyStateWindow::CompanyStateWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CompanyStateWindow)
{
    ui->setupUi(this);
}

void CompanyStateWindow::setupMechanicsTable() {
    ui->mechanicTable->clear();
    ui->mechanicTable->setColumnCount(5);
    ui->mechanicTable->setHorizontalHeaderLabels(QStringList() << "#" << "status" << "car ID" << "serviced cars" << "skill");
}

void CompanyStateWindow::setupCarsTable() {
    ui->carsTable->clear();
    ui->carsTable->setColumnCount(4);
    ui->carsTable->setHorizontalHeaderLabels(QStringList() << "#" << "type" << "status" << "mechanic ID");
}

void CompanyStateWindow::refreshTable(Company const& company) {
    setupMechanicsTable();
    setupCarsTable();
    ui->mechanicTable->setRowCount(company.mechanics().size());
    size_t row = 0;
    for (auto const& mechanic: company.mechanics()) {
        ui->mechanicTable->setItem(row, 0, new QTableWidgetItem(QString::number(row)));

        QString status = mechanic.isFree() ? "free" : "working";
        ui->mechanicTable->setItem(row, 1, new QTableWidgetItem(status));

        if (not mechanic.isFree()) {
            ui->mechanicTable->setItem(row, 2, new QTableWidgetItem(QString::number(mechanic.repairingCarId())));
        }
        ui->mechanicTable->setItem(row, 3, new QTableWidgetItem(QString::number(mechanic.serviced())));
        QString skill = (mechanic.skill() == Mechanic::Skill::PASSANGER_ONLY ? "passanger" : "cargo & passanger");
        std::cerr << static_cast<int>(mechanic.skill()) << '\n';
        ui->mechanicTable->setItem(row, 4, new QTableWidgetItem(skill));
        ++row;
    }

    ui->carsTable->setRowCount(company.cars().size());
    row = 0;
    for (auto const& car: company.cars()) {
        ui->carsTable->setItem(row, 0, new QTableWidgetItem(QString::number(row)));

        QString type = car.type() == Car::Type::PASSENGER ? "passanger" : "cargo";
        ui->carsTable->setItem(row, 1, new QTableWidgetItem(type));

        QString status;
        switch (car.status()) {
        case Car::Status::GOOD:
            status = "good";
            break;
        case Car::Status::REPAIRING:
            status = "repairing";
            break;
        }
        ui->carsTable->setItem(row, 2, new QTableWidgetItem(status));
        ++row;
    }
    row = 0;
    for (auto const& mechanic: company.mechanics()) {
        if (not mechanic.isFree()) {
            ui->carsTable->setItem(mechanic.repairingCarId(), 3, new QTableWidgetItem(QString::number(row)));
        }
        ++row;
    }
}

CompanyStateWindow::~CompanyStateWindow() {
    delete ui;
}
