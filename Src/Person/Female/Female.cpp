#include "Female.h"

Female::Female(uint32_t floors_number, uint32_t current_floor)
{
    int decided = rand() % 100;
    if(decided <= d_decided_percent) is_decided = true;
    else is_decided = false;

    set_weight();
    set_floor(floors_number, current_floor);
};
