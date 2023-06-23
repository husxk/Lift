#pragma once

#include <memory>
#include <iostream>
#include <cstdlib>

#include "../Lift/Lift.h"
#include "../Settings/Settings.h"
#include "../Floor/Floor.h"
#include "../Data/Data.h"


/**

The Simulator class is responsible for running the entire simulation. It controls and manages all other classes involved in the simulation.
*/
class Simulator
{
    /** smart pointer to Settings class. */
    std::unique_ptr<Settings> settings;
    /** smart pointer to an array of Floor class. */
    std::unique_ptr<Floor[]> floors;
    /** smart pointer to Lift class. */
    std::unique_ptr<Lift> lift;
    /** smart pointer to the Data class. */
    std::unique_ptr<Data> data;

    /**

    Checks if the current floor of any person in the lift matches their desired floor.
    If a match is found, the person is removed from the lift and the lift's weight is updated.
    */
    void check_for_desired_floor();

    /**

    Checks if the lift can take people from the current floor.
    It is adding people to the lift while there are people at the current floor
    and the weight of the lift and the person being added is <= maximum lift weight.
    Each person is added to the lift, the lift weight is updated, and the person's desired floor is added to the lift's queue.
    */
    void check_floor_for_people();

    /**

     Checks the floors to see if there are people waiting to call the lift.

     If a person is found at any floor, the lift moves to that floor and iterates through the floors (each lift move is considered as an iteration).

     This is called only when the queue in the lift is empty.
     */
    void check_floors_for_call();

    /**

    Checks the people in the lift for special events.

    If a person has a special event, it is casted.

    At the end, it adjusts the iterations overdue based on additional iterations from special events.
    */
    void check_for_special_events();

    /**

    Iterates through the floors.
    */
    void iterate_floors();

    /**

    Performs additional iterations by iterating through the floors a specified number of times.

    @param additional_iterations - The number of additional iterations.
    */
    void additional_iterations(uint32_t); // probably redundant function

public:
    /** simulator constructor is initializing all necessary objects. */
    Simulator();
    ~Simulator() = default;

    /** iterations stores number of iterations made by simulation to this moment. */
    uint32_t iterations;

    /** returns total iterations that simulation will do. */
    uint32_t get_iterations() const { return settings->get_value("iterations"); }

    /**

    Makes single iteration of the simulation.

    This function is responsible for the logic of the program and cooperates with all objects to ensure the simulation runs correctly.
    */
    void iteration();

    /**

    Checks if there are any people in the lift.
    @return true if the lift is empty (no people inside the Lift), false otherwise.
    */
    bool is_lift_empty() const { return lift->is_people_in_lift(); }

    /**

    Sets the success status of the simulation.
    @param isSuccessful - True if the simulation was successful, false otherwise.
    */
    void is_simulation_successful(bool isSuccessful) { data->set_is_successful(isSuccessful); }

    /**

    Shows the data collected during the simulation.
    */
    void show_results();
};
