#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    m_pModelParametersWindow(nullptr),
    m_pStateWindow(nullptr),
    m_pEventWindow(nullptr),
    m_pUi(new Ui::MainWindow)
{
    m_pUi->setupUi(this);
}

MainWindow::~MainWindow() {
    delete m_pUi;
}

void MainWindow::createModel(uint32_t cars, uint32_t cargoCars, uint32_t mechanics, double l) {
    m_pCompany = std::make_unique<Company>(cars, cargoCars, mechanics, l);

    if (not m_pStateWindow) {
        m_pStateWindow = new CompanyStateWindow(this);
    }
    connect(m_pCompany.get(), &Company::stateChanged, m_pStateWindow, &CompanyStateWindow::refreshTable);
    m_pStateWindow->refreshTable(*m_pCompany);

    if (not m_pEventWindow) {
        m_pEventWindow = new EventWindow(this);
    }
    connect(m_pEventWindow, &EventWindow::serviceRequested, this, &MainWindow::service);
    connect(m_pEventWindow, &EventWindow::carRepaired, this, &MainWindow::setCarRepaired);
    connect(m_pCompany.get(), &Company::stateChanged, m_pEventWindow, &EventWindow::onCompanyStateChanged);
    m_pEventWindow->updateBoxes(*m_pCompany);
}

void MainWindow::service(uint32_t carId) {
    if (not m_pCompany->serviceRequest(carId)) {
        QMessageBox::warning(this, "All mechanics are busy", "There are no free mechanics. Please try later.");
    }
}

void MainWindow::setCarRepaired(uint32_t carId) {
    m_pCompany->setCarRepaired(carId);
}

void MainWindow::on_eventButton_pressed() {
    if (not m_pEventWindow) {
        m_pEventWindow = new EventWindow(this);
    }
    m_pEventWindow->show();
}

void MainWindow::on_parametersButton_pressed() {
    if (not m_pModelParametersWindow) {
        m_pModelParametersWindow = new ModelParametersWindow(this);
    }
    connect(m_pModelParametersWindow, &ModelParametersWindow::modelParametersChanged, this, &MainWindow::createModel);
    m_pModelParametersWindow->show();
}

void MainWindow::on_openStateButton_pressed() {
    if (not m_pStateWindow) {
        m_pStateWindow = new CompanyStateWindow(this);
    }
    m_pStateWindow->show();
}

