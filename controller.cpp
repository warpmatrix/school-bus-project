#include "controller.hpp"
#include "busStation.hpp"
#include "schoolBus.hpp"

void controllerMode(BusStation *busStation, SchoolBus *schoolBus) {
    while (1) {
        std::cout << "*** the information" << '\n';
        char input = legalInput(1, 2);
        if(input == '\x1B') break;
        if(input == '1') queryMode(busStation, schoolBus);
        else setMode(busStation, schoolBus);
    }
}

void setMode(BusStation *busStation, SchoolBus *schoolBus) {
    while (1) {
        std::cout << "1. Update busStation 2. Update schoolBus" << '\n';
        char input = legalInput(1, 2);
        if(input == '\x1B') break;
        if(input == '1') updateStation(busStation);
        else updateBus(schoolBus);
    }
}

void updateStation(BusStation *busStation) {
    while (1) {
        std::cout << "Enter the bus station's id: " << '\n';
        char input = legalInput(1, 7);
        int id = input - '0' - 1;
        std::cout << "Leave *** passengers: ";
        int passengerLef;
        std::cin >> passengerLef;
        std::cout <<"Arrival *** passengers: ";
        int passengerArr;
        std::cin >> passengerArr;

        // busStation[id].setWait( passengerArr - passengerLef );
        std::cout << '\n' << "You will return to the higher menu if you enter 'Esc'..." << '\n';
        std::cout << "Or enter any other key to return to the Update Bus Station menu" << '\n';
        input = getch();
        system("cls");
        if(input == '\x1B') break;
    }
}

void updateBus(SchoolBus *schoolBus) {}
