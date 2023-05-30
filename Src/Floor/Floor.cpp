#include "Floor.h"

Floor::Floor()
{
    floors_number += 1;
    this_floor_number = floors_number;
}

void Floor::add_person()
{
    int special_event_sp = rand() % 100;

    if(special_event_sp > 0 && special_event_sp < 34) // male
        person_queue.push(std::make_shared<Male>(floors_number,this_floor_number) );
    else if(special_event_sp >= 34 && special_event_sp < 67) // female
        person_queue.push(std::make_shared<Female>(floors_number,this_floor_number) );
    else person_queue.push(std::make_shared<Kid>(floors_number,this_floor_number) ); // kid
}

void Floor::iteration()
{
    int new_person = rand() % 100;

    if(new_person > d_person_percent)
    {
        add_person();
    }

}
