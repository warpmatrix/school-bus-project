#include "schoolBus.hpp"
#include "busStation.hpp"


SchoolBus::SchoolBus() {
    emptySeat = SUMSEAT;
    // isRunning = true;
    isRunning = false;
    location = STARTLOC+1;
    line = 1;
}

// int getId() const {
//     return id;
// }
int SchoolBus::getLocation() const {
    return location;
}
/*
int SchoolBus::getEmptySeat() const {
    return emptySeat;
}
*/
bool SchoolBus::getIsRunning() const {
    return isRunning;
}

bool SchoolBus::setLine(int line, BusStation *busStation) {
    if(busStation[location].getNext(line) != -1 && !isRunning) {
        this->line = line;
        return true;
    }
    return false;
}
void SchoolBus::updateEmptySeat(int detNum) {
    emptySeat += detNum;
}
void SchoolBus::setIsRunning(bool isRunning) {
    this->isRunning = isRunning;
}
void SchoolBus::setId(int id) {
    this->id = id;
}

void SchoolBus::printInfo(const BusStation *busStation) const {
    std::cout << "The bus you inquire is ";
    if(isRunning) {
        std::cout << "runing to "
            << busStation[location].getName() << ".\n";
    }
    else {
        std::cout << "waiting for you in "
            << busStation[location].getName() << ".\n";
    }
    std::cout << "The empty seat: " << emptySeat << '\n';
}
