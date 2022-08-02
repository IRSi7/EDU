#pragma once

#include <QMainWindow>
#include <QStringList>
#include "Company.hpp"
#include <optional>

namespace Ui {
class CompanyStateWindow;
}

class CompanyStateWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CompanyStateWindow(QWidget *parent = nullptr);
    ~CompanyStateWindow();

public slots:

    void refreshTable(Company const& company);

private:
    void setupMechanicsTable();
    void setupCarsTable();

private:
    Ui::CompanyStateWindow *ui;
};

