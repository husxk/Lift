#include "Settings.h"

Settings::Settings() // Checks if settings file exists
{
    std::cout << "settings constructor\n";

    std::ifstream file;

    file.exceptions(std::ifstream::badbit | std::ifstream::failbit);

    try
    {
        file.open(path_to_file);
        file.close();
        std::cout << "success" << std::endl;
    }
    catch(std::ifstream::failure &e)
    {
        std::cerr << e.what() << std::endl << "Cannot open file" << std::endl;
        exit(1);
    }
}

void Settings::read_setting_file()
{
    std::ifstream file;
    file.open(path_to_file);

    std::string buffer;
    std::getline(file, buffer); // to check if it is setting file

    std::string setting_file = "# SETTING FILE";

    if(strcmp(buffer.c_str(), setting_file.c_str()) != 0)
    {
        std::cout << std::endl << path_to_file << " is not a setting file" << std::endl;
        exit(1);
    }

    while(!file.eof()) // loads all elements to a map
    {
        std::string key;
        std::string string_value;

        std::getline(file, buffer);

        if(buffer.empty()) // checks for empty line
            continue;

        uint32_t pos = buffer.find(delimiter);
        key = buffer.substr(0, pos);
        string_value = buffer.erase(0, pos + strlen(delimiter));

        uint16_t value;

        try
        {
            value = std::stoi(string_value);    // input error handling // TODO: there is possibility to input larger number than uint16_t -> fix it
        }
        catch(std::invalid_argument e)
        {
            std::cout << std::endl << "Bad input in " << path_to_file << " (cannot do conversion) at " << key << std::endl;
            exit(1);
        }
        catch(std::out_of_range e)
        {
            std::cout << std::endl << "Bad input in " << path_to_file << " (out of range) at " << key << std::endl;
            exit(1);
        }

        settings.emplace(key, value);
    }

    file.close();
    std::cout << settings.at("lift_max_weight");

}