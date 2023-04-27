#pragma once

#include <memory>
#include <iostream>

#include "../Settings/Settings.h"

class Simulator
{
    std::shared_ptr<Settings> settings;

public:
    Simulator();
};
