#pragma once

#include <memory>
#include <iostream>
#include "../Lift/Lift.h"

#include "../Settings/Settings.h"

class Simulator
{
    std::shared_ptr<Settings> settings;

public:
    Simulator();
};
