#pragma once

// TODO: add container for floor list and operations on it, probably std::queue<uint16_t>

#include <cstdint>

constexpr uint16_t d_max_weight = 800; // in kg
constexpr uint16_t d_floors_to_operate = 5; // in range <0;5>
constexpr uint16_t d_start_position = 0; //  start floor
constexpr uint16_t d_current_weight = 0; // start weight

class Lift
{
    uint32_t max_weight; // in kg
    uint32_t floors_to_operate; // range <0;floors_to_operate>
    uint32_t current_position; // current_position at start = 0
    uint32_t current_weight;

public:
    Lift();
    Lift(uint32_t, uint32_t);

    uint32_t get_current_position();

    void set_new_position(uint32_t);

    uint32_t get_floors_to_operate();

    uint32_t get_weight();

    void weight_update(uint32_t, uint8_t);
};