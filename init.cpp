#include "init.hpp"

void init(BusStation *busStation, SchoolBus *schoolBus) {
    system("color 0E");
    
    for(int i=0; i<BUSNUMBER; i++)
      schoolBus[i].setId(i);

    busStation[0].setName("canteen", 0);
    busStation[1].setName("southLab", 1);
    busStation[2].setName("northLab", 2);
    busStation[3].setName("library", 3);
    busStation[4].setName("teacBuilding", 4);
    busStation[5].setName("collBuilding", 5);
    busStation[6].setName("northGate", 6);

    busStation[0].setNext(1, 1, busStation);
    busStation[1].setNext(1, 3, busStation);
    busStation[3].setNext(1, 4, busStation);

    busStation[0].setNext(2, 1, busStation);
    busStation[1].setNext(2, 2, busStation);
    busStation[1].setNext(2, 2, busStation);
    busStation[2].setNext(2, 6, busStation);
    busStation[6].setNext(2, 5, busStation);
}
char legalInput(int min, int max) {
    char input;
    input = getch();
    std::cout << '\n';
    while(!(input>=min+'0' && input<=max+'0') ) {
        std::cout << "Invalid input! Please re-enter: ";
        input = getch();
        std::cout << '\n';
    }
    system("cls");
    return input;
}
std::string getRoute(int line, int head, BusStation *busStation) {
    std::string str;
    for(int p=head; p!=-1; p=busStation[p].getNext(line) )
      if(p==head) str += busStation[p].getName();
      else str += "<->" + busStation[p].getName();
    return str;
}
std::string getStationNum(int line, int head, BusStation *busStation) {
    std::string str;
    int num = 1;
    for(int p=head; p!=-1; p=busStation[p].getNext(line) ) {
        if(num == 1)
          str += std::to_string(num++) + '.' + busStation[p].getName();
        else str += "<->" + std::to_string(num++) + '.' + busStation[p].getName();
    }
    return str;
}
int getRouteLength(int line, BusStation *busStation) {
    int length = 0;
    for(int p=0; p!=-1; p=busStation[p].getNext(line) )
        length++;
    return length;
}
