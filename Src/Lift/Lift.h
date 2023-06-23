#pragma once

#include <cstdint>
#include <queue>
#include <memory>
#include <vector>

#include "../Person/Person.h"
#include "../Person/Female/Female.h"
#include "../Person/Male/Male.h"
#include "../Person/Kid/Kid.h"

/** Default value of start position of lift (on which floor lift spawn)/ */
const uint16_t d_start_position = 0;
/** Default start lift weight. */
const uint16_t d_current_weight = 0;

/**

Lift is responsible for transferring Person between floors.
*/
class Lift
{
    /** Max weight of lift. */
    uint32_t max_weight;
    /** Current lift floor. */
    uint32_t current_position;
    /** Current lift weight. */
    uint32_t current_weight;

    /** Vector of desired floor numbers of people in lift. */
    std::vector<uint32_t> lift_queue;
    /** Vector of people in lift. */
    std::vector<std::shared_ptr<Person> > people_in_lift;

public:
    /**

    Constructor of lift with fixed max weight.
    @param max_weight - max lift weight.
    */
    Lift(uint32_t);
    ~Lift() = default;

    /**

    Returns current position of lift.
    @return Floor number where lift is now.
     */
    uint32_t get_current_position() const { return current_position; };

    /**

    Returns current weight of Lift.
    @return Current weight of Lift.
    */
    uint32_t get_weight() const { return current_weight; };

    /**

    Returns max weight of lift.
    @return Max lift weight.
    */
    uint32_t get_max_weight() const { return max_weight; };

    /**

    Returns size of people_in_lift vector.
    @return Number of elemtents in people_in_lift vector.
    */
    uint32_t get_size_of_people() const { return people_in_lift.size(); };

    /**

    Returns last element of people_in_lift vector.
    @return Shared_ptr of Person at last position of people_in_lift.
    */
    std::shared_ptr<Person> get_back_person() { return people_in_lift.back(); };

    /**

    Returns whether people_in_lift vector is empty.
    @return True if people_in_lift is empty, false otherwise.
     */
    bool is_people_in_lift() const { return people_in_lift.empty(); };

    /**

    Returns first element of people_in_lift vector.
    @return Shared_ptr of Person at first position of people_in_lift.
    */
    std::shared_ptr<Person> get_front_person() { return people_in_lift.front(); }; // probably redundant

    /**

    Returns given element of people_in_lift vector.
    @param index - index in people_in_lift vector which user want to get.
    @return Shared_ptr of Person at given index.
     */
    std::shared_ptr<Person> get_person_at(uint32_t index) { return people_in_lift.at(index); };

    /**

    Push backs lift_queue vector with given floor number.
    @param new_floor - floor number to add.
    */
    void add_new_floor_to_queue(uint32_t new_floor) { lift_queue.push_back(new_floor); };

    /**

    Deletes number at given index in lift_queue vector.
    @param index - index, at which number will be erased from lift_queue.
    */
    void delete_floor_in_queue(uint32_t index) { lift_queue.erase(lift_queue.begin() + index); };

    /**
     *
    Swaps element given and value given at index in lift_queue vector.
    @param new_floor_number - new floor number which will be replacing old number.
    @param index - index of old floor number which will be replaced.
     */
    void swap_floor_number(uint32_t new_floor_number, uint32_t index) { lift_queue.at(index) = new_floor_number; }

    /**

    Updates lift weight.
    Depends on sign it is adding or subtracting from current lift weight.
    @param weight - Person weight to add/subtract from Lift current weight.
    @param operation - '+' or '-', means the operation to be made with current Lift weight and weight given.
    */
    void weight_update(uint32_t, uint8_t);

    /**

    Moves lift to front element of lift_queue vector
    */
    void lift_move() { current_position = lift_queue.front(); };

    /**

    Moves lift to given position .
    @param new_position - new Lift position.
    */
    void direct_move(uint32_t new_position) { current_position = new_position; };

    /**

    Deletes element at given index at people_in_lift vector.
    @param index - index at which user wants to erase Person at people_in_lift.
    */
    void delete_person_at(uint32_t index) { people_in_lift.erase(people_in_lift.begin() + index); };

    /**

    Push backs given Person object at people_in_lift vector.
    @param person - std::shared_ptr of Person class which user want to be added to people_in_lift.
    */
    void add_person(std::shared_ptr<Person> person) { people_in_lift.push_back(person); };

};
