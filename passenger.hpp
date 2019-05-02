#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <iostream>
#include <string>
#include "init.hpp"

class BusStation;
class SchoolBus;

void queryMode(const BusStation *busStation, const SchoolBus *schoolBus);
void inquireRoutes(const BusStation *busStation, const SchoolBus *schoolBus);
void inquireStations(int line, const BusStation *busStation, const SchoolBus *schoolBus);
void inquireBuses(const BusStation *busStation, const SchoolBus *schoolBus);
std::string getRoute(int line, int head, const BusStation *busStation);
std::string getStationNum(int line, int head, const BusStation *busStation);
int getRouteLength(int line, const BusStation *busStation);

#endif
