#pragma once

#include "../Person.h"

#include <iostream>
#include <memory>

class Kid: public Person
{
    special_event_specifier specifier = kid;
public:

    Kid(uint32_t, uint32_t);
    void iteration() override;
    void event() override;
};
