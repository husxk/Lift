#include  <iostream>
#include <memory>
#include "Simulator/Simulator.h"
#include <cstdlib>

int main()
{
    srand(time(NULL));
    auto simulator = std::make_shared<Simulator>();

    for(int i = 0; i < simulator->get_iterations() ; i++) {
        simulator->iteration();
    }

    std::cout << std::endl << "end";
}