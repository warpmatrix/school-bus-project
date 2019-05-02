#ifndef SCHOOLBUS_H_
#define SCHOOLBUS_H_

#define SUMSEAT 20
#define STARTLOC 0

class BusStation;

class SchoolBus {
public:
    SchoolBus();
    int getLocation() const;
    bool getIsRunning() const;
    void printInfo(const BusStation *busStation) const;
    void setId(int id);
    bool setLine(int line, BusStation *busStation);
    void updateEmptySeat(int detNum);
    void setIsRunning(bool isRunning);
private:
    int id;
    int line;
    int emptySeat;
    bool isRunning;
    int location;
};
#endif
