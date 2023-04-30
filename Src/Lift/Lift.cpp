#include "Lift.h"

Lift::Lift()
{
    this->max_weight = d_max_weight;
    this->floors_to_operate = d_floors_to_operate;
    this->current_position = d_start_position;
    this->current_weight = d_current_weight;
}

Lift::Lift(uint32_t max_weight, uint32_t floors_to_operate)
{
    this->max_weight = max_weight;
    this->floors_to_operate = floors_to_operate;
    this->current_position = d_start_position;
    this->current_weight = d_current_weight;
}

uint32_t Lift::get_current_position()
{
    return this->current_position;
}

void Lift::set_new_position(uint32_t new_position)
{
    this->current_position = new_position;
}

uint32_t Lift::get_floors_to_operate()
{
    return this->floors_to_operate;
}

void Lift::weight_update(uint32_t weight, uint8_t operation)
{
    if(operation == '+')
        this->current_weight += weight;
    else // operation == '-'
        this->current_weight -= weight;
}

uint32_t Lift::get_weight()
{
    return this->current_weight;
}
