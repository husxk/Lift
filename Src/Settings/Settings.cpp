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
        std::cout << "success";
    }
    catch(std::ifstream::failure e)
    {
        std::cerr << e.what() << std::endl << "Cannot open file" << std::endl;
        exit(1);
    }
}