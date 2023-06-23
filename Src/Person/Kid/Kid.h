#pragma once

#include "../Person.h"
#include <memory>

class Kid: public Person
{
public:
    /**

    Sets desired floor number and special event specifier.
    @param floors_number - overall floors number in the 'building'.
    @param current_floor - floor number where object will be created.
    */
    Kid(uint32_t, uint32_t);

    /**

    Checks if object has random event, if has, randomise iterations lost because of it.
    Also turning off special even.
    If there is more than 1 Kid object with special event, then this special event can occur.
    @param kid_number - number of Kids in the lift.
    @return additional iteration that are lost because of special event
    */
    uint32_t event(uint32_t) override;
    uint32_t event() override {return 0;};
};
