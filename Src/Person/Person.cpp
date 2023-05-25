#include "Person.h"

Person::Person(int32_t floor_number_)
{
    int special_event_sp = rand() % 100;

    if(special_event_sp > 0 && special_event_sp < 34)
        specifier = male;
    else if(special_event_sp >= 34 && special_event_sp < 67)
        specifier = female;
    else specifier = kid;

    if(specifier == male)   // to get rand() in range <a;b) use (rand() % (b-a)) + a
        weight = (rand() % 60) + 60;
    else if(specifier == female)
        weight = (rand() % 40) + 40;
    else weight = (rand() % 30) + 20;

    floor_number = rand() % floor_number_ + 1 ;

}
