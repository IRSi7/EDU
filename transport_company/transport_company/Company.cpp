#include "Company.hpp"

#include <algorithm>
#include <cmath>
#include <random>
#include <exception>

Company::Company(uint32_t cars, uint32_t cargoCars, uint32_t mechanics, double lCoefficient):
    m_mechanics(mechanics, Mechanic(Mechanic::Skill::PASSANGER_ONLY)),
    m_cargoCars(cargoCars),
    m_cars(cars, Car(Car::Type::PASSENGER)),
    m_lCoefficient(lCoefficient)
{
    m_passangerOnlyMechanics = std::lround(mechanics / lCoefficient);
    std::fill(m_mechanics.begin() + m_passangerOnlyMechanics, m_mechanics.end(), Mechanic(Mechanic::Skill::CARGO_AND_PASSANGER));
    std::fill(m_cars.begin(), m_cars.begin() + cargoCars, Car(Car::Type::CARGO));
}

bool Company::serviceRequest(uint32_t carId) {
    assert(carId < m_cars.size());

    auto findNext = [this] (auto it) {
        return std::find_if(it, m_mechanics.end(),
            [] (auto const& m) {
                return m.isFree();
            }
        );
    };

    auto& car = m_cars[carId];

    auto it = m_mechanics.begin();

    // begining from cargo and passanger mechanics
    if (car.type() == Car::Type::CARGO) {
        it += m_passangerOnlyMechanics;
    }

    std::vector<std::vector<Mechanic>::iterator> freeMechanics;
    for (it = findNext(it); it != m_mechanics.end(); it = findNext(it + 1)) {
        freeMechanics.push_back(it);
    }
    if (freeMechanics.empty()) {
        return false;
    }

    size_t randomId = rand() % freeMechanics.size();
    auto& randomMechanic = *freeMechanics[randomId];
    randomMechanic.setRepairingCarId(carId);
    car.setStatus(Car::Status::REPAIRING);

    emit stateChanged(*this);
    return true;
}

void Company::setCarRepaired(uint32_t carId) {
    assert(carId < m_cars.size());

    m_cars[carId].setStatus(Car::Status::GOOD);
    auto it = std::find_if(m_mechanics.begin(), m_mechanics.end(),
        [&carId] (Mechanic const& mechanic) {
            return mechanic.repairingCarId() == static_cast<int32_t>(carId);
        }
    );
    if (it == m_mechanics.end()) {
        throw std::invalid_argument("there is no mechanic repairing car with the id");
    }
    it->free();
    emit stateChanged(*this);
}
