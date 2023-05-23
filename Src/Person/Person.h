#pragma once
#include <stdint.h>

class Person {

protected:
    uint16_t weight;
    uint32_t floor_number;

    enum special_event_specifier
    {
        male = 1,
        female = 2,
        kid = 4
    };

    special_event_specifier specifier;

public:
    Person() = default;
};
