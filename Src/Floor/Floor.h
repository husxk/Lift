#pragma once

#include <cstdint>
#include <queue>
#include <cstdlib>

#include "../Person/Person.h"
#include "../Person/Female/Female.h"
#include "../Person/Male/Male.h"
#include "../Person/Kid/Kid.h"

/** % needed to spawn new Person at floor. */
const int d_person_percent = 90;

/** Floor is responsible for containing Person, creating Person and transferring Person to Lift. */
class Floor
{
    /**

    Field to store max floor number to give for Person.
    It is incremented when constructor of Floor is called.
    */
    inline static uint32_t floors_number = 0;

    /** Field to store current floor number to give for Person */
    uint32_t this_floor_number;

    /** Stores Person objects at floor level in queue */
    std::queue<std::shared_ptr<Person> > person_queue;

    /**

    Deciding who will spawn at floor.
    Push backs to person_queue queue.
    */
    void add_person();

public:
    /**

    Assigns floor number and increments total floors number.
    Indexes from 0.
    */
    Floor();
    ~Floor() = default;

    /**

    Checks if chance for new person meets requirements in current iteration.
    If requirements meets -> add new person to this floor.
    */
    void iteration();

    /**
    Returns front element of person_queue queue
    @return std::shared_ptr Person object at front of person queue
    */
    std::shared_ptr<Person> get_first_person_in_queue() { return person_queue.front(); };

    /**
    Returns if person_queue queue is empty.
    @return True if person_queue is empty, false otherwise.
    */
    bool is_person() const { return person_queue.empty(); };

    /** Pops person_queue queue */
    void delete_person_from_floor() { person_queue.pop(); };

};