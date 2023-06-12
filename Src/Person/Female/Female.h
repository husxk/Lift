#pragma once

#include "../Person.h"

#include <iostream>
#include <memory>

class Female: public Person
{
public:

    Female(uint32_t, uint32_t);
    uint32_t event(uint32_t) override;
    void event() override {};
};
