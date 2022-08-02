#pragma once

#include <cstdint>

class Mechanic {
public:
    enum class Skill {
        PASSANGER_ONLY,
        CARGO_AND_PASSANGER
    };

public:
    explicit Mechanic(Skill skill);

    Mechanic(Mechanic const&) = default;
    Mechanic(Mechanic&&) = default;
    Mechanic& operator=(Mechanic const&) = default;
    Mechanic& operator=(Mechanic&&) = default;
    ~Mechanic() = default;

    Skill skill() const { return m_skill; }
    void setSkill(Skill skill);

    bool isFree() const { return m_repairingCarId == -1; };
    void free() { m_repairingCarId = -1; }

    uint32_t serviced() const { return m_serviced; };
    void addServiced();

    int32_t repairingCarId() const { return m_repairingCarId; }
    void setRepairingCarId(uint32_t carId);

private:
    Skill m_skill;
    uint32_t m_serviced;
    int32_t m_repairingCarId;
};

