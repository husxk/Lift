#pragma once
#include "../Person.h"

class Male: public Person {
    special_event_specifier specifier = male;
public:

    Male(uint32_t, uint32_t);
    void iteration() override;
    void event() override;
};
