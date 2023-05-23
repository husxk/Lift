#pragma once
#include "../Person.h"

class Male:Person {
    bool is_drunk;
    bool will_puke;
    void iteration();
public:
    Male() = default;
};
