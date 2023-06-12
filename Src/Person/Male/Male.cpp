#include "Male.h"

Male::Male(uint32_t floors_number, uint32_t current_floor)
{
    specifier = male;
    set_floor(floors_number, current_floor);
}

uint32_t Male::event(uint32_t none)
{
    if(get_person_random_event_chance())
    {
        turn_off_random_event();
        uint32_t iterations = (rand() % 3) + 1; // <1;3> not <0;2> -> number of iterations lost by male event
        return iterations;
    }
    else return 0; // if not -> return 0 iterations to be made
}