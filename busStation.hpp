#ifndef BUSSTATION_H_
#define BUSSTATION_H_
#include <string>
class SchoolBus;

class BusStation {
public:
    BusStation();

    void setNext(int line, int nextStation, BusStation *busStation);
    void setName(std::string name, int id);

    std::string getName() const;
    int getNext(int line) const;
    int getWait() const;

    void printInfo(SchoolBus *schoolBus) const;
private:
    int id;
    std::string name;
    int waitingPass;
    int next[LINENUMBER];
    int prev[LINENUMBER];
};

#endif
