#include <memory>
#include "Simulator/Simulator.h"
#include <cstdlib>

int main()
{
    srand(time(nullptr));

    auto simulator = std::make_shared<Simulator>();

    // run simulator
    for(; simulator->iterations < simulator->get_iterations() ; simulator->iterations++) {
        simulator->iteration();
    }

    // set if simulation is successful
    if(simulator->is_lift_empty())
        simulator->is_simulation_successful(true);
    else simulator->is_simulation_successful(false);

    simulator->show_results();
}