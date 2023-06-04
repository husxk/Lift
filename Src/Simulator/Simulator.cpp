#include "Simulator.h"

void Simulator::check_for_desired_floor()
{
    for (uint32_t i = 0; i < lift->people_in_lift.size(); i++) {
        if (lift->people_in_lift.at(i).get()->get_person_floor() == lift->get_current_position())
        {
            lift->weight_update(lift->people_in_lift.at(i)->get_person_weight(), '-');
            lift->delete_floor_in_queue(i);
            lift->people_in_lift.erase(lift->people_in_lift.begin() + i);
            i -= 1;
        }
    }
}

void Simulator::iteration()
{
    // iterate for all floors
    for(int i = 0; i < settings->get_value("floor_number"); i++)
        floors[i].iteration();

    // checks if current floor and desired floor of any person in lift meets,
    // yes -> erase from lift + update lift weight
    check_for_desired_floor();

    // while there is person at current floor and person can get in the lift (lift current weight + person weight <= max lift weight)
    // adds person to lift
    // TODO: factorise this to functions
    while(!floors[lift->get_current_position()].is_person() // is_person() returns if person_queue at floor is empty
            && lift->get_weight() + floors[lift->get_current_position()].get_first_person_in_queue()->get_person_weight() <= lift->get_max_weight())
    {
        lift->people_in_lift.push_back(floors[lift->get_current_position()].get_first_person_in_queue());
        floors[lift->get_current_position()].delete_person_from_floor();
        lift->weight_update(lift->people_in_lift.back()->get_person_weight(), '+');
        lift->add_new_floor_to_queue(lift->people_in_lift.back()->get_person_floor());
    }

    std::cout << "floor: " << lift->get_current_position() << " weight: " << lift->get_weight() << " next: " << lift->people_in_lift.front()->get_person_floor();
    std::cout << std::endl;

    if(lift->is_queue_empty())
    {
        return;
    }
    else
        lift->lift_move(); // TODO: add checking for 0 floors in queue
}


Simulator::Simulator() // TODO: add data collector class
{
    settings = std::make_shared<Settings>();
    settings->get_settings();

    if(settings->settings_default())
        lift = std::make_shared<Lift>();
    else lift = std::make_shared<Lift>(settings->get_value("lift_max_weight"), settings->get_value("floor_number"));

    floors = std::make_unique<Floor[]>(settings->get_value("floor_number"));

}
