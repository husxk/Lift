#include "Settings.h"

Settings::Settings()
{
    std::cout << "Default settings? [y/n] [any key -> yes]"  << std::endl;

    char answer = std::cin.get();

    if(answer == 'n' || answer == 'N')
        is_default = false;
    else is_default = true;
}

bool Settings::settings_default()
{
    return this->is_default;
}

uint32_t Settings::get_input(std::string what)
{
    uint32_t value;
    try
    {
        std::cout << std::endl << "Insert " << what << " in range of uint32_t: ";
        std::cin >> value;

        if(std::cin.fail() | std::cin.bad()) throw std::invalid_argument("Bad input, cannot do conversion");
        if(!std::cin.good()) throw std::invalid_argument("Bad input, unhandled error");

    }
    catch(std::exception &e)
    {
        std::cout << std::endl << e.what()<< std::endl;
        exit(1);
    }

    return value;
}

uint32_t Settings::get_value(std::string key)
{
    return settings.at(key);
}

void Settings::get_settings()
{
    if(is_default)
    {
        settings.emplace("iterations", default_iterations);
        settings.emplace("floor_number", default_floor_number);
        settings.emplace("lift_max_weight", default_lift_max_weight);
        return;
    }

    settings.emplace("iterations", get_input("iterations"));
    settings.emplace("floor_number", get_input("floor_number"));
    settings.emplace("lift_max_weight", get_input("lift_max_weight"));
}
