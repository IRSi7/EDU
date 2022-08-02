#include "Mechanic.hpp"

Mechanic::Mechanic(Skill skill):
    m_skill(skill),
    m_serviced(0),
    m_repairingCarId(-1)
{}

void Mechanic::setSkill(Skill skill) {
    m_skill = skill;
}

void Mechanic::addServiced() {
    ++m_serviced;
}

void Mechanic::setRepairingCarId(uint32_t carId) {
    m_repairingCarId = carId;
}
