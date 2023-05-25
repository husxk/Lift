#pragma once

#include <cstdint>
#include <cstdlib>

class Person {

protected:
    uint16_t weight;
    uint32_t floor_number;

    enum special_event_specifier
    {
        male = 1,
        female = 2,
        kid = 3
    };

    special_event_specifier specifier;

public:
    explicit Person(int32_t);
    bool special_event();
};
