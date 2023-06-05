#pragma once

#include <memory>
#include <iostream>
#include <cstdlib>

#include "../Lift/Lift.h"
#include "../Settings/Settings.h"
#include "../Floor/Floor.h"

#include "../Person/Person.h"
#include "../Person/Female/Female.h"
#include "../Person/Male/Male.h"
#include "../Person/Kid/Kid.h"

class Simulator
{
    std::unique_ptr<Settings> settings;
    std::unique_ptr<Floor[]> floors;
    std::unique_ptr<Lift> lift;

    void check_for_desired_floor();
    void check_floor_for_people();

    void check_floors_for_call();

public:
    Simulator();
    ~Simulator() = default;

    uint32_t get_iterations() const { return settings->get_value("iterations"); }
    void iteration();
};
