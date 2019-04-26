#include "passenger.hpp"
#include "busStation.hpp"
#include "schoolBus.hpp"

void queryMode(BusStation *busStation, SchoolBus *schoolBus) {
    std::cout << "Entering query mode..." << '\n';
    while(1) {
        std::cout << "1.You can inquire the school buses route." << '\n';
        std::cout << "2.You can also inquire more information by entering the school bus's id." << '\n';
        std::cout << "Press 0 to quit." << '\n';
        char input = legalInput(0, 2);
        if(input == '0') break;
        if(input == '1')
            inquireRoutes(busStation, schoolBus);
        else {
            inquireBuses(busStation, schoolBus);
        }
    }
}

void inquireRoutes(BusStation *busStation, SchoolBus *schoolBus) {
    while(1) {
        for(int i=1; i<=LINENUMBER; i++)
          std::cout << "line" << i << ": " << getRoute(i, 0, busStation) << '\n';
        std::cout << "You can choose a route, for more information." << '\n';
        std::cout << "Press 0 to go back." << '\n';
        char input = legalInput(0, LINENUMBER);
        if(input == '0') break;
        inquireStations(input-'0', busStation, schoolBus);
    }
}

void inquireStations(int line, BusStation *busStation, SchoolBus *schoolBus) {
    while (1) {
        std::cout << getStationNum(line, 0, busStation) << '\n';
        std::cout << "Enter the number of the station, for more details." << '\n';
        std::cout << "Press 0 to go back." << '\n';
        int routeLength = getRouteLength(line, busStation);
        char input = legalInput(0, routeLength);
        if(input == '0') break;
        busStation[input-'0'-1].printInfo(schoolBus);
    }
}

void inquireBuses(BusStation *busStation, SchoolBus *schoolBus) {
    while (1) {
        std::cout << "Plz enter the school bus's id(1~"
        << BUSNUMBER << "), for more information." << '\n';
        std::cout << "Press 0 to go back." << '\n';
        int input = legalInput(0, BUSNUMBER);
        if(input == '0') break;
        schoolBus[input-'0'-1].printInfo(busStation);
    }
}
