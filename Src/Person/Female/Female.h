#pragma once
#include "../Person.h"

#include <iostream>
#include <memory>

class Female: public Person
{
    special_event_specifier specifier = female;
public:

    Female(uint32_t, uint32_t);
    void iteration() override;
    void event() override;
};
