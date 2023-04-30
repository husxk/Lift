#include "Simulator.h"

Simulator::Simulator()
{
    settings = std::make_shared<Settings>();
    settings->get_settings();

    if(settings->is_default) // TODO: test it
        auto lift = std::make_shared<Lift>();
    else auto lift = std::make_shared<Lift>(settings->get_value("lift_max_weight"), settings->get_value("floor_number"));
}