#pragma once

#include <cstdint>
#include <iostream>

class Car {
public:
    enum class Type: uint8_t {
        PASSENGER,
        CARGO
    };

    enum class Status: uint8_t {
        REPAIRING,
        GOOD
    };

public:
    Car(Type type, Status status = Status::GOOD);

    Car(Car const&) = default;
    Car(Car&&) = default;
    Car& operator=(Car const&) = default;
    Car& operator=(Car&&) = default;
    ~Car() = default;

public:
    Type type() const { return m_type; }
    Status status() const { return m_status; };
    void setStatus(Status status);

private:
    Type m_type;
    Status m_status;
};


std::ostream& operator<<(std::ostream& out, Car::Type type);
