#pragma once
#include "../Person.h"

#include <iostream>

const int d_decided_percent = 90; // % needed to be decided and not have special event

class Female: protected Person{
    bool is_decided;
    special_event_specifier specifier = female;
    //void change_floor_number();
public:
    explicit Female(uint32_t, uint32_t);
   // void iteration();
};
