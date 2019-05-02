#include "schoolBus.hpp"
#include "busStation.hpp"

SchoolBus::SchoolBus() {
    emptySeat = SUMSEAT;
    isRunning = false;
    location = STARTLOC;
    line = 1;
}

int SchoolBus::getLocation() const {
    return location;
}

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
    std::cout << "The line " << line << " bus(id=" << id+1 << ") you inquire is ";
    if(isRunning) {
        std::cout << "runing to "
            << busStation[location].getName() << ".\n";
    }
    else {
        std::cout << "waiting for you in "
            << busStation[location].getName() << ".\n";
    }
    std::cout << "There are " << emptySeat << " empty seat on the bus."<< '\n';
}
