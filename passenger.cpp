#include "passenger.hpp"
#include "busStation.hpp"
#include "schoolBus.hpp"

void queryMode(const BusStation *busStation, const SchoolBus *schoolBus) {
    std::cout << "Entering query mode..." << '\n';
    std::cout << '\n';
    while(1) {
        std::cout << "1.You can inquire the school buses routes." << '\n';
        std::cout << "2.You can also inquire more information by entering the school bus's id." << '\n';
        std::cout << "Press Esc to quit the inquire mode." << '\n';
        char input = legalInput(1, 2);
        if(input == '\x1B') break;
        if(input == '1')
            inquireRoutes(busStation, schoolBus);
        else inquireBuses(busStation, schoolBus);
    }
}

void inquireRoutes(const BusStation *busStation, const SchoolBus *schoolBus) {
    while(1) {
        for(int i=1; i<=LINENUMBER; i++)
          std::cout << "line" << i << ": " << getRoute(i, 0, busStation) << "\n\n";
        std::cout << "You can choose a line, for more information." << '\n';
        std::cout << "Press Esc to go back." << '\n';
        char input = legalInput(1, LINENUMBER);
        if(input == '\x1B') break;
        inquireStations(input-'0', busStation, schoolBus);
    }
}

void inquireStations(int line, const BusStation *busStation, const SchoolBus *schoolBus) {
    while (1) {
        std::cout << getStationNum(line, 0, busStation) << "\n\n";
        std::cout << "Enter the number of the station, for more details." << '\n';
        std::cout << "Press Esc to go back." << '\n';
        int routeLength = getRouteLength(line, busStation);
        char input = legalInput(1, routeLength);
        if(input == '\x1B') break;
        busStation[input-'0'-1].printInfo(schoolBus);
    }
}

void inquireBuses(const BusStation *busStation, const SchoolBus *schoolBus) {
    while (1) {
        std::cout << "Plz enter the school bus's id(1~"
        << BUSNUMBER << "), for more information." << '\n';
        int id;
        std::cin >> id;
        schoolBus[ id-1 ].printInfo(busStation);
        std::cout << '\n' << "You will return to the higher menu if you enter 'Esc'..." << '\n';
        std::cout << "Or enter any other key to inquire other school bus," << '\n';
        char input = getch();
        system("cls");
        if(input == '\x1B') break;
    }
}

std::string getRoute(int line, int head, const BusStation *busStation) {
    std::string str;
    for(int p=head; p!=-1; p=busStation[p].getNext(line) )
      if(p==head) str += busStation[p].getName();
      else str += "<->" + busStation[p].getName();
    return str;
}

std::string getStationNum(int line, int head, const BusStation *busStation) {
    std::string str;
    int num = 1;
    for(int p=head; p!=-1; p=busStation[p].getNext(line) ) {
        if(num == 1)
          str += std::to_string(num++) + '.' + busStation[p].getName();
        else str += "<->" + std::to_string(num++) + '.' + busStation[p].getName();
    }
    return str;
}

int getRouteLength(int line, const BusStation *busStation) {
    int length = 0;
    for(int p=0; p!=-1; p=busStation[p].getNext(line) )
        length++;
    return length;
}
