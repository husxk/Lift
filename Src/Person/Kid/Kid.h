#pragma once

#include "../Person.h"
#include <memory>

class Kid: public Person
{
public:
    Kid(uint32_t, uint32_t);
    uint32_t event(uint32_t) override;
};
