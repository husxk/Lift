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
    else weight = (rand() % 30) + 20;
}

void Person::set_floor(uint32_t floors_number, uint32_t current_floor) // TODO: change this to sth better
{
    do
    {
        floor_number = rand() % (floors_number + 1); // floors_number is limiting to <0;9>, adding +1 to have <0;10>
    }while(floor_number == current_floor);  // it is not necessary to call lift for the same floor as you are
}

uint16_t Person::get_person_weight() const
{
    return weight;
}

uint32_t Person::get_person_floor() const
{
    return floor_number;
}

bool Person::get_person_random_event_chance() const
{
    return random_event;
}
