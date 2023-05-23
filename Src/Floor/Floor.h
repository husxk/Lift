#pragma once

#include <cstdint>
#include <queue>
#include <cstdlib>

const uint8_t d_max_person_on_floor = 2;

class Floor
{

    struct person
    {
        uint16_t weight;
        uint32_t floor_number;

        enum special_event_specifier
        {
            male = 1,
            female = 2,
            kid = 4
        };

        special_event_specifier specifier;

    };

    std::queue<person> person_queue;

public:
    Floor() = default;
    void iteration();

};