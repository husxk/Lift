#pragma once

#include <memory>
#include <iostream>
#include <cstdlib>

#include "../Lift/Lift.h"
#include "../Settings/Settings.h"
#include "../Floor/Floor.h"
#include "../Data/Data.h"

#include "../Person/Person.h"
#include "../Person/Female/Female.h"
#include "../Person/Male/Male.h"
#include "../Person/Kid/Kid.h"

class Simulator
{
    std::unique_ptr<Settings> settings;
    std::unique_ptr<Floor[]> floors;
    std::unique_ptr<Lift> lift;
    std::unique_ptr<Data> data;

    void check_for_desired_floor();
    void check_floor_for_people();

    void check_floors_for_call();

    void check_for_special_events();

    void iterate_floors();

public:
    Simulator();
    ~Simulator() = default;

    uint32_t iterations;

    uint32_t get_iterations() const { return settings->get_value("iterations"); }
    void iteration();
    void additional_iterations(uint32_t);

    bool is_lift_empty() const { return lift->is_queue_empty(); }
    void is_simulation_successful(bool is) { data->set_is_successful(is); }

    void show_results();
};
