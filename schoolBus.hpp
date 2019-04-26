#ifndef SCHOOLBUS_H_
#define SCHOOLBUS_H_
#define SUMSEAT 20
#define STARTLOC 0
class BusStation;

class SchoolBus {
public:
    SchoolBus();
    // int getId() const;
    int getLocation() const;
    // int getEmptySeat() const;
    bool getIsRunning() const;
    void printInfo(BusStation *busStation) const;
    void setId(int id);
    bool setLine(int line, BusStation *busStation);
    void setEmptySeat(int detNum);
    void setIsRunning(bool isRunning);
private:
    int id;
    int line;
    int emptySeat;
    bool isRunning;
    int location;
};
#endif
