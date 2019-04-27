#ifndef PASSENGER_H_
#define PASSENGER_H_
class BusStation;
class SchoolBus;

void queryMode(BusStation *busStation, SchoolBus *schoolBus);
void inquireRoutes(BusStation *busStation, SchoolBus *schoolBus);
void inquireStations(int line, BusStation *busStation, SchoolBus *schoolBus);
void inquireBuses(BusStation *busStation, SchoolBus *schoolBus);
std::string getRoute(int line, int head, BusStation *busStation);
std::string getStationNum(int line, int head, BusStation *busStation);
int getRouteLength(int line, BusStation *busStation);

#endif
