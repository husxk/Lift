#pragma once

#include "../Person.h"
#include <memory>

class Female: public Person
{
public:
    /* sets desired floor number and special event specifier */
    Female(uint32_t, uint32_t);
    /*
    if object has random event -> set another desired floor
    if called, resets desired floor to another from current, also turning off special event */
    uint32_t event(uint32_t) override;
};
