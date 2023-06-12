#pragma once

#include <cstdint>
#include <queue>
#include <memory>
#include <vector>

#include "../Person/Person.h"
#include "../Person/Female/Female.h"
#include "../Person/Male/Male.h"
#include "../Person/Kid/Kid.h"

const uint16_t d_max_weight = 800;  // max weight
const uint16_t d_start_position = 0; //  start floor
const uint16_t d_current_weight = 0; // start weight

class Lift
{
    uint32_t max_weight;
    uint32_t current_position;  // current_position, at start = 0
    uint32_t current_weight;    // at start = 0

    std::vector<uint32_t> lift_queue; // floor numbers vector
    std::vector<std::shared_ptr<Person> > people_in_lift; // people holder in lift

public:

    Lift();
    Lift(uint32_t);
    ~Lift() = default;

    uint32_t get_current_position() const { return current_position; };
    uint32_t get_weight() const { return current_weight; };
    uint32_t get_max_weight() const { return max_weight; };

    uint32_t get_size_of_people() const { return people_in_lift.size(); };
    std::shared_ptr<Person> get_back_person() { return people_in_lift.back(); };
    bool is_people_in_lift() const { return people_in_lift.empty(); };
    std::shared_ptr<Person> get_front_person() { return people_in_lift.front(); };
    std::shared_ptr<Person> get_person_at(uint32_t index) { return people_in_lift.at(index); };
    bool is_queue_empty() const { return people_in_lift.empty(); };

    void add_new_floor_to_queue(uint32_t new_floor) { lift_queue.push_back(new_floor); };
    void delete_floor_in_queue(uint32_t index) { lift_queue.erase(lift_queue.begin() + index); }; // erases value at given index
    void swap_floor_number(uint32_t new_floor_number, uint32_t index) { lift_queue.at(index) = new_floor_number; } // swaps value given and value at given index

    void weight_update(uint32_t, uint8_t);
    void lift_move() { current_position = lift_queue.front(); }; // moves lift to next floor in queue
    void direct_move(uint32_t new_position) { current_position = new_position; }; // moves lift to direct floor

    void delete_person_at(uint32_t index) { people_in_lift.erase(people_in_lift.begin() + index); }; // deletes person at given index
    void add_person(std::shared_ptr<Person> person) { people_in_lift.push_back(person); };

};
