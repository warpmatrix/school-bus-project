#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <iostream>
#include <string>
#include "init.hpp"
#include "passenger.hpp"

class BusStation;
class SchoolBus;

void controllerMode(BusStation *busStation, SchoolBus *schoolBus);
void setMode(BusStation *busStation, SchoolBus *schoolBus);
void updateStation(BusStation *busStation);
void updateBus(SchoolBus *schoolBus);

#endif
