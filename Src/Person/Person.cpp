#include "Person.h"

Person::Person()
{
    set_weight();
    set_random_event();
}

void Person::set_random_event()
{
    int event_chance = rand() % 100;
    if(event_chance <= d_event_chance) random_event = true;
    else random_event = false;
}

void Person::set_weight()
{
    if(specifier == male)   // to get rand() in range <a;b) use (rand() % (b-a)) + a
        weight = (rand() % 60) + 60;
    else if(specifier == female)
        weight = (rand() % 40) + 40;
    else weight = (rand() % 30) + 30;
}

void Person::set_floor(uint32_t floors_number, uint32_t current_floor) // TODO: change this to sth better
{
    do
    {
        floor_number = rand() % floors_number; // floors_number is limiting to <0;10>
    } while(floor_number == current_floor);  // it is not necessary to call lift for the same floor as you are
}