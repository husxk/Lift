#pragma once

#include "../Person.h"

#include <iostream>
#include <memory>

class Kid: public Person
{
public:
    Kid(uint32_t, uint32_t);
    void event() override {};
    uint32_t event(uint32_t) override;
};
