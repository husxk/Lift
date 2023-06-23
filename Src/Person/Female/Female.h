#pragma once

#include "../Person.h"
#include <memory>

class Female: public Person
{
public:
    /**

    Sets desired floor number and special event specifier.
    @param floors_number - overall floors number in the 'building'.
    @param current_floor - floor number where object will be created.
    */
    Female(uint32_t, uint32_t);

    /**

    Checks if object has random event, if has, set another desired floor.
    If called, resets desired floor to another from current.
    Also turning off special even.
    @param max_floor_number - number floors in the 'building'.
    @return new peron's desired floor
    */
    uint32_t event(uint32_t) override;
    uint32_t event() override {return 0;};
};
