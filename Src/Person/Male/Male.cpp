#include "Male.h"

Male::Male(uint32_t floors_number, uint32_t current_floor)
{
    specifier = male;
    set_floor(floors_number, current_floor);
}

// if object has random event -> randomise iterations lost because of it

uint32_t Male::event(uint32_t none)
{
    uint32_t iterations = 0;

    if(get_person_random_event_chance())
    {
        turn_off_random_event();
        iterations = (rand() % 3) + 1; // <1;3> not <0;2> -> number of iterations lost by male event
    }

    return iterations; // if not -> return 0 iterations to be made
}