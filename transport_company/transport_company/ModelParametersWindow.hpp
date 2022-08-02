#pragma once

#include <QMainWindow>
#include <memory>
#include "Company.hpp"


namespace Ui {
class ModelParametersWindow;
}

class ModelParametersWindow: public QMainWindow {
    Q_OBJECT

public:
    explicit ModelParametersWindow(QWidget *parent = nullptr);
    ~ModelParametersWindow();

signals:
    void modelParametersChanged(uint32_t cars, uint32_t cargoCars, uint32_t mechanics, double l);

private slots:

    void on_setParametersButton_pressed();

private:
    Ui::ModelParametersWindow *ui;
};

