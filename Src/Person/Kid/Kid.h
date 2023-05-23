#pragma once
#include <stdint.h>
#include "../Person.h"

class Kid:Person {
    bool has_toys;
    static uint8_t kid_number;

public:
    Kid() = default;

};

