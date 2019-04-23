#include "schoolBus.hpp"
#include "busStation.hpp"


SchoolBus::SchoolBus() {
    emptySeat = SUMSEAT;
    isRunning = true;
    location = STARTLOC;
    line = 1;
}

// int getId() const {
//     return id;
// }

int SchoolBus::getLocation() const {
    return location;
}
int SchoolBus::getEmptySeat() const {
    return emptySeat;
}
bool SchoolBus::getIsRunning() const {
    return isRunning;
}

bool SchoolBus::setLine(int line, BusStation *busStation) {
    if(busStation[location].getNext(line) != -1) {
        this->line = line;
        return true;
    }
    return false;
}
void SchoolBus::setEmptySeat(int detNum) {
    emptySeat += detNum;
}
void SchoolBus::setIsRunning(bool isRunning) {
    this->isRunning = isRunning;
}
void SchoolBus::setId(int id) {
    this->id = id;
}
