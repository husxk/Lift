#include "Lift.h"

Lift::Lift()
{
    max_weight = d_max_weight;
    floors_to_operate = d_floors_to_operate;
    current_position = d_start_position;
    current_weight = d_current_weight;

    lift_status = std::make_shared<lift_statuses>(stay);
}

Lift::Lift(uint32_t max_weight, uint32_t floors_to_operate)
{
    this->max_weight = max_weight;
    this->floors_to_operate = floors_to_operate;
    current_position = d_start_position;
    current_weight = d_current_weight;

    lift_status = std::make_shared<lift_statuses>(stay);
}

uint32_t Lift::get_current_position()
{
    return current_position;
}

void Lift::set_new_position(uint32_t new_position)
{
    current_position = new_position;
}

uint32_t Lift::get_floors_to_operate()
{
    return floors_to_operate;
}

void Lift::weight_update(uint32_t weight, uint8_t operation)
{
    if(operation == '+')
        current_weight += weight;
    else // operation == '-'
        current_weight -= weight;
}

uint32_t Lift::get_weight()
{
    return current_weight;
}

void Lift::add_new_floor_to_queue(uint32_t new_floor)
{
    lift_queue.push(new_floor);
}

void Lift::delete_current_floor_in_queue()
{
    lift_queue.pop();
}

void Lift::lift_move()
{
    current_position = lift_queue.front();
    lift_queue.pop();
    change_lift_status();
}

void Lift::change_lift_status()
{
    if(lift_queue.empty()) lift_status = std::make_shared<lift_statuses>(stay);
    else if(lift_queue.front() > get_current_position()) lift_status = std::make_shared<lift_statuses>(up);
    else lift_status = std::make_shared<lift_statuses>(down);
}

lift_statuses Lift::get_lift_status()
{
    return *lift_status;
}
