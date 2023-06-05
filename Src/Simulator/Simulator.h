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
    std::shared_ptr<Settings> settings; // TODO change to unique
    std::unique_ptr<Floor[]> floors;
    void check_for_desired_floor();
    void check_floor_for_people();

public:
    std::shared_ptr<Lift> lift; //TODO change to unique
    Simulator();
    uint32_t get_iterations() const { return settings->get_value("iterations"); }
    void iteration();
    ~Simulator() = default;
};
