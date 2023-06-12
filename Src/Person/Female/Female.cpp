#include "Female.h"

Female::Female(uint32_t floors_number, uint32_t current_floor)
{
    specifier = female;
    set_floor(floors_number, current_floor);
}

uint32_t Female::event(uint32_t max_floor_number)
{
    if(get_person_random_event_chance())
    {
        set_floor(max_floor_number, get_person_floor());
        turn_off_random_event();
        return get_person_floor();
    }
    else return get_person_floor();
}