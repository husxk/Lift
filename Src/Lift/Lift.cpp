#include "Lift.h"

Lift::Lift()
{
    max_weight = d_max_weight;
    floors_to_operate = d_floors_to_operate;
    current_position = d_start_position;
    current_weight = d_current_weight;
}

Lift::Lift(uint32_t max_weight, uint32_t floors_to_operate)
{
    this->max_weight = max_weight;
    this->floors_to_operate = floors_to_operate;
    current_position = d_start_position;
    current_weight = d_current_weight;
}

uint32_t Lift::get_current_position()
{
    return current_position;
}

void Lift::weight_update(uint32_t weight, uint8_t operation)
{
    if(operation == '+')
        current_weight += weight;
    else // operation == '-'
        current_weight -= weight;
}

uint32_t Lift::get_max_weight()
{
    return max_weight;
}

uint32_t Lift::get_weight()
{
    return current_weight;
}

bool Lift::is_queue_empty()
{
    return people_in_lift.empty();
}

void Lift::add_new_floor_to_queue(uint32_t new_floor)
{
    lift_queue.push_back(new_floor);
}

void Lift::lift_move()
{
    current_position = lift_queue.front();
   // lift_queue.erase(lift_queue.begin());
}

void Lift::delete_floor_in_queue(uint32_t index)
{
    lift_queue.erase(lift_queue.begin() + index);
}
