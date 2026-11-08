#include "sensor.h"

Sensor::Sensor(std::string name, std::string unit, double minLimit, double maxLimit, int maxUnupdatedCycles)
    : name(name), unit(unit), value(minLimit), minLimit(minLimit), maxLimit(maxLimit), valid(true), unupdatedCycles(0), maxUnupdatedCycles(maxUnupdatedCycles) {}

void Sensor::update(double newValue) {
    value = newValue;
    unupdatedCycles = 0; // Reset temporal counter
    
    // Range validation
    if (value >= minLimit && value <= maxLimit) {
        valid = true;
    } else {
        valid = false;
    }
}

void Sensor::registerUnupdatedCycle() {
    unupdatedCycles++;
    if (unupdatedCycles > maxUnupdatedCycles) {
        valid = false; // Invalid due to temporal timeout
    }
}

std::string Sensor::getName() const { return name; }
std::string Sensor::getUnit() const { return unit; }
double Sensor::getValue() const { return value; }
bool Sensor::isValid() const { return valid; }
int Sensor::getUnupdatedCycles() const { return unupdatedCycles; }