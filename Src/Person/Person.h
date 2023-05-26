#pragma once

#include <cstdint>
#include <cstdlib>

class Person {

protected:
    uint16_t weight;
    uint32_t floor_number = 0;

    enum special_event_specifier
    {
        male = 1,
        female = 2,
        kid = 3
    };

    special_event_specifier specifier;

public:
    Person() = default;
    void set_weight();
    void set_floor(uint32_t, uint32_t);
};
