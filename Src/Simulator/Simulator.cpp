#include "Simulator.h"

Simulator::Simulator()
{
    settings = std::make_shared<Settings>();
    settings->get_settings();
    // TODO: add lift 
}