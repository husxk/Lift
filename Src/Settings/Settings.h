#pragma once

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <unordered_map>

constexpr uint32_t default_iterations = 100;
constexpr uint32_t default_lift_max_weight = 800;
constexpr uint32_t default_floor_number = 10;

class Settings
{
    std::unordered_map<std::string, uint32_t> settings; // iterations, lift_max_weight, floors,
    bool is_default;
    uint32_t get_input(std::string);

public:
    uint32_t get_value(std::string);
    Settings();
    bool settings_default();
    void get_settings();
};
