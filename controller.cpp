#include "controller.hpp"
#include "busStation.hpp"
#include "schoolBus.hpp"

void controllerMode(BusStation *busStation, SchoolBus *schoolBus) {
    while (1) {
        std::cout << "1. Query mode 2. Set mode" << '\n';
        std::cout << "press Esc to return." << '\n';
        char input = legalInput(1, 2);
        if(input == '\x1B') break;
        if(input == '1') queryMode(busStation, schoolBus);
        else setMode(busStation, schoolBus);
    }
}

void setMode(BusStation *busStation, SchoolBus *schoolBus) {
    while (1) {
        std::cout << "1. Update busStation" << '\n';
        std::cout << "     You can update the waiting passenger's number in specified station." << '\n';
        std::cout << "2. Update schoolBus" << '\n';
        std::cout << "     You can reset the line or update the passengers in the bus etc." << '\n';
        std::cout << '\n';
        std::cout << "As the same, press Esc to return." << '\n';
        char input = legalInput(1, 2);
        if(input == '\x1B') break;
        if(input == '1') updateStation(busStation);
        else updateBus(schoolBus, busStation);
    }
}

void updateStation(BusStation *busStation) {
    while (1) {
        std::cout << "Enter the bus station's id: " << '\n';
        char input = legalInput(1, STATIONNUMBER);
        if(input == '\x1B') break;
        int id = input - '0' - 1;
        std::cout << "Leave passengers: ";
        int passengerLef;
        std::cin >> passengerLef;
        std::cout <<"Arrival passengers: ";
        int passengerArr;
        std::cin >> passengerArr;

        busStation[id].updateWait(passengerArr - passengerLef);

        std::cout << '\n' << "You will return to the higher menu if you enter 'Esc'..." << '\n';
        std::cout << "Or enter any other key to return to the Update Bus Station menu" << '\n';
        input = getch();
        system("cls");
        if(input == '\x1B') break;
    }
}

void updateBus(SchoolBus *schoolBus, BusStation *busStation) {
    std::cout << "Enter the bus's id: " << '\n';
    char input = legalInput(1, BUSNUMBER);
    std::cout << "Choose what funtion you want to use." << '\n';
    std::cout << "1. pull-out/pull-up 2.the number of passenger on the bus 3.reset the line" << '\n';
    int id = input - '0' + 1；
    switch (input) {
        case '1':
            std::cout << "Set the bus running? (y/n): " << '\n';
            char ch = getch();
            if(ch=='y' || ch=='Y')
              schoolBus[id].setIsRunning(true);
            else schoolBus[id].setIsRunning(false);
            break;
        case '2':
            std::cout << "Leave passengers: ";
            int passengerLef;
            std::cin >> passengerLef;
            std::cout <<"Arrival passengers: ";
            int passengerArr;
            std::cin >> passengerArr;
            schoolBus[id].updateEmptySeat(passengerArr - passengerLef);
            break;
        case '3':
            std::cout << "Plz enter the line you want to set: " << '\n';
            char input = legalInput(1, LINENUMBER);
            if(!schoolBus[id].setLine(line, busStation) )
                std::cout << "Fail to reset the line." << '\n';
                std::cout << "May be due //(to the line) or the running state" << '\n';
            else {
                schoolBus[id].setLine(line, busStation);
                std::cout << "" << '\n';
            }

        case '\x1B':
            break;
    }
}
