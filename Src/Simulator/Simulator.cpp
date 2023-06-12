#include "Simulator.h"

// checks if current floor and desired floor of any person in lift meets,
// yes -> erase from lift + update lift weight

void Simulator::check_for_desired_floor()
{
    uint32_t a = 0;
    for (uint32_t i = 0; i < lift->get_size_of_people(); i++)
    {
        if (lift->get_person_at(i)->get_person_floor() == lift->get_current_position())
        {
            lift->weight_update(lift->get_person_at(i)->get_person_weight(), '-');
            lift->delete_floor_in_queue(i);
            lift->delete_person_at(i);
            data->add_person();
            i -= 1;
            a++;
        }
    }
    std::cout << "out: " << a << " ";
}

// checks if lift can take people from current floor
// while there is person at current floor and person can get in the lift (lift current weight + person weight <= max lift weight)
// adds person to lift, updates lift weight, adds person desired floor to queue

void Simulator::check_floor_for_people()
{
    while(!floors[lift->get_current_position()].is_person() // is_person() returns if person_queue at floor is empty
          && lift->get_weight() + floors[lift->get_current_position()].get_first_person_in_queue().get()->get_person_weight() <= lift->get_max_weight())
    {
        lift->add_person(floors[lift->get_current_position()].get_first_person_in_queue());
        floors[lift->get_current_position()].delete_person_from_floor();
        lift->weight_update(lift->get_back_person().get()->get_person_weight(), '+');
        lift->add_new_floor_to_queue(lift->get_back_person().get()->get_person_floor());
    }
}

// checks floors if there are people to give lift
// if find person at any floor, moves to this floor and iterate floors (lift move is considered as iteration)

void Simulator::check_floors_for_call()
{
    std::cout << " waits" << std::endl << std::endl;
    uint32_t current_position = lift->get_current_position();
    uint32_t max_floors = settings->get_value("floor_number");

    // checking floors above lift
    for(uint32_t i = current_position; i < max_floors; i++)
    {
        if(!floors[i].is_person())
        {
            lift->direct_move(i);
            iterate_floors();
            iterations++;
            return;
        }
    }

    // checking floors below lift
    for(uint32_t i = current_position; i > 0; i--)
    {
        if(!floors[i].is_person())
        {
            lift->direct_move(i);
            iterate_floors();
            iterations++;
            return;
        }
    }

    // checking ground floor
    if(!floors[0].is_person())
    {
        lift->direct_move(0);
        iterate_floors();
        iterations++;
    }
}

// checks people in lift in terms of special events
// if person has special events -> casts it
// at the end it is making up iterations overdue

void Simulator::check_for_special_events()
{
    uint32_t kid_number = 0;
    uint32_t additional_iterations_number = 0;

    for (uint32_t i = 0; i < lift->get_size_of_people(); i++)
    {
        if(lift->get_person_at(i)->get_person_specifier() == female)
        {
            if(lift->get_person_at(i)->get_person_random_event_chance())
            {
                data->add_random_female_event();
                lift->swap_floor_number(lift->get_person_at(i)->event(settings->get_value("floor_number")), i);
            }
        }

        if(lift->get_person_at(i)->get_person_specifier() == male)
        {
            uint32_t additional = lift->get_person_at(i)->event(0);
            additional_iterations_number += additional;
            if(additional > 0)
                data->add_random_male_event();
        }

        if(lift->get_person_at(i)->get_person_specifier() == kid)
        {
            if((lift->get_person_at(i)->get_person_random_event_chance()))
            {
                kid_number++;
                uint32_t additional = lift->get_person_at(i)->event(kid_number);
                additional_iterations_number += additional;

                if(additional > 0)
                    data->add_random_kid_event();
            }
        }
    }

    additional_iterations(additional_iterations_number);
}

// it is iterating overdue iterations

void Simulator::additional_iterations(uint32_t additional_iterations)
{
    iterations += additional_iterations;

    for(int j = 0; j < additional_iterations; j++)
        iterate_floors();
}

// iterating all floors

void Simulator::iterate_floors()
{
    for(int i = 0; i < settings->get_value("floor_number"); i++)
        floors[i].iteration();
}

// Simulation iteration
// this functions holds the responsibility of logic of this program
// it is cooperating with all objects to let simulation work

void Simulator::iteration()
{
    std::cout << "it: " << iterations << " ";

    iterate_floors();

    check_for_special_events();

    check_for_desired_floor();

    check_floor_for_people();


    std::cout << "floor: " << lift->get_current_position() << " weight: " << lift->get_weight();

    if(!lift->is_people_in_lift())
        std::cout << " next: " << lift->get_front_person().get()->get_person_floor();


    // checks for next lift move

    if(lift->is_queue_empty())
        check_floors_for_call();
    else
        lift->lift_move();

    std::cout << std::endl;
}

// shows data collected at simulation

void Simulator::show_results()
{
    std::cout << std::endl;

    std::cout << "People served: " << data->get_people_served() << std::endl;
    std::cout << "Female events: " << data->get_random_event_female() << std::endl;
    std::cout << "Male events: " << data->get_random_event_male() << std::endl;
    std::cout << "Kid events: " << data->get_random_event_kid() << std::endl;
    std::cout << "Is simulation successful: " << data->get_is_successful() << std::endl;
}

// simulator constructor is initializing all necessary objects

Simulator::Simulator()
{
    settings = std::make_unique<Settings>();
    settings->get_settings();

    if(settings->settings_default())
        lift = std::make_unique<Lift>();
    else lift = std::make_unique<Lift>(settings->get_value("lift_max_weight"));

    floors = std::make_unique<Floor[]>(settings->get_value("floor_number"));

    iterations = 0;

    data = std::make_unique<Data>();
}
