#pragma once

#include <cstdint>
#include <queue>
#include <memory>
#include <vector>

#include "../Person/Person.h"
#include "../Person/Female/Female.h"
#include "../Person/Male/Male.h"
#include "../Person/Kid/Kid.h"

/* default value of start position of lift (on which floor lift spawn) */
const uint16_t d_start_position = 0;
/* default start lift weight */
const uint16_t d_current_weight = 0;

/* Lift is responsible for transferring Person between floors  */
class Lift
{
    /* max weight of lift */
    uint32_t max_weight;
    /* current lift position */
    uint32_t current_position;
    /* current lift weight */
    uint32_t current_weight;

    /* vector of desired floor numbers of people in lift */
    std::vector<uint32_t> lift_queue;
    /* vector of people in lift */
    std::vector<std::shared_ptr<Person> > people_in_lift;

public:
    /* constructor of lift with fixed max weight*/
    Lift(uint32_t);
    ~Lift() = default;

    /* returns current position of lift */
    uint32_t get_current_position() const { return current_position; };
    /* returns current weight of lift*/
    uint32_t get_weight() const { return current_weight; };
    /* returns max weight of lift */
    uint32_t get_max_weight() const { return max_weight; };

    /* returns size of people_in_lift vector */
    uint32_t get_size_of_people() const { return people_in_lift.size(); };
    /* returns back element of people_in_lift vector */
    std::shared_ptr<Person> get_back_person() { return people_in_lift.back(); };
    /* returns whether people_in_lift vector is empty */
    bool is_people_in_lift() const { return people_in_lift.empty(); };
    /* returns front element of people_in_lift vector */
    std::shared_ptr<Person> get_front_person() { return people_in_lift.front(); };
    /* returns given element of people_in_lift vector */
    std::shared_ptr<Person> get_person_at(uint32_t index) { return people_in_lift.at(index); };

    /* push backs lift_queue vector with given number */
    void add_new_floor_to_queue(uint32_t new_floor) { lift_queue.push_back(new_floor); };
    /* deletes given index in lift_queue vector */
    void delete_floor_in_queue(uint32_t index) { lift_queue.erase(lift_queue.begin() + index); };
    /* swaps element given and value given at index in lift_queue vector */
    void swap_floor_number(uint32_t new_floor_number, uint32_t index) { lift_queue.at(index) = new_floor_number; }

    /*
    updates lift weight, depends on sign it is adding or subtracting from current lift weight */
    void weight_update(uint32_t, uint8_t);
    /* moves lift to front element of lift_queue vector */
    void lift_move() { current_position = lift_queue.front(); };
    /* moves lift to given position */
    void direct_move(uint32_t new_position) { current_position = new_position; };

    /* deletes element at given index at people_in_lift vector */
    void delete_person_at(uint32_t index) { people_in_lift.erase(people_in_lift.begin() + index); };
    /* push backs given element at people_in_lift vector */
    void add_person(std::shared_ptr<Person> person) { people_in_lift.push_back(person); };

};
