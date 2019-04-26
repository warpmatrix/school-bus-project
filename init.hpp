#ifndef INIT_H_
#define INIT_H_
#define LINENUMBER 2
#define STATIONNUMBER 7
#define BUSNUMBER 10
#include <string>
#include <conio.h>
#include "busStation.cpp"
#include "schoolBus.cpp"

void init();
char legalInput(int min, int max);
std::string getRoute(int line);
std::string getStationNum(int line, int head, BusStation *busStation);
int getRouteLength(int line, BusStation *busStation);
bool signIn();

#endif
