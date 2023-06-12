#include "Lift.h"

// constructors assigns values to lift depending on if simulation is made by default or on user's input

Lift::Lift()
{
    max_weight = d_max_weight;
    current_position = d_start_position;
    current_weight = d_current_weight;
}

Lift::Lift(uint32_t max_weight)
{
    this->max_weight = max_weight;
    current_position = d_start_position;
    current_weight = d_current_weight;
}

// updates lift weight, depends on sign it is adding or subtracting from current lift weight

void Lift::weight_update(uint32_t weight, uint8_t operation)
{
    if(operation == '+')
        current_weight += weight;
    else // operation == '-'
        current_weight -= weight;
}
