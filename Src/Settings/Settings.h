#pragma once

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <unordered_map>

/** Default number of iterations to be made in simulation. */
const uint32_t default_iterations = 100;
/** Default max lift weight. */
const uint32_t default_lift_max_weight = 800;
/** Default number of floors in the 'building', includes ground floor + 10 floors. */
const uint32_t default_floor_number = 11;

/**

The Settings class contains the settings of the simulation.
*/
class Settings
{
    /**

    The container for the simulation's settings.
    The possible settings include "iterations", "lift_max_weight", and "floors".
    */
    std::unordered_map<std::string, uint32_t> settings;

    /**

     Gets settings from the user.
     @param what - The prompt message displayed to the user.
     @return The input value provided by the user.
     */
    uint32_t get_input(std::string);
    /** Contains if simulation is made by default settings. */
    bool is_default;

public:
    /** Gets if user want to input his data. */
    Settings();
    ~Settings() = default;

    /**
    Returns the value from the map at the given key.
    @param key - The key to get the value from the map.
    @return The value at the given key.
    */
    uint32_t get_value(std::string key) const { return settings.at(key); };

    /**

    Returns whether simulation is default.
    @return True if it is default simulation, false otherwise.
    */
    bool settings_default() const { return is_default; };

    /**

     Gets input from the user about the simulation settings (iterations, floor number, and lift maximum weight).
     It also saves the settings to the settings map.
     */
    void get_settings();
};
