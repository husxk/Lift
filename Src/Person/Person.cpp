#include "Person.h"

void Person::set_weight()
{
//    int special_event_sp = rand() % 100;
//    if(special_event_sp > 0 && special_event_sp < 34)
//        specifier = male;
//    else if(special_event_sp >= 34 && special_event_sp < 67)
//        specifier = female;
//    else specifier = kid;

    if(specifier == male)   // to get rand() in range <a;b) use (rand() % (b-a)) + a
        weight = (rand() % 60) + 60;
    else if(specifier == female)
        weight = (rand() % 40) + 40;
    else weight = (rand() % 30) + 20;
}

void Person::set_floor(uint32_t floors_number)
{
    floor_number = (rand() % floors_number) + 1; // floors_number is limiting to <0;9>, adding +1 to have <1;10>
}


