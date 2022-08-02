#include "Car.hpp"

Car::Car(Type type, Status status):
    m_type(type),
    m_status(status)
{}

void Car::setStatus(Status status) {
    m_status = status;
}

