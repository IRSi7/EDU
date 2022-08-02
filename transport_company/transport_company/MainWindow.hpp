#pragma once

#include <QMainWindow>
#include "Company.hpp"
#include "ModelParametersWindow.hpp"
#include "CompanyStateWindow.hpp"
#include "EventWindow.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow: public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void createModel(uint32_t cars, uint32_t cargoCars, uint32_t mechanics, double l);
    void service(uint32_t carId);
    void setCarRepaired(uint32_t carId);

private slots:
    void on_eventButton_pressed();
    void on_parametersButton_pressed();
    void on_openStateButton_pressed();

private:
    std::unique_ptr<Company> m_pCompany;

private:
    ModelParametersWindow* m_pModelParametersWindow;
    CompanyStateWindow* m_pStateWindow;
    EventWindow* m_pEventWindow;
    Ui::MainWindow *m_pUi;
};

