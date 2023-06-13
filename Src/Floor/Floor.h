#pragma once

#include <cstdint>
#include <queue>
#include <cstdlib>

#include "../Person/Person.h"
#include "../Person/Female/Female.h"
#include "../Person/Male/Male.h"
#include "../Person/Kid/Kid.h"

/* % needed to spawn new Person */
const int d_person_percent = 90;

/* Floor is responsible for containing Person, creating Person and transferring Person to Lift */
class Floor
{
    /* field to store max floor number to give for Person while setting floor */
    inline static uint32_t floors_number = 0;
    /* field to store current floor number to give for Person while setting floor */
    uint32_t this_floor_number;

    /* stores Person objects at floor level in queue */
    std::queue<std::shared_ptr<Person> > person_queue;

    /* deciding who will spawn at floor and push backs to person_queue queue */
    void add_person();

public:
    /* assigns floor number and increments total floors number */
    Floor();
    ~Floor() = default;

    /*
    checks if chance for new person meets requirements in current iteration
    if requirements meets -> add new person to this floor*/
    void iteration();
    /* returns front element of person_queue queue */
    std::shared_ptr<Person> get_first_person_in_queue() { return person_queue.front(); };

    /* returns if person_queue queue is empty */
    bool is_person() const { return person_queue.empty(); };

    /* pops person_queue queue */
    void delete_person_from_floor() { person_queue.pop(); };

};