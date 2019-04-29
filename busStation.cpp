#include "busStation.hpp"
#include "schoolBus.hpp"

BusStation::BusStation() {
    waitingPass = 0;
    for(int i=1; i<=LINENUMBER; i++){
        next[i] = -1;
        prev[i] = -1;
    }
}

void BusStation::setNext(int line, int nextStation, BusStation *busStation) {
    busStation[nextStation].prev[line] = id;
    next[line] = nextStation;
}
void BusStation::setName(std::string name, int id) {
    this->name = name;
    this->id = id;
}

std::string BusStation::getName() const {
    return name;
}
int BusStation::getNext(int line) const {
    return next[line];
}
int BusStation::getWait() const {
    return waitingPass;
}

void BusStation::printInfo(const SchoolBus *schoolBus) const {
    std::cout << "The number of waiting passenger: " << waitingPass << '\n';
    int countComingBus = 0;
    int countWaitingBus = 0;
    for(int i=0; i<=BUSNUMBER; i++)
      if(schoolBus[i].getLocation()==id)
        if(schoolBus[i].getIsRunning()==true)
          countComingBus++;
        else countWaitingBus++;
    std::cout << countWaitingBus << " buses is on the station." << '\n';
    std::cout << "There are " << countComingBus << " buses on the way." << '\n' << '\n';
}
