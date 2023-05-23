#include "Floor.h"

void Floor::iteration()
{
    if(person_queue.size() == d_max_person_on_floor) return; // if floor has max capacity -> return
    else
    {
        if(rand() % 100 > 50)
        {
            person_queue.emplace(person());

            int specifier = rand() % 100;

            if(specifier < 34)
                person_queue.back().specifier = person::male;
            else if (specifier > 34 && specifier < 67)
                person_queue.back().specifier = person::female;
            else
                person_queue.back().specifier = person::kid;



        }
        return;
    }

}
