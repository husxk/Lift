#pragma once
#include "../Person.h"

class Female:Person{
    bool is_decided;
    void change_floor_number();
    void iteration();
public:
    Female() = default;
};
