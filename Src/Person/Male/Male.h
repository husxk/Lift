#pragma once
#include "../Person.h"

class Male: public Person {
public:

    /**

    Sets desired floor number and special event specifier.
    @param floors_number - overall floors number in the 'building'.
    @param current_floor - floor number where object will be created.
    */
    Male(uint32_t, uint32_t);

    /**

    Checks if object has random event, if has, randomise iterations lost because of it.
    Also turning off special even.
    @return additional iteration that are lost because of special event
    */
    uint32_t event() override;
    uint32_t event(uint32_t) override {return 0;};
};
