#pragma once

#include <QMainWindow>
#include "Company.hpp"
#include <memory>

namespace Ui {
class EventWindow;
}

class EventWindow: public QMainWindow {
    Q_OBJECT

public:
    EventWindow(QWidget *parent = nullptr);
    ~EventWindow();

    void updateBoxes(Company const& company);

public slots:
    void onCompanyStateChanged(Company const& company);

signals:
    void serviceRequested(uint32_t carId);
    void carRepaired(uint32_t carId);

private slots:
    void on_requestPushButton_pressed();
    void on_repairPushButton_pressed();

private:
    Ui::EventWindow *ui;
};

