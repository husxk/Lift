#pragma once

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <unordered_map>

/* default number of iterations to be made */
const uint32_t default_iterations = 100;
/* default lift max weight */
const uint32_t default_lift_max_weight = 800;
/* default number of floors */
const uint32_t default_floor_number = 11; // its 0 (ground floor) + 10 floors

/* Settings contains settings of simulation */
class Settings
{
    /*  container for simulation's settings */
    std::unordered_map<std::string, uint32_t> settings; // iterations, lift_max_weight, floors,
    /* gets input from user */
    uint32_t get_input(std::string);
    /* contains if we want to do default simulation */
    bool is_default;

public:
    /* gets if user want to input his data */
    Settings();
    ~Settings() = default;

    /* returns value from map at given key */
    uint32_t get_value(std::string key) const { return settings.at(key); };
    /* returns if user want to have default simulation */
    bool settings_default() const { return is_default; };
    /*
    gets input from user about iterations, floor_number and lift_max_weight
    also saves it to map */
    void get_settings();
};
