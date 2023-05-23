#pragma once

#include <cstdint>
#include <queue>
#include <memory>

const uint16_t d_max_weight = 800; // in kg
const uint16_t d_floors_to_operate = 5; // in range <0;5>
const uint16_t d_start_position = 0; //  start floor
const uint16_t d_current_weight = 0; // start weight

class Lift
{
    uint32_t max_weight; // in kg
    uint32_t floors_to_operate; // range <0;floors_to_operate>
    uint32_t current_position; // current_position at start = 0
    uint32_t current_weight;

    std::queue<uint32_t> lift_queue; // floor number queue

public:
    Lift();
    Lift(uint32_t, uint32_t);

    uint32_t get_floors_to_operate();

    uint32_t get_current_position();
    void set_new_position(uint32_t);

    void add_new_floor_to_queue(uint32_t);
    void delete_current_floor_in_queue();

    uint32_t get_weight();
    void weight_update(uint32_t, uint8_t);

    void lift_move();


};