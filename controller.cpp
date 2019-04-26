#include "controller.hpp"

void controllerMode(BusStation *busStation, SchoolBus *schoolBus) {
    while (1) {
        std::cout << "*** the information" << '\n';
        char input = legalInput(0, 2);
        if(input == '0') break;
        if(input == '1') queryMode(busStation, schoolBus);
        else setMode(busStation, schoolBus);
    }
}

void setMode(BusStation *busStation, SchoolBus *schoolBus) {
    while (1) {
        std::cout << "1. Update busStation 2. Update schoolBus" << '\n';
        char input = legalInput(0,2);
        if(input == '0') break;
        // if(input == '1') updateStation(busStation);
        // else updateBus(schoolBus);
    }
}
