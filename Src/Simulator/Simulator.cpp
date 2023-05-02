#include "Simulator.h"

Simulator::Simulator() // TODO: add data collector class
{
    settings = std::make_shared<Settings>();
    settings->get_settings();

    if(settings->is_default)
        lift = std::make_shared<Lift>();
    else lift = std::make_shared<Lift>(settings->get_value("lift_max_weight"), settings->get_value("floor_number"));
}