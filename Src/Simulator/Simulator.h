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

/* Simulation is responsible for running whole simulation, it controls all of other classes and manages them  */
class Simulator
{
    /* smart pointer to Settings class */
    std::unique_ptr<Settings> settings;
    /* smart pointer to array of Floor class */
    std::unique_ptr<Floor[]> floors;
    /* smart pointer to Lift class */
    std::unique_ptr<Lift> lift;
    /* smart pointer to Data class */
    std::unique_ptr<Data> data;

    /*
    checks if current floor and desired floor of any person in lift meets,
    yes -> erase from lift + update lift weight */
    void check_for_desired_floor();
    /*
    checks if lift can take people from current floor
    while there is person at current floor and person can get in the lift (lift current weight + person weight <= max lift weight)
    adds person to lift, updates lift weight, adds person desired floor to queue */
    void check_floor_for_people();
    /*
    checks floors if there are people to give lift
    if find person at any floor, moves to this floor and iterate floors (lift move is considered as iteration)
     it is called only if queue in lift is empty*/
    void check_floors_for_call();
/*
    checks people in lift in terms of special events
    if person has special events -> casts it
    at the end it is making up iterations overdue */
    void check_for_special_events();
    /*
    iterating floors*/
    void iterate_floors();
    /*
    it is iterating overdue iterations
     (iterating floors x times)*/
    void additional_iterations(uint32_t); // probably redundant function

public:
    /* simulator constructor is initializing all necessary objects */
    Simulator();
    ~Simulator() = default;

    /* iterations stores number of iterations made by simulation to this moment */
    uint32_t iterations;

    /*returns total iterations that simulation will do*/
    uint32_t get_iterations() const { return settings->get_value("iterations"); }

    /*
    Simulation iteration
    this functions holds the responsibility of logic of this program
    it is cooperating with all objects to let simulation work */
    void iteration();
    /* returns if there is any person in lift  */
    bool is_lift_empty() const { return lift->is_queue_empty(); }
    /* sets if simulation was successful */
    void is_simulation_successful(bool is) { data->set_is_successful(is); }

    /* shows data collected at simulation */
    void show_results();
};
