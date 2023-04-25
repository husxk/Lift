#pragma once

#include <fstream>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <unordered_map>

constexpr auto path_to_file = "settings.txt";
constexpr auto delimiter = " = ";

class Settings
{
    uint32_t iterations;
    std::unordered_map<std::string, uint16_t> settings;

public:
    Settings();
    void read_setting_file();
};
