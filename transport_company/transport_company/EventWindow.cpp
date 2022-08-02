#include "EventWindow.hpp"
#include "ui_EventWindow.h"

#include <QMessageBox>

EventWindow::EventWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EventWindow)
{
    ui->setupUi(this);
}

EventWindow::~EventWindow() {
    delete ui;
}

void EventWindow::onCompanyStateChanged(Company const& company) {
    updateBoxes(company);
}

void EventWindow::updateBoxes(Company const& company) {
    ui->serviceCarIdBox->clear();
    ui->repairCarIdBox->clear();
    for (size_t i = 0; i < company.cars().size(); ++i) {
        if (company.cars()[i].status() == Car::Status::GOOD) {
            ui->serviceCarIdBox->addItem(QString::number(i));
        } else {
            ui->repairCarIdBox->addItem(QString::number(i));
        }
    }
}

void EventWindow::on_requestPushButton_pressed() {
    if (ui->serviceCarIdBox->count() != 0) {
        emit serviceRequested(ui->serviceCarIdBox->currentText().toUInt());
    }
}

void EventWindow::on_repairPushButton_pressed() {
    if (ui->repairCarIdBox->count() != 0) {
        emit carRepaired(ui->repairCarIdBox->currentText().toUInt());
        //m_pCompany->setCarRepaired(ui->repairCarIdBox->currentText().toUInt());
    }
}

