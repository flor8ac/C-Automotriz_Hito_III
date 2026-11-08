#pragma once
#include<string>

class Sensor {
private:
    std::string name;
    std::string unit;
    double value;
    double minLimit;
    double maxLimit;
    bool valid;
    int unupdatedCycles;
    int maxUnupdatedCycles;

public:
    Sensor(std::string name, std::string unit, double minLimit, double maxLimit, int maxUnupdatedCycles = 3);

    void update(double newValue);
    void registerUnupdatedCycle();

    std::string getName() const;
    std::string getUnit() const;
    double getValue() const;
    bool isValid() const;
    int getUnupdatedCycles() const;
};