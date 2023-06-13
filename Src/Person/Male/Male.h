#pragma once
#include "../Person.h"

class Male: public Person {
public:
    /* sets desired floor number and special event specifier */
    Male(uint32_t, uint32_t);
    /* checks if object has random event -> randomise iterations lost because of it, also turning off special even */
    uint32_t event(uint32_t) override;
};
