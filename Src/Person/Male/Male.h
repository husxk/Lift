#pragma once
#include "../Person.h"

class Male: public Person {
public:

    Male(uint32_t, uint32_t);
    uint32_t event(uint32_t) override;
};
