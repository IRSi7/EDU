#pragma once

#include "Car.hpp"
#include "Mechanic.hpp"

#include <QObject>
#include <cstdint>
#include <vector>

class Company: public QObject {
    Q_OBJECT
public:
    Company(uint32_t cars, uint32_t cargoCars, uint32_t mechanics, double lCoefficient);

    bool serviceRequest(uint32_t carId);
    void setCarRepaired(uint32_t carId);

    std::vector<Mechanic> const& mechanics() const { return m_mechanics; }
    std::vector<Car> const& cars() const { return m_cars; }

signals:
    void stateChanged(Company const& company);

private:
    uint32_t m_passangerOnlyMechanics;
    std::vector<Mechanic> m_mechanics;

    uint32_t m_cargoCars;
    std::vector<Car> m_cars;

    double m_lCoefficient;
};

