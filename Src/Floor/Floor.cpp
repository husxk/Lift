#include "Floor.h"

bool Floor::is_person()
{
    return person_queue.empty();
}

Floor::Floor() // index from 0
{
    this_floor_number = floors_number;
    floors_number += 1;
}

void Floor::add_person()
{
    int special_event_sp = rand() % 100;

    if(special_event_sp > 0 && special_event_sp < 34) // male
        person_queue.push(std::make_shared<Male>(floors_number, this_floor_number) );
    else if(special_event_sp >= 34 && special_event_sp < 67) // female
        person_queue.push(std::make_shared<Female>(floors_number, this_floor_number) );
    else person_queue.push(std::make_shared<Kid>(floors_number, this_floor_number) ); // kid
}

void Floor::iteration() // TODO: complete this
{
    int new_person = rand() % 100;

    if(new_person > 0)
        add_person();
}

std::shared_ptr<Person> Floor::get_first_person_in_queue()
{
    return person_queue.front();
}

void Floor::delete_person_from_floor()
{
    person_queue.pop();
}